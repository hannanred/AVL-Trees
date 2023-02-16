#include "avl.cpp"
#include "string"
#ifndef __AVL_HPP
#define __AVL_HPP


template <class T, class S>
struct node{
    T key;
    S value; 
    node *left;
    node *right;
    int height;
    node *parent; 

    node (T key, S value){
        this->key = key;
        this->value = value;
        left = NULL;
        right = NULL;
        parent = NULL;
        height = 1;
    }
};


template <class T, class S>
class AVL {
    node<T,S> *root;
    
public:
    AVL();
    ~AVL();
     void treeDestruct(node<T,S>*);
    void insertNode(node<T,S>* p);
    void deleteNode(T k);    
    node<T,S>* searchNode(T k);
    node<T,S>* getRoot();
    int height (node<T,S>* p);
       void inOrderTraversal(node<T,S>* p);
    void postOrderTraversal(node<T,S>* p);
    void preOrderTraversal(node<T,S>* p);
     void insertNodeTrav(node<T,S>* z, node<T,S>* y);
     node<T,S>* searchNodeT(node<T,S>* p, T k);
      void deleter(T k, node<T,S>* x);
    node<T,S>* forMerging(node<T,S> *x);
    int heightFinder (node<T,S>* p);
    void ender(node<T,S>* p);
    node<T,S>* rightRotate(node<T,S>* p);
    node<T,S>* leftRotate(node<T,S>* p);
    node<T,S>* leftRightRotate(node<T,S>* p);
    node<T,S>* rightLeftRotate(node<T,S>* p);
    int  balanceFactor(node<T,S>* p);
    void heightSetter(node<T,S>* p);
    void makeAVL(node<T,S>* p);
     void makeAVL2(node<T,S>* temp, node<T,S>* trav);
      void makeAVLdel(node<T,S>* t);
       void makeAVLdel2(node<T,S>* t);
        void findParent(node<T,S>* child, node<T,S>* parentt,T k);
        void updateParents(node<T,S>* current);
       
    void inOrderTraversalSpecial(node<T,S>* p);
};


#endif