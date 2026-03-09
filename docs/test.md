# Test Report - Laboratory Work #2 (Variant 22)



## Project Information

- **Student:** Vadim Tyushko

- **Group:** PI-12

- **Repository:** tpmp-lab2-task3



---



## Test 1: Student Structure Initialization



**Input Data:**

```c

Student student1;

initStudent(&student1, "Ivan Petrov", 19, 8.5, 2, "PI-23-1");

```



**Expected Result:**

- name = "Ivan Petrov"

- age = 19

- average_grade = 8.5

- course = 2

- group = "PI-23-1"



**Actual Result:**

```

=== Student Information ===

Name: Ivan Petrov

Age: 19

Average Grade: 8.50

Course: 2

Group: PI-23-1

============================

```



**Result:** ✅ PASSED



---



## Test 2: Random Grades Generation and Average Calculation



**Input Data:**

```c

int grades[5] = {8, 9, 7, 10, 8};

float avg = calculateAverageGrade(&student1, grades, 5);

```



**Expected Result:** Average grade = 8.4



**Actual Result:**

```

Grades: 8 9 7 10 8

Calculated average grade: 8.40

```



**Result:** ✅ PASSED



---



## Test 3: Student Information Update



**Input Data:**

```c

updateStudentInfo(&student1, 9.2, 3);

```



**Expected Result:**

- average_grade = 9.2

- course = 3



**Actual Result:**

```

✅ Student information updated

=== Student Information ===

Name: Ivan Petrov

Age: 19

Average Grade: 9.20

Course: 3

Group: PI-23-1

============================

```



**Result:** ✅ PASSED



---



## Test 4: Array of Students



**Input Data:**

```c

Student group[3];

initStudent(&group[0], "Anna Smirnova", 18, 9.1, 1, "PI-23-2");

initStudent(&group[1], "Petr Sidorov", 20, 7.8, 3, "PI-23-1");

initStudent(&group[2], "Maria Ivanova", 19, 8.9, 2, "PI-23-3");

```



**Actual Result:**

```

📋 Array of students:



Student 1:

=== Student Information ===

Name: Anna Smirnova

Age: 18

Average Grade: 9.10

Course: 1

Group: PI-23-2

============================



Student 2:

=== Student Information ===

Name: Petr Sidorov

Age: 20

Average Grade: 7.80

Course: 3

Group: PI-23-1

============================



Student 3:

=== Student Information ===

Name: Maria Ivanova

Age: 19

Average Grade: 8.90

Course: 2

Group: PI-23-3

============================

```



**Result:** ✅ PASSED



---



## Test 5: Full Program Output



**Complete Program Execution:**

```

========================================

Laboratory Work #2

Variant 22: Working with Structures

Author: Vadim Tyushko

Group: PI-23-1

KIS-2 Model: Interface/Server/Client

========================================



=== Student Information ===

Name: Ivan Petrov

Age: 19

Average Grade: 8.50

Course: 2

Group: PI-23-1

============================

Grades: 8 9 7 10 8

Calculated average grade: 8.40



📝 Updating information...

✅ Student information updated

=== Student Information ===

Name: Ivan Petrov

Age: 19

Average Grade: 9.20

Course: 3

Group: PI-23-1

============================



📋 Array of students:



Student 1:

=== Student Information ===

Name: Anna Smirnova

Age: 18

Average Grade: 9.10

Course: 1

Group: PI-23-2

============================



Student 2:

=== Student Information ===

Name: Petr Sidorov

Age: 20

Average Grade: 7.80

Course: 3

Group: PI-23-1

============================



Student 3:

=== Student Information ===

Name: Maria Ivanova

Age: 19

Average Grade: 8.90

Course: 2

Group: PI-23-3

============================



✅ Program completed successfully

```



**Result:** ✅ PASSED



---



## Test 6: GitHub Actions Build



**CI/CD Pipeline Results:**



| Step | Status |

|------|--------|

| Checkout repository | ✅ PASSED |

| Install dependencies | ✅ PASSED |

| Build with Make | ✅ PASSED |

| Run the program | ✅ PASSED |

| Clean build | ✅ PASSED |



**GitHub Actions Status:** ✅ All checks passed



---



## KIS-2 Model Verification



| Component | File | Status |

|-----------|------|--------|

| **Interface** | `src/include/student.h` | ✅ Correct |

| **Server** | `src/server/student_operations.c` | ✅ Correct |

| **Client** | `src/client/main.c` | ✅ Correct |



---



## Conclusion



All tests have been successfully completed. The program works correctly according to variant 22 requirements:



1. ✅ Student structure initialization

2. ✅ Average grade calculation

3. ✅ Student information update

4. ✅ Array of structures

5. ✅ Full program execution

6. ✅ GitHub Actions CI/CD pipeline

7. ✅ KIS-2 model implementation



**Date:** March 9, 2026  

**Signature:** Vadim Tyushko

