#ifndef SORT_H
#define SORT_H


typedef struct {
    int id;
    char title[100];
    char author[100];
    int isActive;   // 1 = aktif, 0 = lazy delete
} Book;


void quickSortBooks(Book arr[], int low, int high);
int binarySearchBooks(Book arr[], int size, int id);


#endif