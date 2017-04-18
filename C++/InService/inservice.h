#ifndef INSERVICE_HPP
#define INSERVICE_HPP
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Person {
protected:
	string name;
	int sex;
public:
	Person(string _name, int _sex): name(_name), sex(_sex) {
		cout << "Construct Person" << endl;
	}
	~Person() {
		cout << "Destruct Person" << endl;
	}
	string getName() { return name; }
	int getSex() { return sex; }
};

class Student : virtual public Person {
protected:
	string sno;
public:
	Student(string _name, int _sex, string _sno):
		Person(_name, _sex){
		sno = _sno;
		cout << "Construct Student" << endl;
	}
	~Student() {
		cout << "Destruct Student" << endl;
	}
	string getSno() { return sno; }
};

class Worker : virtual public Person {
protected:
	string wno;
public:
	Worker(string _name, int _sex, string _wno):
		Person(_name, _sex) {
		wno = _wno;
		cout << "Construct Worker" << endl;
	}
	~Worker() {
		cout << "Destruct Worker" << endl;
	}
	string getWno() { return wno; }
};

class InService : public Student, public Worker {

public:
	InService(string _name, int _sex, string _sno, string _wno):
	Student(_name, _sex, _sno), Worker(_name, _sex, _wno), Person(_name, _sex){
		cout << "Construct InService" << endl;
	}
	~InService() {
		cout << "Destruct InService" << endl;
	}
};

#endif