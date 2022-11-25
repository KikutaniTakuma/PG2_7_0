#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include "List/List.h"


int main() {
	List<int> hoge = {10,20,30,40,50,60,70,80,90,100};

	for(auto& i : hoge){
		cout << i << endl;
	}

	hoge.Clear();

	cout << hoge.Size() << endl;

	std::string endProgram;
	do {
		cout << "I—¹‚·‚é‚É‚Í”Žš‚ð“ü—Í‚µ‚ÄEnterƒL[‚ð‰Ÿ‚µ‚Ä‚­‚¾‚³‚¢" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}