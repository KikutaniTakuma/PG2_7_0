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
		cout << "終了するには数字を入力してEnterキーを押してください" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}