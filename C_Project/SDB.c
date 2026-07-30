#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"
#include "cmd_helper.h"
#include <string.h>
#include <time.h>

typedef enum
{
    MENU_OPTION_ADD_STUDENT,
    MENU_OPTION_READ_STUDENT,
    MENU_OPTION_READ_ALL_STUDENTS,
    MENU_OPTION_DELETE_STUDENT,
    MENU_OPTION_FIND_STUDENT,
    MENU_OPTION_EXIT,
    MENU_OPTION_END
} MenuOption;

boolean SDB_IsFull()
{
    return db.currentStudentCount == MAX_STUDENT_COUNT;
}
uint8 SDB_GetUsedSize()
{
    return db.currentStudentCount;
}
void InputCourse(int courseNum, Course *course)
{
    int id = 0;
    do
    {
        printf("Enter Course %d ID (NOT ZERO): ", courseNum);
        char *idStr = GetString();
        id = atoi(idStr);
    } while (id <= 0);
    course->ID = id;
    int grade = 0;
    do
    {
        printf("Enter Course %d Grade (NOT ZERO): ", courseNum);
        char *gradeStr = GetString();
        grade = atoi(gradeStr);
    } while (grade <= 0);
    course->Grade = grade;
}
int GetStudentYear()
{
    time_t t = time(NULL);
    struct tm *localTime = localtime(&t);
    int currentYear = localTime->tm_year + 1900;

    int year = 0;
    do
    {
        printf("Enter Student Year (YYYY >= 2000): ");
        char *yearStr = GetString();
        year = atoi(yearStr);
    } while (year <= 0 || year > currentYear || year < MIN_YEAR);

    return year;
}
boolean SDB_AddEntry()
{
    if (db.currentStudentCount == MAX_STUDENT_COUNT)
    {
        return FALSE;
    }

    Student student;

    int studentId = 0;
    do
    {
        printf("Enter Student Id: ");
        char *studentIdStr = GetString();
        studentId = atoi(studentIdStr);
    } while (studentId <= 0);
    student.Student_ID = studentId;

    student.Student_year = GetStudentYear();

    for (int i = 0; i < MAX_COURSES; i++)
    {
        InputCourse(i + 1, &student.courses[i]);
    }

    db.students[db.currentStudentCount] = student;
    db.currentStudentCount++;

    return TRUE;
}
void SDB_DeleteEntry(uint32 id)
{
    if (SDB_GetUsedSize() == 0)
        return;
    for (int i = 0; i < db.currentStudentCount; i++)
    {
        if (db.students[i].Student_ID == id)
        {
            for (int j = i; j < db.currentStudentCount - 1; i++)
            {
                db.students[j] = db.students[j + 1];
            }
            db.currentStudentCount--;
        }
    }
}
void PrintStudent(const Student *const s)
{
    printf("Student_ID: %d\n", s->Student_ID);
    printf("Student Year: %d", s->Student_year);
    for (int i = 0; i < MAX_COURSES; i++)
    {
        printf("Course(%d) (Id,Grade): (%d, %d)\n", i + 1, s->courses[i].ID, s->courses[i].Grade);
    }
}
boolean SDB_ReadEntry(uint32 id)
{
    for (int i = 0; i < db.currentStudentCount; i++)
    {
        if (db.students[i].Student_ID == id)
        {
            Student s = db.students[i];
            PrintStudent(&s);
            return TRUE;
        }
    }
    return FALSE;
}
void SDB_GetList(uint8 *count, uint32 *idList)
{
    *count = db.currentStudentCount;
    for (int i = 0; i < db.currentStudentCount; i++)
    {
        idList[i] = db.students[i].Student_ID;
    }
}
boolean SDB_IsIdExist(uint32 id)
{
    for (int i = 0; i < db.currentStudentCount; i++)
    {
        if (db.students[i].Student_ID == id)
        {
            return TRUE;
        }
    }
    return FALSE;
}

static void PrintMenu()
{
    PrintMenuTitle("MAIN MENU");
    printf("1) ADD STUDENT\n");
    printf("2) READ STUDENT\n");
    printf("3) READ ALL STUDENTS\n");
    printf("4) DELETE STUDENT\n");
    printf("5) FIND STUDENT\n");
    printf("6) EXIT\n");
}
static MenuOption GetMenuOption()
{
    int result = -1;
    do
    {
        printf("Enter menu option (%d,%d): ", MENU_OPTION_ADD_STUDENT + 1, MENU_OPTION_END);
        char *menuOptionStr = GetString();
        result = atoi(menuOptionStr);
        result--;
    } while (result < MENU_OPTION_ADD_STUDENT || result >= MENU_OPTION_END);

    return (MenuOption)result;
}

void SDB_App()
{
    MenuOption menuOption = MENU_OPTION_END;
    ClearScreen();
    PrintMenuTitle("Welcome to AMIT PROJECT C");
    PressEnterToContinue();
    ClearScreen();
    do
    {
        PrintMenu();
        menuOption = GetMenuOption();
        SDB_Action((uint8)menuOption);
        PressEnterToContinue();
        ClearScreen();
    } while (menuOption != MENU_OPTION_EXIT);
}
boolean DisplayNoStudentsWarning()
{
    if (SDB_GetUsedSize() == 0)
    {
        printf("No Students currently in DB\n");
        return TRUE;
    }
    return FALSE;
}
void DisplayAllStudentsId()
{
    if (DisplayNoStudentsWarning())
    {
        return;
    }
    uint32 idBuffer[MAX_STUDENT_COUNT];
    uint8 idBufferCount = 0;

    SDB_GetList(&idBufferCount, (uint32 *)idBuffer);
    for (int i = 0; i < idBufferCount; i++)
    {
        printf("%d - %d\n", i + 1, idBuffer[i]);
    }
}
void Menu_AddStudent()
{
    boolean result = SDB_AddEntry();
    printf((result ? "Student Added Successfuly\n" : "Failed to Add student\n"));
}

void Menu_DeleteStudent()
{
    if (DisplayNoStudentsWarning())
    {
        return;
    }
    DisplayAllStudentsId();
    int id;
    do
    {
        printf("Enter student's id to delete or -1 to go back: ");
        char *idStr = GetString();
        id = atoi(idStr);
        if(id == -1)
            return;
    } while ((id <= 0));

    SDB_DeleteEntry(id);
}

void Menu_FindStudent()
{
    if (DisplayNoStudentsWarning())
    {
        return;
    }
    DisplayAllStudentsId();
    printf("Enter student's id: ");
    int id;
    do
    {
        printf("Enter student's id to delete or -1 to go back: ");
        char *idStr = GetString();
        id = atoi(idStr);
        if(id == -1)
            return;
    } while ((id <= 0));

    printf(((SDB_IsIdExist(id)) ? "Student Exists\n" : "Student Not Available\n"));
}
void Menu_ReadStudent()
{
    if (DisplayNoStudentsWarning())
    {
        return;
    }
    DisplayAllStudentsId();
    printf("Enter student's id: ");

    int id;
    do
    {
        printf("Enter student's id to delete or -1 to go back: ");
        char *idStr = GetString();
        id = atoi(idStr);
        if(id == -1)
            return;
    } while ((id <= 0));
    printf("\n");
    boolean result = SDB_ReadEntry(id);
    printf("\n");
    if (!result)
    {
        printf("No student found with ID: %d\n", id);
    }
}

void Menu_ReadAllStudents()
{
    if (DisplayNoStudentsWarning())
    {
        return;
    }
    uint32 idBuffer[MAX_STUDENT_COUNT];
    uint8 idBufferCount = 0;

    SDB_GetList(&idBufferCount, (uint32 *)idBuffer);
    printf("\nStudents: %d\n", SDB_GetUsedSize());
    printf("========================================================================\n");
    for (int i = 0; i < idBufferCount; i++)
    {
        SDB_ReadEntry(idBuffer[i]);
        printf("========================================================================\n");
    }
}

void SDB_Action(uint8 choice)
{
    MenuOption menuOption = (MenuOption)choice;
    switch (menuOption)
    {
    case MENU_OPTION_ADD_STUDENT:
        Menu_AddStudent();
        break;
    case MENU_OPTION_DELETE_STUDENT:
        Menu_DeleteStudent();
        break;
    case MENU_OPTION_FIND_STUDENT:
        Menu_FindStudent();
        break;
    case MENU_OPTION_READ_STUDENT:
        Menu_ReadStudent();
        break;
    case MENU_OPTION_READ_ALL_STUDENTS:
        Menu_ReadAllStudents();
        break;
    case MENU_OPTION_EXIT:
        printf("Thanks for trying our app.\n");
        break;
    default:
        printf("Invalid Action Requested ID: %d\n", choice);
        break;
    }
}