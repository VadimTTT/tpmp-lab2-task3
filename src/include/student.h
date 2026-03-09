#ifndef STUDENT_H
#define STUDENT_H

// Структура Student (вариант 22)
typedef struct {
    char name[50];
    int age;
    float average_grade;
    int course;
    char group[10];
} Student;

// Прототипы функций (интерфейс)
void initStudent(Student* student, const char* name, int age, float grade, int course, const char* group);
void printStudent(const Student* student);
float calculateAverageGrade(const Student* student, const int* grades, int count);
void updateStudentInfo(Student* student, float new_grade, int new_course);

#endif // STUDENT_H