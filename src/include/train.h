#ifndef TRAIN_H
#define TRAIN_H

#define MAX_TRAINS 12
#define DEST_LEN 50
#define TYPE_LEN 20
#define TIME_LEN 6

// Структура TRAIN (задание 3)
typedef struct {
    int train_number;               // № поезда
    char destination[DEST_LEN];      // направление
    char arrival_time[TIME_LEN];     // время прибытия
    char departure_time[TIME_LEN];   // время отбытия
    int distance;                     // расстояние (км)
    int wagon_count;                  // количество вагонов
    char wagon_type[TYPE_LEN];        // тип вагона
    int passengers_per_wagon;         // пассажиров в вагоне
} Train;

// Прототипы функций для работы с поездами
void initTrain(Train* train, int number, const char* dest, 
               const char* arr, const char* dep, int dist,
               int wagons, const char* type, int passengers);
void printTrain(const Train* train);
int calculateTravelTime(const Train* train);
void printLongTrips(Train* trains, int count);
int totalCompartmentPassengers(Train* trains, int count);
void printTrainsToGrodno(Train* trains, int count);
int findMaxWagonsTrain(Train* trains, int count);

#endif