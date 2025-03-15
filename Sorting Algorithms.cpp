/*
 * Authors:
    * Author1: Esraa Emary Abd El-Salam          ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader        ID: 20231143
    * Author3: Mariam Badr Yehia                 ID: 20230391
    * Author4: John Ayman Demian                 ID: 20230109
    * Author5: George Malak Magdy                ID: 20231042

 * Description: The Sorting System is designed to help sort dynamically allocated data using nine different sorting algorithms.
                It provides an interactive menu for selecting a sorting method, supports various data types using templates,
                and displays each sorting step for better understanding.

 * Date: ? / 3 / 2025
 * Prof: Dr. Besheer

 * Version: V1.0
*/
// < ========================================================================================== >

#include <bits/stdc++.h>
using namespace std;

bool isInteger(const string& str) {
    static const regex integerPattern(R"(^-?\d+$)");
    return regex_match(str, integerPattern);
}

bool isFloat(const string& str) {
    static const regex floatPattern(R"(^-?\d+(\.\d+)?$)");
    return regex_match(str, floatPattern);
}

// ----------------------------------------------- CLASS DEFINITION

template<typename T>
class SortingSystem {
    T *data;
    int size;
public:
    SortingSystem(int n);
    ~SortingSystem();

    void inputData();
    void insertionSort();
    void selectionSort();
    void bubbleSort();
    void shellSort();
    void mergeSort();
    void quickSort();
    void countSort();
    void radixSort();
    void bucketSort();

    void merge(int left, int mid, int right);
    int partition(int low, int high);

    void displayData();
    void measureSortTime(void (SortingSystem<T>::*sortFunc)());
    void showMenu();
};

// ----------------------------------------------- CLASS IMPLEMENTATION
// --------------------- CONSTRUCTOR & DESTRUCTOR
template<typename T>
SortingSystem<T>::SortingSystem(int n) : size(n) {
    data = new T[size];
    inputData();
}

template<typename T>
void SortingSystem<T>::inputData() {
    for (int i = 1; i <= this->size; ++i) {
        cout << "Enter element " << i << ":";
        string element;

        // Handle if the type of data is strings.
        if constexpr (is_same<T, string>::value) {
            getline(cin, element);
            while (element.empty()) {
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
                getline(cin, element);
            }
            data[i - 1] = element;
        }

        // Handle if the type of data is char.
        else if constexpr (is_same<T, char>::value) {
            getline(cin, element);
            while (element.empty()) {
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
                getline(cin, element);
            }
            data[i - 1] = element[0];
        }

        // Handle float and double.
        else if constexpr (is_same<T, double>::value || is_same<T, float>::value) {
            while (true) {
                getline(cin, element);
                if (isFloat(element)) {
                    data[i - 1] = stod(element);
                    break;
                }
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
            }
        }

        // Handle int and long.
        else {
            while (true) {
                getline(cin, element);
                if (isInteger(element)) {
                    data[i - 1] = stoll(element);
                    break;
                }
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
            }
        }
    }
    cout << endl;
}

template<typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

// --------------------- INSERTION SORT

template<typename T>
void SortingSystem<T>::insertionSort() {
    for (int i = 1, j; i < this->size; i++) {
        T temp = data[i];
        for (j = i; j > 0 && temp < data[j - 1]; j--)
            data[j] = data[j - 1];
        data[j] = temp;
    }

    cout << "Sorted Data: ";
    displayData();
}

// --------------------- SELECTION SORT

template<typename T>
void SortingSystem<T>::selectionSort() {

}

// --------------------- BUBBLE SORT

template<typename T>
void SortingSystem<T>::bubbleSort() {

}

// --------------------- SHELL SORT

template<typename T>
void SortingSystem<T>::shellSort() {

}

// --------------------- MERGE SORT

template<typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

}

template<typename T>
void SortingSystem<T>::mergeSort() {

}

// --------------------- QUICK SORT

template<typename T>
int SortingSystem<T>::partition(int low, int high) {

}

template<typename T>
void SortingSystem<T>::quickSort() {

}

// --------------------- COUNT SORT

template<typename T>
void SortingSystem<T>::countSort() {

}

// --------------------- RADIX SORT

template<typename T>
void SortingSystem<T>::radixSort() {

}

// --------------------- BUCKET SORT

template<typename T>
void SortingSystem<T>::bucketSort() {

}

// --------------------- DISPLAY DATA

template<typename T>
void SortingSystem<T>::displayData() {
    cout << "[";
    for (int i = 0; i < this->size; ++i) {
        if (i != this->size -1) cout << data[i] << ", ";
        else cout << data[i];
    }
    cout << "]" << endl;
}

// --------------------- MEASURE SORT TIME

template<typename T>
void SortingSystem<T>::measureSortTime(void(SortingSystem<T>::*sortFunc)()) {
    using Clock = chrono::high_resolution_clock;

    auto startTime = Clock::now();     // Start Time Point.
    (this->*sortFunc)();                 // Call the function without parameters
    auto endTime = Clock::now();       // End Time Point.

    chrono::duration<double> duration = endTime - startTime;
    cout << "Sorting time: " << duration.count() << " seconds." << endl << endl;
}

// --------------------- SHOW MENU

template<typename T>
void SortingSystem<T>::showMenu() {
    while (true) {
        cout << "Select a sorting algorithm:" << endl;
        cout << "1. Insertion Sort." << endl;
        cout << "2. Selection Sort." << endl;
        cout << "3. Bubble Sort." << endl;
        cout << "4. Shell Sort." << endl;
        cout << "5. Merge Sort." << endl;
        cout << "6. Quick Sort." << endl;
        cout << "7. Count Sort (only for integers)." << endl;
        cout << "8. Radix Sort (only for integers)." << endl;
        cout << "9. Bucket Sort." << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice (0 - 9):";
        string choice;
        getline(cin, choice);

        if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" &&
            choice != "7" && choice != "8" && choice != "9" && choice != "0") {
            cout << "Invalid choice. Please try again." << endl << endl;
            continue;
        }

        if (choice != "0"){
            cout << "Initial Data: ";
            displayData();
        }

        if (choice == "1")
            measureSortTime(&SortingSystem::insertionSort);
        else if (choice == "2")
            measureSortTime(&SortingSystem::selectionSort);
        else if (choice == "3")
            measureSortTime(&SortingSystem::bubbleSort);
        else if (choice == "4")
            measureSortTime(&SortingSystem::shellSort);
        else if (choice == "5")
            measureSortTime(&SortingSystem::mergeSort);
        else if (choice == "6")
            measureSortTime(&SortingSystem::quickSort);
        else if (choice == "7")
            measureSortTime(&SortingSystem::countSort);
        else if (choice == "8")
            measureSortTime(&SortingSystem::radixSort);
        else if (choice == "9")
            measureSortTime(&SortingSystem::bucketSort);
        else if (choice == "0")
            return;
    }
}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR SORTING SYSTEM -------------\n" << endl;

    while (true) {
        cout << "Enter the number of elements:";
        string numberOfElements;
        getline(cin, numberOfElements);
        if (!isInteger(numberOfElements) || stoi(numberOfElements) <= 0) {
            cout << "Invalid input. Please enter a valid number." << endl;
            continue;
        }

        SortingSystem<string> sortingSystem(stoi(numberOfElements));
        sortingSystem.showMenu();

        string choice;
        while (true) {
            cout << "Do you want to continue? (y/n):";
            getline(cin, choice);

            if (choice == "Y" || choice == "y" || choice == "N" || choice == "n") break;
            else cout << "Invalid choice. Please try again." << endl;
        }

        if (choice == "N" || choice == "n") {
            cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
            return 0;
        }
    }
}