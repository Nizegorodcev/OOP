#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
class Faculty
{
	
public:
	void setfaculty(string faculty)
	{
		this->faculty = faculty;
	}
	void getfaculty()
	{
		cout << "Факультет:" << faculty << endl;
	}
protected:
	string faculty;
};
class Student :public Faculty
{
public:
	void getstudent()
	{
		
		cout <<"ФИО: "<<fio<< " Возраст: " << age << " Курс: " << kurs << "  Факультет: " << faculty << endl;
	}
	void setStudent(string fio,int age,int kurs,string faculty)
	{
		this->fio = fio;
		this->age = age;
		this->kurs = kurs;
		this->faculty = faculty;
	}
protected:
	int age;
	int kurs;
	string fio;
};
class Professor :public Faculty
{
public:
	void getprofessor()
	{
		
		cout << "ФИО преподавателя: " << fio << " Предмет преподавателя: " << subject <<" Факультет: " <<faculty<< endl;
	}
	void setprofessor(string fio,string subject,string faculty)
	{
		this->fio = fio;
		this->subject = subject;
		this->faculty = faculty;
	}
protected:
	string fio;
	string subject;
};
class administration :public Faculty
{
public:
	void setadministration(string university, string faculty)
	{
		this->university = university;
		this->faculty = faculty;
	}
	void getadministration()
	{
	
		cout << "ВУЗ: " << university << " Факультет: " << faculty << endl;
	}
protected:
	string university;
};
void main()
{
	string fiost,facultyst,fiopr,facultypr,subject,university,facultyad;
	int kurs,age;
	Student a;
	Professor b;
	administration c;
	SetConsoleCP(1251);//Для вывода строки на русском, у  тебя Егор здесь, в строке 80 и 81 может быть проблема, при выводе данных возможно сломается раскладка, тогда придется в настройки лазить, но я если что ссылку сохранил.
	SetConsoleOutputCP(1251);//Для вывода строки на русском
	setlocale(LC_ALL, "RUS");
	int vibor = 1000;
	int v = 0;
	while (vibor != 0)
	{
		cout << "Выберите действие:" << '\n' << "1)Ввести данные о студенте:" << "\n" << "2)Ввести данные о преподавателе:" << "\n" << "3)Ввести данные об администрации:" << "\n" << "0)Выход." << endl;
		cin >> vibor;
		switch (vibor)
		{
			case 1:
				system("cls");
				cout << "Введите ФИО студента: " << endl;
				cin >> fiost;
				cout <<"\n" << "Введите возраст студента: " << endl;
				cin >> age;
				cout << "\n" << "Введите курс, на котором обучается студент: " << endl;
				cin >> kurs;
				cout << "\n" << "Введите факультет, на котором обучается студент: " << endl;
				cin >> facultyst;
				cout << "\n" << "\tВывести данные? 1 - да; Любая другая клавиша  - нет;" << endl;
				cin >> v;
				a.setStudent(fiost, age, kurs, facultyst);
				if (v == 1)
				{
					a.getstudent();
					v = 0;
					break;
				}
				else break;
			case 2:
				system("cls");
				cout << "Введите ФИО преподавателя: " << endl;
				cin >> fiopr;
				cout << "\n" << "Введите предмет, который преподаватель ведёт: " << endl;
				cin >> subject;
				cout << "\n" << "Введите факультет, на котором преподаёт преподаватель: " << endl;
				cin >> facultypr;
				b.setprofessor(fiopr, subject, facultypr);
				cout << "\n" << "\tВывести данные? 1 - да; Любая другая клавиша  - нет;" << endl;
				cin >> v;
				if (v == 1)
				{
					b.getprofessor();
					v = 0;
					break;
				}
				else break;
			case 3:
				system("cls");
				cout << "Введите ВУЗ: " << endl;
				cin >> university;
				cout << "\nВведите факультет" << endl;
				cin >> facultyad;
				c.setadministration(university, facultyad);
				cout << "\n" << "\tВывести данные? 1 - да; Любая другая клавиша  - нет;" << endl;
				cin >> v;
				if (v == 1)
				{
					c.getadministration();
					v = 0;
					break;
				}
				else break;
		}
	}

}