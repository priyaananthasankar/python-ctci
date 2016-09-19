#include <iostream>
#include <string>
using namespace std;

char* compress(char* str);
int main()
{
  string name;
  cout << "Enter the string: " << endl;
  cin >> name;
  char *c_str = const_cast<char*>(name.c_str());
  cout << "Compressed string is: " << compress(c_str) << endl;
  return 0;
}

char* compress(char* str){
  char *compressed_str = new char[strlen(str)];
  int count = 1; int j = 0;
  for(int i=0;i<strlen(str)+1;i++){
    if(i==0){
      cout<< str[i];            
    }else{
      if (str[i] == str[i-1]) {
        count += 1;
      }else{   
      cout << count;
      cout << str[i];
      count = 1;
     }

    }
  }
  return compressed_str;
}
