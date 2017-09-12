#include "utility.hpp"
#include "life.hpp"
int main(){
/*	Pre: The user supplies an initial configuration of living cells.
	Post: The program prints a sequence of pictures showing the changes in the configuration 
living cells according to the rules for the game of life.
	Uses: The class Life and its methods initialize(), print(), and update().
		The functions instructions(), user_say_yes() */
	Life configuration;
	instructions();
	configuration.initialize();
	configuration.print();
	cout << "Continue viewing new generations?" << endl;
	while(user_say_yes()){
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations?" << endl;
	}	
	return 0;
}