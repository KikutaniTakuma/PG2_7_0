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
		cout << "�I������ɂ͐�������͂���Enter�L�[�������Ă�������" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}