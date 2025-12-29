#ifndef AVL_H
#define AVL_H


typedef struct AVLNode {
    int key;                
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;


/* AVL temel işlemler */
AVLNode* avlInsert(AVLNode* node, int key);
AVLNode* avlSearch(AVLNode* root, int key);
void inorderTraversal(AVLNode* root);



#endif
