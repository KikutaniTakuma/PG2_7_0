#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include "List/List.h"

int main() {
	
	List<int> hoge = {100,200,300,400,500,600,700};

	hoge.PushBack(800);

	for (auto& i : hoge) {
		cout << i << endl;
	}



	std::string endProgram;
	do {
		cout << "�I������ɂ͐�������͂���Enter�L�[�������Ă�������" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}