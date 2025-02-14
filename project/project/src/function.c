#include "../include/datatype.h"
void mainmenu() // Menu chính
{
    printf("===============PTIT MANAGEMENT===============\n");
    printf("||1. Quản lý sinh viên%22.5c||\n");
    printf("||2. Quản lý giáo viên%22.5c||\n");
    printf("||3. Quản lý lớp học%24.5c||\n");
    printf("||4. Thoát%34.5c||\n");
    printf("=============================================\n");
}
void menu1() // Menu quản lý sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "rb");
    fread(&totalStudent, sizeof(int), 1, f);
    fread(s, sizeof(Student), totalStudent, f);
    fclose(f);
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
void menu2() // Menu quản lý giáo viên
{
    FILE *f1 = fopen("D:/project/project/data/Teacher.bin", "rb");
    FILE *f2 = fopen("D:/project/project/data/Classroom.bin", "rb");
    fread(&totalTeacher, sizeof(int), 1, f1);
    fread(t, sizeof(Teacher), totalTeacher, f1);
    fread(&totalClass, sizeof(int), 1, f2);
    fread(c, sizeof(Classroom), totalClass, f2);
    fclose(f1);
    fclose(f2);
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
void menu3() // Menu quản lý lớp học
{
    FILE *f1 = fopen("D:/project/project/data/Classroom.bin", "rb");
    FILE *f2 = fopen("D:/project/project/data/Student.bin", "rb");
    fread(&totalClass, sizeof(int), 1, f1);
    fread(c, sizeof(Classroom), totalClass, f1);
    fread(&totalStudent, sizeof(int), 1, f2);
    fread(s, sizeof(Student), totalStudent, f2);
    fclose(f1);
    fclose(f2);
    printf("===============CLASS MANAGEMENT===============\n");
    printf("||1. Thêm lớp học%28.5c||\n");
    printf("||2. Hiển thị danh sách lớp học%14.5c||\n");
    printf("||3. Xóa lớp học%29.5c||\n");
    printf("||4. Sửa lớp học%29.5c||\n");
    printf("||5. Xem lớp học%29c||\n");
    printf("||6. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void menuSort() // Menu con dành cho sắp xếp sinh viên
{
    printf("==============STUDENT MANAGEMENT==============\n");
    printf("||1. Thêm sinh viên%26.5c||\n");
    printf("||2. Hiển thị danh sách sinh viên%12.5c||\n");
    printf("||3. Tìm kiếm sinh viên%22.5c||\n");
    printf("||4. Xóa sinh viên%27.5c||\n");
    printf("||5. Sửa sinh viên%27.5c||\n");
    printf("||6. Sắp xếp sinh viên theo tên%14.5c||\n");
    printf("||%2ca. Sắp xếp từ thấp đến cao%15.5c||\n");
    printf("||%2cb. Sắp xếp từ cao đến thấp%15.5c||\n");
    printf("||%2cc. Quay lại%30.5c||\n");
    printf("||7. Quay lại%32.5c||\n");
    printf("==============================================\n");
}
void addStudent() // Thêm sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb+");
    fread(&totalStudent, sizeof(int), 1, f);
    fread(s, sizeof(Student), totalStudent, f);
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
            scanf("%10s", s[i].id);
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
                if (strcmp(s[i].id, s[j].id) == 0)
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
            if ((s[i].age < 0 && s[i].age > 34) || 2025 - s[i].birthdate.year != s[i].age)
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
            scanf("%10s", s[i].phone);
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
            if (strlen(s[i].phone) != 10)
            {
                printf("Độ dài số điện thoại không hợp lệ\n");
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
            scanf("%30s", s[i].gmail);
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
void showList() // Xem danh sách sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            printf("%43cDANH SACH SINH VIEN\n");
            printf("===============================================================================================================\n");
            printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
            for (int i = 0; i < totalStudent; i++)
            {
                printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail, s[i].classId);
            }
            printf("===============================================================================================================\n");
            fclose(f);
        }
    }
}
void searchStudent() // Tìm kiếm sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở file");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            n = 0;
            printf("Nhập tên sinh viên muốn tìm:");
            getchar();
            fgets(find, 20, stdin);
            find[strlen(find) - 1] = '\0';
            for (int i = 0; i < totalStudent; i++)
            {
                if (strstr(s[i].name, find))
                {
                    n = 1;
                    printf("===============================================================================================================\n");
                    printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
                    printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail, s[i].classId);
                    printf("===============================================================================================================\n");
                }
            }
            if (n == 0)
            {
                printf("Không tìm thấy bất kỳ sinh viên nào\n");
            }
        }
    }
}
void delStudent() // Xóa sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            check = 0;
            printf("Nhập ID sinh viên muốn xóa: ");
            scanf("%s", &del);
            getchar();
            for (int i = 0; i < totalStudent; i++)
            {
                if (strcmp(del, s[i].id) == 0)
                {
                    check = 1;
                    printf("Bạn có chắc chắn muốn xóa sinh viên này không?\n");
                    printf("1. Có%5c2.Không\n");
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
                        break;
                    }
                }
            }
            if (check == 0)
            {
                printf("Không tìm thấy sinh viên\n");
            }
            fwrite(&totalStudent, sizeof(int), 1, f);
            fwrite(s, sizeof(Student), totalStudent, f);
            fclose(f);
        }
    }
}
void editStudent() // Sửa thông tin cho sinh viên
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở file\n");
    }
    else
    {
        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            n = 0;
            printf("Nhập ID sinh viên muốn sửa: ");
            scanf("%s", &del);
            for (int i = 0; i < totalStudent; i++)
            {
                if (strcmp(s[i].id, del) == 0)
                {
                    n = 1;
                    printf("Nhập thông tin mới cho sinh viên\n");
                    do
                    {
                        check = 0;
                        getchar();
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
                        scanf("%10s", s[i].phone);
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
                        scanf("%30s", s[i].gmail);
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
                    fwrite(&totalStudent, sizeof(int), 1, f);
                    fwrite(s, sizeof(Student), totalStudent, f);
                    fclose(f);
                    printf("Sửa sinh viên thành công\n");
                    break;
                }
            }
            if (n == 0)
            {
                printf("Khong tim thay sinh vien\n");
            }
        }
    }
}
void sortStudent1() // Sắp xếp sinh viên từ thấp đến cao
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {

        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
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
                printf("||%-12s|%-21s|%-3d/%-3d/%-6d|%-4d|%-13s|%-32s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail);
            }
            printf("=========================================================================================================\n");
            fwrite(&totalStudent, sizeof(int), 1, f);
            fwrite(s, sizeof(Student), totalStudent, f);
        }
        fclose(f);
    }
}
void sortStudent2() // Sắp xếp sinh viên từ cao đến thấp
{
    FILE *f = fopen("D:/project/project/data/Student.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {

        fread(&totalStudent, sizeof(int), 1, f);
        fread(s, sizeof(Student), totalStudent, f);
        if (totalStudent == 0 && f == NULL)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            for (int i = 0; i < totalStudent - 1; i++)
            {
                for (int j = i + 1; j < totalStudent; j++)
                {
                    if (strcmp(s[i].name, s[j].name) < 0)
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
                printf("||%-12s|%-21s|%-3d/%-3d/%-6d|%-4d|%-13s|%-32s||\n", s[i].id, s[i].name, s[i].birthdate.day, s[i].birthdate.month, s[i].birthdate.year, s[i].age, s[i].phone, s[i].gmail);
            }
            printf("=========================================================================================================\n");
            fwrite(&totalStudent, sizeof(int), 1, f);
            fwrite(s, sizeof(Student), totalStudent, f);
        }
        fclose(f);
    }
}
void addTeacher() // Thêm giáo viên
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "wb+");
    fread(&totalTeacher, sizeof(int), 1, f);
    fread(t, sizeof(Teacher), totalTeacher, f);
    printf("Nhập số lượng giáo viên cần thêm:");
    scanf("%d", &n);
    if (totalTeacher + n > 100)
    {
        printf("Danh sách giáo viên đã đầy\n");
    }
    else
    {
        for (int i = totalTeacher; i < totalTeacher + n; i++)
        {
            printf("Nhập thông tin giáo viên thứ %d\n", i + 1);
            do
            {
                loop = 0;
                check = 0;
                printf("Nhập ID giáo viên (Bắt đầu bằng TEA): ");
                scanf("%10s", t[i].id);
                if (strlen(t[i].id) == 0)
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
                    if (strcmp(t[i].id, t[j].id) == 0)
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
                if ((t[i].age < 19 && t[i].age > 48) || 2025 - t[i].birthdate.year != t[i].age)
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
                scanf("%10s", t[i].phone);
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
                if (strlen(t[i].phone) != 10)
                {
                    printf("Độ dài số điện thoại không hợp lệ\n");
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
                scanf("%30s", t[i].gmail);
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
        fwrite(t, sizeof(Teacher), totalTeacher, f);
        fclose(f);
    }
}
void listTeacher() // Xem danh sách giáo viên
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "rb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(t, sizeof(Teacher), totalTeacher, f);
        if (totalTeacher == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            printf("===============================================================================================================\n");
            printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
            for (int i = 0; i < totalTeacher; i++)
            {
                printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10d||\n", t[i].id, t[i].name, t[i].birthdate.day, t[i].birthdate.month, t[i].birthdate.year, t[i].age, t[i].phone, t[i].gmail, t[i].totalClass);
            }
            printf("===============================================================================================================\n");
        }
        fclose(f);
    }
}
void delTeacher() // Xóa giáo viên
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(t, sizeof(Teacher), totalTeacher, f);
        if (totalTeacher == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            check = 0;
            printf("Nhập ID giáo viên muốn xóa: ");
            scanf("%s", &del);
            for (int i = 0; i < totalTeacher; i++)
            {
                if (strcmp(t[i].id, del) == 0)
                {
                    check = 1;
                    printf("Bạn có muốn xóa giáo viên này không?\n");
                    printf("1. Có%5c2. Không\n");
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
            fwrite(t, sizeof(Teacher), totalTeacher, f);
        }
        fclose(f);
    }
}
void editTeacher() // Sửa thông tin giáo viên
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(t, sizeof(Teacher), totalTeacher, f);
        if (totalTeacher == 0 && f == NULL)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            n = 0;
            printf("Nhập ID giáo viên muốn sửa: ");
            scanf("%s", &del);
            for (int i = 0; i < totalTeacher; i++)
            {
                if (strcmp(t[i].id, del) == 0)
                {
                    n = 1;
                    printf("Nhập thông tin mới cho giáo viên\n");
                    do
                    {
                        getchar();
                        check = 0;
                        printf("Nhập tên giáo viên: ");
                        fgets(t[i].name, 20, stdin);
                        t[i].name[strlen(t[i].name) - 1] = '\0';
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
                        scanf("%10s", t[i].phone);
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
                        scanf("%30s", t[i].gmail);
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
                    printf("Chỉnh sửa thông tin giáo viên thành công\n");
                }
            }
            if (n == 0)
            {
                printf("Không tìm thấy giáo viên\n");
            }
            fwrite(&totalTeacher, sizeof(int), 1, f);
            fwrite(t, sizeof(Teacher), totalTeacher, f);
        }
    }
}
void searchTeacher()
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(t, sizeof(Teacher), totalTeacher, f);
        if (totalTeacher == 0 && f == NULL)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            check = 0;
            printf("Nhập tên giáo viên muốn tìm: ");
            getchar();
            fgets(find, 20, stdin);
            find[strlen(find) - 1] = '\0';
            for (int i = 0; i < totalTeacher; i++)
            {
                if (strcmp(t[i].name, find) == 0)
                {
                    check = 1;
                    printf("%43cDANH SACH GIAO VIEN\n");
                    printf("===============================================================================================================\n");
                    printf("||%-10s|%-21s|%-15s|%-5s|%-10s|%-30s|%-12s||\n", "ID", "Tên", "Ngày sinh", "Tuổi", "Số điện thoại", "Gmail", "Lớp");
                    printf("||%-10s|%-20s|%-3d/%-3d/%-6d|%-4d|%-13s|%-30s|%-10s||\n", t[i].id, t[i].name, t[i].birthdate.day, t[i].birthdate.month, t[i].birthdate.year, t[i].age, t[i].phone, t[i].gmail, t[i].classroom[i].id);
                    printf("===============================================================================================================\n");
                }
            }
            if (check == 0)
            {
                printf("Không tìm thấy giáo viên\n");
            }
        }
    }
}
void addClassTeacher()
{
    FILE *f = fopen("D:/project/project/data/Teacher.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalTeacher, sizeof(int), 1, f);
        fread(t, sizeof(Teacher), totalTeacher, f);
        if (totalTeacher == 0 && f == NULL)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            n = 0;
            printf("Nhập ID giáo viên muốn thêm lớp: ");
            scanf("%s", &add);
            for (int i = 0; i < totalTeacher; i++)
            {
                if (strcmp(add, t[i].id) == 0)
                {
                    n = 1;
                    exist = 0;
                    printf("Nhập ID lớp muốn thêm cho giáo viên này: \n");
                    scanf("%s", &add);
                    FILE *fpt = fopen("D:/project/project/data/Classroom.bin", "wb+");
                    if (fpt == NULL)
                    {
                        printf("Không thể mở file danh sách lớp\n");
                    }
                    else
                    {
                        fread(&totalClass, sizeof(int), 1, fpt);
                        fread(c, sizeof(Classroom), totalClass, fpt);
                        if (totalClass == 0)
                        {
                            printf("Danh sách lớp rỗng\n");
                        }
                        else
                        {
                            for (int j = 0; j < totalClass; j++)
                            {
                                if (strlen(c[j].teacherName) == 0 && strcmp(add, c[j].id) == 0)
                                {
                                    exist = 1;
                                    strcpy(c[j].teacherName, t[i].name);
                                    t[i].classroom[totalClass] = c[j];
                                    totalClass++;
                                    printf("Thêm lớp cho giáo viên thành công\n");
                                    break;
                                }
                                else if (strlen(c[j].teacherName) != 0 && strcmp(add, c[j].id) == 0)
                                {
                                    exist = 1;
                                    printf("Lớp đã có giáo viên\n");
                                    break;
                                }
                            }
                            if (exist == 0)
                            {
                                printf("Không tìm thấy lớp\n");
                            }
                        }
                    }
                    if (n == 0)
                    {
                        printf("Không tìm thấy giáo viên\n");
                    }
                    fwrite(&totalClass, sizeof(int), 1, fpt);
                    fwrite(c, sizeof(Classroom), totalClass, fpt);
                    fclose(fpt);
                }
                fwrite(&totalTeacher, sizeof(int), 1, f);
                fwrite(t, sizeof(Teacher), totalTeacher, f);
            }
        }
    }
}
void addClass()
{
    FILE *f = fopen("D:/project/project/data/Classroom.bin", "wb+");
    fread(&totalClass, sizeof(int), 1, f);
    fread(c, sizeof(Classroom), totalClass, f);
    printf("Nhập số lượng lớp cần thêm:");
    scanf("%d", &n);
    for (int i = totalClass; i < totalClass + n; i++)
    {
        c[i].totalStudent = 0;
        do
        {
            check = 0, loop = 0;
            printf("Nhập ID lớp (Bắt đầu INT): ");
            scanf("%10s", c[i].id);
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
            if (c[i].id[0] != 'I' || c[i].id[1] != 'N' || c[i].id[2] != 'T')
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
            scanf("%20s", c[i].name);
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
    totalClass += n;
    fwrite(&totalClass, sizeof(int), 1, f);
    fwrite(c, sizeof(Classroom), totalClass, f);
    fclose(f);
}
void listClass()
{
    FILE *f = fopen("D:/project/project/data/Classroom.bin", "rb");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalClass, sizeof(int), 1, f);
        fread(c, sizeof(Classroom), totalClass, f);
        if (totalClass == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            printf("%43cDANH SACH LOP\n");
            printf("===============================================================================================================\n");
            printf("||%-10s|%-23s|%-6s|%-24s||\n", "ID", "Tên lớp", "Sĩ số", "Giáo viên");
            for (int i = 0; i < totalClass; i++)
            {
                printf("||%-10s|%-20s|%-5d|%-22s||\n", c[i].id, c[i].name, c[i].totalStudent, c[i].teacherName);
            }
            printf("===============================================================================================================\n");
            fclose(f);
        }
    }
}
void showClass()
{
    FILE *f = fopen("D:/project/project/data/Classroom.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalClass, sizeof(int), 1, f);
        fread(c, sizeof(Classroom), totalClass, f);
        if (totalClass == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            n = 0;
            printf("Nhập ID lớp muốn xem: ");
            scanf("%s", &find);
            for (int i = 0; i < totalClass; i++)
            {
                if (strcmp(find, c[i].id) == 0)
                {
                    n = 1;
                    printf("===============================================================================================================\n");
                    printf("||%-10s|%-20s|%-6s|%-20s||\n", "ID", "Tên lớp", "Sĩ số", "Giáo viên");
                    printf("||%-10s|%-20s|%-6d|%-20s||\n", c[i].id, c[i].name, c[i].totalStudent, c[i].teacherName);
                    printf("===============================================================================================================\n");
                    printf("Bạn có muốn thêm sinh viên cho lớp không?\n");
                    printf("1. Có%5c2. Không\n");
                    printf("Lựa chọn của bạn: ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        printf("Nhập số sinh viên muốn thêm: ");
                        scanf("%d", &numToAdd);
                        FILE *fpt = fopen("D:/project/project/data/Student.bin", "wb+");
                        if (fpt == NULL)
                        {
                            printf("File danh sách sinh viên không tồn tại\n");
                            break;
                        }
                        else
                        {
                            fread(&totalStudent, sizeof(int), 1, fpt);
                            fread(s, sizeof(Student), totalStudent, fpt);
                            if (totalStudent == 0)
                            {
                                printf("Danh sách sinh viên rỗng\n");
                            }
                            else
                            {
                                while (numToAdd--)
                                {
                                    exist = 0;
                                    printf("Nhập ID sinh viên muốn thêm: ");
                                    scanf("%s", &add);
                                    for (int j = 0; j < totalStudent; j++)
                                    {
                                        if (strcmp(add, s[j].id) == 0 && strlen(s[i].classId) == 0)
                                        {
                                            exist = 1;
                                            strcpy(s[j].classId, c[i].id);
                                            c[i].students[c[i].totalStudent] = s[j];
                                            c[i].totalStudent++;
                                            printf("Thêm sinh viên thành công\n");
                                        }
                                        else if (strcmp(add, s[j].id) == 0 && strlen(s[i].classId) != 0)
                                        {
                                            exist = 1;
                                            printf("Sinh viên hiện đã có lớp\n");
                                        }
                                    }
                                    if (exist == 0)
                                    {
                                        printf("Không tìm thấy sinh viên\n");
                                    }
                                }
                            }
                            if (n == 0)
                            {
                                printf("Không tìm thấy lớp học");
                            }
                        }
                        fwrite(&totalStudent, sizeof(int), 1, fpt);
                        fwrite(s, sizeof(Student), totalStudent, fpt);
                        fclose(fpt);
                    }
                    break;
                }
            }
        }
    }
    fclose(f);
}
void delClass()
{
    FILE *f = fopen("D:/project/project/data/Classroom.bin", "wb+");
    if (f == NULL)
    {
        printf("Lỗi mở File\n");
    }
    else
    {
        fread(&totalClass, sizeof(int), 1, f);
        fread(c, sizeof(Classroom), totalClass, f);
        if (totalClass == 0)
        {
            printf("Danh sách rỗng\n");
        }
        else
        {
            check = 0;
            printf("Nhập ID lớp muốn xóa: ");
            scanf("%s", &del);
            getchar();
            for (int i = 0; i < totalClass; i++)
            {
                if (strcmp(del, c[i].id) == 0)
                {
                    check = 1;
                    printf("Bạn có chắc chắn muốn xóa lớp này không?\n");
                    printf("1. Có%5c2.Không\n");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 1:
                        for (int k = 0; k < totalStudent; k++)
                        {
                            if (strcmp(s[k].classId, c[i].id) == 0)
                            {
                                strcpy(s[k].classId, '\0');
                            }
                        }
                        for (int j = i; j < totalClass - 1; j++)
                        {
                            c[j] = c[j + 1];
                        }
                        totalClass--;
                        printf("Xóa lớp thành công\n");
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
                printf("Không tìm thấy lớp\n");
            }
            fwrite(&totalClass, sizeof(int), 1, f);
            fwrite(c, sizeof(Classroom), totalClass, f);
            fclose(f);
        }
    }
}