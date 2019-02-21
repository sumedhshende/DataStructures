// bst.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<vector>
#include <list>
#include <cmath>
#include <ctime>

using namespace std;

struct bnode {
    bnode* left;
    bnode* right;
    int val;
    bnode() :left(nullptr), right(nullptr) {}
};


class bstree {
    bnode* _r;

private:
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
    void clean(bnode** r) {
        bnode* t = *r;
        if (t->left) clean(&t->left);
        if (t->right) clean(&t->right);
        delete t;
        *r = nullptr;
    }
    int height(bnode* r) {
        if (r == nullptr) return 0;
        int lh = height(r->left) + 1;
        int rh = height(r->right) + 1;
        if (lh > rh) return lh;
        else return rh;
    }

public:
    bstree() :_r(nullptr) {}
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
    void preorder(vector<int>& vA, bnode* r) {
        if (r == nullptr) return;
        vA.push_back(r->val);
        preorder(vA, r->left);
        preorder(vA, r->right);
    }

    void insert(int val) {
        _r = insert(val, _r);
    }
    void clean() {
        clean(&_r);
    }
    int height() {
        return height(_r);
    }
    void pprint() {
        vector<int> v;
        list<bnode*> l;
        bnode* t = _r;
        if (t == nullptr) return;
        l.push_back(t);

        while (!l.empty()) {
            bnode* t = l.front();

            if (t->left != nullptr) {
                l.push_back(t->left);
            }
            if (t->right != nullptr) {
                l.push_back(t->right);
            }
            v.push_back(t->val);
            l.pop_front();
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
        bst.buildbst();
        // bst.preorder(v1, r);
        bst.clean();
        // bst.preorder(v2, r);
        bst.pprint();
        return false;
    }
    bool test_insert() {
        bstree bst;
        vector<int> vA;

        srand(time(nullptr));
        int testCount = 10;
        for (int i = 0; i < testCount; i++) {
            int elemCount = rand() % 20;
            for (int j = 0; j < elemCount; j++) {
                vA.push_back(rand() % 20);
            }
            for (int k = 0; k<elemCount; k++) {
                bst.insert(vA[k]);
            }
            cout << " --- Height ---->   " << bst.height() << endl;
            bst.pprint();
            bst.clean();
            cout << endl;
        }
        return true;
    }
};

int main()
{
    test_bst tbst;
    cout << "Test bstree::test_insert() : " << (tbst.test_insert() ? "PASS" : "FAIL");

    return 0;
}

