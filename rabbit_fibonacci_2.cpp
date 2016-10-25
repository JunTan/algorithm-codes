#include <iostream>

using namespace std;

int rabbit (int n);

int main()
{
  //f(n) = f(n-1)*1;
  //f(1) = 1;

 int n;
 cout << "Enter the generation (integer): ";
 cin >> n;

 cout << "The population of " << n << " generation is "<< rabbit(n) << endl;
}

int rabbit (int n)
{
  if ( n == 1 || n == 2)
    return 1;
  if ( n > 2)
      return rabbit(n-1)+rabbit (n-2);
}
