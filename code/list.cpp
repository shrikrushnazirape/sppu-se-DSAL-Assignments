//============================================================================
// Name        : LinkedList_practice_assignment.cpp
// Author      : Shrikrushna Zirape
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node{
	int data;
	Node *next;
public:
	Node(){
		data=0;
		next=NULL;
	}

	Node(int k){
		data = k;
		next = NULL;
	}

	friend class LinkedList;
};


class LinkedList{
public:
	Node *head;

	LinkedList(){
		head =NULL;
	}
	void addAtEnd(int k);
	void addAtBegin(int k);
	void addBefore(int before, int data);
	void addAfter(int after, int data);
	void addAtLocation(int add, int data);
	void deleteByKey(int key);
	void printAllList();
	void printReverse(Node *temp);
	void makeListReverse();
	void unionOfList(LinkedList a, LinkedList b);
	void intersectionOfList(LinkedList a, LinkedList b);
	bool is_present(int key);
	void conList(LinkedList a, LinkedList b);

};

void LinkedList::addAtEnd(int k){
	Node *NewNode = new Node(k);
	if(head == NULL){
		head = NewNode;
	}
	else{
		Node *temp2 = head;
		while(temp2->next != NULL){
			temp2 = temp2->next;
		}
		temp2->next=NewNode;
	}
}

void LinkedList::addAtBegin(int k){
	Node *NewNode = new Node(k);
	if(head == NULL){
		head = NewNode;
	}
	else{
		NewNode->next = head;
		head = NewNode;
	}
}

void LinkedList::addBefore(int before, int data){
	Node *current = head;
	Node *previous = NULL;
	while(current->data != before){
		previous = current;
		current = current->next;
	}
	Node *NewNode= new Node(data);
	NewNode->next = current;
	previous->next = NewNode;
}

void LinkedList::addAfter(int after, int data){
	Node *current = head;
	while(current-> data != after){
		current=current->next;
	}
	Node *NewNode=new Node(data);
	NewNode->next = current->next;
	current->next = NewNode;

}
void LinkedList::addAtLocation(int add, int data){
	Node *temp = head;
	while(temp != NULL){
		if(temp->data == add){
			temp->data =data;
			cout<<"modified at location\n";
		}
		temp = temp->next;
	}
	cout<<"Address not found\n";
}
void LinkedList::deleteByKey(int k){
	if (head == NULL) {
		      cout << "Singly Linked List already Empty. Can't delete" << endl;
		    } else if (head != NULL) {
		      if ( head-> data == k) {
		        head = head -> next;
		        cout << "Node UNLINKED with  value : " << k << endl;
		      } else {
		        Node * temp = NULL;
		        Node * prevptr = head;
		        Node * currentptr = head -> next;
		        while (currentptr != NULL) {
		          if (currentptr -> data == k) {
		            temp = currentptr;
		            currentptr = NULL;
		          } else {
		            prevptr = prevptr -> next;
		            currentptr = currentptr -> next;
		          }
		        }
		        if (temp != NULL) {
		          prevptr -> next = temp -> next;
		          cout << "Node UNLINKED with  value : " << k << endl;
		        } else {
		          cout << "Node Doesn't exist with  value : " << k << endl;
		        }
		      }
		    }
}

void LinkedList::printAllList(){
		if(head == NULL){
			cout<<"nothing to show \n";
		}
		else{
			Node *temp = head;
			while(temp != NULL){
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<endl;
		}
}

void LinkedList::printReverse(Node *temp){
	if(temp==NULL){
		return;
	}
	LinkedList::printReverse(temp->next);
	cout<<temp->data<<"\t";

}

void LinkedList::makeListReverse(){
	Node *current, *previous, *next;
	current = head;
	previous =NULL;
	next = NULL;
	while(current != NULL){
		next=current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	head=previous;
}
bool LinkedList::is_present(int key){
    bool check=false;
    if(head == NULL){
        return false;
    }
    else{
        Node *temp=head;
        while (temp != NULL){
            if(temp->data == key){
                check=true;
            }
            temp=temp->next;
        }
        return check;
    }
}

void LinkedList::unionOfList(LinkedList a, LinkedList b){

    Node *tempa =  a.head;
    Node *tempb =  b.head;
    while (tempa != NULL){
        if(is_present(tempa->data)==false){
            addAtEnd(tempa->data);
        }
        tempa=tempa->next;
    }
    while (tempb != NULL){
        if(is_present(tempb->data)==false){
            addAtEnd(tempb->data);
        }
        tempb= tempb->next;
    }
}


void LinkedList::conList(LinkedList a, LinkedList b){

    Node *tempa =  a.head;
    Node *tempb =  b.head;
    while (tempa != NULL){
         addAtEnd(tempa->data);
        tempa=tempa->next;
    }
    while (tempb != NULL){
        addAtEnd(tempb->data);
        tempb= tempb->next;
    }
}



void intersectionOfList(LinkedList a, LinkedList b){
//     Node *temp=a.head;
//     while(temp != NULL){
//         if(b.is_present(temp->data)){
//             if(a.is_present(temp->data) == false){
//            	 addAtEnd(temp->data);
//             }
//         }
//         temp=temp->next;
//     }

 }



int main() {

	LinkedList l;
	int location, data;
	int ch;

	return 0;
}
