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
    printf("||2. Hiển thị danh sách giáo viên%12.5c||\n");
    printf("||3. Xóa giáo viên%27.5c||\n");
    printf("||4. Sửa giáo viên%27.5c||\n");
    printf("||5. Tìm kiếm giáo viên%22.5c||\n");
    printf("||6. Thêm lớp cho giáo viên%18.5c||\n");
    printf("||7. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void menu3()
{
    printf("===============CLASS MANAGEMENT===============\n");
    printf("||1. Thêm lớp học%28.5c||\n");
    printf("||2. Hiển thị danh sách lớp học%14.5c||\n");
    printf("||3. Xóa lớp học%29.5c||\n");
    printf("||4. Sửa lớp học%29.5c||\n");
    printf("||5. Xem lớp học%29c||\n");
    printf("||6. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void addStu()
{
    FILE *f = fopen("D:/project/project/data/Student.txt", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
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
                printf("Nhập ID sinh viên (Bắt đầu bằng PIT): ");
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
                if (s[i].id[0] != 'P' || s[i].id[1] != 'I' || s[i].id[2] != 'T')
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
                fgets(s[i].name, 20, stdin);
                s[i].name[strlen(s[i].name) - 1] = '\0';
                fflush(stdin);
                if (strlen(s[i].name) == 0)
                {
                    printf("Tên không được để trống\n");
                }
                if (strlen(s[i].name) > 20)
                {
                    printf("Tên không được quá 20 ký tự\n");
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
            } while (strlen(s[i].name) > 20 || strlen(s[i].name) == 0 || check == 1);
            do
            {
                check = 0;
                leap = 0;
                printf("Nhập năm sinh: ");
                scanf("%d", &s[i].birthdate.year);
                if (s[i].birthdate.year < 2000 || s[i].birthdate.day > 2006)
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
            } while (s[i].birthdate.year < 2000 || s[i].birthdate.year > 2006 || check == 1);
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
                scanf("%s", &s[i].phone);
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
                scanf("%s", &s[i].gmail);
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
                    else if (s[i].gmail[j] == ' ')
                    {
                        printf("Gmail không được chứa khoảng trắng\n");
                        check = 1;
                        break;
                    }
                }
                if (strchr(s[i].gmail, '@') == NULL || strchr(s[i].gmail, '.') == NULL)
                {
                    check = 1;
                    printf("Gmail không hợp lệ\n");
                }
            } while (loop == 1 || check == 1);

            printf("Thêm sinh viên thành công\n");
        }
        totalStudent += n;
        fwrite(&totalStudent, sizeof(int), 1, f);
        fwrite(s, sizeof(Student), totalStudent, f);
        fclose(f);
    }
}
void showList()
{
    FILE *f = fopen("D:/project/project/data/Student.txt", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
    }
    if (totalStudent == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    printf("%43cDANH SACH SINH VIEN\n");
    printf("=================================================================================================================\n");
    printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
    for (int i = 0; i < totalStudent; i++)
    {
        printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail, s[i].classId);
    }
    printf("=================================================================================================================\n");
    fclose(f);
}
void searchStu()
{
    FILE *f = fopen("D:/project/project/data/Student.txt", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở file");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
    }
    if (totalStudent == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    printf("Nhập tên sinh viên muốn tìm:");
    getchar();
    fgets(find, 20, stdin);
    find[strlen(find) - 1] = '\0';
    for (int i = 0; i < totalStudent; i++)
    {
        if (strcmp(find, s[i].name) == 0)
        {
            printf("%43cDANH SACH SINH VIEN\n");
            printf("===================================================================================================================\n");
            printf("||%-10s|%-21s|%-14s|%-5s|%-10s|%-30s|%-10s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
            printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail, s[i].classId);
            printf("===================================================================================================================\n");
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
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalStudent == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
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
        }
        if (check == 0)
        {
            printf("Không tìm thấy sinh viên\n");
        }
        fwrite(&totalStudent, sizeof(int), 1, f);
        fwrite(&s, sizeof(Student), totalStudent, f);
        fclose(f);
    }
}
void editStu()
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở file\n");
    }
    if (totalStudent == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
        check = 0;
        printf("Nhập ID sinh viên muốn sửa: ");
        scanf("%s", &del);
        for (int i = 0; i < totalStudent; i++)
        {
            if (strcmp(s[i].id, del) == 0)
            {
                check = 1;
                printf("Nhập thông tin mới cho sinh viên\n");
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
                    scanf("%s", &s[i].phone);
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
                    scanf("%s", &s[i].gmail);
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
                        else if (s[i].gmail[j] == ' ')
                        {
                            printf("Gmail không được chứa khoảng trắng\n");
                            check = 1;
                            break;
                        }
                    }
                    if (strchr(s[i].gmail, '@') == NULL || strchr(s[i].gmail, '.') == NULL)
                    {
                        check = 1;
                        printf("Gmail không hợp lệ\n");
                    }
                } while (loop == 1 || check == 1);
                printf("Sửa sinh viên thành công\n");
                break;
            }
        }
        if (check == 0)
        {
            printf("Không tìm thấy sinh viên\n");
        }
        fwrite(&s, sizeof(Student), totalStudent, f);
        fclose(f);
    }
}
void sortStu()
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalStudent == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {

        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
    }
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
void addTea()
{
    FILE *f = fopen("D:/project/project/data/Teacher.txt", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        printf("Nhập số lượng giáo viên cần thêm:");
        scanf("%d", &n);
        if (totalTeacher + n > 100)
        {
            printf("Danh sách giáo viên đã đầy\n");
        }
        for (int i = totalTeacher; i < totalTeacher + n; i++)
        {
            printf("Nhập thông tin giáo viên thứ %d\n", i + 1);
            do
            {
                loop = 0;
                check = 0;
                printf("Nhập ID giáo viên (Bắt đầu bằng TEA): ");
                scanf("%s", &t[i].id);
                if (t[i].id == "\0")
                {
                    printf("ID không được để trống\n");
                    loop = 1;
                }
                if (strlen(t[i].id) > 10)
                {
                    printf("ID không được quá 10 ký tự\n");
                    loop = 1;
                }
                if (t[i].id[0] != 'T' || t[i].id[1] != 'E' || t[i].id[2] != 'A')
                {
                    printf("ID không hợp lệ\n");
                    check = 1;
                }
                for (int j = 0; j < i; j++)
                {
                    if (t[i].id == t[j].id)
                    {
                        printf("ID đã tồn tại\n");
                        loop = 1;
                        break;
                    }
                }
            } while (strlen(t[i].id) > 10 || loop == 1 || check == 1);
            getchar();
            do
            {
                check = 0;
                printf("Nhập tên giáo viên: ");
                fgets(t[i].name, 20, stdin);
                t[i].name[strlen(t[i].name) - 1] = '\0';
                fflush(stdin);
                if (strlen(t[i].name) == 0)
                {
                    printf("Tên không được để trống\n");
                }
                if (strlen(t[i].name) > 20)
                {
                    printf("Tên không được quá 20 ký tự\n");
                }
                for (int j = 0; j < strlen(s[i].name); j++)
                {
                    if (t[i].name[j] >= '0' && t[i].name[j] <= '9')
                    {
                        printf("Tên không được chứa số\n");
                        check = 1;
                        break;
                    }
                }
            } while (strlen(t[i].name) > 20 || strlen(t[i].name) == 0 || check == 1);
            do
            {
                check = 0;
                leap = 0;
                printf("Nhập năm sinh: ");
                scanf("%d", &t[i].birthdate.year);
                if (t[i].birthdate.year < 1970 || t[i].birthdate.day > 2000)
                {
                    printf("Năm sinh không hợp lệ\n");
                }
                if (isalpha(t[i].birthdate.year))
                {
                    printf("Năm sinh không được chứa chữ cái\n");
                    check = 1;
                }
                if (t[i].birthdate.year % 4 == 0 && t[i].birthdate.year % 100 != 0 || t[i].birthdate.year % 400 == 0)
                {
                    leap = 1;
                }
            } while (t[i].birthdate.year < 1970 || t[i].birthdate.year > 2000 || check == 1);
            do
            {
                check = 0;
                printf("Nhập tháng sinh: ");
                scanf("%d", &t[i].birthdate.month);
                if (t[i].birthdate.month < 1 || t[i].birthdate.month > 12)
                {
                    printf("Tháng sinh không hợp lệ\n");
                    check = 1;
                }
                if (isalpha(t[i].birthdate.month))
                {
                    printf("Tháng sinh không được chứa chữ cái\n");
                    check = 1;
                }
            } while (t[i].birthdate.month < 1 || t[i].birthdate.month > 12 || check == 1);
            do
            {
                check = 0;
                printf("Nhập ngày sinh: ");
                scanf("%d", &t[i].birthdate.day);
                if (isalpha(t[i].birthdate.day))
                {
                    printf("Ngày sinh không được chứa chữ cái\n");
                    check = 1;
                }
                if (leap == 0 && t[i].birthdate.month == 2 && t[i].birthdate.day > 28)
                {
                    printf("Tháng 2 của năm %d không có ngày %d\n", t[i].birthdate.year, t[i].birthdate.day);
                    check = 1;
                }
                if ((t[i].birthdate.month <= 7 && t[i].birthdate.month % 2 == 0) && t[i].birthdate.day > 30)
                {
                    printf("Tháng %d không có ngày %d\n", t[i].birthdate.month, t[i].birthdate.day);
                    check = 1;
                }
                if ((t[i].birthdate.month > 7 && t[i].birthdate.month % 2 != 0) && t[i].birthdate.day > 30)
                {
                    printf("Tháng %d không có ngày %d\n", t[i].birthdate.month, t[i].birthdate.day);
                    check = 1;
                }

            } while (t[i].birthdate.day < 1 || t[i].birthdate.day > 31 || check == 1);
            do
            {
                check = 0;
                printf("Nhập tuổi giáo viên: ");
                scanf("%d", &t[i].age);
                if (t[i].age < 19 && t[i].age > 48)
                {
                    printf("Tuổi không hợp lệ\n");
                    check = 1;
                }
                if (isalpha(t[i].age))
                {
                    printf("Tuổi không được chứa chữ cái\n");
                    check = 1;
                }
                if (t[i].age == "\0")
                {
                    printf("Tuổi không được để trống\n");
                    check = 1;
                }
            } while (t[i].age < 19 && t[i].age > 48 || check == 1);
            getchar();
            do
            {
                loop = 0;
                check = 0;
                printf("Nhập số điện thoại giáo viên: ");
                scanf("%s", &t[i].phone);
                for (int j = 0; j < strlen(t[i].phone); j++)
                {
                    if (t[i].phone[j] == ' ')
                    {
                        printf("Số điện thoại không được chứa khoảng trắng\n");
                        check = 1;
                        break;
                    }
                    if (t[i].phone[j] < '0' || t[i].phone[j] > '9')
                    {
                        printf("Số điện thoại không được chứa chữ cái\n");
                        check = 1;
                        break;
                    }
                }
                if (strlen(t[i].phone) == 0)
                {
                    printf("Số điện thoại không được để trống\n");
                    check = 1;
                }
                if (strlen(t[i].phone) > 10)
                {
                    printf("Số điện thoại không được quá 10 ký tự\n");
                    check = 1;
                }
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(t[i].phone, t[j].phone) == 0)
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
                scanf("%s", t[i].gmail);
                if (strlen(t[i].gmail) == 0)
                {
                    printf("Gmail không được để trống\n");
                    check = 1;
                }
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(t[i].gmail, t[j].gmail) == 0)
                    {
                        printf("Gmail đã tồn tại\n");
                        loop = 1;
                        break;
                    }
                }
                if (strchr(t[i].gmail, '@') == NULL || strchr(t[i].gmail, '.') == NULL)
                {
                    check = 1;
                    printf("Gmail không hợp lệ\n");
                }
            } while (loop == 1 || check == 1);
            printf("Thêm giáo viên thành công\n");
        }
        totalTeacher += n;
        fwrite(&totalTeacher, sizeof(int), 1, f);
        fwrite(&t, sizeof(Teacher), totalTeacher, f);
        fclose(f);
    }
}
void listTea()
{
    FILE *f = fopen("D:/project/project/data/Teacher.txt", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalTeacher == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(&t, sizeof(Teacher), totalTeacher, f);
    }
    printf("=================================================================================================================\n");
    printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
    for (int i = 0; i < totalTeacher; i++)
    {
        printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", t[i].id, t[i].name, t[i].birthdate.day, t[i].birthdate.month, t[i].birthdate.year, t[i].age, t[i].phone, t[i].gmail, t[i].classroom[i].id);
    }
    printf("=================================================================================================================\n");
    fclose(f);
}
void delTea()
{
    FILE *f = fopen("D:/project/project/data/Teacher.txt", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalTeacher == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
        check = 0;
        printf("Nhập ID sinh viên muốn xóa: ");
        scanf("%s", &del);
        for (int i = 0; i < totalTeacher; i++)
        {
            if (strcmp(t[i].id, del) == 0)
            {
                check = 1;
                int option;
                printf("Bạn có muốn xóa giáo viên này không?\n");
                printf("1. Có%5s2. Không\n");
                printf("Lựa chọn của bạn: ");
                scanf("%d", &option);
                switch (option)
                {
                case 1:
                    for (int j = i; j < totalTeacher - 1; j++)
                    {
                        t[j] = t[j + 1];
                    }
                    totalTeacher--;
                    printf("Xóa giáo viên thành công\n");
                    break;
                case 2:
                    break;
                default:
                    printf("Lựa chọn không hợp lệ\n");
                    break;
                }
            }
        }
        if (check == 0)
        {
            printf("Không tìm thấy giáo viên\n");
        }
        fwrite(&totalTeacher, sizeof(int), 1, f);
        fwrite(&t, sizeof(Teacher), totalTeacher, f);
    }
}
void editTea()
{
    FILE *f = fopen("D:/project/project/data/Teacher.txt", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalTeacher == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
        check = 0;
        printf("Nhập ID giáo viên muốn sửa: ");
        scanf("%s", &del);
        for (int i = 0; i < totalTeacher; i++)
        {
            if (strcmp(t[i].id, del) == 0)
            {
                printf("Nhập thông tin mới cho giáo viên\n");
                do
                {
                    check = 1;
                    printf("Nhập tên giáo viên: ");
                    fgets(t[i].name, 20, stdin);
                    t[i].name[strlen(t[i].name) - 1] = '\0';
                    fflush(stdin);
                    if (strlen(t[i].name) == 0)
                    {
                        printf("Tên không được để trống\n");
                    }
                    if (strlen(t[i].name) > 20)
                    {
                        printf("Tên không được quá 20 ký tự\n");
                    }
                    for (int j = 0; j < strlen(s[i].name); j++)
                    {
                        if (t[i].name[j] >= '0' && t[i].name[j] <= '9')
                        {
                            printf("Tên không được chứa số\n");
                            check = 1;
                            break;
                        }
                    }
                } while (strlen(t[i].name) > 20 || strlen(t[i].name) == 0 || check == 1);
                do
                {
                    check = 0;
                    leap = 0;
                    printf("Nhập năm sinh: ");
                    scanf("%d", &t[i].birthdate.year);
                    if (t[i].birthdate.year < 1970 || t[i].birthdate.day > 2000)
                    {
                        printf("Năm sinh không hợp lệ\n");
                    }
                    if (isalpha(t[i].birthdate.year))
                    {
                        printf("Năm sinh không được chứa chữ cái\n");
                        check = 1;
                    }
                    if (t[i].birthdate.year % 4 == 0 && t[i].birthdate.year % 100 != 0 || t[i].birthdate.year % 400 == 0)
                    {
                        leap = 1;
                    }
                } while (t[i].birthdate.year < 1970 || t[i].birthdate.year > 2000 || check == 1);
                do
                {
                    check = 0;
                    printf("Nhập tháng sinh: ");
                    scanf("%d", &t[i].birthdate.month);
                    if (t[i].birthdate.month < 1 || t[i].birthdate.month > 12)
                    {
                        printf("Tháng sinh không hợp lệ\n");
                        check = 1;
                    }
                    if (isalpha(t[i].birthdate.month))
                    {
                        printf("Tháng sinh không được chứa chữ cái\n");
                        check = 1;
                    }
                } while (t[i].birthdate.month < 1 || t[i].birthdate.month > 12 || check == 1);
                do
                {
                    check = 0;
                    printf("Nhập ngày sinh: ");
                    scanf("%d", &t[i].birthdate.day);
                    if (isalpha(t[i].birthdate.day))
                    {
                        printf("Ngày sinh không được chứa chữ cái\n");
                        check = 1;
                    }
                    if (leap == 0 && t[i].birthdate.month == 2 && t[i].birthdate.day > 28)
                    {
                        printf("Tháng 2 của năm %d không có ngày %d\n", t[i].birthdate.year, t[i].birthdate.day);
                        check = 1;
                    }
                    if ((t[i].birthdate.month <= 7 && t[i].birthdate.month % 2 == 0) && t[i].birthdate.day > 30)
                    {
                        printf("Tháng %d không có ngày %d\n", t[i].birthdate.month, t[i].birthdate.day);
                        check = 1;
                    }
                    if ((t[i].birthdate.month > 7 && t[i].birthdate.month % 2 != 0) && t[i].birthdate.day > 30)
                    {
                        printf("Tháng %d không có ngày %d\n", t[i].birthdate.month, t[i].birthdate.day);
                        check = 1;
                    }

                } while (t[i].birthdate.day < 1 || t[i].birthdate.day > 31 || check == 1);
                do
                {
                    check = 0;
                    printf("Nhập tuổi giáo viên: ");
                    scanf("%d", &t[i].age);
                    if (t[i].age < 19 && t[i].age > 48)
                    {
                        printf("Tuổi không hợp lệ\n");
                        check = 1;
                    }
                    if (isalpha(t[i].age))
                    {
                        printf("Tuổi không được chứa chữ cái\n");
                        check = 1;
                    }
                    if (t[i].age == "\0")
                    {
                        printf("Tuổi không được để trống\n");
                        check = 1;
                    }
                } while (t[i].age < 19 && t[i].age > 48 || check == 1);
                getchar();
                do
                {
                    loop = 0;
                    check = 0;
                    printf("Nhập số điện thoại giáo viên: ");
                    scanf("%s", &t[i].phone);
                    for (int j = 0; j < strlen(t[i].phone); j++)
                    {
                        if (t[i].phone[j] == ' ')
                        {
                            printf("Số điện thoại không được chứa khoảng trắng\n");
                            check = 1;
                            break;
                        }
                        if (t[i].phone[j] < '0' || t[i].phone[j] > '9')
                        {
                            printf("Số điện thoại không được chứa chữ cái\n");
                            check = 1;
                            break;
                        }
                    }
                    if (strlen(t[i].phone) == 0)
                    {
                        printf("Số điện thoại không được để trống\n");
                        check = 1;
                    }
                    if (strlen(t[i].phone) > 10)
                    {
                        printf("Số điện thoại không được quá 10 ký tự\n");
                        check = 1;
                    }
                    for (int j = 0; j < i; j++)
                    {
                        if (strcmp(t[i].phone, t[j].phone) == 0)
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
                    printf("Nhập gmail giáo viên: ");
                    fgets(t[i].gmail, 50, stdin);
                    if (strlen(t[i].gmail) == 0)
                    {
                        printf("Gmail không được để trống\n");
                        check = 1;
                    }
                    for (int j = 0; j < i; j++)
                    {
                        if (strcmp(t[i].gmail, t[j].gmail) == 0)
                        {
                            printf("Gmail đã tồn tại\n");
                            loop = 1;
                            break;
                        }
                    }
                    if (strchr(t[i].gmail, '@') == NULL || strchr(t[i].gmail, '.') == NULL)
                    {
                        check = 1;
                        printf("Gmail không hợp lệ\n");
                    }
                } while (loop == 1 || check == 1);
            }
        }
        printf("Chỉnh sửa thông tin giáo viên thành công");
        if (check == 0)
        {
            printf("Không tìm thấy giáo viên\n");
        }
        fwrite(&t, sizeof(Teacher), totalTeacher, f);
    }
}
void searchTea()
{
    FILE *f = fopen("D:/project/project/data/Teacher.txt", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    if (totalTeacher == 0 && f == NULL)
    {
        printf("Danh sách rỗng\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(&t, sizeof(Teacher), totalTeacher, f);
    }
    check = 0;
    printf("Nhập tên giáo viên muốn tìm: ");
    fgets(find, 20, stdin);
    find[strlen(find) - 1] = '\0';
    for (int i = 0; i < totalTeacher; i++)
    {
        if (strcmp(t[i].name, find) == 0)
        {
            check = 1;
            printf("%43cDANH SACH GIAO VIEN\n");
            printf("=================================================================================================================\n");
            printf("||%-10s|%-21s|%-14s|%-5s|%-10s|%-30s|%-10s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
            printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", t[i].id, t[i].name, t[i].birthdate.day, t[i].birthdate.month, t[i].birthdate.year, t[i].age, t[i].phone, t[i].gmail, t[i].classroom[i].id);
            printf("=================================================================================================================\n");
        }
    }
    if (check == 0)
    {
        printf("Không tìm thấy giáo viên\n");
    }
}
void addCla()
{
    FILE *f = fopen("D:/project/project/data/Classroom.txt", "wb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        printf("Nhập số lượng lớp cần thêm:");
        scanf("%d", &n);
        for (int i = totalClass; i < totalClass + n; i++)
        {
            do
            {
                check = 0, loop = 0;
                printf("Nhập ID lớp (Bắt đầu INT): ");
                fgets(c[i].id, 10, stdin);
                if (strlen(c[i].id) > 10)
                {
                    printf("ID lớp không được quá 10 ký tự\n");
                    check = 1;
                }
                if (strcmp(c[i].id, "\0") == 0)
                {
                    printf("ID không được để trống\n");
                    check = 1;
                }
                if (s[i].id[0] != 'I' || s[i].id[1] != 'N' || s[i].id[2] != 'T')
                {
                    printf("ID không hợp lệ");
                    check = 1;
                }
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(c[i].id, c[j].id) == 0)
                    {
                        printf("ID đã tồn tại");
                        loop = 1;
                        break;
                    }
                }
            } while (strlen(c[i].id) > 10 || check == 1 || loop == 1);
            do
            {
                check = 0, loop = 0;
                printf("Nhập tên lớp: ");
                fgets(c[i].name, 20, stdin);
                c[i].name[strlen(c[i].name) - 1] = '\0';
                fflush(stdin);
                if (strlen(c[i].name) > 20)
                {
                    check = 1;
                    printf("Tên lớp không được quá 20 ký tự\n");
                }
                for (int j = 0; j < i; j++)
                {
                    if (strcmp(c[i].name, c[j].name) == 0)
                    {
                        printf("Tên lớp trùng lặp\n");
                        check = 1;
                    }
                }
            } while (strlen(c[i].name) > 20 || check == 1 || loop == 1);
        }
    }
}