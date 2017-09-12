#ifndef UTILITY_HPP
#define UTILITY_HPP
#include <iostream>
using namespace std;
bool user_say_yes(){
	char c;
	bool initial_response = true;
	do{
		if(initial_response)
			cout << "(y, n)?" << flush;
		else
			cout << "Respond with either y or n:" << flush;
		do{
			cin >> c;
		}while(c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	}while(c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}
#endif