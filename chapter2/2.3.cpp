// Author : Priya Ananthasankar
// Goal: Given a linked list and access to only a specific node and not the head node,
// delete item from the linked list.
// Commands: g++ 2.3.cpp; ./a.out
#include <iostream>
using namespace std;

struct Node{
		char x;
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
	void addValue(char n){
		// As we add the nodes we determine the length
		Node *newNode = new Node();
		newNode->x = n;
		newNode->next = head;
		head = newNode;
		length = length + 1;
	}

	// Delete a node from a linked list
	char deleteValue(){
		
		Node* n = head;
		char val = head -> x;
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

};

Node* findNode(LinkedList* l,char c){
	Node* start = l->getHead();
	while(start != NULL){
		if(start->x == c){
			return start;
		}
		start = start -> next;
	}
	return NULL;
}

char deleteNode(LinkedList* l, Node* n){
	char ch = n->x;
	while(n->next->next != NULL){
		n->x = n->next->x;
		n = n->next;
	}
	n->x = n->next->x;
	n->next = NULL;
	delete n->next;
	return ch;
}

int main(){

	// Enter a sample string
	string s; char val;
	cout << "Enter a string: "<< endl;
	cin >> s;

	LinkedList l;

	for (int k=0;k<strlen(s.c_str());k++){
		l.addValue(s[k]);
	}

	cout << "Enter the value to be deleted "<< endl;
	cin >> val;
	cout << "BEFORE" << endl;
	l.print();
	Node* node = findNode(&l,val);
	cout << "AFTER" << endl;
	cout << deleteNode(&l,node) << " was removed" << endl;
	l.print();	
}