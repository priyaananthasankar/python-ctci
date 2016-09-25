// Author : Priya Ananthasankar
// Goal: Given 2 linked lists, where numbers are stored in reverse order, add the lists.
// Commands: g++ 2.4.cpp; ./a.out
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

LinkedList partitionLinkedList(LinkedList* l, int val){

	LinkedList l2; LinkedList l3;
	Node* start = l->getHead();
	while(start != NULL){
		int curr = start -> x;
		if(curr < val){
			l2.addValue(curr);
		}else{
			l3.addValue(curr);
		}
		start = start->next;
	}
	start = l2.getHead();
	while(start-> next != NULL){
		start = start -> next;
	}
	start->next = l3.getHead();
	return l2;

}

int main(){
	
	int l=0;
	cout<<"Enter the set of numbers length:" << endl;
	cin >> l;

	int num; LinkedList l1; 


	cout <<"Enter the numbers one by one" << endl;
	for(int i=0;i<l;i++){
		cin >> num;
		l1.addValue(num);
	}

    int partition =0;
	cout << "Enter the value around which you want to partition" << endl;
	cin >>  partition;
	l1.print();

	LinkedList final_list = partitionLinkedList(&l1, partition);
	final_list.print();
	
}