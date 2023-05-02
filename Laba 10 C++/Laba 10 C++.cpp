#include<iostream>
#include<thread>
#include<chrono>
#include<string>
#include<mutex>
#include<fstream>
#include<Windows.h>
using namespace std;
mutex m;
void readfile(string path)
{
	lock_guard<mutex> lock(m);
	ifstream fin;
	string str;
	cout << "Чтение, ID потока: " << this_thread::get_id() << endl;
	fin.open(path);
	for (int i = 0; i < 10; i++)
	{
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				str = "";
				getline(fin, str);
				cout << str << endl;
				this_thread::sleep_for(chrono::microseconds(1000));
			}
		}
	}

	

}
void writefile(string path)
{
	lock_guard<mutex> lock(m);
	ofstream fout;
	fout.open(path);
	cout<<"Запись, ID: " << this_thread::get_id() << endl;
	for (int i = 0; i < 10; i++)
	{
		if (fout.is_open())
		{
			
			fout << rand() % 10 << endl;
			this_thread::sleep_for(chrono::microseconds(1001));
		}

	}
	
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string path = "Myfile.txt";
	thread th1(readfile,path);
	thread th2(writefile,path);
	this_thread::sleep_for(chrono::microseconds(1));
	cout <<"Вызвана main, ID: " << this_thread::get_id() << endl;
	th1.join();
	th2.join();
	

}
