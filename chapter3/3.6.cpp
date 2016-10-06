// Author : Priya Ananthasankar
// Goal: Write a program to sort a stack using only another stack
// Commands: g++ 3.6.cpp; ./a.out
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
		if(top == NULL){
			return -1;
		}
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

void sort(Stack* targetStack, Stack* bufferStack){

	if(bufferStack -> getTop() == NULL){
		int var = targetStack -> pop();
		bufferStack -> push(var);
	}
	 while(targetStack -> getTop() != NULL){
	 	int swapitem = targetStack -> pop();
	 	while((bufferStack -> getTop() != NULL) && (swapitem < bufferStack -> getTop() -> x)){
	 	  int item = bufferStack -> pop();
	 	  targetStack->push(item);
	 	}

	 	bufferStack -> push(swapitem);
	 }
	
}

int main(){
	Stack *targetStack, *bufferStack;
	targetStack = new Stack();
	bufferStack = new Stack();

	int n, item;
	cout << "Enter number of items : " << endl;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> item;
		targetStack -> push(item);
	}
	cout <<"BEFORE SORTING " << endl;
	targetStack -> print();

	sort(targetStack,bufferStack);

	cout <<"AFTER SORTING " << endl;
	bufferStack -> print();
}
