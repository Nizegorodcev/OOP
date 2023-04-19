#include<iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "RUS");
	long long num;
	do {
		try {
			cout << "Введите число: ";
			if (!(cin >> num)) throw 1;
			if (cin.peek() != '\n') throw 2;
		}
		catch (int i) {
			if (i == 1) cin.clear();
			while (cin.get() != '\n');
			cerr << "Введен символ! Попробуйте ещё раз. \n";
			continue;
		}
		break;
	} while (true);
	cout << num;
}
