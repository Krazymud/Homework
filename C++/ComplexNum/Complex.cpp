#include <sstream>
using namespace std;
class Complex{
private:
	double real;
	double imag;
public:
	Complex(double x=0, double y=0) : real(x), imag(y){}
	friend ostream &operator <<(ostream& os, const Complex&c){
		string output, temp;
		stringstream ss;
		if(c.real != 0){
			ss << c.real;
			ss >> output; ss.clear();
			if(c.imag > 0)
				output += "+";
		}
		if(c.imag != 0){
			if(c.imag == -1)
				output += "-";
			else if(c.imag != 1){
				ss << c.imag;
				ss >> temp;
				output += temp;
			}
			output += "i";
		}
		if(c.real == 0 && c.imag == 0)
			output = "0";
		os << output;
		return os;
	}//e.g 2+3i  -2-5i
	friend istream &operator >>(istream& is, Complex &c){
		is >> c.real >> c.imag;
		return is;
	}
	Complex operator +(const Complex &obj){
		Complex temp(real + obj.real, imag + obj.imag);
		return temp;
	}
	Complex operator -(const Complex &obj){
		Complex temp(real - obj.real, imag - obj.imag);
		return temp;
	}
	Complex operator *(const Complex &obj){
		Complex temp(real * obj.real - imag * obj.imag, real * obj.imag + imag * obj.real);
		return temp;
	}
};