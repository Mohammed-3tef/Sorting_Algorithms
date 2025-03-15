/*
 * Authors:
    * Author1: Esraa Emary Abd El-Salam          ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader        ID: 20231143
    * Author3: Mariam Badr Yehia                 ID: 20230391
    * Author4: John Ayman Demian                 ID: 20230109
    * Author5: George Malak Magdy                ID: 20231042

 * Description: This is a program that manages "Iftar Invitations" which makes you add a guest,
             display it and edit the date of invitation.

 * Date: ? / 3 / 2025
 * Prof: Dr. Besheer

 * Version: V1.0
*/

// < ========================================================================================== >

#include <bits/stdc++.h>
#include <regex>

using namespace std;

bool isInteger(string str) {
    if (str.empty()) return false;
    if (str[0] == '-') str = str.substr(1);

    for (int i = 0; i < str.length(); i++) {
        if (!isdigit(str[i])) return false;
    }

    return true;
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
        if constexpr (is_same<T, string>::value) {                             // handle if the type of data is strings.
            getline(cin, element);
            while (element.empty()) {
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
                getline(cin, element);
            }
            data[i - 1] = element;
        } else if constexpr (is_same<T, char>::value) {                           // handle if the type of data is char.
            getline(cin, element);
            while (element.empty()) {
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
                getline(cin, element);
            }
            data[i - 1] = element[0];
        } else if constexpr (is_same<T, double>::value || is_same<T, float>::value) {        // handle float and double.
            regex pattern(R"(^-?\d+(\.\d+)?$)");
            while (true) {
                getline(cin, element);
                if (regex_match(element, pattern)) {
                    data[i - 1] = stod(element);
                    break;
                }
                cout << "Invalid Input!\n";
                cout << "\nEnter element " << i << ":";
            }
        } else {                                                                                 // handle int and long.
            regex pattern(R"(^-?\d+$)");
            while (true) {
                getline(cin, element);
                if (regex_match(element, pattern)) {
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
        T tmp = data[i];
        for (j = i; j > 0 && tmp < data[j - 1]; j--) data[j] = data[j - 1];
        data[j] = tmp;
    }

    for (int i = 0; i < this->size; ++i) {
        cout << data[i] << " ";
    }
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

}

// --------------------- MEASURE SORT TIME

template<typename T>
void SortingSystem<T>::measureSortTime(void(SortingSystem<T>::*sortFunc)()) {
    (this->*sortFunc)();
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
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }

        if (choice == "1")
            insertionSort();
        else if (choice == "2")
            selectionSort();
        else if (choice == "3")
            bubbleSort();
        else if (choice == "4")
            shellSort();
        else if (choice == "5")
            mergeSort();
        else if (choice == "6")
            quickSort();
        else if (choice == "7")
            countSort();
        else if (choice == "8")
            radixSort();
        else if (choice == "9")
            bucketSort();
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