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

int main()
{
	bool debug=true;
	string infix;
	cout << "Enter Infix Expression: \n";
	getline(cin,infix);
	string prefix = infixToPrefix(infix, debug);
	cout << "\nPrefix => " << prefix<<"\n";
	string postfix = infixToPostfix(infix, debug);
	cout << "\nPostfix => " << postfix<<"\n";
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

	return "";
}
string infixToPrefix(string infix, bool debug) {
    stack<char> S;
	string prefix, pprefix, opStk;

	for (int i = infix.length()-1; i >= 0; i --)
    {
        //if (infix [i] == ' '||infix[i] ==',' ||infix == ' ')
            //continue;
        if (isOperator (infix[i]))
        {
            while ( hasHigherPrecedence(S.top(), infix[i]))
            {
                prefix += S.top();
                if(debug)
                    cout << "\nOP stack: " << opStk << " prefixStk: " << prefix<<"!1"<<endl;

                opStk.erase (opStk.size ()-1);
                S.pop();
                //}
                //S.push (infix[i];
                if(debug)
                    cout << "\nOP stack: " << opStk << " prefixStk: " << prefix<<"!2"<<endl;
             }
                //opStk.erase(opStk.size()-1);

                opStk +=infix[i];
                S.pop();
                S.push (infix[i]);

                if(debug)
                    cout << "\nOP stack: " << opStk << " prefixStk: " << prefix<<"!3"<< endl;
            }
            else if (isOperand(infix[i]))
            {
            prefix += infix [i];

            if (debug)
                cout << "OP stack: " << opStk << " prefixStk: " << prefix<< "!4"<< endl;
            }
            //opStk += infix[i];

            S.push (infix[i]);
           //if (debug) cout << "OP stakc: " << opStk << " prefixStk: " << prefix;
        }


    /*while (!S.empty ())
    {
        prefix += S.top ();

        if(debug)
         cout << "OP stakc: " << opStk << " prefixStk: " << prefix;
        S.pop();
    }*/


	return "";
}
