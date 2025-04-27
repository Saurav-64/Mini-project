#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <limits>
#include <algorithm>

class Student
{
private:
    int roll_no;
    int age;
    std::string name;

public:
    Student(int roll_no, int age, std::string name)
    {
        this->roll_no = roll_no;
        this->age = age;
        this->name = name;
    }

    void setRollno(int roll_no)
    {
        this->roll_no = roll_no;
    }

    int getRollno()
    {
        return roll_no;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return age;
    }

    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName()
    {
        return name;
    }
};

void addNewStudent(std::vector<Student> &student)
{
    std::system("cls");
    int roll_no;
    int age;
    char ch;
    do
    {
        std::cout << "\t\t------------------------------" << std::endl;
        std::cout << "\t\t\tAdd the student" << std::endl;
        std::cout << "\t\t------------------------------" << std::endl;
        std::string name;
        std::cout << "Enter roll number : ";
        std::cin >> roll_no;
        for (int i = 0; i < student.size(); i++)
        {
            if (student[i].getRollno() == roll_no)
            {
                std::cout << "The student already exist" << std::endl;
                return;
            }
        }
        std::cout << "Enter age : ";
        std::cin >> age;
        std::cout << "Enter name : ";
        std::cin >> name;

        Student newStudent(roll_no, age, name);
        student.push_back(newStudent);
        std::cout << "\n\t\tNew Student Detail Added Sucessfully" << std::endl;
        std::cout << "---------------------------------------------------------------------------------\n";
        std::cout << "\n\tDo you want to add more detail of student(Y/N) : ";
        std::cin >> ch;
    } while (ch == 'Y' || ch == 'y');
};
void displayStudent(std::vector<Student> &students)
{
    std::system("cls");
    std::cout << "\t\t--------------------------------------------" << std::endl;
    std::cout << "\t\t\tDisplaying Student Details" << std::endl;
    std::cout << "\t\t----------------------------------------" << std::endl;
    std::cout << "ROLL NO" << "\t\t" << "Age" << "\t\t" << "Name" << std::endl;
    for (auto &student : students)
    {
        std::cout << student.getRollno() << "\t\t" << student.getAge() << "\t\t" << student.getName() << std::endl;
    }
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
};
void searchStudent(std::vector<Student> &students)
{
    std::system("cls");
    std::cout << "\t\t----------------------------------------" << std::endl;
    std::cout << "\t\t\tSearch BY Roll no :" << std::endl;
    std::cout << "\t\t----------------------------------------" << std::endl;
    int check_roll;
    std::cout << "Enter the student roll no : ";
    std::cin >> check_roll;
    for (auto &student : students)
    {
        if (student.getRollno() == check_roll)
        {
            std::cout << "Roll NO : " << student.getRollno() << std::endl
                      << "Name : " << student.getName() << std::endl
                      << "Age : " << student.getAge() << std::endl;
            break;
        }
    }

    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
};
void updateStudent(std::vector<Student> &students)
{

    std::system("cls");
    std::cout << "\t\t----------------------------------------" << std::endl;
    std::cout << "\t\t\t Update Student Info" << std::endl;
    std::cout << "\t\t----------------------------------------" << std::endl;
    int check_roll;
    std::cout << "Enter the student roll no to update : ";
    std::cin >> check_roll;
    for (auto &student : students)
    {
        if (student.getRollno() == check_roll)
        {
            std::cout << "The of info of student : " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "Roll NO : " << student.getRollno() << std::endl
                      << "Name : " << student.getName() << std::endl
                      << "Age : " << student.getAge() << std::endl;
            int op;
            bool exist = false;
            while (!exist)
            {
                std::cout << "What to Change ? " << std::endl;
                std::cout << "----------------------------------------------------------" << std::endl;
                std::cout << "\n\n1. Roll NO" << std::endl;
                std::cout << "2. Name" << std::endl;
                std::cout << "3. Age" << std::endl;
                std::cout << "4. No change" << std::endl;
                std::cout << "Enter the choice : ";
                std::cin >> op;
                switch (op)
                {
                case 1:
                {
                    int change_rollno;
                    std::cout << "New Roll NO : ";
                    std::cin >> change_rollno;
                    student.setRollno(change_rollno);
                    break;
                }

                case 2:
                {
                    std::string change_name;
                    std::cout << "Changed Name  : ";
                    std::cin >> change_name;
                    student.setName(change_name);
                    break;
                }

                case 3:
                {
                    int change_age;
                    std::cout << "New Age : ";
                    std::cin >> change_age;
                    student.setAge(change_age);
                    break;
                }

                case 4:
                {
                    exist = true;
                    break;
                }
                default:
                {
                    std::cout << "Invalid Choice" << std::endl;
                    break;
                }
                }
            }

            std::cout << "The of info of student after updating : " << std::endl;
            std::cout << "----------------------------------------------------------" << std::endl;
            std::cout << "Roll NO : " << student.getRollno() << std::endl
                      << "Name : " << student.getName() << std::endl
                      << "Age : " << student.getAge() << std::endl;
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();

            break;
        }
    }
};
void removeStudent(std::vector<Student> &students)
{
    std::cout << "\t\t----------------------------------------" << std::endl;
    std::cout << "\t\t\tRemoving Sudent Detail" << std::endl;
    std::cout << "\t\t----------------------------------------" << std::endl;
    int rem_rollno;
    std::cout << "Enter the roll no of student whose detail is to be removed : ";
    std::cin >> rem_rollno;

    students.erase(
        std::remove_if(students.begin(), students.end(),
                       [&rem_rollno](Student &s)
                       { return s.getRollno() == rem_rollno; }),
        students.end());
    std::cout << "ROLL NO" << "\t\t" << "Age" << "\t\t" << "Name" << std::endl;
    for (auto &student : students)
    {
        std::cout << student.getRollno() << "\t\t" << student.getAge() << "\t\t" << student.getName() << std::endl;
    }
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
int main()
{
    std::vector<Student> students;
    students.push_back(Student(1, 18, "Ali"));

    int op;
    bool exist = false;
    while (!exist)
    {
        std::system("cls");
        std::cout << "\t\t----------------------------------------" << std::endl;
        std::cout << "\t\t\tStudent Management System" << std::endl;
        std::cout << "\t\t----------------------------------------" << std::endl;
        std::cout << "1 . Add New Student " << std::endl;
        std::cout << "2. Display All Student" << std::endl;
        std::cout << "3. Search Student" << std::endl;
        std::cout << "4. Update Student" << std::endl;
        std::cout << "5. Delete Student" << std::endl;
        std::cout << "6. Exit" << std::endl;

        std::cout << "Enter your choice : ";
        std::cin >> op;

        switch (op)
        {
        case 1:
            addNewStudent(students);
            break;

        case 2:
            displayStudent(students);
            break;

        case 3:
            searchStudent(students);
            break;

        case 4:
            updateStudent(students);
            break;

        case 5:
            removeStudent(students);
            break;

        case 6:
            exist = true;
        default:
            std::cout << "Invalid Choice" << std::endl;
        }
    }
}