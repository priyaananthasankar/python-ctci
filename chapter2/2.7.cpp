// Author : Priya Ananthasankar
// Goal: Given a string stored as a single linked list, determine if the string is a palindrome or not
// Commands: g++ 2.7.cpp; ./a.out
#include <iostream>
using namespace std;

class LinkedList {
	struct Node{
		char x;
		Node* next;
	};


private: Node *head; int length;

public:
	LinkedList(){
		head = NULL;
		length = 0;
	}

	// Add nodes to a linked list
	void addValue(char n){
		// As we add the nodes we determine the length
		Node *newNode = new Node();
		newNode->x = n;
		newNode->next = head;
		head = newNode;
		length = length + 1;
	}

	// Delete a node from a linked list
	char deleteValue(){
		
		Node* n = head;
		char val = head -> x;
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

	// Determine if a string is a palindrome or not
	bool isPalindrome(){
		Node *start = head;
		char node_arr[length]; int i=0;

		// Traverse through exactly half of the linked list and store in array
		while(start != NULL){
			node_arr[i] = start -> x;
			start = start-> next;
			++i;
			if(i == length/2){
				break;
			}
		}
		

		if(length % 2 != 0){
			// odd numbered array- start comparing from next because we would have already traversed to the mid point element
			start = start -> next;
		}

		for (int j = i-1;j >0 ;j--){
				if(start == NULL){
					break;
				}
				if(start  -> x != node_arr[j]){
					return false;
				}
				start = start -> next;
			}
		return true;
	}

};

int main(){

	// Enter a sample string
	string s;
	cout << "Enter a string: "<< endl;
	cin >> s;

	//TEST CASES: 
	// malayalam (odd)
	// abba (even)

	LinkedList l;

	for (int k=0;k<strlen(s.c_str());k++){
		l.addValue(s[k]);
	}
	
	l.print();

	// Print if Palindrome or not
	if(l.isPalindrome() == true){
		cout << "Palindrome" << endl;
	}else{
		cout << "Not a Palindrome" << endl;
	}
}