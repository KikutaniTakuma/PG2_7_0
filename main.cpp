#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include "List/List.h"

int main() {
	




	std::string endProgram;
	do {
		cout << "I—¹‚·‚é‚É‚Í”Žš‚ð“ü—Í‚µ‚ÄEnterƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}