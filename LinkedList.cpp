#ifndef __LIST_CPP
#define __LIST_CPP
using namespace std;
#include <cstdlib>
#include "LinkedList.h"
#include <iostream>
template <class T>
LinkedList<T>::LinkedList()
{
	head = NULL;
}
template <class T>
ostream& operator<<(ostream& os, const LinkedList<T>& list)
{
	ListItem<T>* ptr;
	ptr = list.getHead2();
	while(ptr!=NULL)
	{
		os<< ptr->value;
		if(ptr->next != NULL)
		{
			cout << ",";
		}
		ptr=ptr->next;
	}
    return os;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& otherLinkedList)
{
	

	if (otherLinkedList.head == NULL)
      {

       head = tail = NULL;  
       }                     
    else
    { 
        head = new ListItem<T>( otherLinkedList.head->value );     
        ListItem<T>* temp2 = otherLinkedList.head->next;
        ListItem<T>* temp = head;
        while (temp2 != NULL)
        {
            temp->next = new ListItem<T>( temp2->value ); 
            temp = temp->next;                                      
            temp2 = temp2->next;                            
        }
        tail = temp;
    } 
    
}

template <class T>
LinkedList<T>::~LinkedList()
{
	while(head)
	{
        head = head->next;
        delete head;
	}
}

template <class T>
void LinkedList<T>::insertAtHead(T item)
{
	if(head == NULL)
	{
		ListItem<T>* node= new ListItem<T>(item);
		node->value = item;
		head=node;
		tail=node;
	}
	else
	{
		ListItem<T>* temp = new ListItem<T>(item); 
		temp->value = item;
		temp->next = head;
		head->prev = temp;
		head = temp;
    }
}

template <class T>
void LinkedList<T>::insertAtTail(T item)
{
	if(head == NULL)
	{
		insertAtHead(item);
		return;
	}
	ListItem<T>* temp = new ListItem<T>(item);
	temp->value=item;
	tail->next = temp;
	temp->prev=tail;
	tail=temp;
}

template <class T>
void LinkedList<T>::insertAfter(T toInsert, T afterWhat)
{

	ListItem<T>* prev = searchFor(afterWhat);
	ListItem<T>* new_order = new ListItem<T>(toInsert);
	new_order->value = toInsert;

	new_order->next = prev->next;
	prev->next = new_order;

	if (new_order->next != NULL) {
		new_order->next->prev=new_order;
	}


	// if(head == NULL)
	// {
	// 	return;
	// }
	// ListItem<T>* temp = head;
	// while(temp->value!=afterWhat && temp->next!=NULL)
	// {
	// 	temp = temp->next;
	// }
	// 	ListItem<T>* newnode = new ListItem<T>(toInsert);
	// 	newnode->value = toInsert;
	// 	if(temp == tail)
	// 	{
	// 		tail->next = newnode;
	// 		newnode->prev = tail;
	// 		tail = newnode;
	// 		return;

	// 	}
	// 	else
	// 	{
	// 		temp->next = newnode;
	// 		newnode->prev = temp;
	// 		if(temp->next == NULL)
	// 		{
	// 			newnode->next = NULL;
	// 		}
	// 		else
	// 		{
	// 			newnode->next = temp->next;
	// 			temp->next->prev=newnode;
	// 		}

	// 	}
		
	// return;
}


template <class T>
ListItem<T>* LinkedList<T>::getHead()
{
	return head;
}

template <class T>
ListItem<T>* LinkedList<T>::getTail()
{
	return tail;
}

template <class T>
ListItem<T> *LinkedList<T>::searchFor(T item)
{
	ListItem<T>* temp = head;
	if(head != NULL)
	{
		while(temp!=NULL)
		{
			if(temp->value == item)
			{
				break;
			}
			else
			{
				temp = temp->next;
			}
		}
	}
	return temp;

}

template <class T>
void LinkedList<T>::deleteElement(T item)
{
	ListItem<T>* temp = head;
	if(head == NULL)
	{
		return;
	}
	else if(head->value == item)
	{
		deleteHead();
		return;

	}
	else if(tail->value == item)
	{
		deleteTail();
		return;
	}
	
	else
	{
		
		while(temp->next!=NULL)
		{
			if(temp->value == item)
			{

				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				temp = NULL;
				return;
			}
			else
			{
				temp = temp->next;
			}
		}

	}

}

template <class T>
void LinkedList<T>::deleteHead()
{
	
	if(head->next == NULL)
	{
		head = NULL;
		tail = NULL;
	}
	else
	{	
		head = head->next;
		delete head->prev;
	}
	
	
}


template <class T>
void LinkedList<T>::deleteTail()
{

	if(tail->prev == NULL)
	{
	    head =  NULL;
		tail = NULL;
	}
	else
	{
		tail->prev->next = NULL;
		tail= tail->prev;
		delete tail->next;
	}
	
}

template <class T>
int LinkedList<T>::length()
{
	ListItem<T>* temp = head;
	int counter = 0;
	while(temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return counter;

}
#endif
