// Author : Priya Ananthasankar
// Goal: Write a program to have two queues  - one had dogs and other has cats.
// If user asks for cat/dog it should return oldest cat or dog. If user asks
// animal, it should return oldest animal - it could be either cat or dog.
// Commands: g++ 3.6.cpp; ./a.out
#include <iostream>
#include <ctime>
using namespace std;


struct Node{
		string x;
		time_t ms;
		Node* next;
	};

class Queue{

	private: 
		Node *first, *last; 

public: 

	Queue(){
		first = NULL;
		last = NULL;
	}


	void enqueue(string item){
		Node* newNode = new Node();		
		newNode->x = item;
		time_t result = time(nullptr);
		newNode -> ms = result;
		if(first == NULL){
			newNode -> next = first;
			first = newNode;
			last = newNode;
		}else{
			last -> next = newNode;
			last = newNode;

		}
	}

	string dequeue(){
		
		string item = first -> x;
		cout << "Popped " << first -> ms << endl;
		Node* poppedNode = first;
		first = first-> next;
		delete poppedNode;
		return item;
	}

	void print(){
		Node *start = first;
		cout << "****** LINKED LIST ******" << endl;
		while(start != NULL){
			cout << start -> x << "->";
			start = start -> next;
			if(start == NULL){
				cout << "NULL" << endl;
			}
		}
	}

	Node* getFirst(){
		return first;
	}

	Node* getLast(){
		return last;
	}

};

string getOldestAnimal(Queue *dogs, Queue *cats){
	if((dogs -> getFirst() -> ms  ) < (cats -> getFirst() -> ms)){
		//cout << dogs -> getFirst -> ms;
		return dogs->dequeue();
	}else
	{
		cout << cats -> getFirst() -> ms;
		return cats->dequeue();
	}
}

int main(){

	Queue *dogs, *cats; int n; string item;
	cout << "Enter number of animals : "<<endl;
	cin >> n;

	dogs = new Queue();
	cats = new Queue();

	for(int i=0;i<n;i++){
		cin >> item;
		if(item == "dog"){
			dogs->enqueue(item);
		}else if(item == "cat"){
			cats ->enqueue(item);
		}
	}
	string option;
	cout << "Enter animal? " << endl;
	cin >> option;
	if(option == "dog"){
		cout << dogs -> dequeue() << endl;
		dogs->print();
	}else if(option == "cat"){
		cout << cats -> dequeue() << endl;
		cats->print();
	}else{
		cout << getOldestAnimal(dogs,cats) << endl;
		cats -> print();
		dogs -> print();
	}

}