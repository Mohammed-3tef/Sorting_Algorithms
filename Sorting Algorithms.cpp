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

 * Date: 19 / 3 / 2025
 * Prof: Dr. Besheer

 * Version: V1.0
*/
// < ========================================================================================== >

#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------- GLOBAL VARIABLES

string contentOfFile[100];        // Array of the content of the file.
int indexInFile = 0;
bool runFile = false;

// ----------------------------------------------- HELPER FUNCTIONS

bool isValidInteger(const string &str) {
    static const regex integerPattern(R"(^-?\d+$)");
    return regex_match(str, integerPattern);
}

bool isValidFloat(const string &str) {
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
    void mergeSortHelper(int left, int right);

    int partition(int low, int high);
    void recQuickSort(int first, int last);

    void countSortForRadix(int exp);

    void displayData();
    void display(T arr[], int arrSize);

    void measureSortTime(void (SortingSystem<T>::*sortFunc)());
    void showMenu();
};

// ----------------------------------------------- CLASS IMPLEMENTATION

// --------------------- CONSTRUCTOR & INPUT DATA & DESTRUCTOR

template<typename T>
SortingSystem<T>::SortingSystem(const int n) : size(n) {
    data = new T[size];
    inputData();
}

template<typename T>
void SortingSystem<T>::inputData() {
    if (runFile) {
        for (int i = 1; i <= this->size; ++i) {
            // Handle if the type of data is strings.
            if constexpr (is_same<T, string>::value) {
                data[i - 1] = contentOfFile[indexInFile++];
                cout << "Element " << i << " : " << data[i - 1] << endl;
            }

                // Handle if the type of data is char.
            else if constexpr (is_same<T, char>::value) {
                data[i - 1] = contentOfFile[indexInFile++][0];
                cout << "Element " << i << " : " << data[i - 1] << endl;
            }

                // Handle if the type of data is float and double.
            else if constexpr (is_same<T, double>::value || is_same<T, float>::value) {
                data[i - 1] = stod(contentOfFile[indexInFile++]);
                cout << "Element " << i << " : " << data[i - 1] << endl;
            }

                // Handle if the type of data is int and long.
            else {
                data[i - 1] = stoll(contentOfFile[indexInFile++]);
                cout << "Element " << i << " : " << data[i - 1] << endl;
            }
        }
    }
    else {
        for (int i = 1; i <= this->size; ++i) {
            cout << "Please, enter element " << i << " : ";
            string element;

            // Get the input and check if it is empty.
            getline(cin, element);
            while (element.empty()) {
                getline(cin, element);
                cout << "Invalid Input!\n";
                cout << "\nPlease, enter element " << i << " : ";
            }

            // Handle if the type of data is strings.
            if constexpr (is_same<T, string>::value) {
                data[i - 1] = element;
            }

                // Handle if the type of data is char.
            else if constexpr (is_same<T, char>::value) {
                data[i - 1] = element[0];
            }

                // Handle if the type of data is float and double.
            else if constexpr (is_same<T, double>::value || is_same<T, float>::value) {
                while (true) {
                    if (isValidFloat(element)) {
                        data[i - 1] = stod(element);
                        break;
                    }
                    cout << "Invalid Input!\n";
                    cout << "\nPlease, enter element " << i << ":";
                    getline(cin, element);
                }
            }

                // Handle if the type of data is int and long.
            else {
                while (true) {
                    if (isValidInteger(element)) {
                        data[i - 1] = stoll(element);
                        break;
                    }
                    cout << "Invalid Input!\n";
                    cout << "\nPlease,enter element " << i << ":";
                    getline(cin, element);
                }
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
    cout << "Sorting using Insertion Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    for (int i = 1, j; i < this->size; i++) {
        T temp = this->data[i];
        for (j = i; j > 0 && temp < this->data[j - 1]; j--)
            this->data[j] = this->data[j - 1];
        this->data[j] = temp;

        // Display each iteration in sorting.
        if (i < this->size - 1) {
            cout << "Iteration " << i << " : ";
            displayData();
        }
    }

    // Display the final sorted data.
    cout << endl << "Sorted Data: ";
    displayData();
}

// Another version to bucket sort
template<typename T>
void insertionSortForBucket(T buck[], int size) {
    for (int i = 1, j; i < size; i++) {
        T temp = buck[i];
        for (j = i; j > 0 && temp < buck[j - 1]; j--)
            buck[j] = buck[j - 1];
        buck[j] = temp;
    }
}

// --------------------- SELECTION SORT

template<typename T>
void SortingSystem<T>::selectionSort() {
    cout << "Sorting using Selection Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    for (int i = 0; i < (this->size - 1); ++i) {
        int minIndex = i;
        for (int j = (i + 1); j < this->size; ++j) {
            if (this->data[j] < this->data[minIndex]) {
                minIndex = j;
            }
        }
        swap(this->data[i], this->data[minIndex]);

        cout << "Iteration " << i + 1 << " : ";
        displayData();
    }

    cout << endl << "Sorted Data: ";
    displayData();
}

// --------------------- BUBBLE SORT
template<typename T>
void SortingSystem<T>::bubbleSort() {
    cout << "Sorting using Bubble Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    long long num_iteration = 1;
    for (int i = 0; i < this->size; i++) {
        for (int j = this->size - 1; j > i; --j) {
            if (data[j - 1] > data[j]) {
                swap(data[j - 1], data[j]);
                
                // Display each Iteration in sorting
                cout << "Iteration " << num_iteration << " : ";
                displayData();
                num_iteration++;
            }
        }
    }

    cout << endl << "Sorted Data: ";
    displayData();
}

// --------------------- SHELL SORT

template<typename T>
void SortingSystem<T>::shellSort() {
    cout << "Sorting using Sell Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    for (int gap = this->size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < this->size; i += 1) {
            T temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap)
                data[j] = data[j - gap];

            data[j] = temp;
        }
    }

    cout << endl << "Sorted Data: ";
    displayData();
}

// --------------------- MERGE SORT

int iteration = 0;

template<typename T>
void SortingSystem<T>::merge(const int left, const int mid, const int right) {
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    T *left_data = new T[n1];
    T *right_data = new T[n2];

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
        i++;
        k++;
    }

    while (j < n2) {
        data[k] = right_data[j];
        j++;
        k++;
    }

    // Print the current state of the data after iteration of merge sort
    iteration++;
    cout << "Iteration " << iteration << " : ";
    displayData();

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
void SortingSystem<T>::mergeSort() {
    cout << "Sorting using Merge Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    mergeSortHelper(0, size - 1);

    cout << endl << "Sorted Data: ";
    displayData();
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
    cout << "Sorting using Quick Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    recQuickSort(0, this->size - 1);

    cout << endl << "Sorted Data: ";
    displayData();
}

// --------------------- COUNT SORT

template<typename T>
void SortingSystem<T>::countSort() {
    cout << "Sorting using Count Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    // Find the maximum value in the array
    int Max_Value = data[0];
    for (int i = 1; i < this->size; i++) {
        Max_Value = max(Max_Value, data[i]);
    }

    // Create and initialize a count array
    int *C = new int[Max_Value + 1](); // Dynamic allocation, initialized to 0

    cout << "Max_Value: " << Max_Value << endl;

    // Step 1: Count occurrences
    for (int i = 0; i < this->size; i++) {
        C[data[i]]++;
    }

    // Step 2: Compute cumulative count
    cout << "Cumulative Data: [";
    for (int i = 1; i <= Max_Value; i++) {
        C[i] += C[i - 1];
        if (i != Max_Value) cout << C[i] << ", ";
        else cout << C[i];
    }
    cout << "]" << endl;

    T *B = new T[this->size];       // Create the output array

    // Step 3: Place elements in sorted order
    for (int i = this->size - 1; i >= 0; i--) {
        B[C[data[i]] - 1] = data[i];
        C[data[i]]--;
    }

    // Step 4: Copy sorted array back to data
    for (int i = 0; i < this->size; i++) {
        data[i] = B[i];
    }

    cout << endl << "Sorted Data: ";
    displayData();

    // Free the temporary data array.
    delete[] C;
    delete[] B;
}

template<typename T>
void SortingSystem<T>::countSortForRadix(int exp) {
    T *B = new T[this->size]; // Output array
    int C[10] = {0}; // Counting array for digits (0-9)

    // Step 1: Count occurrences of each digit at place 'exp'
    for (int i = 0; i < this->size; i++) {
        int digit = (data[i] / exp) % 10;
        C[digit]++;
    }

    // Step 2: Compute cumulative count
    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Step 3: Place elements in sorted order (stable sort)
    for (int i = this->size - 1; i >= 0; i--) {
        int digit = (data[i] / exp) % 10;
        B[C[digit] - 1] = data[i];
        C[digit]--;
    }

    // Step 4: Copy sorted elements back to an original array
    for (int i = 0; i < this->size; i++) {
        data[i] = B[i];
    }

    // Free dynamically allocated memory
    delete[] B;
}

// --------------------- RADIX SORT

template<typename T>
void SortingSystem<T>::radixSort() {
    cout << "Sorting using Radix Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    int Max_Value = 0;
    for (int i = 1; i < this->size; i++) {
        Max_Value = max(Max_Value, data[i]);
    }

    // Apply counting sort for each digit place
    for (int exp = 1; Max_Value / exp > 0; exp *= 10) {
        countSortForRadix(exp);
        cout << "After sorting on place value " << exp << ": ";
        displayData();
    }

    cout << endl << "Sorted Data: ";
    displayData();
}

// --------------------- BUCKET SORT

template<typename T>
void SortingSystem<T>::bucketSort() {
    cout << "Sorting using Bucket Sort...\n\n";
    cout << "Initial Data: ";
    displayData();

    T minimum = (this->data[0]), maximum = (this->data[0]);
    for (int i = 0; i < this->size; ++i) {
        T val = (this->data[i]);
        if (val > maximum) maximum = val;
        if (val < minimum) minimum = val;
    }

    // 2D arrays store buckets, each bucket has a specific range of values.
    T **buckets = new T *[this->size];
    // array follow indexes for each bucket.
    int *bucket_sizes = new int[this->size];
    // initialize the buckets and their indexes.
    for (int i = 0; i < this->size; ++i) {
        buckets[i] = new T[this->size];
        bucket_sizes[i] = 0;
    }

    if (minimum == maximum) {
        cout << endl << "Sorted Data: ";
        displayData();
        return;
    }

    for (int i = 0; i < this->size; ++i) {
        // Calculate the Normalization that uses to determine the index and the bucket which has the value.
        T norm = (this->data[i] - minimum) / (maximum - minimum);
        // Calculate the index by Normalization.
        int index = static_cast<int>(norm * (this->size - 1));
        // store the value in its bucket
        buckets[index][bucket_sizes[index]] = this->data[i];
        bucket_sizes[index]++;
    }

    // Sort each bucket's value by insertion sort.
    int index = 1;
    for (int i = 0; i < this->size; ++i) {
        if (bucket_sizes[i] > 0) {
            insertionSortForBucket(buckets[i], bucket_sizes[i]);
            cout << "Iteration " << index++ << ": ";
            display(buckets[i], bucket_sizes[i]);
        }
    }

    // Return again the values in original Array
    index = 0;
    for (int i = 0; i < this->size; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            data[index++] = buckets[i][j];
        }
    }

    cout << endl << "Sorted Data: ";
    displayData();


    // Free the temporary data array.
    for (int i = 0; i < this->size; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucket_sizes;
}

// --------------------- DISPLAY DATA

template<typename T>
void SortingSystem<T>::display(T arr[], int arrSize) {
    cout << "[";
    for (int i = 0; i < arrSize; ++i) {
        if (i != arrSize - 1) cout << arr[i] << ", ";
        else cout << arr[i];
    }
    cout << "]" << endl;
}

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
        cout << "Select a sorting algorithm: " << endl;
        cout << "1. Insertion Sort." << endl;
        cout << "2. Selection Sort." << endl;
        cout << "3. Bubble Sort." << endl;
        cout << "4. Shell Sort." << endl;
        cout << "5. Merge Sort." << endl;
        cout << "6. Quick Sort." << endl;
        cout << "7. Count Sort (only for integers)." << endl;
        cout << "8. Radix Sort (only for integers)." << endl;
        cout << "9. Bucket Sort (only for integers and floating point numbers)." << endl;
        cout << "0. Exit From Menu." << endl;

        string choice;
        if (runFile) {
            choice = contentOfFile[indexInFile++];
            cout << "Your choice (0 - 9) : " << choice << endl;
        }
        else {
            cout << "Enter your choice (0 - 9):";
            getline(cin, choice);
            if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" &&
                choice != "7" && choice != "8" && choice != "9" && choice != "0") {
                cout << "Invalid choice. Please try again." << endl << endl;
                continue;
            }
        }

        // Create a temporary data array to store the original data before sorting it.
        T *tempData = new T[this->size];
        for (int i = 0; i < this->size; i++) {
            tempData[i] = this->data[i];
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
        else if (choice == "7") {
            if constexpr (is_integral<T>::value) {
                measureSortTime(&SortingSystem::countSort);
            }
            else cout << "Count Sort is only available for integers." << endl << endl;
        }
        else if (choice == "8") {
            if constexpr (is_integral<T>::value) {
                measureSortTime(&SortingSystem::radixSort);
            }
            else cout << "Radix Sort is only available for integers." << endl << endl;
        }
        else if (choice == "9") {
            if constexpr (is_integral<T>::value || is_floating_point<T>::value) {
                measureSortTime(&SortingSystem::bucketSort);
            }
            else cout << "Bucket Sort is only available for integers and floating point numbers." << endl << endl;
        }
        else if (choice == "0") {
            delete[] tempData;
            return;
        }

        // Free the temporary data array and restore the original data.
        delete[] this->data;
        this->data = tempData;
    }
}

// ----------------------------------------------- HELPER FUNCTIONS

void runFromTerminal() {
    while (true) {
        // Choose the data type for the sorting system (numbers or strings).
        string dataType;
        while (true) {
            cout << "\nPlease, enter the data type :" << endl;
            cout << "1) Integers " << endl;
            cout << "2) Doubles & Floats" << endl;
            cout << "3) Strings & Characters" << endl;
            cout << "Please, enter your choice: ";
            getline(cin, dataType);

            if (dataType == "1" || dataType == "2" || dataType == "3") break;
            cout << "Invalid choice. Please enter a valid number." << endl << endl;
        }

        // Enter the number of elements to be sorted in the system.
        string numberOfElements;
        while (true) {
            cout << "Please, enter the number of elements:";
            getline(cin, numberOfElements);

            if (isValidInteger(numberOfElements) && stoi(numberOfElements) > 0) break;
            cout << "Invalid input. Please enter a valid number." << endl << endl;
        }

        // Create the sorting system object based on the data type.
        if (dataType == "1") {
            SortingSystem<int> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }
        else if (dataType == "2") {
            SortingSystem<double> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }
        else if (dataType == "3") {
            SortingSystem<string> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }

        // Ask the user if they want to continue using the system or exit.
        string choice;
        while (true) {
            cout << "Do you want to continue? (y/n):";
            getline(cin, choice);
            choice = (choice);
            if (choice == "Y" || choice == "y" || choice == "N" || choice == "n") break;
            else cout << "Invalid choice. Please try again." << endl << endl;
        }

        if (choice == "N" || choice == "n") {
            cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
            return;
        }
    }
}

void runFromFile() {
    string fileContent, fileName, element;
    stringstream content;

    cout << "Please, enter file name:";
    while (true) {
        // Get the file name and check the validity of format.
        getline(cin, fileName);
        if (fileName.size() < 5) {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please, enter a valid file name :";
            continue;
        }

        // Check file extension.
        if (fileName.substr(fileName.size() - 4, 4) != ".txt") {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please, enter a valid file name :";
            continue;
        }

        // Check if the file exists.
        ifstream file(fileName);
        if (!file.good()) {
            cout << "\nThe file name should be like this ----> (file name).txt\n";
            cout << "Please, enter a valid file name :";
            continue;
        }
        content << file.rdbuf();
        break;
    }
    fileContent = content.str();

    // Put the content of the file into an array.
    int count = 0;
    for (char character : fileContent) {
        if (character == '\n' || character == ' ') {
            contentOfFile[count] = element;
            element = "";
            count++;
        }
        else element += character;
    }
    contentOfFile[count] = element;

    while (true) {
        cout << "\nPlease, enter the data type " << endl;
        cout << "1) Integers" << endl;
        cout << "2) Doubles & Floats" << endl;
        cout << "3) Strings & Characters" << endl;

        string dataType = contentOfFile[indexInFile++];
        cout << "Your choice : " << dataType << endl << endl;

        string numberOfElements = contentOfFile[indexInFile++];
        cout << "Please, number of elements:" << numberOfElements << endl << endl;

        // Create the sorting system object based on the data type.
        if (dataType == "1") {
            SortingSystem<int> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }
        else if (dataType == "2") {
            SortingSystem<double> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }
        else if (dataType == "3") {
            SortingSystem<string> sortingSystem(stoi(numberOfElements));
            sortingSystem.showMenu();
        }

        // check if user wants to exit.
        string choice = contentOfFile[indexInFile++];
        cout << "Do you want to continue? (y/n) : " << choice << endl;

        if (choice == "N" || choice == "n") {
            cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
            return;
        }
    }
}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    cout << "\n------------- WELCOME TO OUR SORTING SYSTEM -------------\n" << endl;
    string choice;

    while (true) {
        cout << "What do you want to do?" << endl;
        cout << "1) Run From Terminal" << endl;
        cout << "2) Run From File" << endl;
        cout << "3) Exit " << endl;
        cout << "please, enter your choice : ";
        getline(cin, choice);

        // Check the validity of input.
        if (choice == "1" || choice == "2" || choice == "3") break;
        cout << "Invalid choice. Please, Try again." << endl << endl;
    }

    // Run from the terminal.
    if (choice == "1") runFromTerminal();

    // Run from the file.
    else if (choice == "2") {
        runFile = true;
        runFromFile();
    }

    else cout << "\n----- Thank you for using our system! Goodbye! -----" << endl;
}
