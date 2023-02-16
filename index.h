#ifndef __INDEX_H
#define __INDEX_H
#include <string>
#include "avl.hpp"
#include "LinkedList.h"
using namespace std;

class Index {
	private:
	AVL<string,LinkedList<int>> *wordsTree;
    public:
    
    Index(); // creates an empty (i.e. without words) Index object
    ~Index(); // frees the memory occupied by nodes containing words

    void initialize(string wordsFile); // populates words read from wordsFile into wordsTree, wordsFile is the name of the file

    node<string,LinkedList<int>>* findWord(string word); // corresponds to node<T>* search(T k, S val) 
    void deleteWord(string word); // corresponds to void delete_node(T k, S val) 
    void editWord(string oldWord, string newWord); // changes the key
    void insertWord(node<string,LinkedList<int>>* word); // corresponds to void insert(node<T,S> p)
   string punctuationSmall(string word);
   void print(node<string,LinkedList<int>>* x,ofstream& output);
  
};

#endif
