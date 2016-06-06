#include <iostream>
#include <string>
using namespace std;

char* replace(char* str);
int main()
{
  string name;
  name = "Jone D oe  ";
  char *c_str = const_cast<char*>(name.c_str());
  cout << "Modified string is: " << replace(c_str) << endl;
  return 0;
}

char* replace(char* str)
{
  int no_of_spaces = 0;
  for(int i=0;i<strlen(str);i++)
  {
     if(str[i] == ' '){
       no_of_spaces++;
     }	
  }
  int length = strlen(str);
  int mod_length = length + no_of_spaces * 2;
  char *new_str  = new char[mod_length];
  int new_str_index = 0;
  new_str[mod_length] = '\0';
  for(int i = 0 ;i<length;i++){
   if(str[i] == ' '){
      new_str[new_str_index] = '%';
      new_str[new_str_index+1] = '2';
      new_str[new_str_index+2] = '0';     
      new_str_index = new_str_index + 3;
   }
   else{
     new_str[new_str_index] = str[i];
     new_str_index = new_str_index + 1;
   }
  }
  for (int i=0;i<mod_length;i++){
    cout << new_str[i] << endl;
  }
  return new_str;  
}
