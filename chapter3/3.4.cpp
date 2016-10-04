// Author : Priya Ananthasankar
// Goal: Write a program to simulate Tower of Hanoi problem
// Commands: g++ 3.4.cpp; ./a.out
#include<iostream>
using namespace std;

void hanoi(int n, int source, int dest, int spare){
	if(n == 0){
		cout<< "Move disk " << n << " from source " << source << " to destination " << dest << endl;
	}else{
		hanoi(n-1,source,spare,dest);
		cout<< "Move disk " << n << " from source " << source << " to destination " << dest << endl;
		hanoi(n-1,spare,dest,source);
	}
}


int main(){

	int n;
	
	cout << "Enter the number of disks: " << endl;
	cin >> n;

	hanoi(n-1,0,1,2);

}
