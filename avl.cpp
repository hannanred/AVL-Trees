#ifndef __AVL_CPP
#define __AVL_CPP

#include <iostream>
#include "avl.hpp"
#include "string"
using namespace std;


template <class T, class S>
AVL<T,S>::AVL(){
    root = NULL;
    
}

template <class T, class S>
AVL<T,S>:: ~AVL(){

    if(root==NULL)
    {
        return;
    }
    else if(root->left != NULL and root->right!=NULL)
    {
        treeDestruct(root);
    }
    
}
template <class T, class S>
void AVL<T,S> :: treeDestruct (node<T,S>* r)
{
    if (r==NULL)
    {
        return;
    }
    treeDestruct(r->left);
    treeDestruct(r->right);
    delete r;

}

template <class T, class S>
int AVL<T,S> :: height (node<T,S>* p){
    return heightFinder(p);
}

template <class T, class S>
int AVL<T,S> :: heightFinder (node<T,S>* p){
 if(p != NULL and p->left == NULL and p->right == NULL)
    {

        return 1;
    }
    else if(p==NULL)
    {
        return 0;
    }
       
 else{
            int l =  heightFinder(p->left);
            int r =  heightFinder(p->right);
            
        if (r<l)
            {
                
                    
                  return l+1;
            }
            else 
            {
            
                    return r+1;
            }
        }

}



template <class T, class S>
void AVL<T,S> :: insertNode(node<T,S>* newNode){
    node<T,S> *trav = root;

if(trav == NULL)
    {
        root = newNode;
        root->left = NULL;
        root->right=NULL;
        root->parent = NULL;
        
    }
else {
        insertNodeTrav(newNode, trav);
     }
   
     heightSetter(getRoot());
    
   
    

        
     heightSetter(getRoot());
     updateParents(getRoot());
 
      makeAVL(newNode);
   
      updateParents(getRoot());

 }


template <class T, class S>
void AVL<T,S>::makeAVL(node<T,S>* p){

    node<T,S>* temp = p;
      node<T,S>* trav= p;
 //  cout << "HOHOHO" << endl;
      // cout << temp->key;
    while(temp->parent!=NULL)
    {
       // cout << "ERROR IS HERE" << endl;
     //   cout << temp->key << endl;
        temp = temp->parent;
        if(balanceFactor(temp)==2 or balanceFactor(temp)==-2)
        {
          //  cout << "BALANCING" << endl;
            makeAVL2(temp,trav);
        }
    
        // if(balanceFactor(temp) == 2 and gc!=child and child!=temp)
        // {
        //     if(gc==temp->left->left)
        //     {
        //         rightRotate(gc);
        //     }
        //     else if(gc == temp->left->right)
        //     {
        //         leftRightRotate(gc);
        //     }
        // }
        // else if(balanceFactor(temp) == -2 and gc!=child and child!=temp)
        // {
        //     if(gc==temp->right->right){
        //         leftRotate(gc);
        //     }
        //     else if(gc==temp->right->left){
        //         rightLeftRotate(gc);
        //     }
        // }

    }



}
template <class T, class S>
void AVL<T,S> ::makeAVL2(node<T,S>* temp,node<T,S>* trav){

    
    if(trav->parent != NULL and trav->parent->parent!=NULL)
    {
        while(trav->parent->parent != temp)
        {
            trav=trav->parent;
        }
    }



      if(balanceFactor(temp) == 2)
        {
            if(trav==temp->left->left)
            {
                rightRotate(trav);
            }
            else if(trav == temp->left->right)
            {
              
              leftRightRotate(trav);
            }
        }
        else if(balanceFactor(temp) == -2)
        {
            if(trav==temp->right->right){
              
                leftRotate(trav);
            }
            else if(trav==temp->right->left){
               
                rightLeftRotate(trav);
            }
        }


}

template <class T, class S>
void AVL<T,S> :: insertNodeTrav(node<T,S>* a, node<T,S>* b){    

    if(b->key < a->key)
    {
  
        if(b->right ==NULL)
        {
         
            b->right = a;
     
            a->left = NULL;
  
            a->right = NULL;
                 
            a->parent = b;
              
          
        }
        else{
         
            insertNodeTrav(a, b->right);
        }
    }
    else if(b->key > a->key)
    {
    
        if(b->left ==NULL)
        {
            b->left = a;
            a->right = NULL;
            a->left = NULL;
            a->parent = b;
           
        }
        else{
            insertNodeTrav(a, b->left);
        }
    }

}


template <class T, class S>
node<T,S>* AVL<T,S> :: searchNode(T key){
   
       return searchNodeT(root,key);
    
}

template <class T, class S>
node<T,S>* AVL<T,S> :: searchNodeT(node<T,S>* p, T k){
    if(p==NULL )
    { 
        return NULL;
    }
    else if(p->key == k)
    {
      //  cout << "WE SEARCH\n";
        //cout << p->key;
        return p;
    }
    else if(p->key < k)
    {
       return searchNodeT(p->right, k);
    }
    else if(p->key > k)
    {
       return searchNodeT(p->left, k);
    }
    
}
template <class T, class S>
void AVL<T,S>::preOrderTraversal(node<T,S>* p){

if(p==NULL)
    {
        return;
    }
    else{
        cout << p->key<<":"<<p->value << " ";
        preOrderTraversal(p->left);
        preOrderTraversal(p->right);
    }

}

template <class T, class S>
void AVL<T,S>::inOrderTraversalSpecial(node<T,S>* p){
if(p==NULL)
    {
        return;
    }
    else{
        inOrderTraversalSpecial(p->left);
        cout << p->key<< " " << p->value << endl;
        inOrderTraversalSpecial(p->right);
    }

}
template <class T, class S>
void AVL<T,S>::inOrderTraversal(node<T,S>* p){
if(p==NULL)
    {
        return;
    }
    else{
        inOrderTraversal(p->left);
        cout << p->key<<":" << p->value << " ";
        inOrderTraversal(p->right);
    }

}


template <class T, class S>
void AVL<T,S>::postOrderTraversal(node<T,S>* p){
    if(p==NULL)
    {
        return;
    }
    else{
        postOrderTraversal(p->left);
        postOrderTraversal(p->right);
        cout << p->key<<":"<<p->value << " ";
    }
}
template <class T, class S>
void AVL<T,S>::ender(node<T,S>* p){
if(p==NULL)
    {
        return;
    }
    else{
        ender(p->left);
        ender(p->right);
        p->value= 0;
    }

}
template <class T, class S>
void AVL<T,S>::deleteNode(T k){
cout << "DELETNIG";
    node<T,S>* temp = searchNode(k);
  
        if(root == NULL)
    {
        return;
    }
    else if(root->key == k and root->left==NULL and root->right == NULL)
    {
        root->left = NULL;
        root->right = NULL;
        root = NULL;
        delete root;
    }
    else 
    {
        deleter(k, root);
    }
    heightSetter(getRoot());
   updateParents(getRoot());
    heightSetter(getRoot());


    makeAVLdel(temp);
 
}
template <class T, class S>
void AVL<T,S>::heightSetter(node<T,S>* p){

    if(p==NULL)
    {
        return;
    }
    else{
        root->height = height(p);
        heightSetter(p->left);
        heightSetter(p->right);
    }


}
template <class T, class S>
void AVL<T,S>::makeAVLdel(node<T,S>* t){
    if(t==NULL)
    {
        return;
    }
else{
    while(t!=NULL){
     
    
        if(balanceFactor(t)==2 or balanceFactor(t)==-2){
           
            makeAVLdel2(t);
          
        }
    t = t->parent;
    }
}
}
template <class T, class S>
void AVL<T,S>::makeAVLdel2(node<T,S>* t){
  //  cout << "WE GON BE ROTATING";
    //cout << t->key;
    node<T,S>* y;
    node<T,S>* z;
    int o = height(t->right);
    int po = height(t->left);
    if(o > po){
        y = t->right;
    }
    else{
        y = t->left;
    }
    int xD = height(y->right);
    int sad = height(y->left);
     if(xD > sad){
        z = y->right;
    }
    else{
        z = y->left;
    }

     if(balanceFactor(t) == 2)
        {
            if(z==t->left->left)
            {
               // cout << "Rightrotating";
                rightRotate(z);
            }
            else if(z == t->left->right)
            {
             // cout << "LRROTATING";
                leftRightRotate(z);
            }
        }
        else if(balanceFactor(t) == -2)
        {
            if(z==t->right->right){
             // cout << "LEFT ROTATING";
                leftRotate(z);
            }
            else if(z==t->right->left){
              // cout << "RIGHT LEFT ROTATING";
                rightLeftRotate(z);
            }
        }

}
template <class T, class S>
void AVL<T,S>::deleter(T k,node<T,S>* x)
{
    node<T,S>* temp;
    if(k>x->key)
    {
        deleter(k,x->right);
    }
    else if(k<x->key)
    {
        deleter(k,x->left);
    }
    else if(x->key == k)
    {
        if(x->left == NULL and x->right == NULL)
        {
            if(x->parent->right == x)
            {
                x->parent->right = nullptr;
            }
            else if(x->parent->left==x)
            {
                x->parent->left=nullptr;
            }
            delete x;
            x= nullptr;
            
        
            // cout << "no key"<<endl;
        }
        else if(x->left != NULL and x->right == NULL)
        {

                temp=x->left;
                if(x->parent->right == x)
            {
                x->parent->right = temp;
            }
            else if(x->parent->left==x)
            {
                x->parent->left=temp;
            }
                
                delete x;
                x = nullptr;

        }
            else if(x->right != NULL and x->left == NULL)
            {
                temp=x->right;
                if(x->parent->right == x)
            {
                x->parent->right = temp;
            }
            else if(x->parent->left==x)
            {
                x->parent->left=temp;
            }
                
                delete x;
                x = nullptr;
            }
        else if(x->right != NULL and x->left!=NULL)
        {
            temp = forMerging(x->right);
            node<T,S> * a = x->parent;
            node <T,S> * b = x->right;
            node <T,S> * c = x->left;
           x->key = temp->key;
           x->value = temp->value;
           x->right = b;
           x->left = c;
           x->parent = a;
            if(temp->right != NULL and temp->parent == x)
            {
                
                x->right = temp->right;
                temp->left = NULL;
                temp->right = NULL;
                temp->parent= NULL;
           
                temp = NULL;
              delete temp;
        
            }
            else if (temp->right == NULL and temp->parent == x){
              
               x->right = nullptr;
               temp->left = NULL;
                temp->right = NULL;
                temp->parent= NULL;
            
             
               temp = NULL;
               delete temp;
            
        }
        else if(temp->right != NULL and temp->parent != x){
        
            temp->parent->left = temp->right;
            temp->left = NULL;
                temp->right = NULL;
                temp->parent= NULL;
         
              
            temp = NULL;
            delete temp;
        }
        else if(temp->right == NULL and temp->parent !=x){
        
            temp->parent->left = NULL;
            temp->left = NULL;
                temp->right = NULL;
                temp->parent= NULL;
           
            
            temp = NULL;
            delete temp;
        
        }
      
        
        }

        }
    }
template <class T,class S>
node<T,S>* AVL<T,S>::forMerging(node<T,S> *x){
    while(x->left != NULL)
    {
        x= x->left;

    }
    return x;
}

template <class T, class S>
node<T,S>* AVL<T,S>::getRoot(){
    return root;
}

template <class T, class S>
node<T,S>* AVL<T,S>::rightRotate(node<T,S>* p) {



    node<T,S>* ancestor = p->parent->parent;
   
    node<T,S>* parentt = p->parent;
 

   if(ancestor->parent == NULL)
   {
    root = parentt;
    parentt->parent=NULL;

    ancestor->left = parentt->right;
    parentt->right = ancestor;
    ancestor->parent = parentt;
    p->parent = parentt;
 
    
   }

    else if(ancestor->parent->right == ancestor)
    {
      
        ancestor->parent->right = parentt;
        parentt->parent = ancestor->parent;
       
        ancestor->left = parentt->right;
    parentt->right = ancestor;
     ancestor->parent = parentt;
    p->parent = parentt;
    
    }

    else if(ancestor->parent->left == ancestor)
    {
       
        ancestor->parent->left = parentt;
        parentt->parent=ancestor->parent;
        ancestor->left = parentt->right;
    parentt->right = ancestor;
     ancestor->parent = parentt;
    p->parent = parentt;
    }

updateParents(getRoot());
return p;
}

template <class T, class S>
node<T,S>* AVL<T,S>::leftRotate(node<T,S>* p) {

   node<T,S>* ancestor = p->parent->parent;
    node<T,S>* parentt = p->parent;

   if(ancestor->parent == NULL)
   {

    root = parentt;
parentt->parent = NULL;
    ancestor->right = parentt->left;
    parentt->left = ancestor;
     ancestor->parent = parentt;
    p->parent = parentt;
   
   }

   else if(ancestor->parent->right == ancestor)
    {
      
   
        ancestor->parent->right = parentt;
       parentt->parent = ancestor->parent;
        ancestor->right = parentt->left;
    parentt->left = ancestor;
     ancestor->parent = parentt;
    p->parent = parentt;
    
    }

    else if(ancestor->parent->left == ancestor)
    {

        ancestor->parent->left = parentt;
        parentt->parent = ancestor->parent;
       ancestor->right = parentt->left;
    parentt->left = ancestor;
     ancestor->parent = parentt;
    p->parent = parentt;
    }
updateParents(getRoot());
return p;
}

template <class T, class S>
node<T,S>* AVL<T,S>::leftRightRotate(node<T,S>* p){

    node<T,S>* ancestor = p->parent->parent;
    node<T,S>* parentt = p->parent;
    if(ancestor->parent == NULL)
   {
   ancestor->left = parentt->right;
    parentt->right = p->left;
    p->left = parentt;
    root = p;
       p->parent = NULL;
    ancestor->left = p->right;
    p->right = ancestor;
    ancestor->parent = p;
    parentt->parent = p;
 

   }
   
   else if(ancestor->parent->right == ancestor)
    {
      
       ancestor->left = parentt->left;
    parentt->right = p->left;
    p->left = p->parent;
    ancestor->parent->right = p;
    p->parent = ancestor->parent;
    ancestor->left = p->right;
    p->right = ancestor;
    ancestor->parent = p;
    parentt->parent = p;


    }

    else if(ancestor->parent->left == ancestor)
    {
    
      ancestor->left = parentt->left;
    parentt->right = p->left;
    p->left = p->parent;
    ancestor->parent->left = p;
    p->parent = ancestor->parent;
    ancestor->left = p->right;
    p->right = ancestor;
    ancestor->parent = p;
    parentt->parent = p;


    }

updateParents(getRoot());
return p;
}

template <class T, class S>
node<T,S>* AVL<T,S>::rightLeftRotate(node<T,S>* p){

    node<T,S>* ancestor = p->parent->parent;
    node<T,S>* parentt = p->parent;
    if(p->parent->parent->parent == NULL)
   {
   ancestor->right = parentt->left;
    parentt->left = p->right;
    p->right = parentt;
    root = p;
    p->parent = NULL;
    ancestor->right = p->left;
    p->left = ancestor;
    ancestor->parent = p;
    parentt->parent = p;

 
   }
   
   else if(ancestor->parent->right == ancestor)
    {
      
       ancestor->right = parentt->left;
    parentt->left = p->right;
    p->right = parentt;
    ancestor->parent->right = p;
    p->parent = ancestor->parent;
    ancestor->right = p->left;
    p->left = ancestor;
    ancestor->parent = p;
    parentt->parent = p;


    }

    else if(ancestor->parent->left == ancestor)
    {
    
    ancestor->right = parentt->left;
    parentt->left = p->right;
    p->right = parentt;
    ancestor->parent->left = p;
    p->parent= ancestor->parent;
    ancestor->right = p->left;
    p->left = ancestor;
    ancestor->parent = p;
    parentt->parent = p;

    }
updateParents(getRoot());
return p;

}
template <class T, class S>
void AVL<T,S>::updateParents(node<T,S>* current){

    if (current == NULL)
    {
        return;
    }
    updateParents(current->left);
    findParent(getRoot(),getRoot(),current->key);
    updateParents(current->right);
}
template <class T, class S>
void AVL<T,S>::findParent(node<T,S>* child, node<T,S>* parentt,T k)
{
    if(child==NULL)
    { 
        return;
    }
      else if(child==parentt and child->key==k)
    {
        return;
    }
    else if(child->key < k)
    {
        findParent(child->right, child, k);
    }
    else if(child->key > k)
    {
        findParent(child->left,child, k);
    }
    else if(child!=parentt and child->key==k)
    {
        child->parent = parentt;
    }
   
}
template <class T, class S>
int AVL<T,S>::balanceFactor(node<T,S>* p){
//heightofleftsub-heightofrightsub
return (height(p->left)- height(p->right));
}

// int main()
// {
//     //55,43,26,82,93,04,39,95,50,6,62,17,21,49,77,5,32,60,88,16,44,72,80,8,36
//         AVL<string,string> B;
// //cout << "1";
//         B.insertNode(new node<string,string>("e","abc"));
//      ///   cout << "2";

//  B.insertNode(new node<string,string>("c","abc"));
//  //cout << "3";
//   B.insertNode(new node<string,string>("f","abc"));
//    B.insertNode(new node<string,string>("b","abc"));
//      B.insertNode(new node<string,string>("d","abc"));
//        B.insertNode(new node<string,string>("g","abc"));
//          B.insertNode(new node<string,string>("a","abc"));
//    B.deleteNode("g");
//      B.insertNode(new node<string,string>("a","abc"));
// B.preOrderTraversal(B.getRoot());
//     //lrworking

// }
#endif