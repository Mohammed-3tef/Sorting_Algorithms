/*
 * Authors:
    * Author1: Esraa Emary Abd El-Salam, ID: 20230054
    * Author2: Mohammed Atef Abd El-Kader, ID: 20231143
    * Author3: Mariam Badr Yehia, ID: 20230391
    * Author4: John Ayman Demian, ID: 20230109
    * Author5: George Malak Magdy, ID: 20231042

 * Description: This is a program that manages "Iftar Invitations" which makes you add a guest,
             display it and edit the date of invitation.

 * Version: V1.0
*/

// < ========================================================================================== >

#include <bits/stdc++.h>
using namespace std;

// ----------------------------------------------- CLASS DEFINITION

template <typename T>
class SortingSystem {
    T* data;
    int size;
public:
    SortingSystem(int n);
    ~SortingSystem();

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
// --------------------- Constructors & Destructors
template <typename T>
SortingSystem<T>::SortingSystem(int n) {
    size = n;
    data = new T[size];
}

template <typename T>
SortingSystem<T>::~SortingSystem() {
    delete[] data;
}

// --------------------- INSERTION SORT

template <typename T>
void SortingSystem<T>::insertionSort() {

}

// --------------------- SELECTION SORT

template <typename T>
void SortingSystem<T>::selectionSort() {

}

// --------------------- BUBBLE SORT

template <typename T>
void SortingSystem<T>::bubbleSort() {

}

// --------------------- SHELL SORT

template <typename T>
void SortingSystem<T>::shellSort() {

}

// --------------------- MERGE SORT

template <typename T>
void SortingSystem<T>::merge(int left, int mid, int right) {

}

template <typename T>
void SortingSystem<T>::mergeSort() {

}

// --------------------- QUICK SORT

template <typename T>
int SortingSystem<T>::partition(int low, int high) {

}

template <typename T>
void SortingSystem<T>::quickSort() {

}

// --------------------- COUNT SORT

template <typename T>
void SortingSystem<T>::countSort() {

}

// --------------------- RADIX SORT

template <typename T>
void SortingSystem<T>::radixSort() {

}

// --------------------- BUCKET SORT

template <typename T>
void SortingSystem<T>::bucketSort() {

}

// --------------------- DISPLAY DATA

template <typename T>
void SortingSystem<T>::displayData() {

}

// --------------------- MEASURE SORT TIME

template <typename T>
void SortingSystem<T>::measureSortTime(void (SortingSystem<T>::*sortFunc)()) {

}

// --------------------- SHOW MENU

template <typename T>
void SortingSystem<T>::showMenu() {

}

// ----------------------------------------------- MAIN FUNCTION

int main() {
    
    return 0;
}