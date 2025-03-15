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

bool isInteger(const string &str) {
    static const regex integerPattern(R"(^-?\d+$)");
    return regex_match(str, integerPattern);
}

bool isFloat(const string &str) {
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

    void mergeSortHelper(int left, int right) ;

    int partition(int low,   int high);

    void recQuickSort( int first,  int last);

    void displayData();

    void measureSortTime(void (SortingSystem<T>::*sortFunc)());

    void showMenu();
};

// ----------------------------------------------- CLASS IMPLEMENTATION

// --------------------- CONSTRUCTOR & DESTRUCTOR
template<typename T>
SortingSystem<T>::SortingSystem(const int n) : size(n) {
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
    cout << "\nSorting using Selection Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    for (int i = 1, j; i < this->size; i++) {
        T temp = data[i];
        for (j = i; j > 0 && temp < data[j - 1]; j--)
            data[j] = data[j - 1];
        data[j] = temp;

        if (i < this->size - 1) {
            cout << "Iteration " << i << " : ";
            displayData();
        }
    }

    cout << "Sorted Data: ";
    displayData();
}

// --------------------- SELECTION SORT

template<typename T>
void SortingSystem<T>::selectionSort() {
    for (int i = 0; i < (this->size - 1); ++i) {
        int Least_Element = i;
        for (int j = (i + 1); j < this->size; ++j) {
            if (this->data[j] < this->data[Least_Element]) {
                Least_Element = j;
            }
        }
        swap(this->data[i], this->data[Least_Element]);
    }
}

// --------------------- BUBBLE SORT

template<typename T>
void SortingSystem<T>::bubbleSort() {
    long long num_iteration = 1 ;
    for (int i = 0; i < this->size; i++) {
        for (int j = this->size - 1 ; j > i; --j) {
            if (data[j-1] > data[j]) {
                swap(data[j-1], data[j]);
                cout << "Iteration " << num_iteration << " : " ;
                displayData();
                cout << endl;
                num_iteration++;
            }
        }
    }
    cout << "Sorted Data: " ;
    displayData();
    cout << endl;
}

// --------------------- SHELL SORT

template<typename T>
void SortingSystem<T>::shellSort() {

}

// --------------------- MERGE SORT
int iteration = 0 ;
template<typename T>
void SortingSystem<T>::merge(const int left, const int mid, const int right) {
        const int n1 = mid - left + 1;
        const int n2 = right - mid;

        T* left_data = new T[n1];
        T* right_data = new T[n2];

        for (int i = 0; i < n1; i++)
            left_data[i] = data[left + i];
        for (int i = 0; i < n2; i++)
            right_data[i] = data[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (left_data[i] <= right_data[j]) {
                data[k] = left_data[i];
                i++;
            } else {
                data[k] = right_data[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            data[k] = left_data[i];
            i++; k++;
        }

        while (j < n2) {
            data[k] = right_data[j];
            j++; k++;
        }

        // Print the current state of the data after iteration of merge sort
        iteration++;
        cout << "Iteration " << iteration << " : ";
        displayData() ;
        cout << endl;

        // Free temporary data arrays
        delete[] left_data;
        delete[] right_data;
    }

template<typename T>
void SortingSystem<T>::mergeSortHelper(const int left, const int right) {
        if (left < right) {
            const int mid = left + (right - left) / 2;
            mergeSortHelper(left, mid);      // Sort left half
            mergeSortHelper(mid + 1, right); // Sort right half
            merge(left, mid, right);         // Merge the two halves
        }
    }
template<typename T>
void SortingSystem<T>:: mergeSort() {

    mergeSortHelper(0, size - 1);

    cout << "Sorted Data: "  ;
    displayData() ;
    cout << endl;

}

// --------------------- Quick SORT
template<typename T>
int SortingSystem<T>::partition(int low, const int high) {
    swap(data[low], data[(low + high) / 2]);
    T pivot = data[low];
    int smallIndex = low;

    for (int index = low + 1; index <= high; index++) {
        if (data[index] < pivot) {
            smallIndex++;
            swap(data[smallIndex], data[index]);
        }
    }

    swap(data[low], data[smallIndex]);

    // Print the current partition
    cout << "Pivot: " << pivot << " --> [";
    for (int i = low; i < smallIndex; i++) {
        cout << data[i];
        if (i < smallIndex - 1) cout << ", ";
    }
    cout << "]  " << pivot << "  [";
    for (int i = smallIndex + 1; i <= high; i++) {
        cout << data[i];
        if (i < high) cout << ", ";
    }
    cout << "]" << endl;

    return smallIndex;
}
template<typename T>
void SortingSystem<T>::recQuickSort(const int first, const int last) {
    if (first < last) {
        int pivotLocation = partition(first, last);
        recQuickSort(first, pivotLocation - 1);
        recQuickSort(pivotLocation + 1, last);
    }
}
template<typename T>
void SortingSystem<T>::quickSort() {

    recQuickSort(0, this->size - 1);

    cout << "Sorted Data: ";
     displayData();
    cout << endl;
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
        if (i != this->size - 1) cout << data[i] << ", ";
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
            choice = (choice);
            if (choice == "Y" || choice == "y" || choice == "N" || choice == "n") break;
            else cout << "Invalid choice. Please try again." << endl;
        }

        if (choice == "N" || choice == "n") {
            cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
            return 0;
        }
    }
}