#include <stdio.h>
#include <string.h>
#include "file.h"


int loadBooksFromCSV(const char* filename, Book books[]) {
    FILE* file = fopen(filename, "r");
    if (!file) return 0;


    char line[256];
    int count = 0;


    fgets(line, sizeof(line), file); 


    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%d,%99[^,],%99[^\n]",
               &books[count].id,
               books[count].title,
               books[count].author);
        books[count].isActive = 1;
        count++;
    }


    fclose(file);
    return count;

}
