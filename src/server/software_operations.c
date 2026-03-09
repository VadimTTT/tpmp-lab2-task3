#include <stdio.h>
#include <string.h>
#include "../include/software.h"

// Инициализация структуры ПО
void initSoftware(Software* sw, const char* name, const char* company,
                  int year, float version, int support, float price) {
    strcpy(sw->name, name);
    strcpy(sw->company, company);
    sw->release_year = year;
    sw->version = version;
    sw->support_period = support;
    sw->price = price;
}

// Вывод информации о ПО
void printSoftware(const Software* sw) {
    printf("\n=== Software Information ===\n");
    printf("Name: %s\n", sw->name);
    printf("Company: %s\n", sw->company);
    printf("Release year: %d\n", sw->release_year);
    printf("Version: %.1f\n", sw->version);
    printf("Support period: %d years\n", sw->support_period);
    printf("Price: %.2f RUB\n", sw->price);
}

// Вывод ПО дороже 200 руб и с поддержкой более 3 лет
void printExpensiveSoftware(Software* soft, int count) {
    printf("\n--- Software > 200 RUB and support > 3 years ---\n");
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (soft[i].price > 200 && soft[i].support_period > 3) {
            printf("%s (v%.1f) by %s - %.2f RUB, support: %d years\n",
                   soft[i].name, soft[i].version, soft[i].company,
                   soft[i].price, soft[i].support_period);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No software meets the criteria\n");
    }
}

// Вывод ПО по производителю
void printSoftwareByCompany(Software* soft, int count, const char* company) {
    printf("\n--- Software by %s ---\n", company);
    int found = 0;
    
    for (int i = 0; i < count; i++) {
        if (strcmp(soft[i].company, company) == 0) {
            printf("%s (v%.1f) - %.2f RUB\n",
                   soft[i].name, soft[i].version, soft[i].price);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No software by %s\n", company);
    }
}