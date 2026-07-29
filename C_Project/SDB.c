#include <stdio.h>
#include <stdlib.h>
#include "SDB.h"

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
    return db.currentStudentCount == 0;
}
uint8 SDB_GetUsedSize()
{
    return db.currentStudentCount;
}
void InputCourse(int courseNum, int *courseId, int *courseGrade)
{

    printf("Enter Course %d ID: ", courseNum);
    scanf("%d", courseId);

    printf("Enter Course %d Grade: ", courseNum);
    scanf("%d", courseGrade);
}
boolean SDB_AddEntry()
{
    if (db.currentStudentCount == MAX_STUDENT_COUNT)
    {
        return FALSE;
    }

    Student student;

    printf("Enter Student ID: ");
    scanf("%d", &student.Student_ID);

    InputCourse(1, &student.Course1_ID, &student.Course1_grade);
    InputCourse(2, &student.Course2_ID, &student.Course2_grade);
    InputCourse(3, &student.Course3_ID, &student.Course3_grade);

    db.students[db.currentStudentCount] = student;
    db.currentStudentCount++;

    return TRUE;
}
void SDB_DeleteEntry(uint32 id)
{
    for (int i = 0; i < db.currentStudentCount; i++)
    {
        if (db.students[i].Student_ID == id)
        {
            for (int j = i; j < db.currentStudentCount - 1; i++)
            {
                db.students[j] = db.students[j + 1];
            }
        }
    }
}
void PrintStudent(const Student *const s)
{
    printf("Student_ID: %d\n", s->Student_ID);
    printf("Course1 (Id,Grade): (%d, %d)\n", s->Course1_ID, s->Course1_grade);
    printf("Course2 (Id,Grade): (%d, %d)\n", s->Course2_ID, s->Course2_grade);
    printf("Course3 (Id,Grade): (%d, %d)\n", s->Course3_ID, s->Course3_grade);
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
        scanf("%d", &result);
        result--;
    } while (result < MENU_OPTION_ADD_STUDENT || result >= MENU_OPTION_END);
    return (MenuOption)result;
}

void ClearBuffer()
{
    char c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}
void PressEnterToContinue()
{
    ClearBuffer();
    printf("Press Enter to Continue...\n");
    char c = getchar();
    while (c != '\n')
        c = getchar();
}
void ClearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
}
void SDB_App()
{
    MenuOption menuOption = MENU_OPTION_END;
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

void Menu_AddStudent()
{
    boolean result = SDB_AddEntry();
    printf((result ? "Student Added Successfuly\n" : "Failed to Add student\n"));
}
void Menu_DeleteStudent()
{
    printf("Enter student's id to delete or -1 to go back: ");
    int id;
    scanf("%d", &id);
    if (id >= 0)
        SDB_DeleteEntry(id);

    return;
}

void Menu_FindStudent()
{
    printf("Enter student's id: ");
    int id;
    scanf("%d", &id);
    if (id >= 0)
        printf(((SDB_IsIdExist(id)) ? "Student Exists\n" : "Student Not Available\n"));

    return;
}
void Menu_ReadStudent()
{
    printf("Enter student's id: ");
    int id;
    scanf("%d", &id);
    if (id >= 0)
    {
        boolean result = SDB_ReadEntry(id);
        if (!result)
        {
            printf("No student found with ID: %d\n", id);
        }
    }
    return;
}

void Menu_ReadAllStudents()
{
    uint32 idBuffer[MAX_STUDENT_COUNT];
    uint8 idBufferCount = 0;

    SDB_GetList(&idBufferCount, (uint32 *)idBuffer);
    for (int i = 0; i < idBufferCount; i++)
    {
        SDB_ReadEntry(idBuffer[i]);
    }
    return;
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
    default:
        printf("Invalid Action Requested ID: %d\n", choice);
        break;
    }
}