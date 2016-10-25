#include <iostream>
#include <string>
#include <cstdlib> // atoi
#include <stack>
#include <cctype> // isdigit()

using namespace std;

// Functions Prototypes
string infixToPostfix(string infix, bool debug);
string infixToPrefix(string infix, bool debug);
int GetOperatorWeight(char op);
int hasHigherPrecedence(char operator1, char operator2);
bool isOperator(char ch);
bool isOperand(char ch);

void menu()
{
	cout << "n - New Infix expression\n"
		 << "1 - prefix conversion\n"
		 << "2 - postfix conversion\n"
		 << "d - turn Debug mode on(Y), off(N)\n"
		 << "X - to Exit this program\n"
		 << "Enter your command: ";
}


int main()
{
	bool debug=true;
    bool stay = true;
    string choice;
	string infix;

	cout << "Enter Infix Expression: \n";
    getline(cin,infix);

	while(stay) {  // main menu while starts
    menu();
    stay = true;
    cin >> choice;
    cin.ignore();

    if(choice.size() == 1)
    {
      char ch = choice[0];
      string value;
      char bug;
      switch(ch)
      {
        case 'n':
        case 'N':
           cout << "Enter Infix Expression: \n";
           getline(cin,infix);
           cout << endl;
           break;

        case '1':
            {
                string prefix = infixToPrefix(infix, debug);
	            cout << "\nPrefix => " << prefix<<"\n";
	            cout << endl;
            }

	        break;

        case '2':
            {
                string postfix = infixToPostfix(infix, debug);
	            cout << "\nPostfix => " << postfix<<"\n";
	            cout << endl;
            }
	        break;

        case 'd':
        case 'D':
            {
                cin >> bug;
                if (bug == 'n' || bug == 'N')
                    debug = false;
                else
                    debug == true;
            }
            break;

        case 'x': // exit Stack sub-menu
        case 'X':
          stay = false;
          break;
      }
    }
  }
}

// Function to verify whether a character is english letter or numeric digit.
// We are assuming in this solution that operand will be a single character
bool isOperand(char ch) {
	return isalnum(ch);
}

// Function to verify whether a character is operator symbol or not.
bool isOperator(char ch) {
	if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return true;
	return false;
}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op) {
	if(op == '^') return true;
	return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
	int weight = -1;
	switch(op) {
		case '+':
		case '-':
			weight = 1;
			break;

		case '*':
		case '/':
			weight = 2;
			break;

		case '^':
			weight = 3;
			break;
	}
	return weight;
}

// Function to perform an operation and return output.
int hasHigherPrecedence(char op1, char op2)
{
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if(op1Weight == op2Weight)
	{
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

string infixToPostfix(string infix, bool debug) {
	stack <char> S;
	string postfix, pprefix, opStk;

	for (int i = 0; i <=infix.length()-1; i ++)
    {
      if (isOperand (infix[i]))
      {
        postfix += infix [i];
        if (debug)
          cout << "\nOP stack: " << opStk << "\t\tpostfixStk: "<<postfix << "---1";
      }

      else if (isOperator (infix[i]))
      {
        while(!S.empty()&&hasHigherPrecedence(S.top(),infix[i])!=0)//true !=0
        {
          postfix += S.top();
            if (debug)
                cout << "\nOp stack: "<< opStk << "\t\tpostfixStk: "<< postfix << "---2";
          opStk.erase (opStk.size()-1);
            S.pop();

                if (debug)
                    cout << "\nOP stack: "<< opStk << "\t\tpostfixStk: "<< postfix<<"---3";
         }
        opStk += infix[i];
        S.push (infix[i]);
        if (debug)
          cout << "\nOP stack: " << opStk << "\t\tpostfixStk: "<< postfix << "---4";
      }
    }

    while (!S.empty())
    {
        postfix += S.top ();
        opStk.erase (opStk.size()-1);

        if(debug)
         cout << "\nOP stakc: " << opStk << "\t\tpostfixStk: " << postfix<<"---5";
        S.pop();
    }

	return postfix;
}
string infixToPrefix(string infix, bool debug) {
	stack <char> S;
	string prefix, pprefix, opStk;

	for (int i = infix.length()-1; i >= 0; i --)
    {
       if (isOperand (infix[i]))
        {
            prefix += infix [i];
            if (debug)
                cout << "\nOP stack: " << opStk << "\t\tprefixStk: "<<prefix;
        }

        else if (isOperator (infix[i]))
        {
            while(!S.empty()&&hasHigherPrecedence(S.top(),infix[i]))
            {
                prefix += S.top();
                if (debug)
                    cout << "\nOp stack: "<< opStk << "\t\tprefixStk: "<< prefix;
                opStk.erase (opStk.size()-1);
                S.pop();

                if (debug)
                    cout << "\nOP stack: "<< opStk << "\t\tprefixStk: "<< prefix;
            }
            opStk += infix[i];
            S.push (infix[i]);
            if (debug)
                cout << "\nOP stack: " << opStk << "\t\tprefixStk: "<< prefix;
        }
    }

    while (!S.empty())
    {
        prefix += S.top ();
        opStk.erase (opStk.size()-1);

        if(debug)
         cout << "\nOP stakc: " << opStk << "\t\tprefixStk: " << prefix;
        S.pop();
    }

    cout << "\nThe result is: ";
    for (int n = prefix.length()-1;n>=0; n--)
    {
        pprefix += prefix[n];
    }


	return pprefix;
}
