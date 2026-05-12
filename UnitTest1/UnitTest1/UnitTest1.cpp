#include "pch.h"
#include "CppUnitTest.h"
#include "stubs.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
    TEST_CLASS(UserTests)
    {
    public:
        TEST_METHOD(GetFullName_ReturnsName)
        {
            User u("Иван Иванов", "ivan", "secret");
            Assert::AreEqual(std::string("Иван Иванов"), u.getFullName());
        }

        TEST_METHOD(VerifyLogin_ReturnsTrue)
        {
            User u("Иван Иванов", "ivan", "secret");
            Assert::IsTrue(u.verifyLogin("ivan", "secret"));
        }

        TEST_METHOD(VerifyLogin_ButWrongPass_ReturnsFalse)
        {
            User u("Иван Иванов", "ivan", "secret");
            Assert::IsFalse(u.verifyLogin("ivan", "wrong"));
        }

        TEST_METHOD(VerifyLogin_ButWrongLogin_ReturnsFalse)
        {
            User u("Иван Иванов", "ivan", "secret");
            Assert::IsFalse(u.verifyLogin("petr", "secret"));
        }

        TEST_METHOD(VerifyLogin_ButSpace_ReturnsFalse)
        {
            User u("Иван Иванов", "ivan", "secret");
            Assert::IsFalse(u.verifyLogin("", ""));
        }
    };
    TEST_CLASS(TeacherTests)
    {
    public:
        TEST_METHOD(GetSalary_ReturnsValue) 
        {
            Teacher t("Мария Петрова", "maria", "pass123", 75000.0);
            Assert::AreEqual(75000.0, t.getSalary());
        }

        TEST_METHOD(GetSalary_ReturnsZero)
        {
            Teacher t("Новый Учитель", "new", "pass", 0.0);
            Assert::AreEqual(0.0, t.getSalary());
        }

        TEST_METHOD(VerifyLogin_ReturnTrue)
        {
            Teacher t("Мария Петрова", "maria", "pass123", 75000.0);
            Assert::IsTrue(t.verifyLogin("maria", "pass123"));
        }
        // Так как наследник user можно не проверять на пустоту/неправильный логин/пароль
        // если вдруг окажется, что нужно то они тут есть просто их не видно

        TEST_METHOD(GetFullName_ReturnsName)
        {
            Teacher t("Мария Петрова", "maria", "pass123", 50000.0);
            Assert::AreEqual(std::string("Мария Петрова"), t.getFullName());
        }
    };
    TEST_CLASS(StudentTests)
    {
    public:
        TEST_METHOD(GetBal_ReturnsBal)
        {
            Student s("Алексей Смирнов", "alex", "pass", 2.5);
            Assert::AreEqual((float)2.5, s.getBal());
        }

        TEST_METHOD(GetBal_ReturnsZero)
        {
            Student s("Новый Студент", "new_s", "pass", 0);
            Assert::AreEqual((float)0, s.getBal());
        }

        TEST_METHOD(VerifyLogin_ReturnTrue)
        {
            Student s("Алексей Смирнов", "alex", "pass", 90);
            Assert::IsTrue(s.verifyLogin("alex", "pass"));
        }

        TEST_METHOD(GetFullName_ReturnsFullName)
        {
            Student s("Алексей Смирнов", "alex", "pass", 90);
            Assert::AreEqual(std::string("Алексей Смирнов"), s.getFullName());
        }
    };
    TEST_CLASS(HomeworkTests)
    {
    public:
        TEST_METHOD(GetName_ReturnsName)
        {
            Homework hw("ДЗ по математике", 10, "Математика",
                "Решить задачи", 25, 5, 2025, "Задача 1-5");
            Assert::AreEqual(std::string("ДЗ по математике"), hw.getName());
        }

        TEST_METHOD(GetGradeId_ReturnsId)
        {
            Homework hw("ДЗ", 11, "Физика", "Описание", 1, 6, 2025, "Задача");
            Assert::AreEqual(11, hw.getGradeId());
        }

        TEST_METHOD(GetSubject_ReturnsSubject)
        {
            Homework hw("ДЗ", 10, "Химия", "Описание", 10, 4, 2025, "Опыт");
            Assert::AreEqual(std::string("Химия"), hw.getSubject());
        }

        TEST_METHOD(GetDescription_ReturnsDescription)
        {
            Homework hw("ДЗ", 9, "История", "Прочитать главу 5", 5, 3, 2025, "Конспект");
            Assert::AreEqual(std::string("Прочитать главу 5"), hw.getDescription());
        }

        TEST_METHOD(GetDeadLine_ReturnsDate)
        {
            Homework hw("ДЗ", 10, "Биология", "Описание", 15, 12, 2025, "Доклад");
            Assert::AreEqual(15, hw.getDeadLineDay());
            Assert::AreEqual(12, hw.getDeadLineMonth());
            Assert::AreEqual(2025, hw.getDeadLineYear());
        }

        TEST_METHOD(GetTask_ReturnsTask)
        {
            Homework hw("ДЗ", 10, "Литература", "Описание", 20, 9, 2025, "Написать сочинение");
            Assert::AreEqual(std::string("Написать сочинение"), hw.getTask());
        }
    };
    TEST_CLASS(JournalTests)
    {
    public:
        TEST_METHOD(AddStudent_StudentCountPlusPlus)
        {
            Journal j;
            Student s("Студент 1", "s1", "p1", 80);
            j.addStudent(&s);
            Assert::AreEqual(size_t(1), j.getStudents().size());
        }

        TEST_METHOD(AddStudent_ButMany_StudentCountPlusPlus)
        {
            Journal j;
            Student s1("Студент 1", "s1", "p1", 80);
            Student s2("Студент 2", "s2", "p2", 70);
            j.addStudent(&s1);
            j.addStudent(&s2);
            Assert::AreEqual(size_t(2), j.getStudents().size());
        }

        TEST_METHOD(AddTeacher_TeacherCountPlusPlus)
        {
            Journal j;
            Teacher t("Учитель 1", "t1", "p1", 60000.0);
            j.addTeacher(&t);
            Assert::AreEqual(size_t(1), j.getTeachers().size());
        }

        TEST_METHOD(DelStudent_StudentCountMinusMinus)
        {
            Journal j;
            Student s("Студент", "s1", "p1", 75);
            j.addStudent(&s);
            j.delStudent(&s);
            Assert::AreEqual(size_t(0), j.getStudents().size());
        }

        TEST_METHOD(DelTeacher_TeacherCountMinusMinus)
        {
            Journal j;
            Teacher t("Учитель", "t1", "p1", 55000.0);
            j.addTeacher(&t);
            j.delTeacher(&t);
            Assert::AreEqual(size_t(0), j.getTeachers().size());
        }
        TEST_METHOD(AddHomework_HomeworkCountPlusPlus)
        {
            Journal j;
            Homework hw("ДЗ", 10, "Математика", "Описание", 1, 1, 2025, "Задача");
            j.addHomework(&hw);
            Assert::AreEqual(size_t(1), j.getHomework().size());
        }

        TEST_METHOD(AddStudent_ButNullPtr)
        {
            Journal j;
            j.addStudent(nullptr);
            Assert::AreEqual(size_t(0), j.getStudents().size());
        }

        TEST_METHOD(AddNullTeacher_DoesNotCrash)
        {
            Journal j;
            j.addTeacher(nullptr);
            Assert::AreEqual(size_t(0), j.getTeachers().size());
        }
    };
}
