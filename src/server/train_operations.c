#include <stdio.h>
#include <string.h>
#include "../include/train.h"

// Инициализация структуры поезда
void initTrain(Train* train, int number, const char* dest, 
               const char* arr, const char* dep, int dist,
               int wagons, const char* type, int passengers) {
    train->train_number = number;
    strcpy(train->destination, dest);
    strcpy(train->arrival_time, arr);
    strcpy(train->departure_time, dep);
    train->distance = dist;
    train->wagon_count = wagons;
    strcpy(train->wagon_type, type);
    train->passengers_per_wagon = passengers;
}

// Вывод информации о поезде
void printTrain(const Train* train) {
    printf("\n=== Train Information ===\n");
    printf("Train number: %d\n", train->train_number);
    printf("Destination: %s\n", train->destination);
    printf("Arrival time: %s\n", train->arrival_time);
    printf("Departure time: %s\n", train->departure_time);
    printf("Distance: %d km\n", train->distance);
    printf("Wagons: %d\n", train->wagon_count);
    printf("Wagon type: %s\n", train->wagon_type);
    printf("Passengers per wagon: %d\n", train->passengers_per_wagon);
    printf("Total passengers: %d\n", train->wagon_count * train->passengers_per_wagon);
}

// Вычисление времени в пути (часы)
int calculateTravelTime(const Train* train) {
    int arr_h, arr_m, dep_h, dep_m;
    sscanf(train->arrival_time, "%d:%d", &arr_h, &arr_m);
    sscanf(train->departure_time, "%d:%d", &dep_h, &dep_m);
    
    int arr_minutes = arr_h * 60 + arr_m;
    int dep_minutes = dep_h * 60 + dep_m;
    
    if (arr_minutes < dep_minutes) {
        arr_minutes += 24 * 60; // прибытие на следующий день
    }
    
    return (arr_minutes - dep_minutes) / 60;
}

// Вывод поездов в пути более 24 часов
void printLongTrips(Train* trains, int count) {
    printf("\n--- Trains with travel time > 24 hours ---\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        int travel_time = calculateTravelTime(&trains[i]);
        if (travel_time > 24) {
            printf("Train %d: %s -> %s, travel time: %d hours\n",
                   trains[i].train_number,
                   trains[i].departure_time,
                   trains[i].arrival_time,
                   travel_time);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No trains with travel time > 24 hours\n");
    }
}

// Подсчет пассажиров в купейных вагонах
int totalCompartmentPassengers(Train* trains, int count) {
    int total = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(trains[i].wagon_type, "купейный") == 0) {
            total += trains[i].wagon_count * trains[i].passengers_per_wagon;
        }
    }
    
    return total;
}

// Вывод поездов в Гродно
void printTrainsToGrodno(Train* trains, int count) {
    printf("\n--- Trains to Grodno ---\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(trains[i].destination, "Гродно") == 0) {
            printf("Train %d, arrival: %s\n", 
                   trains[i].train_number, trains[i].arrival_time);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No trains to Grodno\n");
    }
}

// Поиск поезда с максимальным количеством вагонов
int findMaxWagonsTrain(Train* trains, int count) {
    if (count == 0) return -1;
    
    int max_idx = 0;
    for (int i = 1; i < count; i++) {
        if (trains[i].wagon_count > trains[max_idx].wagon_count) {
            max_idx = i;
        }
    }
    
    printf("\n--- Train with maximum wagons (%d) ---\n", trains[max_idx].wagon_count);
    printTrain(&trains[max_idx]);
    
    return max_idx;
}