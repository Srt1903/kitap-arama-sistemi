#include <string.h>
#include "sort.h"


/* Yardımcı fonksiyon */
static void swap(Book* a, Book* b) {
    Book temp = *a;
    *a = *b;
    *b = temp;
}


/* Partition (ID'ye göre) */
static int partition(Book arr[], int low, int high) {
    int pivot = arr[high].id;
    int i = low - 1;


    for (int j = low; j < high; j++) {
        if (arr[j].id < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


/* QuickSort */
void quickSortBooks(Book arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortBooks(arr, low, pi - 1);
        quickSortBooks(arr, pi + 1, high);
    }
}


/* Binary Search */
int binarySearchBooks(Book arr[], int size, int targetID) {
    int left = 0;
    int right = size - 1;


    while (left <= right) {
        int mid = (left + right) / 2;


        if (arr[mid].id == targetID)
            return mid;
        else if (arr[mid].id < targetID)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}