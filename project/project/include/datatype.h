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
    char phone[10], name[50], gmail[50], id[10];
    BirthDate birthdate;
} Student;
typedef struct teacher
{
    int age;
    char phone[10], name[25], gmail[50], id[10];
    BirthDate birthdate;
} Teacher;
typedef struct classroom
{
    char name[10], id[10];
    Student students[40];
    Teacher teachers;
} Classroom;
Student s[100];
int choice, totalStudent = 0, totalTeacher = 0, totalClass = 0, loop = 0, check = 0, leap = 0;
char find[50], del[50];