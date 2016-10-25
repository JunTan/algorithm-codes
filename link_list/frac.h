#ifndef _FRAC_H
#define _FRAC_H

#include <iostream>
#include <sstream>
#include <cstdlib> // labs()

using namespace std;

class frac; // Forward Declaration


// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const frac &);
istream &operator >> (istream &, frac &);

class frac {
	int num, den;
public:
	frac() {num = 0; den = 1;}
    frac(string s){
		stringstream strm(s);
		strm >> num;

		char peekchar = strm.peek();
		if(strm && peekchar == '/'){
			strm.get();
			strm>>den;
		}
		else
			den = 1;
	}
	frac(int num_, int den_) :num(num_), den(den_) {}
    frac(const frac& rhs) : num(rhs.num), den(rhs.den) {}
    frac operator=(const frac& rhs) {num=rhs.num; den=rhs.den; return *this;}
	// math + - * /
	frac operator + (frac &f2) { frac temp; temp.num = num*f2.den + den*f2.num; temp.den = den*f2.den; return lowterms(temp);}
	frac operator - (frac &f2) { frac temp; temp.num = num*f2.den - den*f2.num; temp.den = den*f2.den; return lowterms(temp);}
	frac operator * (frac &f2) { frac temp; temp.num = num*f2.num; temp.den = den*f2.den; return lowterms(temp);}
	frac operator / (frac &f2) { frac temp; temp.num = num*f2.den; temp.den = den*f2.num; return lowterms(temp);}

	bool operator < (frac &f2)
	{
	    frac temp;
	    temp.num = num*f2.den - den*f2.num;
	    temp.den = den*f2.den;
	    if(temp.num < 0 || temp.den < 0)
            return 1;
        else
            return 0;
	    }

    bool operator == (frac &f2)
	{
	    if(num == f2.num && den == f2.den)
            return 1;
        else
            return 0;
	    }

    bool operator != (frac &f2)
	{
	    if(num == f2.num && den == f2.den)
            return 0;
        else
            return 1;
	    }

	// increment ++ decrement --
	frac operator++() {++num; return lowterms(*this);}
	frac operator++(int) {num++; return lowterms(*this);}
	frac operator--() {--num; return lowterms(*this);}
	frac operator--(int) {num--; return lowterms(*this);}
	// comparator - fill the blank





    double get_value() {return double(num)/den;}

	//stream extraction operators
	friend istream& operator>>(istream& strm, frac& f) {
		int numer;
		int denom=1;
		int whole=0;
		int peekchar;
		bool valid=false;

		strm >> numer; //get the numerator

		peekchar = strm.peek(); //peek at next character

		if(strm && peekchar == '+') { //if next character is a +
			strm.get(); //skip the + character
			whole = numer; //then first character was whole, not numerator
			strm >> numer; //get the real numerator
			valid = true;
			peekchar = strm.peek();
		}
		if(strm && peekchar == '/') { //if next character is a /
			strm.get(); //skip the / character
			strm >> denom; //get the denominator
			valid = true;
		}
		if (strm || valid) { //if we succeeded in reading
			if (denom == 0)
				denom = 1;
			numer += (whole*denom);
			f = frac(numer, denom);
		 }
		 return strm;
	}

	// stream insertion operator overload
	friend ostream& operator<<(ostream& strm,const frac& f) {
		strm << f.num << '/' << f.den;
		return strm;
	}

	// auxiliary method
	frac lowterms(frac &f) { //arg reduced to lowest terms
		frac t;						//temporary fraction
		long tlong, gcd;

		t.num = labs(f.num);		//use non-negative copies
		t.den = labs(f.den);
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
		t.num = f.num / gcd;		//divide both num and den by gcd
		t.den = f.den / gcd;		//to reduce frac to lowest terms
		return t;
	}
};

#endif
