#include <iostream>
#include <string>

using namespace std;

void reverseArray (string name, int n)
{
  if ( n >= 0)
  {
    cout << name[n];
    reverseArray(name, n-1);
  }
}

int main()
{
  string name = "abcdefg";
  int n;
  n = name.size() -1;
  reverseArray (name,n);
}
