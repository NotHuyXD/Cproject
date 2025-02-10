#include "../include/datatype.h"
void mainmenu()
{
    printf("===============PTIT MANAGEMENT===============\n");
    printf("||1. Quản lý sinh viên%22.5c||\n");
    printf("||2. Quản lý giáo viên%22.5c||\n");
    printf("||3. Quản lý lớp học%24.5c||\n");
    printf("||4. Thoát%34.5c||\n");
    printf("=============================================\n");
}
void menu1()
{
    printf("==============STUDENT MANAGEMENT==============\n");
    printf("||1. Thêm sinh viên%26.5c||\n");
    printf("||2. Hiển thị danh sách sinh viên%12.5c||\n");
    printf("||3. Tìm kiếm sinh viên%22.5c||\n");
    printf("||4. Xóa sinh viên%27.5c||\n");
    printf("||5. Sửa sinh viên%27.5c||\n");
    printf("||6. Sắp xếp sinh viên theo tên%14.5c||\n");
    printf("||7. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void menu2()
{
    printf("==============TEACHER MANAGEMENT==============\n");
    printf("||1. Thêm giáo viên%26.5c||\n");
    printf("||2. Xóa giáo viên%27.5c||\n");
    printf("||3. Sửa giáo viên%27.5c||\n");
    printf("||4. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void menu3()
{
    printf("===============CLASS MANAGEMENT===============\n");
    printf("||1. Thêm lớp học%28.5c||\n");
    printf("||2. Xóa lớp học%29.5c||\n");
    printf("||3. Sửa lớp học%29.5c||\n");
    printf("||4. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void addStu()
{
    FILE *f = fopen("Student.txt", "wb");
    int n;
    printf("Nhập số lượng sinh viên cần thêm:");
    scanf("%d", &n);
    if (totalStudent + n > 100)
    {
        printf("Danh sách sinh viên đã đầy\n");
    }
    for (int i = totalStudent; i < totalStudent + n; i++)
    {
        printf("Nhập thông tin sinh viên thứ %d\n", i + 1);
        do
        {
            loop = 0;
            check = 0;
            printf("Nhập ID sinh viên: ");
            scanf("%s", &s[i].id);
            if (s[i].id == "\0")
            {
                printf("ID không được để trống\n");
                loop = 1;
            }
            if (strlen(s[i].id) > 10)
            {
                printf("ID không được quá 10 ký tự\n");
                loop = 1;
            }
            if (s[i].id[0] != 'N' && s[i].id[1] != '2' && s[i].id[3] != '4')
            {
                printf("ID không hợp lệ\n");
                check = 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (s[i].id == s[j].id)
                {
                    printf("ID đã tồn tại\n");
                    loop = 1;
                    break;
                }
            }
        } while (strlen(s[i].id) > 10 || loop == 1 || check == 1);
        getchar();
        do
        {
            check = 0;
            printf("Nhập tên sinh viên: ");
            fgets(s[i].name, 35, stdin);
            s[i].name[strlen(s[i].name) - 1] = '\0';
            fflush(stdin);
            if (strlen(s[i].name) == 0)
            {
                printf("Tên không được để trống\n");
            }
            if (strlen(s[i].name) > 35)
            {
                printf("Tên không được quá 35 ký tự\n");
            }
            for (int j = 0; j < strlen(s[i].name); j++)
            {
                if (s[i].name[j] >= '0' && s[i].name[j] <= '9')
                {
                    printf("Tên không được chứa số\n");
                    check = 1;
                    break;
                }
            }
        } while (strlen(s[i].name) > 35 || strlen(s[i].name) == 0 || check == 1);
        do
        {
            check = 0;
            leap = 0;
            printf("Nhập năm sinh: ");
            scanf("%d", &s[i].birthdate.year);
            if (s[i].birthdate.year < 1990 || s[i].birthdate.day > 2025)
            {
                printf("Năm sinh không hợp lệ\n");
            }
            if (isalpha(s[i].birthdate.year))
            {
                printf("Năm sinh không được chứa chữ cái\n");
                check = 1;
            }
            if (s[i].birthdate.year % 4 == 0 && s[i].birthdate.year % 100 != 0 || s[i].birthdate.year % 400 == 0)
            {
                leap = 1;
            }
        } while (s[i].birthdate.year < 1990 || s[i].birthdate.year > 2025 || check == 1);
        do
        {
            check = 0;
            printf("Nhập tháng sinh: ");
            scanf("%d", &s[i].birthdate.month);
            if (s[i].birthdate.month < 1 || s[i].birthdate.month > 12)
            {
                printf("Tháng sinh không hợp lệ\n");
                check = 1;
            }
            if (isalpha(s[i].birthdate.month))
            {
                printf("Tháng sinh không được chứa chữ cái\n");
                check = 1;
            }
        } while (s[i].birthdate.month < 1 || s[i].birthdate.month > 12 || check == 1);
        do
        {
            check = 0;
            printf("Nhập ngày sinh: ");
            scanf("%d", &s[i].birthdate.day);
            if (isalpha(s[i].birthdate.day))
            {
                printf("Ngày sinh không được chứa chữ cái\n");
                check = 1;
            }
            if (leap == 0 && s[i].birthdate.month == 2 && s[i].birthdate.day > 28)
            {
                printf("Tháng 2 của năm %d không có ngày %d\n", s[i].birthdate.year, s[i].birthdate.day);
                check = 1;
            }
            if ((s[i].birthdate.month <= 7 && s[i].birthdate.month % 2 == 0) && s[i].birthdate.day > 30)
            {
                printf("Tháng %d không có ngày %d\n", s[i].birthdate.month, s[i].birthdate.day);
                check = 1;
            }
            if ((s[i].birthdate.month > 7 && s[i].birthdate.month % 2 != 0) && s[i].birthdate.day > 30)
            {
                printf("Tháng %d không có ngày %d\n", s[i].birthdate.month, s[i].birthdate.day);
                check = 1;
            }

        } while (s[i].birthdate.day < 1 || s[i].birthdate.day > 31 || check == 1);
        do
        {
            check = 0;
            printf("Nhập tuổi sinh viên: ");
            scanf("%d", &s[i].age);
            if (s[i].age < 0 && s[i].age > 34)
            {
                printf("Tuổi không hợp lệ\n");
                check = 1;
            }
            if (isalpha(s[i].age))
            {
                printf("Tuổi không được chứa chữ cái\n");
                check = 1;
            }
            if (s[i].age == "\0")
            {
                printf("Tuổi không được để trống\n");
                check = 1;
            }
        } while (s[i].age < 0 && s[i].age > 34 || check == 1);
        getchar();
        do
        {
            loop = 0;
            check = 0;
            printf("Nhập số điện thoại sinh viên: ");
            fgets(s[i].phone, 10, stdin);
            fflush(stdin);
            for (int j = 0; j < strlen(s[i].phone); j++)
            {
                if (s[i].phone[j] == ' ')
                {
                    printf("Số điện thoại không được chứa khoảng trắng\n");
                    check = 1;
                    break;
                }
                if (s[i].phone[j] < '0' || s[i].phone[j] > '9')
                {
                    printf("Số điện thoại không được chứa chữ cái\n");
                    check = 1;
                    break;
                }
            }
            if (strlen(s[i].phone) == 0)
            {
                printf("Số điện thoại không được để trống\n");
                check = 1;
            }
            if (strlen(s[i].phone) > 10)
            {
                printf("Số điện thoại không được quá 10 ký tự\n");
                check = 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (strcmp(s[i].phone, s[j].phone) == 0)
                {
                    printf("Số điện thoại đã tồn tại\n");
                    loop = 1;
                    break;
                }
            }
        } while (loop == 1 || check == 1);
        do
        {
            loop = 0;
            check = 0;
            printf("Nhập gmail sinh viên: ");
            gets(s[i].gmail);
            if (strlen(s[i].gmail) == 0)
            {
                printf("Gmail không được để trống\n");
                check = 1;
            }
            for (int j = 0; j < i; j++)
            {
                if (strcmp(s[i].gmail, s[j].gmail) == 0)
                {
                    printf("Gmail đã tồn tại\n");
                    loop = 1;
                    break;
                }
            }
            if (strchr(s[i].gmail, '@') == NULL || strchr(s[i].gmail, '.') == NULL)
            {
                printf("Gmail không hợp lệ\n");
                check = 1;
            }
        } while (loop == 1 || check == 1);
        printf("Thêm sinh viên thành công\n");
    }
    totalStudent += n;
    fwrite(&s, sizeof(Student), totalStudent, f);
    fclose(f);
}
void showList()
{
    FILE *f = fopen("Student.txt", "rb");
    fread(&s, sizeof(Student), totalStudent, f);
    printf("=========================================================================================================\n");
    printf("||%-12s|%-22s|%-15s|%-5s|%-10s|%-32s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail");
    for (int i = 0; i < totalStudent; i++)
    {
        printf("||%-13s|%-21s|%-3d/%-3d/%-6d|%-4d|%-13s|%-32s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail);
    }
    printf("=========================================================================================================\n");
    fclose(f);
}
void findStu()
{
    printf("Nhập tên sinh viên muốn tìm:");
    getchar();
    gets(find);
    for (int i = 0; i < totalStudent; i++)
    {
        if (strcmp(find, s[i].name) == 0)
        {
            printf("=========================================================================================================\n");
            printf("||%-12s|%-22s|%-15s|%-5s|%-10s|%-32s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail");
            printf("||%-13s|%-21s|%-3d/%-3d/%-6d|%-4d|%-13s|%-32s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail);
            printf("=========================================================================================================\n");
            break;
        }
        else if (strcmp(find, s[i].name) != 0)
        {
            printf("Không tìm thấy sinh viên\n");
        }
    }
}
void delStu()
{
    FILE *f = fopen("Student.txt", "wb");
    check = 0;
    printf("Nhập ID sinh viên muốn xóa: ");
    scanf("%s", &del);
    for (int i = 0; i < totalStudent; i++)
    {
        if (del == s[i].id)
        {
            check = 1;
            int option;
            printf("Bạn có chắc chắn muốn xóa sinh viên này không?\n");
            printf("1. Có%5s2.Không\n");
            scanf("%d", &option);
            switch (option)
            {
            case 1:
                for (int j = i; j < totalStudent - 1; j++)
                {
                    s[j] = s[j + 1];
                }
                totalStudent--;
                printf("Xóa sinh viên thành công\n");
                break;
            case 2:
                break;
            default:
                printf("Lựa chọn không hợp lệ\n");
            }
            break;
        }
        else if (check == 0)
        {
            printf("Không tìm thấy sinh viên\n");
        }
    }
    fwrite(&s, sizeof(Student), totalStudent, f);
    fclose(f);
}
void editStu()
{
    FILE *f = fopen("Student.txt", "wb");
    check = 0;
    printf("Nhập ID sinh viên muốn sửa: ");
    scanf("%s", &del);
    for (int i = 0; i < totalStudent; i++)
    {
        if (strcmp(s[i].id, del) == 0)
        {
            check = 1;
            printf("Nhập thông tin mới cho sinh viên\n");
            printf("Nhập tên: ");
            fgets(s[i].name, 35, stdin);
            s[i].name[strlen(s[i].name) - 1] = '\0';
            printf("Nhập tuổi: ");
            scanf("%d", &s[i].age);
            printf("Nhập số điện thoại: ");
            gets(s[i].phone);
            printf("Nhập gmail: ");
            gets(s[i].gmail);
            printf("Sửa sinh viên thành công\n");
            break;
        }
        else if (check == 0)
        {
            printf("Không tìm thấy sinh viên\n");
        }
    }
    fwrite(&s, sizeof(Student), totalStudent, f);
    fclose(f);
}
void sortStu()
{
    FILE *f = fopen("Student.txt", "rb");
    fread(&s, sizeof(Student), totalStudent, f);
    for (int i = 0; i < totalStudent - 1; i++)
    {
        for (int j = i + 1; j < totalStudent; j++)
        {
            if (strcmp(s[i].name, s[j].name) > 0)
            {
                Student temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("=========================================================================================================\n");
    printf("||%-12s|%-22s|%-15s|%-5s|%-10s|%-32s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail");
    for (int i = 0; i < totalStudent; i++)
    {
        printf("||%-13s|%-21s|%-3d/%-3d/%-6d|%-4d|%-13s|%-32s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail);
    }
    printf("=========================================================================================================\n");
    fclose(f);
}