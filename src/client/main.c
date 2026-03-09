#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/student.h"

// Function to generate random grades
void generateGrades(int* grades, int count) {
    for (int i = 0; i < count; i++) {
        grades[i] = 4 + rand() % 7; // grades from 4 to 10
    }
}

// Function to print grades
void printGrades(const int* grades, int count) {
    printf("Grades: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    printf("========================================\n");
    printf("Laboratory Work #2\n");
    printf("Variant 22: Working with Structures\n");
    printf("Author: Vadim Tyushko\n");
    printf("Group: PI-23-1\n");
    printf("KIS-2 Model: Interface/Server/Client\n");
    printf("========================================\n\n");
    
    // Create a student (client uses interface)
    Student student1;
    initStudent(&student1, "Ivan Petrov", 19, 8.5, 2, "PI-23-1");
    
    // Print student information
    printStudent(&student1);
    
    // Generate and calculate average grade
    const int GRADE_COUNT = 5;
    int grades[GRADE_COUNT];
    generateGrades(grades, GRADE_COUNT);
    printGrades(grades, GRADE_COUNT);
    
    float calculated_avg = calculateAverageGrade(&student1, grades, GRADE_COUNT);
    printf("Calculated average grade: %.2f\n", calculated_avg);
    
    // Update information
    printf("\n📝 Updating information...\n");
    updateStudentInfo(&student1, 9.2, 3);
    printStudent(&student1);
    
    // Create an array of students
    printf("\n📋 Array of students:\n");
    Student group[3];
    initStudent(&group[0], "Anna Smirnova", 18, 9.1, 1, "PI-23-2");
    initStudent(&group[1], "Petr Sidorov", 20, 7.8, 3, "PI-23-1");
    initStudent(&group[2], "Maria Ivanova", 19, 8.9, 2, "PI-23-3");
    
    for (int i = 0; i < 3; i++) {
        printf("\nStudent %d:\n", i + 1);
        printStudent(&group[i]);
    }
    
    printf("\n✅ Program completed successfully\n");
    return 0;
}