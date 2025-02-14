#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct BirthDate
{
    int day, month, year;
} BirthDate;
typedef struct student
{
    int age;
    char phone[11], name[20], gmail[31], id[11];
    BirthDate birthdate;
    char classId[10];
} Student;
typedef struct classroom
{
    char name[11], id[11];
    Student students[20];
    char teacherName[20];
    int totalStudent;
} Classroom;
typedef struct teacher
{
    int age, totalClass;
    char phone[11], name[20], gmail[31], id[11];
    BirthDate birthdate;
    Classroom classroom[];

} Teacher;
Student s[100];
Classroom c[10];
Teacher t[100];
int choice, totalStudent = 0, totalTeacher = 0, totalClass = 0, loop = 0, check = 0, leap = 0, exist = 0;
char find[20], del[10], add[10];
int classList = 0;
int n, option, numToAdd;
char sort;