//
//  main.cpp
//  FINAL PROJECT
//
//  Created by Denta Bramasta Hidayat on 14/06/21.
//

#include <bits/stdc++.h>
using namespace std;
 

vector <int> posisi;
struct BSTNodeTree {
    BSTNodeTree *left, *right;
    int key;
    bool cek = false;
};

struct BST {
    BSTNodeTree *_root;
    unsigned int _size;
    
    void init() {
        _root = NULL;
        _size = 0x0000FFFF;
    }
   
    bool isEmpty() {
        return _root == NULL;
    }
   
    bool find(int value) {
        BSTNodeTree *temp = __search(_root, value);
        if (!temp){
            return false;
        }
        if (temp->key == value){
            return true;
        } else {
            return false;
        }
    }
    
    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }
    void inOrder() {
        __inorder(_root);
    }
    
    void Kiri() {
        int levelMax = 0;
        Kiri(_root, true, &levelMax);
    }
    
    void Kanan() {
        int levelMax = 0;
        Kanan(_root, true, &levelMax);
    }
private:
   
    void Kiri(BSTNodeTree *root, int area, int *levelMax) {
        if (root == NULL){
            return;
        }
        if (*levelMax<area && area!=0) {
            root->cek = true;
            *levelMax = area;
        }
        Kiri(root->left, area+1, levelMax);
        Kiri(root->right, area+1, levelMax);
    }

    void Kanan(BSTNodeTree *root, int area, int *levelMax) {
        if (root == NULL) {
            return;
        }
        if (*levelMax<area && area!=0) {
            root->cek = true;
            *levelMax = area;
        }
        Kanan(root->right, area+1, levelMax);
        Kanan(root->left, area+1, levelMax);
    }
   
    BSTNodeTree* __createNode(int n) {
        BSTNodeTree *newNode = (BSTNodeTree*) malloc(sizeof(BSTNodeTree));
        newNode->key = n;
        newNode->left = newNode->right = NULL;
        newNode->cek = false;
        return newNode;
    }
   
    BSTNodeTree* __search(BSTNodeTree *root, int n) {
        while (root != NULL) {
            if (n < root->key){
                root = root->left;
            } else if (n > root->key){
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
   
    BSTNodeTree* __insert(BSTNodeTree *root, int n) {
        if (root == NULL){
            return __createNode(n);
        }
        if (n < root->key){
            root->left = __insert(root->left, n);
        } else if (n>root->key){
            root->right = __insert(root->right, n);
        }
        return root;
    }
  
    void __inorder(BSTNodeTree *root) {
        if (root != NULL) {
            __inorder(root->left);
            if(!root->cek) {
                if(root->left || root->right) {
                    posisi.push_back(root->key);
                }
            }
            __inorder(root->right);
        }
    }
};


int main() {

    BST bst;
    bst.init();
    int inp, num = 0, ans;
    cin >> inp;
    
    for(int i = 0; i < inp; i++) {
        cin >> num;
        bst.insert(num);
    }

    if(num > 0 && num != 0){
        bst.Kiri();
        bst.Kanan();
    }
    bst.inOrder();
    ans = posisi.size();
    
    if(ans > 0 && (ans != 0)) {
        for(int i = 0; i < ans; i++) {
            cout<<posisi[i];
            cout<<" ";
        }
    } else if (ans == 0 || ans <= -1) {
        cout << "Yah, gk ada posisi yang aman :(" << endl;
    }
    return 0;
}
