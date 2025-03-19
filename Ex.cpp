#include <bits/stdc++.h>
using namespace std ;
void display(long double arr[],int si){
    for (int i = 0; i < si; ++i) {
        if(i == si-1) cout << arr[i] ;
        else cout << arr[i] << " ," ;

    }
    cout << endl;
}

void insertion_sort( long double buck [] , int size) {
    for (int i = 1, j; i < size; i++) {
        long double temp = buck[i];
        for (j = i; j > 0 && temp < buck[j - 1]; j--)
            buck[j] = buck[j - 1];
        buck[j] = temp;

    }
}

void bucketSort(long double data[] , int size) {
    cout << "Sorting using Selection Sort...\n\n";
    cout << "Initial Data: ";
    display(data , size);

    long double  minimum = (data[0]) ;
    long double  maximum = (data[0]) ;
    for (int i = 0; i < size; ++i) {
        long double val = (data[i]);
        if (val > maximum) maximum = val;
        if (val < minimum) minimum = val;
    }

    if (minimum == maximum) {
        cout << "All elements are already Sorted.\nSorted Data: ";
        display (data , size);
        return;
    }

    auto ** buckets = new long double*[size];
    int* bucket_sizes = new int[size];

    for (int i = 0; i < size; ++i) {
        buckets[i] = new long double[size];
        bucket_sizes[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        long double norm = (data[i] - minimum) / (maximum - minimum);
        int index = (norm * (size - 1));

        buckets[index][bucket_sizes[index]] = data[i];
        bucket_sizes[index]++;
    }
    int index = 1;
    for (int i = 0; i < size; ++i) {
        if (bucket_sizes[i] > 0) {
            insertion_sort(buckets[i], bucket_sizes[i]);
            cout << "Iteration " << index++ << ':' ; display(buckets[i], bucket_sizes[i]);
        }
    }
    index = 0 ;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < bucket_sizes[i]; ++j) {
            data[index++] = buckets[i][j];
        }
    }
    cout << "Sorted Data :" ; display(data , size);
    for (int i = 0; i < size; ++i) {
        delete[] buckets[i];
    }
    delete[] buckets;
    delete[] bucket_sizes;
}

int main(){
    int size ;
    cout << "Enter size ; "; cin >> size ;
    long double arr[size];
    cout << "Enter Elements :\n" ;
    for (int i = 0; i < size ; ++i) {
        cout << "Element " << i << " : "; cin >> arr[i];
    }
    bucketSort(arr,size);
    return 0;
}