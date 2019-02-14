// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <list>
#include <cmath>

using namespace std;

struct bnode {
    bnode* left;
    bnode* right;
    int val;
    bnode() :left(nullptr), right(nullptr) {}
};


class bstree {
    bnode* _r;
public:
    bstree():_r(nullptr) {

    }
    bnode* buildbst() {
        bnode*r = new bnode;
        r->val = 5;
        r->left = new bnode;
        r->left->val = 2;
        r->right = new bnode;
        r->right->val = 8;

        r->left->left = new bnode;
        r->left->left->val = 1;
        r->left->right = new bnode;
        r->left->right->val = 3;

        r->right->left = new bnode;
        r->right->left->val = 7;
        r->right->right = new bnode;
        r->right->right->val = 9;
        _r = r;
        return r;
    }
    void preorder(vector<int>& vA,bnode* r) {
        if (r == nullptr) return;
        vA.push_back(r->val);
        preorder(vA, r->left);
        preorder(vA, r->right);
    }
    void clean(bnode** r) {
        bnode* t = *r;
        if (t->left) clean(&t->left);
        if (t->right) clean(&t->right);
        delete t;
       *r = nullptr;
    }
    bnode* insert(int val, bnode* r) {
          if (r == nullptr) {
            r = new bnode;
            r->val = val;;
        }
        if (val < r->val)
          r->left = insert(val, r->left);
        if (val > r->val)
          r->right = insert(val, r->right);
        return r;
    }
    void pprint() {
        vector<int> v;
        list<bnode*> l;
        bnode* t = _r;
        if (t == nullptr) return;
        l.push_back(t);

        while (!l.empty()) {
            bnode* t = l.front();
            l.pop_front();
            if (t->left) {
                l.push_back(t->left);
            }
            if (t->right) {
                l.push_back(t->right);
            }
            v.push_back(t->val);
        }
        int level = 0;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
    }
};
class test_bst {
public:
    
    bool test_clean() {
        bstree bst;
        bnode* r = bst.buildbst();
        vector<int> v1;
        vector<int> v2;
       
        bst.pprint(); 
        bst.preorder(v1, r);
        bst.clean(&r);
        bst.preorder(v2, r);
        bst.pprint();
        if (v2.size() == 0) {
            return true;
        }
        return false;
    }
};

int main()
{
    test_bst tbst;
    cout << "Test bstree::clean() : " << (tbst.test_clean() ? "PASS": "FAIL");
   
    return 0;
}

