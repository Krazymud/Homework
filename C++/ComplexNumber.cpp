#include <iostream>
using std::cin;
using std::cout;
using std::endl;
 
class Complex{
	private: 
	double realPart;
	double imaginaryPart;
	public:
	Complex();
	
	Complex( double real, double imaginary);
	
	Complex add( const Complex &right ) ;
	
	Complex subtract( const Complex &right ) ;
	
	void printComplex();
	
	void setComplexNumber( double rp, double ip );
};

Complex::Complex(){
  realPart=0;
  imaginaryPart=0;
}
Complex::Complex( double real, double imaginary ) {
  setComplexNumber( real, imaginary );
} 

Complex Complex::add( const Complex &right ) {
  Complex trans;
  trans.realPart=realPart+right.realPart;
  trans.imaginaryPart=imaginaryPart+right.imaginaryPart;
  return trans;
} 

Complex Complex::subtract( const Complex &right ) {
  Complex trans;
  trans.realPart=realPart-right.realPart;
  trans.imaginaryPart=imaginaryPart-right.imaginaryPart;
  return trans;
} 

void Complex::printComplex() {
 cout << '(' << realPart << ", " << imaginaryPart << ')';
} 

void Complex::setComplexNumber( double rp, double ip ) {
 realPart = rp;
 imaginaryPart = ip;
} 
int main() {
    int n[8];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    cin >> n[4] >> n[5] >> n[6] >> n[7];
    Complex a(n[0], n[1]), b(n[2], n[3]), c;
    // create three Complex objects
 
    a.printComplex();  // output object a
    cout << " + ";
    b.printComplex();  // output object b
    cout << " = ";
    c = a.add(b);
    // invoke add function and assign to object c
    c.printComplex();  // output object c
 
    cout << '\n';
    a.setComplexNumber(n[4], n[5]);  // reset realPart and
    b.setComplexNumber(n[6], n[7]);  // and imaginaryPart
    a.printComplex();  // output object a
    cout << " - ";
    b.printComplex();  // output object b
    cout << " = ";
    c = a.subtract(b);  // invoke add function and assign to object c
    c.printComplex();  // output object c
    cout << endl;
}  // end main
