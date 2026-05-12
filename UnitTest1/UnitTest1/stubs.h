#ifndef STUBS_H
#define STUBS_H

#include <string>
#include <vector>
#include <algorithm>

class User {
protected:
    std::string fullName;
    std::string login;
    std::string pass;

public:
    User(const std::string& fullName, const std::string& login, const std::string& pass);
    bool verifyLogin(const std::string& loginn, const std::string& pas) const;
    std::string getFullName() const;
};

class Teacher : public User {
private:
    double salary;

public:
    Teacher(const std::string& fullName, const std::string& login, const std::string& pass, double salary);
    double getSalary() const;
};

class Student : public User {
private:
    float bal;

public:
    Student(const std::string& fullName, const std::string& login, const std::string& pass,const float bal);
    float getBal() const;
};

class Homework {
private:
    std::string name;
    int gradeId;
    std::string subject;
    std::string description;
    int deadLine[3];   // День, Месяц, Год
    std::string task;

public:
    Homework(const std::string& name, int gradeId, const std::string& subject,
        const std::string& description, int day, int month, int year, const std::string& task);
    std::string getName() const;
    int getGradeId() const;
    std::string getSubject() const;
    std::string getDescription() const;
    std::string getTask() const;
    int getDeadLineDay() const;
    int getDeadLineMonth() const;
    int getDeadLineYear() const;
};

class Journal {
private:
    std::vector<Student*>  students;
    std::vector<Teacher*>  teachers;
    std::vector<Homework*> homework;

public:
    void addStudent(Student* stud);
    void addTeacher(Teacher* teach);
    void addHomework(Homework* homeW);
    void delStudent(Student* stud);
    void delTeacher(Teacher* teach);
    const std::vector<Student*>& getStudents() const;
    const std::vector<Teacher*>& getTeachers() const;
    const std::vector<Homework*>& getHomework() const;
    void showHomework() const;
};

#endif // STUBS_H