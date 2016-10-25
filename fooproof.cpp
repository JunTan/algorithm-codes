#include <iostream>
#include <sstream> // stringstream
#include <string>

using namespace std;

void string_string();
void string_phrase();
void string_int();
void string_float();

int main()
{
    char choice = ' ';
    while(true) {
        cout << "----- Fool Proof Menu -------------\n"
             << "1 - Enter a line of text\n"
             << "2 - Enter a text phrase\n"
             << "3 - Enter an integer number\n"
             << "4 - Enter a float number\n"
             << "q - quit\n"
             << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case '1':
            string_string();
            break;

        case '2':
            string_phrase();
            break;

        case '3':
            string_int();
            break;

        case '4':
            string_float();
            break;

        case 'q':
        case 'Q':
            return 0;

        default:
            cout << "\nCant recognize your input.\n";
        }


	}
}

void string_string()
{
    string input = "";
    cout << "\nEnter a line of text string: ";
		getline(cin, input);
		cout << "    You have entered: " << input << endl;
		if (input.empty()) // not an integer
			cout << " => Can not find a string!\n\n";
		else
			cout << " => Found this string: " << input << "\n\n";
}

void string_phrase()
{
    string i = "";
    string input = "";
    cout << "\nEnter a non-space text phrase: ";
		getline(cin, input, ' ');
		cout << "    You have entered: " << input << endl;
		stringstream ss(input);
		ss >> i;
		if (ss.fail()) // not an integer
			cout << " => Can not find a phrase!\n\n";
		else
			cout << " => Found this phrase: " << i << "\n\n";
}

void string_int()
{
    int i = 0;
    string input = "";
    cout << "\nEnter a number: ";
		getline(cin, input);
		cout << "    You have entered: " << input << endl;
		stringstream ss(input);
		ss >> i;
		if (ss.fail()) // not an integer
			cout << " => Can not find a number!\n\n";
		else
			cout << " => Found this number: " << i << "\n\n";
}

void string_float()
{
    float i = 0;
    string input = "";
    cout << "\nEnter a number: ";
		getline(cin, input);
		cout << "    You have entered: " << input << endl;
		stringstream ss(input);
		ss >> i;
		if (ss.fail()) // not an integer
			cout << " => Can not find a float!\n\n";
		else
			cout << " => Found this float: " << i << "\n\n";
}
