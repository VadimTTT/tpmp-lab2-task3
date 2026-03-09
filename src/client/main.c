#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/student.h"

// Функция для генерации случайных оценок
void generateGrades(int* grades, int count) {
    for (int i = 0; i < count; i++) {
        grades[i] = 4 + rand() % 7; // оценки от 4 до 10
    }
}

// Функция для вывода оценок
void printGrades(const int* grades, int count) {
    printf("Оценки: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", grades[i]);
    }
    printf("\n");
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    printf("========================================\n");
    printf("Лабораторная работа №2\n");
    printf("Вариант 22: Работа со структурами\n");
    printf("Автор: Тюшко Вадим\n");
    printf("Группа: ПИ-23-1\n");
    printf("Модель КИС-2: Интерфейс/Сервер/Клиент\n");
    printf("========================================\n\n");
    
    // Создание студента (клиент использует интерфейс)
    Student student1;
    initStudent(&student1, "Иван Петров", 19, 8.5, 2, "ПИ-23-1");
    
    // Вывод информации о студенте
    printStudent(&student1);
    
    // Генерация и расчет среднего балла
    const int GRADE_COUNT = 5;
    int grades[GRADE_COUNT];
    generateGrades(grades, GRADE_COUNT);
    printGrades(grades, GRADE_COUNT);
    
    float calculated_avg = calculateAverageGrade(&student1, grades, GRADE_COUNT);
    printf("Рассчитанный средний балл: %.2f\n", calculated_avg);
    
    // Обновление информации
    printf("\n📝 Обновление информации...\n");
    updateStudentInfo(&student1, 9.2, 3);
    printStudent(&student1);
    
    // Создание массива студентов
    printf("\n📋 Массив студентов:\n");
    Student group[3];
    initStudent(&group[0], "Анна Смирнова", 18, 9.1, 1, "ПИ-23-2");
    initStudent(&group[1], "Петр Сидоров", 20, 7.8, 3, "ПИ-23-1");
    initStudent(&group[2], "Мария Иванова", 19, 8.9, 2, "ПИ-23-3");
    
    for (int i = 0; i < 3; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printStudent(&group[i]);
    }
    
    printf("\n✅ Программа завершена\n");
    return 0;
}