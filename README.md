# tpmp-lab2-task3

## Overview
Данный проект демонстрирует работу со структурами данных на языке C в рамках лабораторной работы №2. Реализованы две структуры согласно варианту 22: **TRAIN** (поезда) и **SOFTWARE** (программное обеспечение). Проект построен по модели КИС-2 (Kernel-Interface-Client).

## Author
**Студент:** Тюшко Вадим  
**Группа:** 12
**Вариант:** 22

## Project Structure
```
tpmp-lab2-task3/
├── src/
│   ├── include/           # ИНТЕРФЕЙС: заголовочные файлы
│   │   ├── train.h        # Структура TRAIN и прототипы функций
│   │   └── software.h     # Структура SOFTWARE и прототипы функций
│   ├── server/            # ЯДРО: реализация функций
│   │   ├── train_operations.c
│   │   └── software_operations.c
│   └── client/            # КЛИЕНТ: точка входа
│       └── main.c
├── docs/                   # Документация и тесты
├── Makefile                # Сборка проекта
└── README.md               # Документация
```

## Model KIS-2 (Kernel-Interface-Client)
| Компонент | Назначение | Файлы |
|-----------|------------|-------|
| **Interface** | Объявление структур и функций | `train.h`, `software.h` |
| **Kernel** | Реализация логики | `train_operations.c`, `software_operations.c` |
| **Client** | Точка входа, демонстрация | `main.c` |

## Data Structures

### Structure TRAIN (Task 3)
```c
typedef struct {
    int train_number;           // № поезда
    char destination[50];        // направление
    char arrival_time[6];        // время прибытия
    char departure_time[6];      // время отбытия
    int distance;                 // расстояние
    int wagon_count;              // количество вагонов
    char wagon_type[20];          // тип вагона
    int passengers_per_wagon;     // пассажиров в вагоне
} Train;
```

**Functions:**
- `initTrain()` — инициализация структуры
- `printTrain()` — вывод информации
- `calculateTravelTime()` — время в пути
- `printLongTrips()` — поезда в пути >24 часов
- `totalCompartmentPassengers()` — пассажиры в купейных вагонах
- `printTrainsToGrodno()` — поезда в Гродно
- `findMaxWagonsTrain()` — поезд с макс. количеством вагонов

### Structure SOFTWARE (Task 4)
```c
typedef struct {
    char name[50];               // название
    char company[50];             // производитель
    int release_year;             // год выпуска
    float version;                 // версия
    int support_period;            // период поддержки (лет)
    float price;                    // цена
} Software;
```

**Functions:**
- `initSoftware()` — инициализация
- `printSoftware()` — вывод информации
- `printExpensiveSoftware()` — ПО дороже 200 руб и поддержка >3 лет
- `printSoftwareByCompany()` — ПО по производителю

## Usage

### Build and Run
```bash
# Компиляция проекта
make

# Запуск программы
make run

# Очистка временных файлов
make clean

# Полная пересборка
make clean && make && make run
```

### Manual Compilation
```bash
gcc -o program src/client/main.c src/server/train_operations.c src/server/software_operations.c -I./src/include -Wall -Wextra -std=c99
./program
```

## Test Data

### Sample Trains
| № | Destination | Arrival | Departure | Distance | Wagons | Type | Pass/Wagon |
|---|-------------|---------|-----------|----------|--------|------|------------|
| 101 | Минск | 10:30 | 08:00 | 350 | 12 | купейный | 36 |
| 202 | Гродно | 18:45 | 06:15 | 420 | 8 | плацкарт | 54 |
| 303 | Владивосток | 14:20 | 05:10 | 1200 | 15 | купейный | 36 |
| 404 | Брест | 22:15 | 20:30 | 200 | 10 | люкс | 24 |
| 505 | Гродно | 09:50 | 23:40 | 420 | 9 | плацкарт | 54 |

### Sample Software
| Name | Company | Year | Version | Support | Price |
|------|---------|------|---------|---------|-------|
| Photoshop | Adobe | 2022 | 24.5 | 4 | 1500 |
| WinRAR | Rarlab | 2021 | 6.1 | 5 | 250 |
| Notepad | Microsoft | 2023 | 11.0 | 2 | 0 |
| Visual Studio | Microsoft | 2022 | 17.0 | 3 | 0 |
| AutoCAD | Autodesk | 2021 | 2024.0 | 4 | 1200 |

## Expected Output
```
========================================
Laboratory Work #2
Variant 22
Author: Vadim Tyushko
Group: PI-23-1
========================================

========== TASK 3: TRAIN STRUCTURE ==========

=== Train Information ===
Train number: 101
Destination: Минск
Arrival time: 10:30
Departure time: 08:00
Distance: 350 km
Wagons: 12
Wagon type: купейный
Passengers per wagon: 36
Total passengers: 432

... (и так далее)

--- Trains with travel time > 24 hours ---
Train 303: 05:10 -> 14:20, travel time: 33 hours

Total passengers in compartment wagons: 972

--- Trains to Grodno ---
Train 202, arrival: 18:45
Train 505, arrival: 09:50

--- Train with maximum wagons (15) ---

========== TASK 4: SOFTWARE STRUCTURE ==========

--- Software > 200 RUB and support > 3 years ---
Photoshop (v24.5) by Adobe - 1500.00 RUB, support: 4 years
WinRAR (v6.1) by Rarlab - 250.00 RUB, support: 5 years
AutoCAD (v2024.0) by Autodesk - 1200.00 RUB, support: 4 years

--- Software by Microsoft ---
Notepad (v11.0) - 0.00 RUB
Visual Studio (v17.0) - 0.00 RUB

✅ Program completed successfully
```

## GitHub Actions
Проект настроен на автоматическую сборку через GitHub Actions при каждом push и pull request. Конфигурация находится в `.github/workflows/ci.yml`.

## Test Report
Подробные результаты тестирования находятся в файле [docs/test-report.md](docs/test-report.md).

## Additional Notes
- Проект следует модели КИС-2 (Kernel-Interface-Client)
- Код оформлен согласно стандартам: отступы 4 пробела, комментарии к функциям
- Используется Makefile для автоматизации сборки
- Все функции имеют защиту от некорректных входных данных

## Submodule Information
Данный репозиторий добавлен как submodule в основной репозиторий лабораторной работы:
```bash
git submodule add https://github.com/VadimTTT/tpmp-lab2-task3.git
```

## License
MIT License