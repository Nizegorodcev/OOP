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
		cout << "���������:" << faculty << endl;
	}
protected:
	string faculty;
};
class Student :public Faculty
{
public:
	void getstudent()
	{
		
		cout <<"���: "<<fio<< " �������: " << age << " ����: " << kurs << "  ���������: " << faculty << endl;
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
		
		cout << "��� �������������: " << fio << " ������� �������������: " << subject <<" ���������: " <<faculty<< endl;
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
	
		cout << "���: " << university << " ���������: " << faculty << endl;
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
	SetConsoleCP(1251);//��� ������ ������ �� �������, �  ���� ���� �����, � ������ 80 � 81 ����� ���� ��������, ��� ������ ������ �������� ��������� ���������, ����� �������� � ��������� ������, �� � ���� ��� ������ ��������.
	SetConsoleOutputCP(1251);//��� ������ ������ �� �������
	setlocale(LC_ALL, "RUS");
	int vibor = 1000;
	int v = 0;
	while (vibor != 0)
	{
		cout << "�������� ��������:" << '\n' << "1)������ ������ � ��������:" << "\n" << "2)������ ������ � �������������:" << "\n" << "3)������ ������ �� �������������:" << "\n" << "0)�����." << endl;
		cin >> vibor;
		switch (vibor)
		{
			case 1:
				system("cls");
				cout << "������� ��� ��������: " << endl;
				cin >> fiost;
				cout <<"\n" << "������� ������� ��������: " << endl;
				cin >> age;
				cout << "\n" << "������� ����, �� ������� ��������� �������: " << endl;
				cin >> kurs;
				cout << "\n" << "������� ���������, �� ������� ��������� �������: " << endl;
				cin >> facultyst;
				cout << "\n" << "\t������� ������? 1 - ��; ����� ������ �������  - ���;" << endl;
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
				cout << "������� ��� �������������: " << endl;
				cin >> fiopr;
				cout << "\n" << "������� �������, ������� ������������� ����: " << endl;
				cin >> subject;
				cout << "\n" << "������� ���������, �� ������� �������� �������������: " << endl;
				cin >> facultypr;
				b.setprofessor(fiopr, subject, facultypr);
				cout << "\n" << "\t������� ������? 1 - ��; ����� ������ �������  - ���;" << endl;
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
				cout << "������� ���: " << endl;
				cin >> university;
				cout << "\n������� ���������" << endl;
				cin >> facultyad;
				c.setadministration(university, facultyad);
				cout << "\n" << "\t������� ������? 1 - ��; ����� ������ �������  - ���;" << endl;
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