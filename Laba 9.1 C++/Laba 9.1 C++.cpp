#include<iostream>
#include <string>
#include<fstream>
#include<Windows.h>
#include<regex>
using namespace std;
void main()
{
	string path = "Myfile.txt";
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUS");
	ifstream fin;
	string x;
	string newstr;
	string str;
	cmatch m;
	cout << "������� ������� ���� ��� ������!" << endl;
	fin.open(path);
	cout << "���� ������� ������." << endl;
	while (!fin.eof())
	{
		str = "";
		getline(fin, str);

	}
	newstr = regex_replace(str, regex("0"), "����");
	newstr = regex_replace(newstr, regex("1"), " ���� ");
	newstr = regex_replace(newstr, regex("2"), " ��� ");
	newstr = regex_replace(newstr, regex("3"), " ��� ");
	newstr = regex_replace(newstr, regex("4"), " ������ ");
	newstr = regex_replace(newstr, regex("5"), " ���� ");
	newstr = regex_replace(newstr, regex("6"), " ����� ");
	newstr = regex_replace(newstr, regex("7"), " ���� ");
	newstr = regex_replace(newstr, regex("8"), " ������ ");
	newstr = regex_replace(newstr, regex("9"), " ������ ");
	cout << newstr;
}



