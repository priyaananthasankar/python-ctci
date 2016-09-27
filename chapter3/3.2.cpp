// Author : Priya Ananthasankar
// Goal: Given a stack implemented as a linked list write push pop and min
// in such a way that all three will be done in O(1) time.
// Commands: g++ 3.2.cpp; ./a.out
#include<iostream>
using namespace std;

struct Node{
		int x;
		Node* next;
	};

class MinStack {

	private: Node* minTop;

	public:
		MinStack(){
			minTop = NULL;
		}

		void push(int item){
			Node* newNode = new Node();		
			newNode->x = item;
			newNode -> next = minTop;
			minTop = newNode;
		}

		int pop(){
			int item = minTop -> x;
			Node* poppedNode = minTop;
			minTop = minTop-> next;
			delete poppedNode;
			return item;
		}

		int minimum(){
			return minTop->x;
		}
};

class Stack{

	private: 
		Node *top; int length; MinStack* ms;

public: 

	Stack(){
		ms = NULL;
		top = NULL;
		length = 0;
	}


	void push(int item){
		Node* newNode = new Node();		
		newNode->x = item;
		newNode -> next = top;
		top = newNode;
		if(ms == NULL){
			ms = new MinStack();
			ms->push(top->x);
		}else{
			if(ms->minimum() > item){
				ms->push(item);
			}
		}
	}

	int pop(){
		int item = top -> x;
		Node* poppedNode = top;
		top = top-> next;
		if(poppedNode -> x == ms->minimum()){
			ms->pop();
		}
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

	int getMinimum(){
		return ms->minimum();
	}

};


int main(){
	Stack stack;  int length;

	cout << "Enter the length of the stack: " << endl;
	cin >> length;

	int item;

	cout << "Enter the items: " << endl;
	for(int i=0;i<length;i++){
		cin >> item;
		stack.push(item);
	}

	stack.print();
	cout <<"The min value in the stack is: " << stack.getMinimum() << endl;
	stack.pop();
	stack.print();
	cout <<"The min value in the stack after popping is: " << stack.getMinimum() << endl;


}