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
    char phone[10], name[20], gmail[50], id[10];
    BirthDate birthdate;
    char classId[10];
} Student;
typedef struct classroom
{
    char name[10], id[10];
    Student students[20];
    char teacherId[10];
} Classroom;
typedef struct teacher
{
    int age;
    char phone[10], name[20], gmail[50], id[10];
    BirthDate birthdate;
    Classroom classroom[];

} Teacher;
Student s[100];
Classroom c[10];
Teacher t[100];
int choice, totalStudent = 0, totalTeacher = 0, totalClass = 0, loop = 0, check = 0, leap = 0;
char find[50], del[50];
int classList = 0;
int n;