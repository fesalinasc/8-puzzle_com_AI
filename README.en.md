# 🧩 8-Puzzle in C with Artificial Intelligence

This project implements the classic **8-Puzzle**, where the goal is to arrange the numbers from **1 to 8** in ascending order, leaving an empty space (**0**) in the last position.

The project was entirely developed in **C** and allows for both **manual gameplay** and **automatic resolution using search algorithms (AI)**.

---

## 🎮 Execution Modes

Upon starting the program, the user can choose between:

1. 🎲 **Play manually**
2. 🤖 **Breadth-First Search (BFS)**
3. 🧠 **Depth-First Search (DFS)**
4. ❌ **Exit**

---

## 🚀 Features

* 🔄 Automatic generation of **always solvable** boards
* 🎹 Manual movement of pieces by the user
* 🤖 Automatic resolution using:

* **Breadth-First Search (BFS)**
* **Depth-First Search**
* 🧠 Reconstruction and printing of the **solution path**
* 📊 Counter of **visited states**
* 🖥️ Simple interface via **Console**
* 📚 Use of **Data Structures**:

* Stack

* Queue

* Implicit State Trees

---

## 🧠 Algorithms Used

### 🔹 Breadth-First Search (BFS)

* Guarantees finding the **shortest solution**
* Explores all states level by level
* Uses a **queue** to control the nodes

### 🔹 Depth-Limited Search

* Explores paths in depth up to a **defined limit**
* Uses a **stack**
* Avoids loops through depth control

---

## 📂 Project Structure

```

📦 8-puzzle-c
├── main.c # Contains the entire game implementation, structures, and search algorithms
└── README.md # Documentation Project


---

## ▶️ How to Compile and Run

### 1️⃣ Compile

```bash
gcc main.c -o puzzle

```

### 2️⃣ Run

```bash
./puzzle
```

> ⚠️ **Note**
> The code uses `system("cls")`, which works on **Windows**.

> On Linux or macOS, replace with:

>
> ```c
> system("clear");

> ```

---

## 🎮 Controls (Manual Mode)

Enter the **number of the piece** you want to move (as long as it's adjacent to the empty space).

Example of expected final state:

```
1 2 3
4 5 6
7 8 _
```

---

## 🧩 Main Data Structures

### 🔹 `Node` Structure

Represents a state of the puzzle:

* 3x3 matrix of the board
* Pointer to the parent (path reconstruction)
* Node depth
* Pointer to the next node

### 🔹 Stack

Used in **Depth-Limited Search**

### 🔹 Queue

Used in **Breadth-First Search**

---

## 🛠️ Main Functions

* `generate_initial_puzzle()` – generates a solvable random puzzle
* `print_puzzle()` – prints the board to the console
* `suc_function()` – generates states Successors
* `breadth_first_search()` – solves using BFS
* `depth-limited_search()` – solves using DFS limited
* `print_path()` – displays the step-by-step solution
* `complete()` – checks if the puzzle is solved

---

## 🏁 Completion

When the puzzle is solved, the program displays:

* Number of states visited
* Complete step-by-step solution
* Success message 🎉

---

## 👤 Author

**Felipe Salinas Caodaglio**
