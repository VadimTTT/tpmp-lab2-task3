# Test Report - Laboratory Work #2 (Variant 22)

## Project Information
- **Student:** Vadim Tyushko
- **Group:** PI-23-1
- **Repository:** tpmp-lab2-task3
- **Date:** March 9, 2026
- **Variant:** 22 (TRAIN + SOFTWARE structures)

---

## TEST GROUP 1: TRAIN Structure Tests

### Test 1.1: Train Initialization

**Input Data:**
```c
Train train1;
initTrain(&train1, 101, "Минск", "10:30", "08:00", 350, 12, "купейный", 36);
```

**Expected Result:**
- train_number = 101
- destination = "Минск"
- arrival_time = "10:30"
- departure_time = "08:00"
- distance = 350
- wagon_count = 12
- wagon_type = "купейный"
- passengers_per_wagon = 36
- total passengers = 432

**Actual Result:**
```
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
```

**Result:** ✅ PASSED

---

### Test 1.2: Travel Time Calculation

**Input Data:**
```c
Train train1 = {101, "Минск", "10:30", "08:00", 350, 12, "купейный", 36};
int travel_time = calculateTravelTime(&train1);
```

**Expected Result:** travel_time = 2 hours (10:30 - 08:00)

**Actual Result:**
- Travel time = 2 hours

**Result:** ✅ PASSED

---

### Test 1.3: Long Trips (>24 hours)

**Input Data:**
```c
Train train3 = {303, "Владивосток", "14:20", "05:10", 1200, 15, "купейный", 36};
int travel_time = calculateTravelTime(&train3);
```

**Expected Result:** travel_time = 33 hours (14:20 next day - 05:10)

**Actual Result:**
```
--- Trains with travel time > 24 hours ---
Train 303: 05:10 -> 14:20, travel time: 33 hours
```

**Result:** ✅ PASSED

---

### Test 1.4: Compartment Passengers Calculation

**Input Data:**
```c
Train trains[3] = {
    {101, "Минск", "10:30", "08:00", 350, 12, "купейный", 36},
    {202, "Гродно", "18:45", "06:15", 420, 8, "плацкарт", 54},
    {303, "Владивосток", "14:20", "05:10", 1200, 15, "купейный", 36}
};
int total = totalCompartmentPassengers(trains, 3);
```

**Expected Result:** 
- Train 101: 12 × 36 = 432
- Train 303: 15 × 36 = 540
- Total = 432 + 540 = 972

**Actual Result:** 
```
Total passengers in compartment wagons: 972
```

**Result:** ✅ PASSED

---

### Test 1.5: Trains to Grodno Filter

**Input Data:**
```c
Train trains[5] = {
    {101, "Минск", "10:30", "08:00", 350, 12, "купейный", 36},
    {202, "Гродно", "18:45", "06:15", 420, 8, "плацкарт", 54},
    {303, "Владивосток", "14:20", "05:10", 1200, 15, "купейный", 36},
    {404, "Брест", "22:15", "20:30", 200, 10, "люкс", 24},
    {505, "Гродно", "09:50", "23:40", 420, 9, "плацкарт", 54}
};
printTrainsToGrodno(trains, 5);
```

**Expected Result:** Two trains to Grodno (202 and 505)

**Actual Result:**
```
--- Trains to Grodno ---
Train 202, arrival: 18:45
Train 505, arrival: 09:50
```

**Result:** ✅ PASSED

---

### Test 1.6: Train with Maximum Wagons

**Input Data:** Same trains array as above

**Expected Result:** Train 303 with 15 wagons

**Actual Result:**
```
--- Train with maximum wagons (15) ---
=== Train Information ===
Train number: 303
Destination: Владивосток
Arrival time: 14:20
Departure time: 05:10
Distance: 1200 km
Wagons: 15
Wagon type: купейный
Passengers per wagon: 36
Total passengers: 540
```

**Result:** ✅ PASSED

---

## TEST GROUP 2: SOFTWARE Structure Tests

### Test 2.1: Software Initialization

**Input Data:**
```c
Software soft1;
initSoftware(&soft1, "Photoshop", "Adobe", 2022, 24.5, 4, 1500);
```

**Expected Result:**
- name = "Photoshop"
- company = "Adobe"
- release_year = 2022
- version = 24.5
- support_period = 4
- price = 1500

**Actual Result:**
```
=== Software Information ===
Name: Photoshop
Company: Adobe
Release year: 2022
Version: 24.5
Support period: 4 years
Price: 1500.00 RUB
```

**Result:** ✅ PASSED

---

### Test 2.2: Expensive Software Filter (price > 200, support > 3)

**Input Data:**
```c
Software soft[5] = {
    {"Photoshop", "Adobe", 2022, 24.5, 4, 1500},
    {"WinRAR", "Rarlab", 2021, 6.1, 5, 250},
    {"Notepad", "Microsoft", 2023, 11.0, 2, 0},
    {"Visual Studio", "Microsoft", 2022, 17.0, 3, 0},
    {"AutoCAD", "Autodesk", 2021, 2024.0, 4, 1200}
};
printExpensiveSoftware(soft, 5);
```

**Expected Result:** Should match: Photoshop, WinRAR, AutoCAD (Notepad and VS are free or support ≤3)

**Actual Result:**
```
--- Software > 200 RUB and support > 3 years ---
Photoshop (v24.5) by Adobe - 1500.00 RUB, support: 4 years
WinRAR (v6.1) by Rarlab - 250.00 RUB, support: 5 years
AutoCAD (v2024.0) by Autodesk - 1200.00 RUB, support: 4 years
```

**Result:** ✅ PASSED

---

### Test 2.3: Software by Company Filter

**Input Data:**
```c
printSoftwareByCompany(soft, 5, "Microsoft");
```

**Expected Result:** Notepad and Visual Studio

**Actual Result:**
```
--- Software by Microsoft ---
Notepad (v11.0) - 0.00 RUB
Visual Studio (v17.0) - 0.00 RUB
```

**Result:** ✅ PASSED

---

### Test 2.4: Edge Case - No Software by Company

**Input Data:**
```c
printSoftwareByCompany(soft, 5, "Google");
```

**Expected Result:** "No software by Google"

**Actual Result:**
```
--- Software by Google ---
No software by Google
```

**Result:** ✅ PASSED

---

## TEST GROUP 3: Full Program Integration Test

### Test 3.1: Complete Program Execution

**Command:**
```bash
make clean && make && make run
```

**Full Output:**
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

=== Train Information ===
Train number: 202
Destination: Гродно
Arrival time: 18:45
Departure time: 06:15
Distance: 420 km
Wagons: 8
Wagon type: плацкарт
Passengers per wagon: 54
Total passengers: 432

=== Train Information ===
Train number: 303
Destination: Владивосток
Arrival time: 14:20
Departure time: 05:10
Distance: 1200 km
Wagons: 15
Wagon type: купейный
Passengers per wagon: 36
Total passengers: 540

=== Train Information ===
Train number: 404
Destination: Брест
Arrival time: 22:15
Departure time: 20:30
Distance: 200 km
Wagons: 10
Wagon type: люкс
Passengers per wagon: 24
Total passengers: 240

=== Train Information ===
Train number: 505
Destination: Гродно
Arrival time: 09:50
Departure time: 23:40
Distance: 420 km
Wagons: 9
Wagon type: плацкарт
Passengers per wagon: 54
Total passengers: 486

--- Trains with travel time > 24 hours ---
Train 303: 05:10 -> 14:20, travel time: 33 hours

Total passengers in compartment wagons: 972

--- Trains to Grodno ---
Train 202, arrival: 18:45
Train 505, arrival: 09:50

--- Train with maximum wagons (15) ---
=== Train Information ===
Train number: 303
Destination: Владивосток
Arrival time: 14:20
Departure time: 05:10
Distance: 1200 km
Wagons: 15
Wagon type: купейный
Passengers per wagon: 36
Total passengers: 540

========== TASK 4: SOFTWARE STRUCTURE ==========

=== Software Information ===
Name: Photoshop
Company: Adobe
Release year: 2022
Version: 24.5
Support period: 4 years
Price: 1500.00 RUB

=== Software Information ===
Name: WinRAR
Company: Rarlab
Release year: 2021
Version: 6.1
Support period: 5 years
Price: 250.00 RUB

=== Software Information ===
Name: Notepad
Company: Microsoft
Release year: 2023
Version: 11.0
Support period: 2 years
Price: 0.00 RUB

=== Software Information ===
Name: Visual Studio
Company: Microsoft
Release year: 2022
Version: 17.0
Support period: 3 years
Price: 0.00 RUB

=== Software Information ===
Name: AutoCAD
Company: Autodesk
Release year: 2021
Version: 2024.0
Support period: 4 years
Price: 1200.00 RUB

--- Software > 200 RUB and support > 3 years ---
Photoshop (v24.5) by Adobe - 1500.00 RUB, support: 4 years
WinRAR (v6.1) by Rarlab - 250.00 RUB, support: 5 years
AutoCAD (v2024.0) by Autodesk - 1200.00 RUB, support: 4 years

--- Software by Microsoft ---
Notepad (v11.0) - 0.00 RUB
Visual Studio (v17.0) - 0.00 RUB

✅ Program completed successfully
```

**Result:** ✅ PASSED - All functions working correctly

---

## TEST GROUP 4: GitHub Actions CI/CD Tests

### Test 4.1: Build Pipeline

**GitHub Actions Workflow:** `.github/workflows/ci.yml`

| Step | Status | Duration |
|------|--------|----------|
| Checkout repository | ✅ PASSED | 2s |
| Install dependencies | ✅ PASSED | 5s |
| Build with Make | ✅ PASSED | 3s |
| Run the program | ✅ PASSED | 1s |
| Clean build | ✅ PASSED | 1s |

**GitHub Actions Status:** ✅ All checks passed

---

## KIS-2 Model Verification

| Component | File | Status |
|-----------|------|--------|
| **Interface (Train)** | `src/include/train.h` | ✅ Correct |
| **Interface (Software)** | `src/include/software.h` | ✅ Correct |
| **Kernel (Train)** | `src/server/train_operations.c` | ✅ Correct |
| **Kernel (Software)** | `src/server/software_operations.c` | ✅ Correct |
| **Client** | `src/client/main.c` | ✅ Correct |

---

## Test Summary

| Test Group | Tests Run | Passed | Failed |
|------------|-----------|--------|--------|
| TRAIN Structure Tests | 6 | 6 | 0 |
| SOFTWARE Structure Tests | 4 | 4 | 0 |
| Integration Tests | 1 | 1 | 0 |
| GitHub Actions | 1 | 1 | 0 |
| **TOTAL** | **12** | **12** | **0** |

**Success Rate:** 100% ✅

---

## Conclusion

All tests have been successfully completed. The program works correctly according to variant 22 requirements:

### Task 3 (TRAIN Structure) - ✅ COMPLETE
- [x] Train initialization
- [x] Travel time calculation
- [x] Long trips (>24 hours) detection
- [x] Compartment passengers calculation
- [x] Trains to Grodno filtering
- [x] Maximum wagons train detection

### Task 4 (SOFTWARE Structure) - ✅ COMPLETE
- [x] Software initialization
- [x] Expensive software filtering (>200 RUB, support >3 years)
- [x] Software by company filtering
- [x] Edge cases handling

### Architecture - ✅ COMPLETE
- [x] KIS-2 model (Interface/Kernel/Client)
- [x] Makefile build automation
- [x] GitHub Actions CI/CD
- [x] Coding standards compliance

**Date:** March 9, 2026  
**Signature:** _________________________  
**Vadim Tyushko**