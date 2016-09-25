// Author : Priya Ananthasankar
// Goal: Given a corrupt circular linked list , return the node at the beginning of the loop
// (OR) identify if a given linked list is circular and return the node at the beginning of the loop.
// Commands: g++ 2.6.cpp; ./a.out
#include <iostream>
using namespace std;

struct Node{
		Node *next;
		char item;
	};

class LinkedList{
	

 private: Node* head;
 		  Node* circlePoint;

 public:

 LinkedList(){
 	head = NULL;
 	circlePoint = NULL;
 }

 void addNode(char c){
 	Node* node = new Node();
 	node -> item = c;
 	node -> next = head;
    head = node;	
 }

 char deleteNode(){
 	char c = head -> item;
 	Node* deletedNode = head;
 	head = head -> next;
 	delete deletedNode;
 	return c;
 }

 void makeCorruptCircular(char c){
 	Node* start = head;
 	Node* circularPoint;

 	while(start-> next != NULL){
 		char current = start -> item;
 		if (current == c){
 			circularPoint = start;
 		}
 		start = start -> next;
 	}
 	// reached end of the list - join the end with circular point
 	start->next = circularPoint;
 	circlePoint = circularPoint;
 }

 void print(){
 	Node *start = head;
		cout << "****** LINKED LIST ******" << endl;
		Node* circularPoint; int iter = 0;
		while(start != NULL){
		    
			cout << start -> item << "->";
			start = start -> next;
			if (start == circlePoint){
				if(iter == 1){ 
					cout << circularPoint -> item << "-> NULL" << endl;
					break;
				}
				circularPoint = circlePoint;
				iter = 1;
			}
		}
 }

 Node* getHead(){
 	return head;
 }
 };

Node* determineCollisionPoint(LinkedList* list){

	Node* slowPointer; Node* fastPointer;
	slowPointer = list -> getHead();
	// Its a circular linked list so one of these null checks is enough.
	if(slowPointer != NULL && slowPointer -> next != NULL){
		fastPointer = slowPointer -> next -> next;
		if(fastPointer != NULL){
			while(slowPointer != fastPointer){
				slowPointer = slowPointer -> next;
				fastPointer = fastPointer -> next -> next;
			}
			slowPointer = list -> getHead();
			fastPointer = fastPointer -> next -> next;
			while (slowPointer != fastPointer){
				fastPointer = fastPointer -> next;
				slowPointer = slowPointer -> next;

			}
			// Once slow pointer == fast pointer, it means we have confirmed
			// the location of the corrupt circular list collision point
			return slowPointer;
		}
	}
	return NULL;
}

int main(){

	string s; char corruptChar;
	cout << "Enter the string: " << endl;
	cin >> s;
	cout << "Enter a character in the string: " << endl;
	cin >> corruptChar;


	// Construct a corrupt circular linked list
	LinkedList* circ_l = new LinkedList();

	for(int i=0;i<strlen(s.c_str());i++){
		circ_l -> addNode(s[i]);
	}
	
	circ_l->makeCorruptCircular(corruptChar);
	//circ_l->print();
	Node* collisionPoint = determineCollisionPoint(circ_l);
	if(collisionPoint){
		cout << collisionPoint -> item << " is the collision point of the corrupt circular linked list" << endl;
	}
	else{
		cout << "Problem in the code";
	}

}

