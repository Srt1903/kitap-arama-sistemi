#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"


TrieNode* createTrieNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;


    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;


    return node;
}


void trieInsert(TrieNode* root, const char* word) {
    TrieNode* current = root;


    for (int i = 0; word[i] != '\0'; i++) {
        unsigned char index = (unsigned char)word[i];


        if (!current->children[index])
            current->children[index] = createTrieNode();


        current = current->children[index];
    }
    current->isEndOfWord = 1;
}


int trieSearchPrefix(TrieNode* root, const char* prefix) {
    TrieNode* current = root;


    for (int i = 0; prefix[i] != '\0'; i++) {
        unsigned char index = (unsigned char)prefix[i];
        if (!current->children[index])
            return 0;
        current = current->children[index];
    }
    return 1;   

}
