// Name: Jun Tan
// Modify the recursive rabbit function so that it is visually
// easy to follow the flow of execution. In stead of just adding
// "Enter" and "Leave" messages, indent the trace messages according 
// to how "deep" the current recursive call is.
#include <iostream>

using namespace std;

int rabbit (int n);

int main()
{

 int n;
 cout << "Enter the generation (integer): ";
 cin >> n;

 cout << "The population of " << n << " generation is "<< rabbit(n) << endl;
}

int rabbit (int n)
{
  int a;

  cout << "Enter rabbit: n=" << n<< endl;
  if ( n  <= 2)
    {
        a = 1;
        cout << "Leave rabbit: n = " << n << " value = " << a << endl;
        return a;
    }

  else if ( n > 2)
  {

      a= rabbit(n-1)+rabbit (n-2);

  }
   cout << "Leave rabbit: n = " << n << " value = "<< a << endl;


   return a;
}
