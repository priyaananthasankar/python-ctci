// Author : Priya Ananthasankar
// Goal: Given 2 linked lists, where numbers are stored in reverse order, add the lists.
// Commands: g++ 2.5.cpp; ./a.out
#include <iostream>
using namespace std;

struct Node{
		int x;
		Node* next;
	};

class LinkedList {
	


private: Node *head; 

public:

	int length;
	LinkedList(){
		head = NULL;
		length = 0;
	}

	Node* getHead(){
		return head;
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
		//cout << length;
	}
};

int addLists(LinkedList* l3,Node* start_l1, Node* start_l2,int carry){
	int sum = 0;
	if(start_l1 != NULL){
		int d1 = start_l1 -> x;
		int d2 = start_l2 -> x;
		sum = d1 + d2 + carry;
		if (sum > 10){
			carry = 1; 
			sum = sum - 10;
		} else{
			carry = 0;
		}
		addLists(l3,start_l1->next,start_l2->next,carry);
		l3->addValue(sum);
	}
	if(start_l1 == NULL && carry != 0){
		l3 -> addValue(carry);
	}
	return sum;
}

int main(){

	// Enter a sample number
	string n1;
	cout << "Enter a number: "<< endl;
	cin >> n1;

	string n2;
	cout << "Enter a number: "<< endl;
	cin >> n2;

	LinkedList l1; LinkedList l2;

	if(strlen(n1.c_str()) > strlen(n2.c_str())){
		//pad l2 with zeroes
		int diff = strlen(n1.c_str()) - strlen(n2.c_str());
		for(int k=0;k<diff;k++){
			l2.addValue(0);
		}

	}else if(strlen(n2.c_str()) > strlen(n1.c_str())){

		int diff = strlen(n2.c_str()) - strlen(n1.c_str());
		for(int k=0;k<diff;k++){
			l1.addValue(0);
		}
	}

	for (int k=0;k<strlen(n1.c_str());k++){
		 int a = n1[k] - 48;
		 l1.addValue(a);
	}

	for (int k=0;k<strlen(n2.c_str());k++){
		 int a = n2[k] - 48;
		 l2.addValue(a);
	}
	
	l1.print();
	l2.print();

	Node* start_l1 = l1.getHead();
	Node* start_l2 = l2.getHead();
	int carry = 0;
	LinkedList* l3 = new LinkedList();
	addLists(l3,start_l1,start_l2,carry);
	l3 -> print();
}