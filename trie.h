#ifndef TRIE_H
#define TRIE_H




#define ALPHABET_SIZE 128   




typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;




/* Trie işlemleri */
TrieNode* createTrieNode();
void trieInsert(TrieNode* root, const char* word);
int trieSearchPrefix(TrieNode* root, const char* prefix);




#endif