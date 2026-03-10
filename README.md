[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/pdil6WiN)
# Shortest Remaining Time First (SRTF) CPU Scheduling — C Implementation

## 🎯 Objective

To implement the **Shortest Remaining Time First (SRTF)** CPU Scheduling algorithm using the C programming language.

SRTF is the **preemptive version of Shortest Job First (SJF)** scheduling.

At every unit of time, the process with the **smallest remaining burst time** is selected for execution.

---

## 📥 Input Format

```
n
PID AT BT
PID AT BT
...
```

### Where:

* **n** → Number of processes
* **PID** → Process ID
* **AT** → Arrival Time
* **BT** → Burst Time

---

## 📤 Output Format

The program must display:

```
Waiting Time:
PID WT
...

Turnaround Time:
PID TAT
...

Average Waiting Time: X.X
Average Turnaround Time: X.X
```

---

## 🧮 Formulas Used

### Turnaround Time

```
TAT = Completion Time − Arrival Time
```

### Waiting Time

```
WT = Turnaround Time − Burst Time
```

---

## ⚙️ Algorithm Steps

1. Read number of processes
2. Store process details (PID, AT, BT)
3. Remaining Time (RT) = Burst Time
4. Start time = 0
5. Repeat until all processes complete:

   * Select process with:

     * Arrival Time ≤ Current Time
     * Smallest Remaining Time
   * Execute for 1 time unit
   * Decrease remaining time
   * If remaining time becomes 0:

     * Record Completion Time
6. Compute:

   * Turnaround Time
   * Waiting Time
   * Averages
7. Print results

---

## ▶️ Compilation & Execution

### Compile

```
gcc srtf.c -o srtf
```

### Run

```
./srtf
```

---

## 🗂️ Files in Repository

```
srtf.c              → C program implementation
autograding.json    → GitHub Classroom test configuration
run.sh              → Compile & run script
README.md           → Assignment description
```

---

## 🧪 Test Cases

This assignment includes **5 test cases** for evaluation.

Each test checks:

* Scheduling correctness
* Waiting time calculation
* Turnaround time calculation
* Average values
* Output format accuracy

---

## ⚠️ Important Notes

* This is a **preemptive scheduling algorithm**
* Always choose process with **smallest remaining time**
* CPU may be idle if no process has arrived
* Print averages to **1 decimal place**
* Output must match format exactly
* Extra spaces or blank lines may fail autograding

---

## 📊 Example

### Input

```
5
P1 2 6
P2 5 2
P3 1 8
P4 0 3
P5 4 4
```

### Output

```
Waiting Time:
P1 7
P2 0
P3 14
P4 0
P5 2
Turnaround Time:
P1 13
P2 2
P3 22
P4 3
P5 6
Average Waiting Time: 4.6
Average Turnaround Time: 9.2
```

---

## 🧑‍🏫 Evaluation Scheme

| Component            | Marks   |
| -------------------- | ------- |
| Logic & Scheduling   | 40      |
| Correct Calculations | 30      |
| Output Format        | 20      |
| Passing Test Cases   | 10      |
| **Total**            | **100** |

---

## 🎓 Academic Integrity

* Submit your own work
* Do not copy from others
* Plagiarism detection may be used
