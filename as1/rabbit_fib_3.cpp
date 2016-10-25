// Modify the recursive rabbit function so that it is visually
//easy to follow the flow of execution. In stead of just adding
//"Enter" and "Leave" messages, indent the trace messages according 
// to how "deep" the current recursive call is.
#include <iostream>

using namespace std;

int rabbit (int n, int s);

int main()
{

 int n;
 cout << "Enter the generation (integer): ";
 cin >> n;

 cout << "The population of " << n << " generation is "<< rabbit(n, n-n) << endl;
}

int rabbit (int n, int s)
{
  for (int i = 0; i < s; i ++)
  {
      cout << "\t ";
  }
  int a;

  cout << "Enter rabbit: n=" << n<< endl;
  if ( n  <= 2)
    {
        a = 1;
        for (int i = 0; i < s; i ++)
       {
          cout << "\t ";
        }
        cout << "Leave rabbit: n = " << n << " value = " << a << endl;
        return a;
    }

  else if ( n > 2)
  {

      a= rabbit(n-1, s+1)+rabbit (n-2, s+1);

  }
  for (int i = 0; i < s; i ++)
  {
      cout << "\t ";
  }
   cout << "Leave rabbit: n = " << n << " value = "<< a << endl;


   return a;
}
