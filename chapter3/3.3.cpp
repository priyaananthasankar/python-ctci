// Author : Priya Ananthasankar
// Goal: Given a set of stacks implement push and pop in such a way that
// pushing beyond capacity of internal stack will allocate a new stack.
// Popping beyonf capacity of internal stacks will remove the stack and roll back
// to previous stack. Simulate a plate of stacks.
// Commands: g++ 3.3.cpp; ./a.out
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
		int item = arr[top];
		top = top-1;
		return item;
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
		cout << endl;
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
  		   		Stack* current = &(setOfStacks.at(currentStack));
  		   		if(current->capacityReached()){
  		   			Stack* s = new Stack();
  		   			s->setStackNumber(currentStack + 1);
  		   			s->push(item);
  		   			setOfStacks.push_back(*s);
  		   			currentStack  = currentStack + 1;
  		   		}else{
  		   			current->push(item);
  		   		}
  		   	}
  		   	 
  		   }

  		   int pop(){
  		   	   if(setOfStacks.empty()){  		   	   	
  		   	   	return -1;
  		   	   }else{
  		   	   	  Stack* current = &(setOfStacks.at(currentStack));
  		   	   	  int popped = current->pop();
  		   	   	  if(current->isEmpty()){
  		   	   	  	setOfStacks.erase(setOfStacks.begin() + currentStack);
  		   	   	  	currentStack = currentStack - 1;
  		   	   	  }
  		   	   	  return popped;
  		   	   }
  		   }

  		   void print(){
  		   	  for (int i =0;i<setOfStacks.size();i++){
  		   	  	cout << "Stack number: " << i+1 << endl;
  		   	  	Stack c = setOfStacks.at(i);
  		   	  	c.print();
  		   	  }
  		   }

};


int main(){

	SetOfStacks* plateStack = new SetOfStacks();
	cout << "Enter the length of items :" <<endl;
	int length;
	cin >> length; int item;

	// Push items;
	cout <<"Enter items: " << endl;
	for(int i=0;i<length;i++){
		cin >> item;
		plateStack->push(item);
	}

	cout << "Enter how much you want to pop out: "<< endl;
	cin >>item;
	// Pop out more than capacity of one stack. Make sure
	// it rolls back
	for(int i=0;i<item;i++){
		int pop = plateStack -> pop();
		if(pop == -1){
			cout << "Nothing to pop" << endl;
			break;
		}
		cout << "Popped " << pop << endl;
	}

	plateStack -> print();
}