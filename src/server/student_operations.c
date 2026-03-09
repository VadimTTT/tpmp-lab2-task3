#include <stdio.h>
#include <string.h>
#include "../include/student.h"

// Implementation of functions (server part)

void initStudent(Student* student, const char* name, int age, float grade, int course, const char* group) {
    strcpy(student->name, name);
    student->age = age;
    student->average_grade = grade;
    student->course = course;
    strcpy(student->group, group);
}

void printStudent(const Student* student) {
    printf("=== Student Information ===\n");
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("Average Grade: %.2f\n", student->average_grade);
    printf("Course: %d\n", student->course);
    printf("Group: %s\n", student->group);
    printf("============================\n");
}

float calculateAverageGrade(const Student* student, const int* grades, int count) {
    // To avoid unused parameter warning
    (void)student;
    
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
    printf("✅ Student information updated\n");
}