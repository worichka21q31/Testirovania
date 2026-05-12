#include "pch.h"
#include "stubs.h"

User::User(const std::string& fullName, const std::string& login, const std::string& pass)
    : fullName(fullName), login(login), pass(pass) {}

bool User::verifyLogin(const std::string& loginn, const std::string& pas) const {
    return login == loginn && pass == pas;
}

std::string User::getFullName() const {
    return fullName;
}

Teacher::Teacher(const std::string& fullName, const std::string& login, const std::string& pass, double salary)
    : User(fullName, login, pass), salary(salary) {}

double Teacher::getSalary() const { 
    return salary; 
}

Student::Student(const std::string& fullName, const std::string& login, const std::string& pass, const float bal)
    : User(fullName, login, pass), bal(bal) {
}

float Student::getBal() const {
    return bal;
}


Homework::Homework(const std::string& name, int gradeId, const std::string& subject, const std::string& description, int day, int month, int year, const std::string& task)
    : name(name), gradeId(gradeId), subject(subject), description(description), task(task)
{
    deadLine[0] = day; deadLine[1] = month; deadLine[2] = year;
}

std::string Homework::getName() const { 
    return name; 
}
int Homework::getGradeId() const { 
    return gradeId; 
}
std::string Homework::getSubject() const { 
    return subject; 
}
std::string Homework::getDescription() const { 
    return description;
}
std::string Homework::getTask() const {
    return task; 
}
int Homework::getDeadLineDay() const { 
    return deadLine[0];
}
int Homework::getDeadLineMonth() const { 
    return deadLine[1];
}
int Homework::getDeadLineYear() const {
    return deadLine[2]; 
}

void Journal::addStudent(Student* stud) { 
    if (stud) { 
    students.push_back(stud);
    } 
}
void Journal::addTeacher(Teacher* teach) 
{
    if (teach) { 
        teachers.push_back(teach); 
    }
}
void Journal::addHomework(Homework* homeW) {
    if (homeW){
        homework.push_back(homeW);
    }
}

void Journal::delStudent(Student* stud) {
    auto it = std::find(students.begin(), students.end(), stud);
    students.erase(it);
}
void Journal::delTeacher(Teacher* t) {
    auto it = std::find(teachers.begin(), teachers.end(), t);
    teachers.erase(it);
}

const std::vector<Student*>& Journal::getStudents() const {
    return students;
}
const std::vector<Teacher*>& Journal::getTeachers() const {
    return teachers;
}
const std::vector<Homework*>& Journal::getHomework() const { 
    return homework; 
}
void Journal::showHomework() const {}