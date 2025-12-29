#include <stdio.h>
#include <string.h>


#include "avl.h"
#include "trie.h"
#include "graph.h"
#include "sort.h"
#include "stack.h"
#include "file.h"


#define MAX_BOOKS 100


Book books[MAX_BOOKS];
Book originalBooks[MAX_BOOKS];
int bookCount = 0;


AVLNode* avlRoot = NULL;
TrieNode* trieRoot = NULL;
Graph g;
Stack actionStack;


/* ----------------------------- */


void loadBooks() {
    bookCount = loadBooksFromCSV("books.csv", books);


    for (int i = 0; i < bookCount; i++) {
        originalBooks[i] = books[i];
        avlRoot = avlInsert(avlRoot, books[i].id);
        trieInsert(trieRoot, books[i].title);
    }


    initGraph(&g, bookCount);
}


/* ----------------------------- */


void listBooks() {
    printf("\n--- KITAPLAR ---\n");
    for (int i = 0; i < bookCount; i++) {
        if (books[i].isActive)
            printf("[%d] %s - %s\n",
                   books[i].id,
                   books[i].title,
                   books[i].author);
    }
}


/* ----------------------------- */


void addBook() {
    if (bookCount >= MAX_BOOKS) return;


    Book b;
    printf("ID: ");
    scanf("%d", &b.id);


    if (avlSearch(avlRoot, b.id)) {
        printf("Bu ID zaten var.\n");
        return;
    }


    printf("Baslik: ");
    scanf(" %[^\n]", b.title);


    printf("Yazar: ");
    scanf(" %[^\n]", b.author);


    b.isActive = 1;


    push(&actionStack, (Action){ACTION_ADD, bookCount});


    books[bookCount] = b;
    avlRoot = avlInsert(avlRoot, b.id);
    trieInsert(trieRoot, b.title);
    bookCount++;


    printf("Kitap eklendi.\n");
}


/* ----------------------------- */


void deleteBookLazy() {
    int id;
    printf("Silinecek ID: ");
    scanf("%d", &id);


    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id && books[i].isActive) {
            books[i].isActive = 0;
            push(&actionStack, (Action){ACTION_DELETE, i});
            printf("Kitap silindi (lazy).\n");
            return;
        }
    }
    printf("Kitap bulunamadi.\n");
}


/* ----------------------------- */


void undo() {
    if (isEmpty(&actionStack)) {
        printf("UNDO yok.\n");
        return;
    }


    Action a = pop(&actionStack);


    if (a.type == ACTION_ADD) {
        bookCount--;
        printf("Ekleme geri alindi.\n");
    }
    else if (a.type == ACTION_DELETE) {
        books[a.index].isActive = 1;
        printf("Silme geri alindi.\n");
    }
}


/* ----------------------------- */


void menu() {
    printf("\n===== KITAP SISTEMI =====\n");
    printf("1. Listele\n");
    printf("2. Kitap ekle\n");
    printf("3. Kitap sil (lazy)\n");
    printf("4. UNDO\n");
    printf("0. Cikis\n");
    printf("Secim: ");
}


/* ----------------------------- */


int main() {
    int c;


    trieRoot = createTrieNode();
    initStack(&actionStack);
    loadBooks();


    do {
        menu();
        scanf("%d", &c);


        switch (c) {
            case 1: listBooks(); break;
            case 2: addBook(); break;
            case 3: deleteBookLazy(); break;
            case 4: undo(); break;
            case 0: break;
            default: printf("Gecersiz.\n");
        }
    } while (c != 0);


    return 0;
}