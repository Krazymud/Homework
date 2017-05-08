#ifndef DATE_HPP
#define DATE_HPP
#include <sstream>
using std::string;
using std::stringstream;
class Date {
private:
	int _year;
	int _month;
	int _day;
public:
	Date(Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	Date(int y, int m, int d) :_year(y), _month(m), _day(d) {}
	Date(string dateString) {
		string temp; int n, i;
		string store[3];
		int s[3];
		stringstream ss;
		for (n = 0, i = 0; n < dateString.length(); n++) {
			if (dateString[n] == '-')
				i++;
			else
				store[i] += dateString[n];
		}
		ss << store[0];
		ss >> s[0]; ss.clear();
		ss << store[1];
		ss >> s[1]; ss.clear();
		ss << store[2];
		ss >> s[2];
		_year = s[0]; _month = s[1]; _day = s[2];
	}// the format of dateString is like "2017-5-7"
	int getYear() const { return _year; }
	void setYear(int y) { _year = y; }
	int getMonth() const { return _month; }
	void setMonth(int m) { _month = m; }
	int getDay() const { return _day; }
	void setDay(int d) { _day = d; }
	bool operator==(Date& other) const {
		if (_year == other._year && _month == other._month && _day == other._day)
			return 1;
		return 0;
	}
	bool operator<(Date& other) const {
		if (_year < other._year)
			return 1;
		if (_year == other._year) {
			if (_month <= other._month) {
				if (_month < other._month)
					return 1;
				if (_day < other._day)
					return 1;
				return 0;
			}
			return 0;
		}
		return 0;
	}
	bool operator>(Date& other) const {
		if (_year > other._year)
			return 1;
		if (_year == other._year) {
			if (_month >= other._month) {
				if (_month > other._month)
					return 1;
				if (_day > other._day)
					return 1;
				return 0;
			}
			return 0;
		}
		return 0;
	}
	std::string toString() const {
		string output, temp;
		stringstream ss;
		ss << _year;
		ss >> temp; ss.clear();
		output += temp; output += "-";
		ss << _month;
		ss >> temp; ss.clear();
		output += temp; output += "-";
		ss << _day;
		ss >> temp; ss.clear();
		output += temp;
		return output;
	}// return a string like "year-month-day"
};

#endif