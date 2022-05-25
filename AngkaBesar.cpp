//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * Node structure and
 * uniqueBST structure
 */
int hitung = 0;

typedef struct bstnode_t {
    int key;
    int count;
    struct bstnode_t \
        *left, *right;
} BSTNode;

typedef struct bst_t {
    BSTNode *_root;
    unsigned int _size;
} BST;

typedef struct counter_t{
    int count;
}counter;


 /* !!! WARNING UTILITY FUNCTION !!!*/
 

BSTNode* __bst__createNode(int value) {
    BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
    newNode->key = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BSTNode* __bst__insert(BSTNode *root, int value) {
    if (root == NULL)
        return __bst__createNode(value);

    if (value < root->key)
        root->left = __bst__insert(root->left, value);
    else if (value > root->key)
        root->right = __bst__insert(root->right, value);
    
    return root;
}

BSTNode* __bst__search(BSTNode *root, int value) {
    while (root != NULL) {
        if (value < root->key)
            root = root->left;
        else if (value > root->key)
            root = root->right;
        else
            return root;
    }
    return root;
}


/**
 * PRIMARY FUNCTION
 * ---------------------------
 * Accessible and safe to use.
 */

void bst_init(BST *bst) {
    bst->_root = NULL;
    bst->_size = 0;
}

bool bst_isEmpty(BST *bst) {
    return bst->_root == NULL;
}

bool bst_find(BST *bst, int value) {
    BSTNode *temp = __bst__search(bst->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->key == value)
        return true;
    else
        return false;
}

void bst_insert(BST *bst, int value) {
    if (!bst_find(bst, value)) {
        bst->_root = __bst__insert(bst->_root, value);
        bst->_size++;
    }
}

void kth_largest(BSTNode *root, int k, counter *c){
    if(root == NULL || c->count >=k) return;
    
    kth_largest(root->right,k, c);
    c->count++;
    
    if(c->count == k){
        printf("%d", root->key);
        return;
    }
    kth_largest(root->left, k, c);
}



 
int main(){
    
    BST myBST;
    bst_init(&myBST);
    int ronde, i, j;
    counter c ;
    c.count=0;
    scanf("%d %d", &ronde, &j);
    
    for(i = 0; i < ronde; i++){
        int num;
        scanf("%d", &num);
        bst_insert(&myBST, num);
    }

    kth_largest(myBST._root, j, &c);
    
    return 0;
}
