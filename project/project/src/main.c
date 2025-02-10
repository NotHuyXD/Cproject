#include <stdio.h>
#include <stdlib.h>
#include "function.c"
int main(int argc, char const *argv[])
{
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
                    addStu();
                    break;
                case 2:
                    showList();
                    break;
                case 7:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                }
            } while (menuchoice != 6);
            break;
        case 2:
            do
            {
                menu2();
                printf("Nhập lựa chọn của bạn: ");
                scanf("%d", &menuchoice);
                switch (menuchoice)
                {
                case 4:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                    break;
                }
            } while (menuchoice != 4);
            break;
        case 3:
            do
            {
                menu3();
                printf("Lựa chọn của bạn: ");
                scanf("%d", &menuchoice);
                switch (menuchoice)
                {
                case 4:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                    break;
                }
            } while (menuchoice != 4);
            break;
        case 4:
            break;
        default:
            printf("Lựa chọn không hợp lệ\n");
        }
    } while (choice != 4);
    return 0;
}