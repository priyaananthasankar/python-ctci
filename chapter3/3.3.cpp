// Author : Priya Ananthasankar
// Goal: Given a stack implemented as a linked list write push pop and min
// in such a way that all three will be done in O(1) time.
// Commands: g++ 3.2.cpp; ./a.out
#include<iostream>
#include<vector>
using namespace std;

struct Node{
		int x;
		Node* next;
	};


class Stack{

private: 
		int arr[10]; int top; int stackNumber;

public: 

	Stack(){
		stackNumber = -1;
		top = -1;
	}

	void setStackNumber(int n){
		stackNumber = n;
	}

	int getStackNumber(){
		return stackNumber;
	}

	void push(int item){
		if(top == -1){
			arr[top+1] = item;
		}else{
			arr[top+1] = item;
		}
		top = top+1;
	}	

	int pop(){
		return arr[top];
		top = top-1;
	}

	bool capacityReached(){
		if (top == 9){
			return true;
		}
		return false;
	}

	bool isEmpty(){
		if(top == -1){
			return true;
		}
		return false;
	}

	void print(){
		for(int i=top;i>=0;i--){
			cout << arr[i] << " ";
		}
	}
	
};


class SetOfStacks {

  private: std::vector<Stack> setOfStacks;
  		   int currentStack;

  public: 
  		   SetOfStacks(){
  		   	currentStack = -1;
  		   }

  		   void push(int item){
  		   	if(setOfStacks.empty()){
  		   		Stack* s = new Stack();
  		   		s->setStackNumber(0);
  		   		s->push(item);
  		   		setOfStacks.push_back(*s);
  		   		currentStack = 0;
  		   	}else{
  		   		Stack current = setOfStacks.at(currentStack);
  		   		if(current.capacityReached()){
  		   			Stack* s = new Stack();
  		   			s->setStackNumber(currentStack + 1);
  		   			s->push(item);
  		   			setOfStacks.push_back(*s);
  		   			currentStack  = currentStack + 1;
  		   		}else{
  		   			current.push(item);
  		   		}
  		   	}
  		   	 
  		   }

  		   int pop(){
  		   	   if(setOfStacks.empty()){
  		   	   	cout << "nothing to pop";
  		   	   	return 0;
  		   	   }else{
  		   	   	  Stack current = setOfStacks.at(currentStack);
  		   	   	  int popped = current.pop();
  		   	   	  if(current.isEmpty()){
  		   	   	  	setOfStacks.erase(setOfStacks.begin() + currentStack);
  		   	   	  	currentStack = currentStack - 1;
  		   	   	  }
  		   	   	  return popped;
  		   	   }
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
	stack.pop();
	stack.print();
}