// Author : Priya Ananthasankar
// Goal: Write a program implement a queue using two stacks
// Commands: g++ 3.5.cpp; ./a.out
#include<iostream>
using namespace std;

struct Node{
		int x;
		Node* next;
	};

class Stack{

	private: 
		Node *top; 

public: 

	Stack(){
		top = NULL;
	}


	void push(int item){
		Node* newNode = new Node();		
		newNode->x = item;
		newNode -> next = top;
		top = newNode;
	}

	int pop(){
		int item = top -> x;
		Node* poppedNode = top;
		top = top-> next;
		delete poppedNode;
		return item;
	}

	void print(){
		Node *start = top;
		cout << "****** LINKED LIST ******" << endl;
		while(start != NULL){
			cout << start -> x << "->";
			start = start -> next;
			if(start == NULL){
				cout << "NULL" << endl;
			}
		}
	}

	Node* getTop(){
		return top;
	}

	bool isEmpty(){
		if(top == NULL){
			return true;
		}
		return false;
	}

};

/** Abstraction of Queue implemented using two stacks */
class Queue{

	private: 
		Stack *oldStack, *newStack;

	public:

		Queue(){
			oldStack = new Stack();
			newStack = new Stack();
		}

		void enqueue(int number){
			newStack->push(number);
		}

		int dequeue(){
			if(oldStack -> isEmpty()){
				Node* start = newStack->getTop();
				while(start != NULL){
					oldStack -> push(start -> x);
					start = start -> next;
				}
			}
			int item = oldStack -> pop();
			return item;
		}

};

int main(){
	Queue* q = new Queue();

	int n; int item;

	cout <<"Enter number of items: " << endl;
	cin >> n; 

	for (int i=0;i<n;i++){
		cin >> item;
		q -> enqueue(item);
	}

	// Demonstrate enqueue and dequeue
	cout<< q->dequeue();
	q->enqueue(10);
	cout << q -> dequeue();
}
