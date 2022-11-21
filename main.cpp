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

	cout << "何番目に好きなお寿司ですか？" << endl;
	cin >> buf.rank;
	cout << endl;

	cout << "好きなお寿司を入力してください" << endl;
	cin >> buf.neta;
	cout << endl;

	cout << "1貫の値段を入力してください" << endl;
	cin >> buf.plice;
	cout << endl;

	hoge[0] = buf;

	printf(" | rank | 前のアドレス｜寿司ネタ | 値段 |   アドレス　 | 次のアドレス | \n");
	printf("------------------------------------------------------------------------\n");

	for (int i = 0; i < hoge.Size(); i++) {
		printf(" | %4d | %.12x｜%8s | %4d | %.12x | %.12x | \n\n\n", 
			      hoge[i].data.rank, hoge[i].before, hoge[i].data.neta.c_str(), hoge[i].data.plice, &hoge[i], hoge[i].next);
	}
	cout << endl;

	while(buf.rank > 0){
		cout << "rankに0以下を入力したら終了\n" << endl;

		cout << "何番目に好きなお寿司ですか？" << endl;
		cin >> buf.rank;
		cout << endl;

		if (buf.rank <= 0) {
			break;
		}

		cout << "好きなお寿司を入力してください" << endl;
		cin >> buf.neta;
		cout << endl;

		cout << "1貫の値段を入力してください" << endl;
		cin >> buf.plice;
		cout << endl;

		hoge.Push(buf, buf.rank - 2);

		printf(" | rank | 前のアドレス｜寿司ネタ | 値段 |   アドレス　 | 次のアドレス | \n");
		printf("------------------------------------------------------------------------\n");

		for (int i = 0; i < hoge.Size(); i++) {
			printf(" | %4d | %.12x｜%8s | %4d | %.12x | %.12x |\n",
				hoge[i].data.rank, hoge[i].before, hoge[i].data.neta.c_str(), hoge[i].data.plice, &hoge[i], hoge[i].next);
		}
		cout << endl;
	}




	std::string endProgram;
	do {
		cout << "終了するには数字を入力してEnterキーを押してください" << endl;
		cin >> endProgram;
	} while (std::any_of(endProgram.begin(), endProgram.end(), isalpha));
	return 0;
}