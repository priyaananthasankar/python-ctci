// Author : Priya Ananthasankar
// Goal: Given a linked list find the kth item from the last without
// using the length of the linked list.
// Commands: g++ 2.2.cpp; ./a.out
#include <iostream>
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

};

int kthtoLast(LinkedList* l,int k){

	Node* fastPointer = l->getHead();
	Node* slowPointer = l->getHead();

	// advance the fast pointer immediately and 
	// introduce the slow pointer with a delay of k

	for(int i=0;i<k;i++){
		fastPointer = fastPointer-> next;
	}

	while(fastPointer != NULL){
		slowPointer = slowPointer-> next;
		fastPointer = fastPointer -> next;
	}
	return slowPointer -> x;

}


int main(){

	// Enter a sample string
	int l=0;
	cout<<"Enter the set of numbers length:" << endl;
	cin >> l;

	int num; LinkedList l1; int k;


	cout <<"Enter the numbers one by one" << endl;
	for(int i=0;i<l;i++){
		cin >> num;
		l1.addValue(num);
	}

	cout << "Enter the kth value" << endl;
	cin >>  k;
	l1.print();


    cout<< "The kth to last value is: " << kthtoLast(&l1,k)<< endl;
}