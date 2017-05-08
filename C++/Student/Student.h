#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "Date.h"
#include "Person.h"
class Student :public Person {
private:
	Date graduateDate;
public:
	Student(string name, int age, Date date): Person(name, age), graduateDate(date){}
	void set(int age) {
		Person::set(age);
	}
	void set(string name) {
		Person::set(name);
	}
	void set(Date& date) {
		graduateDate = date;
	}
	virtual void sayHi() const {
		Person::sayHi();
		Date today("2017-5-7");
		if (graduateDate > today)
			cout << "I will graduate on " << graduateDate.toString() << "." << endl;
		else if (graduateDate == today)
			cout << "I graduated today!" << endl;
		else
			cout << "I have graduated on " << graduateDate.toString() << "." << endl;
	}
};

#endif