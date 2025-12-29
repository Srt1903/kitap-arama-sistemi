#include <stdio.h>
#include <stdlib.h>
#include "avl.h"


int height(AVLNode *n) {
    return n ? n->height : 0;
}


int max(int a, int b) {
    return (a > b) ? a : b;
}


AVLNode* newNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}


int getBalance(AVLNode *n) {
    return n ? height(n->left) - height(n->right) : 0;
}


/* Rotasyonlar */


AVLNode* rightRotate(AVLNode *y) {
    AVLNode *x = y->left;
    AVLNode *T2 = x->right;


    x->right = y;
    y->left = T2;


    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;


    return x;
}


AVLNode* leftRotate(AVLNode *x) {
    AVLNode *y = x->right;
    AVLNode *T2 = y->left;


    y->left = x;
    x->right = T2;


    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;


    return y;
}


/* AVL Insert */


AVLNode* avlInsert(AVLNode* node, int key) {
    if (!node)
        return newNode(key);


    if (key < node->key)
        node->left = avlInsert(node->left, key);
    else if (key > node->key)
        node->right = avlInsert(node->right, key);
    else
        return node; 


    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);


    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);


    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);


    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }


    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }


    return node;
}


/* Arama */


AVLNode* avlSearch(AVLNode* root, int key) {
    if (!root || root->key == key)
        return root;


    if (key < root->key)
        return avlSearch(root->left, key);


    return avlSearch(root->right, key);
}


/* Inorder traversal */


void inorderTraversal(AVLNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);

}
