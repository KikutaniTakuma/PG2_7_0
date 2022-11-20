#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include <list>
#include "List/List.h"

int main() {
	List<int> hoge = { 10,20,30,40,50,60,70 };

	for (int i = 0; i < hoge.Size(); i++) {
		cout << hoge[i] << endl;
	}

	cout << endl;

	hoge.Clear();

	for (int i = 0; i < hoge.Size(); i++) {
		cout << hoge[i] << endl;
	}

	cout << endl;

	std::string endProgram;
	do {
		cout << "I—¹‚·‚é‚É‚Í”Žš‚ð“ü—Í‚µ‚ÄEnterƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}