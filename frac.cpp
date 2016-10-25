#include <iostream>
#include <cstdlib> // labs()

using namespace std;

class frac; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const frac &);
istream &operator >> (istream &, frac &);

class frac {
//private:
	long num;
	long den;

public:
	// constructors
	frac() {
		num = 0;
		den = 1;
	}

	frac(long n, long d) {
		num = n;
		den = d;
	}

	frac(const frac &f) {
		num = f.num;
		den = f.den;
	}

	// accessors and mutators
	long getNum() {return num;}
	long getDen() {return den;}
	void setNum(long n) {num = n;}
	void setDen(long d) {den = d;}

	// overload operator
	frac operator=(const frac &f) {
		num = f.num;
		den = f.den;
	}

	// math operators
	frac operator+(frac &f);
	frac operator-(frac &f);
	frac operator*(frac &f);
	frac operator/(frac &f);

	// logic operators
	bool operator==(frac &f);
	bool operator!=(frac f);
	bool operator>(frac f);
	bool operator<(frac f);

	// auxiliary methods
	frac inputfrac();
	void outputfrac() {std::cout << ' ' << num << '/' << den << ' ';}
	frac lowterms(frac &a);

	// unary operators
	frac operator++();
	frac operator++(int);
	frac operator--();
	frac operator--(int);

	// Friends - overload stream operators

	friend ostream &operator << (ostream &strm, const frac &f)
	{
		strm << f.num << '/' << f.den;
		return strm;
	}
};

frac frac::operator + (frac &f2)	{  // (a*d+b*c) / (b*d)
	frac temp;
	temp.num = num*f2.den + den*f2.num;
	temp.den = den*f2.den;
	return lowterms(temp);
}
//--------------------------------------------------------------
frac frac::operator - (frac &f2)	{  // (a*d-b*c) / (b*d)

frac temp;
	temp.num = num*f2.den - den*f2.num;
	temp.den = den*f2.den;
	return lowterms(temp);



}
//--------------------------------------------------------------
frac frac::operator * (frac &f2)	{  // (a*c) / (b*d)

    frac temp;
	temp.num = num*f2.num ;
	temp.den = den*f2.den;
	return lowterms(temp);



}
//--------------------------------------------------------------
frac frac::operator / (frac &f2)	 {  // (a*d) / (b*c)

    frac temp;
	temp.num = num*f2.den ;
	temp.den = den*f2.num;
	return lowterms(temp);



}
//--------------------------------------------------------------

bool frac::operator > (frac f)	{  // >
	return (num*f.den > den*f.num) ? true : false;
}
//--------------------------------------------------------------

bool frac::operator == (frac &f)	{  // ==
	return (num*(f.den) == den* (f.getNum())) ? true : false;
}
//--------------------------------------------------------------

bool frac::operator != (frac f)	{  // !=
	return (num*(f.getDen()) != den* (f.getNum())) ? true : false;
}
//--------------------------------------------------------------

frac frac::operator++() {
	++num;
	return lowterms(*this);
}
//--------------------------------------------------------------

frac frac::operator++(int) {
	num++;
	return lowterms(*this);
}
//--------------------------------------------------------------

frac frac::operator--() {
	--num;
	return lowterms(*this);
}
//--------------------------------------------------------------

frac frac::operator--(int) {
	num--;
	return lowterms(*this);
}
//--------------------------------------------------------------

frac frac::inputfrac() { //input
	char dummychar;
	while(1) {
		cin >> num;				//numerator
		cin >> dummychar;		//'/' character
		cin >> den;				//denominator
		if(den != 0) break;		//no problem, so exit loop
		cout << "Denominator cannot be zero. Try again: ";
	}
}

frac frac::lowterms(frac &a) { //arg reduced to lowest terms
	frac t;						//temporary fraction
	long tlong, gcd;

	t.num = labs(a.num);		//use non-negative copies
	t.den = labs(a.den);
	if( t.num!=0 && t.den==0 )	//check for n/0
		{ cout << "Illegal fraction: division by 0"; exit(1); }
	else if( t.num==0 )			//check for 0/n
		{ t.num=0; t.den = 1; return(t); }

	//this 'while' loop finds the gcd of t.num and t.den
	while(t.num != 0) {
		if(t.num < t.den)		//ensure numerator larger
			{ tlong=t.num; t.num=t.den; t.den=tlong; }
		t.num = t.num - t.den;  //subtract them
	}
	gcd = t.den;
	t.num = a.num / gcd;		//divide both num and den by gcd
	t.den = a.den / gcd;		//to reduce frac to lowest terms
	return t;
}

int main()
	{
	frac f1, f2, fans;
	char op;

	do {
		cout << "\nEnter fraction, operator, fraction";
		cout << "\nform 3/4 + 3/8 (or 0/1 + 0/1 to exit): ";
		f1.inputfrac();
		cin >> op;
		f2.inputfrac();
		switch(op) {
			case '+':
				fans = f1 + f2;
				fans.outputfrac();
				break;
			case '-':
				fans = f1 - f2;
				fans.outputfrac();
				break;
			case '*':
				fans = f1 * f2;
				fans.outputfrac();
				break;
			case '/':
				fans = f1 / f2;
				fans.outputfrac();
				break;
			case '1':
				fans = ++f1;
				fans.outputfrac();
				break;
			case '2':
				fans = f1++;
				fans.outputfrac();
				break;
			case '3':
				fans = --f1;
				fans.outputfrac();
				break;
			case '4':
				fans = f1--;
				fans.outputfrac();
				break;
			case '>':
				f1.outputfrac();
				if(f1 > f2) cout << " is ";
				else cout << " is NOT ";
				cout << "greater than ";
				f2.outputfrac();
				break;
			case 's':
				cout << f1 << " and " << f2;
				break;

			default:
				cout << "No such operator";
		}  //end switch
	} while(  f1 != frac(0,1) || f2 != frac(0,1) );
	cout << endl;
	return 0;
}
