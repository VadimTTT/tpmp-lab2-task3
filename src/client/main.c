#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/train.h"
#include "../include/software.h"

// Функция для демонстрации работы с поездами
void demonstrateTrains() {
    printf("\n========== TASK 3: TRAIN STRUCTURE ==========\n");
    
    Train trains[5];
    
    // Инициализация тестовых данных
    initTrain(&trains[0], 101, "Минск", "10:30", "08:00", 350, 12, "купейный", 36);
    initTrain(&trains[1], 202, "Гродно", "18:45", "06:15", 420, 8, "плацкарт", 54);
    initTrain(&trains[2], 303, "Владивосток", "14:20", "05:10", 1200, 15, "купейный", 36);
    initTrain(&trains[3], 404, "Брест", "22:15", "20:30", 200, 10, "люкс", 24);
    initTrain(&trains[4], 505, "Гродно", "09:50", "23:40", 420, 9, "плацкарт", 54);
    
    // Вывод всех поездов
    printf("\nAll trains:\n");
    for (int i = 0; i < 5; i++) {
        printTrain(&trains[i]);
    }
    
    // Поезда в пути более 24 часов
    printLongTrips(trains, 5);
    
    // Пассажиры в купейных вагонах
    int total = totalCompartmentPassengers(trains, 5);
    printf("\nTotal passengers in compartment wagons: %d\n", total);
    
    // Поезда в Гродно
    printTrainsToGrodno(trains, 5);
    
    // Поезд с максимальным количеством вагонов
    findMaxWagonsTrain(trains, 5);
}

// Функция для демонстрации работы с ПО
void demonstrateSoftware() {
    printf("\n========== TASK 4: SOFTWARE STRUCTURE ==========\n");
    
    Software soft[5];
    
    // Инициализация тестовых данных
    initSoftware(&soft[0], "Photoshop", "Adobe", 2022, 24.5, 4, 1500);
    initSoftware(&soft[1], "WinRAR", "Rarlab", 2021, 6.1, 5, 250);
    initSoftware(&soft[2], "Notepad", "Microsoft", 2023, 11.0, 2, 0);
    initSoftware(&soft[3], "Visual Studio", "Microsoft", 2022, 17.0, 3, 0);
    initSoftware(&soft[4], "AutoCAD", "Autodesk", 2021, 2024.0, 4, 1200);
    
    // Вывод всего ПО
    printf("\nAll software:\n");
    for (int i = 0; i < 5; i++) {
        printSoftware(&soft[i]);
    }
    
    // ПО дороже 200 руб и поддержка > 3 лет
    printExpensiveSoftware(soft, 5);
    
    // ПО от Microsoft
    printSoftwareByCompany(soft, 5, "Microsoft");
}

int main() {
    printf("========================================\n");
    printf("Laboratory Work #2\n");
    printf("Variant 22\n");
    printf("Author: Vadim Tyushko\n");
    printf("Group: PI-23-1\n");
    printf("========================================\n");
    
    demonstrateTrains();
    demonstrateSoftware();
    
    printf("\n✅ Program completed successfully\n");
    return 0;
}