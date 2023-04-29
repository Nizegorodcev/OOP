
#include "Taxi.h"
#include<Windows.h>
#include<fstream>
void writefile(Taxi* arr,string path)//������ � ����
{
	ofstream fout;
	string client, where_from, where, driver;
	fout.open(path);
	if (fout.is_open())
	{
		cout << "���� ������." << endl;
		cout << "������� ��� �������:" << endl;
		cin >> client;
		cout << "������� ����� ������ ��� �������: " << endl;
		cin >> where_from;
		cout << "������� ����� ���� ��� ����: " << endl;
		cin >> where;
		cout << "������� ��� ��� ��������:" << endl;
		cin >> driver;
		fout << client<<"\t" << where_from<<"\t" << where <<"\t" << driver << endl;
	}
	else
	{
		cout << "�� ������� ������� ����!" << endl;
	}
	fout.close();
}
void readfile(string path)
{
	ifstream fin;
	string str;
	fin.open(path);
	if ((fin.is_open()))
	{	
		cout << "���� ������." << endl;
		cout <<"|    ��� �������   |������|���� |��� ��������                   |" << endl;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	else
	{
		cout << "������ ��� �������� �����!" << endl;
	}
	fin.close();
}
bool compare(string a, string b)//��������� ���
{
	int kol = 0;
	if (a.length() == b.length())
	{
		for (int i = 0; i < a.length();i++)
		{
			if (a[i] == b[i]) kol+=1;
			else break;
		}
		if (kol == a.length())
		{
			return true;
		}
		else return false;
	}
	else return false;
}
void searchDriver(Driver* arr, int size)
{
	string value;
	cout << "������� ��� ��������, �������� �� ������ �����?" << endl;
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (compare(value, arr[i].driver) == true)
		{
			cout << "��� ��������: " << arr[i].driver << endl;
			cout << "����� ������: " << arr[i].marka << endl;
			cout << "���� ������: " << arr[i].colour << endl;
			cout << "��������������� ����: " << arr[i].registration_mark << endl;
		}
	}
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("chcp 1251");

	int len = 0;
	int len1 = 0;
	int len2 = 0;
	int v;
	string str;
	Driver* a = new Driver [1000];//����� ��������� ���������� � ���� ��������� � ��� ������ �������� ���������� ������ �� ���
	Taxi* arr = new Taxi[1000];
	string path;
	a[0].driver = "������_����_��������";
	a[0].colour = "�����";
	a[0].marka = "Renault_Logan";
	a[0].registration_mark = "T248CO";
	a[1].driver = "�������_��������_�����������";
	a[1].colour = "�����";
	a[1].marka = "Daewoo_Nexia";
	a[1].registration_mark = "�545��";
	a[2].driver = "�����_�������_����������";
	a[2].colour = "������";
	a[2].marka = "Hyunday_Solaris";
	a[2].registration_mark = "�228��";
	len += 3;
	int size;
	//client* arr2 = new client[1000];//����� ��������� ���������� � ��������
	cout << "\t ��� ������������ �������-�����!\n" << endl;
	while (true)
	{
		cout << "�������� ��������: " << endl;
		cout << "1)������ ������ �� �������� �����" << endl;
		cout << "2)�������� �����" << endl;
		cout << "3)����� ���������� �� ��� ��������" << endl;
		cout << "4)������� � ������� ������ � �����" << endl;
		cout << "5)�������� ������ � ����." << endl;//� ����������
		cout << "0)�����" << endl;
		cin >> v;
		switch (v)
		{
		case 1:
			a->application(a, len);
			len++;
			cout << "\n\t������ � ��� ��������." << endl;
			break;
		case 2:
			arr->order(arr, len2);
			arr->getTaxi(arr, len2);
			len2++;
			arr->getdriver(a, len);
			break;
		case 3:
			searchDriver(a, len);
			break;
		case 4:
			cout << "������� �������� �����: "<<endl;
			cin >> path;
			readfile(path);
			path = "";
			break;
		case 5:
			cout << "������� �������� ����� � ������� �� ������ �������� ������:" << endl;
			cin >> path;
			writefile(arr,path);

			break;
		}
		if (v == 0)
		{
			delete[] arr;
			delete[] a;
			break;
		}
		
		

	}
}
