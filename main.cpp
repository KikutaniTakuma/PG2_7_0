#include <iostream>
#include <algorithm>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#include "List/List.h"

struct Sushi
{
	int rank;
	std::string neta;
	int plice;
};

int main() {
	List<Sushi> hoge;

	Sushi buf;

	cout << "���ԖڂɍD���Ȃ����i�ł����H" << endl;
	cin >> buf.rank;
	cout << endl;

	cout << "�D���Ȃ����i����͂��Ă�������" << endl;
	cin >> buf.neta;
	cout << endl;

	cout << "1�т̒l�i����͂��Ă�������" << endl;
	cin >> buf.plice;
	cout << endl;

	hoge[0] = buf;

	printf(" | rank | �O�̃A�h���X�b���i�l�^ | �l�i |   �A�h���X�@ | ���̃A�h���X | \n");
	printf("------------------------------------------------------------------------\n");

	for (int i = 0; i < hoge.Size(); i++) {
		printf(" | %4d | %.12x�b%8s | %4d | %.12x | %.12x | \n\n\n", 
			      hoge[i].data.rank, hoge[i].before, hoge[i].data.neta.c_str(), hoge[i].data.plice, &hoge[i], hoge[i].next);
	}
	cout << endl;

	while(buf.rank > 0){
		cout << "rank��0�ȉ�����͂�����I��\n" << endl;

		cout << "���ԖڂɍD���Ȃ����i�ł����H" << endl;
		cin >> buf.rank;
		cout << endl;

		if (buf.rank <= 0) {
			break;
		}

		cout << "�D���Ȃ����i����͂��Ă�������" << endl;
		cin >> buf.neta;
		cout << endl;

		cout << "1�т̒l�i����͂��Ă�������" << endl;
		cin >> buf.plice;
		cout << endl;

		hoge.Push(buf, buf.rank - 2);

		printf(" | rank | �O�̃A�h���X�b���i�l�^ | �l�i |   �A�h���X�@ | ���̃A�h���X | \n");
		printf("------------------------------------------------------------------------\n");

		for (int i = 0; i < hoge.Size(); i++) {
			printf(" | %4d | %.12x�b%8s | %4d | %.12x | %.12x |\n",
				hoge[i].data.rank, hoge[i].before, hoge[i].data.neta.c_str(), hoge[i].data.plice, &hoge[i], hoge[i].next);
		}
		cout << endl;
	}




	std::string endProgram;
	do {
		cout << "�I������ɂ͐�������͂���Enter�L�[�������Ă�������" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}