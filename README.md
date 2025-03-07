# Sorting_Algorithms

## 📌 Problem Statement
The **Sorting System** is designed to help users sort dynamically allocated data using **nine different sorting algorithms**. It provides an **interactive menu** for selecting a sorting method, supports **various data types using templates**, and **displays each sorting step** for better understanding. Additionally, it **measures execution time** to analyze efficiency.

---

## ⚙️ Features & Requirements

### 📍 1. Sorting Algorithms Implemented
- ✅ **Insertion Sort**
- ✅ **Selection Sort**
- ✅ **Bubble Sort**
- ✅ **Shell Sort**
- ✅ **Merge Sort**
- ✅ **Quick Sort**
- ✅ **Count Sort** *(Only for integers)*
- ✅ **Radix Sort** *(Only for integers)*
- ✅ **Bucket Sort**

### 📍 2. Interactive Menu
- The program displays a **menu** listing all **nine sorting algorithms**.
- Users can **select a sorting method** by entering a number **from 1 to 9**.
- Users **define the dataset size** and **input values dynamically**.

### 📍 3. Template-Based Implementation
- Sorting algorithms are implemented using **templates (T)**.
- Supports **multiple data types**: `int`, `float`, `double`, `string`, etc.

### 📍 4. Sorting Process Display
- After **every iteration**, the **current state of the array** is printed.
- For **Quick Sort**, an example visualization:
  ```
  Data: 78 34 12 90 50 60
  Pivot: 60 → [34, 12, 50]  60  [78, 90]
  Pivot: 12 → [12]  34  50  60  [78, 90]
  Pivot: 90 → [78]  90
  ```

### 📍 5. Performance Tracking
- The program **measures and displays execution time** for each sorting algorithm.

### 📍 6. Test Cases
- Includes **test cases** for each part of the problem to validate correctness.

---

## 📖 Example Usage
```sh
Welcome to Sorting System
Select Sorting Algorithm:
1. Insertion Sort
2. Selection Sort
3. Bubble Sort
...
Enter your choice: 5
Enter dataset size: 6
Enter elements: 78 34 12 90 50 60
Sorting Steps:
...
Execution Time: X ms
```

---

## 👨‍💻 Contributing
Contributions are welcome! Feel free to fork the repo and submit a pull request.

## ✍️ Authors
- Esraa Emary Abd El-Salam: [GitHub](https://github.com/esraa-emary) - [LinkedIn](https://www.linkedin.com/in/esraa-emary-b372b8303/)
- Mariam Badr Yehia: [GitHub](https://github.com/Mariam-Badr-MB) - [LinkedIn](https://www.linkedin.com/in/mariambadr13/)
- George Malak Magdy:  [GitHub](https://github.com/GeorgeMalakM) - [LinkedIn](https://www.linkedin.com/in/george-malak204/)
- John Ayman Demian:  [GitHub](https://github.com/Johnayman1) - [LinkedIn]()
- Mohammed Atef Abd El-Kader: [GitHub](https://github.com/Mohammed-3tef) - [LinkedIn](https://www.linkedin.com/in/mohammed-atef-b0a408299/)

## 📜 License
This project is licensed under the MIT License.

---
✨ **Developed with ❤️ in C++** ✨
