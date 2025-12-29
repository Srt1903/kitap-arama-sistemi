#ifndef DATA_H
#define DATA_H


#define MAX_TITLE 100
#define MAX_AUTHOR 100
#define MAX_TAGS 100


typedef struct Book {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    char tags[MAX_TAGS];
} Book;


#endif