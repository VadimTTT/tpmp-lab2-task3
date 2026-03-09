#ifndef SOFTWARE_H
#define SOFTWARE_H

#define MAX_SOFT 20
#define NAME_LEN 50
#define COMPANY_LEN 50

// Структура SOFTWARE (задание 4)
typedef struct {
    char name[NAME_LEN];           // название
    char company[COMPANY_LEN];      // производитель
    int release_year;               // год выпуска
    float version;                   // версия
    int support_period;              // период поддержки (лет)
    float price;                      // цена
} Software;

// Прототипы функций для работы с ПО
void initSoftware(Software* sw, const char* name, const char* company,
                  int year, float version, int support, float price);
void printSoftware(const Software* sw);
void printExpensiveSoftware(Software* soft, int count);
void printSoftwareByCompany(Software* soft, int count, const char* company);

#endif