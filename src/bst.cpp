// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
using namespace std;

template<class T>
struct bnode {
    bnode* left;
    bnode* right;
    T val;
    bnode() :left(nullptr), right(nullptr) {}
};

template<class T>
class bstree {
public:
    
    bnode<T>* buildbst() {
        bnode<T>*r = new bnode<T>;
        r->val = 5;
        r->left = new bnode<T>;
        r->left->val = 2;
        r->right = new bnode<T>;
        r->right->val = 8;

        r->left->left = new bnode<T>;
        r->left->left->val = 1;
        r->left->right = new bnode<T>;
        r->left->right->val = 3;

        r->right->left = new bnode<T>;
        r->right->left->val = 7;
        r->right->right = new bnode<T>;
        r->right->right->val = 9;
        return r;
    }
    void preorder(bnode<T>* r) {
        if (r == nullptr) return;
        cout << r->val << " ";
        preorder(r->left);
        preorder(r->right);
    }
    void clean(bnode<T>** r) {
        bnode<T>* t = *r;
        if (t->left) clean(&t->left);
        if (t->right) clean(&t->right);
        delete t;
       *r = nullptr;
    }
};

int main()
{
    bstree<int> bst;
    bnode<int>* r = bst.buildbst();
    bst.preorder(r);
    bst.clean(&r);
    bst.preorder(r);
    return 0;
}

