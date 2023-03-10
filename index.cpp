#ifndef __INDEX_CPP
#define __INDEX_CPP
#include "index.h"
#include "string"
#include "LinkedList.h"
#include "LinkedList.cpp"
#include<iostream>
#include <fstream>
#include <vector>
#include "avl.cpp"
#include "avl.hpp"
#include <sstream>
#include <algorithm>
#include <iterator>
#include <functional>
#include <ctype.h>
using namespace std;


Index::Index() {
	//TODO	

wordsTree = new AVL<string,LinkedList<int>>();
wordsTree= NULL;
}

Index::~Index(){  
	//OPTIONAL
}

void Index::initialize(string wordsFile) {
	//TODO
	

	wordsTree = new AVL<string,LinkedList<int>>();
	int i = 0;
	ifstream file;
	file.open(wordsFile);

	if(file.is_open()){
		string line,word;
		
			while(getline(file,line)){
				++i;

				istringstream is(line);
			while(is >> word){
				
				word = punctuationSmall(word);
					node<string,LinkedList<int>> *wow = findWord(word);
				if(wow==NULL)
				 {
		//	wordsTree = new AVL<string,LinkedList<int>>();
				 LinkedList<int> list=LinkedList<int>();
				  list.insertAtHead(i);
				  // int z = word.size();
				
		
				node<string,LinkedList<int>> *x= new node<string,LinkedList<int>>(word, list);
			
				//cout << x->value;
				//wordsTree->insertNode(x);

				insertWord(x);
		
				}
				else if(wow!=NULL)
				{
					ListItem<int> *temp = wow->value.getHead();
					bool duplicate = 0; //bool so no duplicate line numbers stored
					while(temp!=NULL)
					{

						if (temp->value == i)
						{
							duplicate = 1;
						}
						temp = temp->next;
					}
					if(duplicate!=1)
					{
						wow->value.insertAtTail(i);
					}
					
				}
				// 	cout << "ERROR";

				// 	// node<string,LinkedList<int>> *temp =wordsTree->searchNode(word);
				// 	// cout << "ERROR2";
				// 	// cout << temp->value;
				// 	// // // cout << temp->value;
				// 	// // cout << list2;
				// 	// list2.insertAtTail(i);
				// // 	// temp->value = list2;
				// // 	//temp->value.LinkedList->insertAtTail(i);
				// }

			}
			
		
	}
	}
	else{
		cout << "error, no such word file exists";
	}

	cout << "Input file has been processed, generating output file:";
	ofstream output("output.txt");
	print(wordsTree->getRoot(),output);
	cout << "\nThe output file has been generated by the name of output.txt, in case of a line containing the same word more than once, that line has only been counted once";
}


void Index::print(node<string,LinkedList<int>>* x, ofstream& output)
{
	if(x==NULL)
    {
        return;
    }
    else{
        print(x->left,output);
        output << x->key;
        output << " ";
        ListItem<int> *y = x->value.getHead();
        while(y!=NULL)
        {
        	output<< y->value;
        	if(y->next!=NULL)
        	{
        		output<<",";
        	}
        	y=y->next;
        }
        output<< endl;
       	print(x->right,output);
    }
}
string Index::punctuationSmall(string word){


word.erase (std::remove_if (word.begin (), word.end (), ::ispunct), word.end ());

   for (int i = 0, length = word.size(); i < length; i++)
    {
        if (word[i]<0 or word[i]>127)
        {
        	// cout << "I RUN";
         word.erase(i--, 1);
         length = word.size();
        }
    }

  for (int i = 0, length = word.size(); i < length; i++)
    {
        if(word[i] >= 'A' and word [i]<= 'Z')
        {
        	word[i] = word[i] + 32;
        }
    }
    return word;
//cout << word <<endl;
//std::cout << words << endl;
// 	int z = word.length();
// 	if(word.substr(z-1,1)=="." or word.substr(z-1,1)=="?" or word.substr(z-1,1)=="," or word.substr(z-1,1)=="!" or word.substr(z-1,1)==":" or word.substr(z-1,1)==";" or word.substr(z-1,1)=="-" or "'")
// 	{


// 	return word.substr(0,z-1);
// }
// else{
// 	return word;
// }
}
void Index::deleteWord(string word) {
	//TODO
	wordsTree->deleteNode(word);

}

void Index::editWord(string oldWord, string newWord) {
	//TODO
	node<string,LinkedList<int>>* wow = findWord(oldWord);
	wow->key = newWord;

	


}

void Index::insertWord(node<string,LinkedList<int>>* word) {

 wordsTree->insertNode(word);
}
node<string,LinkedList<int>>* Index::findWord(string word) {
	node<string,LinkedList<int>> *wow = wordsTree->searchNode(word);
	return wow;
}

#endif

int main() {

	string wordsFile = "words.txt.txt";
	Index g;
	g.initialize(wordsFile);
	// cout << "THE WORD IS";
	// cout<< "\nediting\n";
	// // g.editWord("york","hannan");
	//g.deleteWord("york");
//	g.wordsTree->preOrderTraversal(g.wordsTree->getRoot());

	// cout << g.findWord("hannan")->value;
	// cout << g.findWord("york")->key;

}
