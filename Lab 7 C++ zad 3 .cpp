#include<iostream>
using namespace std;
class Weekend
{
public:
	Weekend()
	{
		cout << "������� ��������!" << endl;
	}
	 virtual ~Weekend()
	{
		 cout << "�������� ����������..." << endl;
	}

protected:

};
class Holiday: public Weekend
{
public:
	Holiday()
	{
		cout << "������� ��������!" << endl;
	}
	 ~Holiday()
	{
		cout << "�������� ����������..." << endl;
	}
};
class Vacation: public Weekend
{
public:
	Vacation()
	{
		cout << "������� ������!" << endl;
	}
	~Vacation()
	{
		cout << "������ ����������..." << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "RUS");
	Weekend *Week= new Vacation;
	Week;
	delete Week;
}