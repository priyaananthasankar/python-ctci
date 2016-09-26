// Author : Priya Ananthasankar
// Goal: Given an unsorted linked list, remove the duplicates
// Commands: g++ 2.1.cpp; ./a.out
#include <iostream>
#include <map>
using namespace std;

struct Node{
		int x;
		Node* next;
	};

class LinkedList {
	


private: Node *head; int length;

public:
	LinkedList(){
		head = NULL;
		length = 0;
	}

	// Add nodes to a linked list
	void addValue(int n){
		// As we add the nodes we determine the length
		Node *newNode = new Node();
		newNode->x = n;
		newNode->next = head;
		head = newNode;
		length = length + 1;
	}

	// Delete a node from a linked list
	int deleteValue(){
		
		Node* n = head;
		int val = head -> x;
		head = head -> next;
		delete n;
		return val;
	}

	// Print the linked list
	void print(){
		Node *start = head;
		cout << "****** LINKED LIST ******" << endl;
		while(start != NULL){
			cout << start -> x << "->";
			start = start -> next;
			if(start == NULL){
				cout << "NULL" << endl;
			}
		}
	}

	Node* getHead(){
		return head;
	}

	int getLength(){
		return length;
	}

};

void removeDuplicates(LinkedList* l){
	Node* p1 = l->getHead();
	Node* p2; Node* dup;

	while(p1 != NULL && p1->next != NULL){
		p2 = p1;
		while(p2 -> next != NULL){
			if(p1->x == p2->next->x){
				dup = p2->next;
          		p2->next = p2->next->next;
          		free(dup);
			}else{
				p2 = p2-> next;
			}
		}
		p1 = p1->next;
	}
}


int main(){

	int l=0;
	cout<<"Enter the set of numbers length:" << endl;
	cin >> l;

	int num; LinkedList l1; int k;


	cout <<"Enter the numbers one by one" << endl;
	for(int i=0;i<l;i++){
		cin >> num;
		l1.addValue(num);
	}

	cout <<"With duplicates"<< endl;
	l1.print();

    removeDuplicates(&l1);

	cout <<"Without duplicates"<< endl;
    l1.print();
}