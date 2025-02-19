#include <stdio.h>
#include <stdlib.h>
#include "function.c"
int main(int argc, char const *argv[])
{
    accountInformation();
    loginAccount();
    do
    {
        int menuchoice = 0;
        mainmenu();
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            do
            {
                menu1();
                printf("Nhập lựa chọn của bạn: ");
                scanf("%d", &menuchoice);
                switch (menuchoice)
                {
                case 1:
                    addStudent();
                    break;
                case 2:
                    showList();
                    break;
                case 3:
                    searchStudent();
                    break;
                case 4:
                    delStudent();
                    break;
                case 5:
                    editStudent();
                    break;
                case 6:
                    menuSort();
                    printf("Lựa chọn sắp xếp của bạn: ");
                    getchar();
                    scanf("%c", &sort);
                    switch (sort)
                    {
                    case 'a':
                        sortStudent1();
                        break;
                    case 'b':
                        sortStudent2();
                        break;
                    case 'c':
                        break;
                    default:
                        printf("Lựa chọn không hợp lệ\n");
                        break;
                    }
                case 7:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                }
            } while (menuchoice != 7);
            break;
        case 2:
            do
            {
                menu2();
                printf("Nhập lựa chọn của bạn: ");
                scanf("%d", &menuchoice);
                switch (menuchoice)
                {
                case 1:
                    addTeacher();
                    break;
                case 2:
                    listTeacher();
                    break;
                case 3:
                    delTeacher();
                    break;
                case 4:
                    editTeacher();
                    break;
                case 5:
                    searchTeacher();
                    break;
                case 6:
                    addClassTeacher();
                    break;
                case 7:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                    break;
                }
            } while (menuchoice != 7);
            break;
        case 3:
            do
            {
                menu3();
                printf("Lựa chọn của bạn: ");
                scanf("%d", &menuchoice);
                switch (menuchoice)
                {
                case 1:
                    addClass();
                    break;
                case 2:
                    listClass();
                    break;
                case 3:
                    delClass();
                    break;
                case 5:
                    showClass();
                    break;
                case 4:
                    editClass();
                    break;
                case 6:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                    break;
                }
            } while (menuchoice != 6);
            break;
        default:
            printf("Lựa chọn không hợp lệ\n");
        }
    } while (choice != 4);
    return 0;
}