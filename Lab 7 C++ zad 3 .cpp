#include<iostream>
using namespace std;
class Weekend
{
public:
	Weekend()
	{
		cout << "Сегодня выходной!" << endl;
	}
	 virtual ~Weekend()
	{
		 cout << "Выходной закончился..." << endl;
	}

protected:

};
class Holiday: public Weekend
{
public:
	Holiday()
	{
		cout << "Сегодня праздник!" << endl;
	}
	 ~Holiday()
	{
		cout << "Праздник закончился..." << endl;
	}
};
class Vacation: public Weekend
{
public:
	Vacation()
	{
		cout << "Сегодня отпуск!" << endl;
	}
	~Vacation()
	{
		cout << "Отпуск закончился..." << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "RUS");
	Weekend *Week= new Vacation;
	Week;
	delete Week;
}