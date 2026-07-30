#ifndef SDB_H
#define SDB_H
#include "STD.h"
#define MIN_YEAR 2000
#define MAX_STUDENT_COUNT 10
#define MAX_COURSES 3
typedef struct course
{
    uint32 ID;
    uint32 Grade;
} Course;

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    Course courses[MAX_COURSES];
} Student;

#endif

typedef struct StudentsDb
{
    int currentStudentCount;
    Student students[MAX_STUDENT_COUNT];
} StudentDb;

static StudentDb db;

boolean SDB_IsFull();
uint8 SDB_GetUsedSize();
boolean SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
boolean SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *idList);
boolean SDB_IsIdExist(uint32 id);
void SDB_App();
void SDB_Action(uint8 choice);