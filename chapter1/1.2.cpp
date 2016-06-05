#include <iostream>
#include <string>
using namespace std;

char* reverse(char* str);
int main()
{
  cout << "Enter the string" << endl;
  string name;
  cin >> name;
  char *c_str = const_cast<char*>(name.c_str());
  cout << reverse(c_str);
  return 0;
}

char* reverse(char* str)
{
  for(int i=0;i<strlen(str)/2;i++)
  {
    char temp=str[i];
    str[i]=str[strlen(str)-i-1];
    str[strlen(str)-i-1]=temp;
  }
  return str;
}
