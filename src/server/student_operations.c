#include <stdio.h>
#include <string.h>
#include "../include/student.h"

// Реализация функций (серверная часть)

void initStudent(Student* student, const char* name, int age, float grade, int course, const char* group) {
    strcpy(student->name, name);
    student->age = age;
    student->average_grade = grade;
    student->course = course;
    strcpy(student->group, group);
}

void printStudent(const Student* student) {
    printf("=== Информация о студенте ===\n");
    printf("Имя: %s\n", student->name);
    printf("Возраст: %d\n", student->age);
    printf("Средний балл: %.2f\n", student->average_grade);
    printf("Курс: %d\n", student->course);
    printf("Группа: %s\n", student->group);
    printf("============================\n");
}

float calculateAverageGrade(const Student* student, const int* grades, int count) {
    if (count <= 0) return 0.0;
    
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return (float)sum / count;
}

void updateStudentInfo(Student* student, float new_grade, int new_course) {
    student->average_grade = new_grade;
    student->course = new_course;
    printf("✅ Информация о студенте обновлена\n");
}