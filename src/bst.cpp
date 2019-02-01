// bst.cpp : Defines the entry point for the console application.
//

#include<cstdio>
#include<iostream>
#include<iomanip>
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
void postorder(bnode<T>* p, int indent=0)
{
    if(p != NULL) {
        if(p->left) postorder(p->left, indent+4);
        if(p->right) postorder(p->right, indent+4);
        if (indent) {
            std::cout << setw(indent) << ' ';
        }
        cout<< p->val;
    }
}
    void clean(bnode<T>** r) {
        bnode<T>* t = *r;
        if (t->left) clean(&t->left);
        if (t->right) clean(&t->right);
        delete t;
       *r = nullptr;
    }
    void insert(bnode<T>* r, T val){
        if(r == nullptr) return;
         
        if(val < r->val) {
            if(r->left != nullptr && val > r->left->val) {
                insert(r->left, val);
            }else{
                bnode<T>* t = new bnode<T>;
                t->val = val;
                t->left = r->left;
                r->left = t;
               return;
            }
        } else {
             if(r->right != nullptr && val > r->right->val) {
                insert(r->right, val);
            }else{
                bnode<T>* t = new bnode<T>;
                t->val = val;
                t->right = r->right;
                r->right = t;
               return;
            }
        }
    }
};

int main()
{
    bstree<int> bst;
    bnode<int>* r = bst.buildbst();
    cout << setw(10);
    bst.postorder(r, 0);
//    cout << endl;   
   // bst.clean(&r);
   // bst.preorder(r);
   bst.insert(r, 4);
  bst.postorder(r, 0);
  // cout << endl;
   bst.insert(r, 6);
   bst.postorder(r, 0);
  // cout << endl; 

   bst.insert(r, 11);
   bst.postorder(r, 0);
  // cout << endl;
   bst.insert(r, 0);
   bst.postorder(r, 0);
  // cout << endl;
    return 0;
}

