
#include "Taxi.h"
#include<Windows.h>
#include<fstream>
void writefile(Taxi* arr,string path)//Запись в файл
{
	ofstream fout;
	string client, where_from, where, driver;
	fout.open(path);
	if (fout.is_open())
	{
		cout << "Файл открыт." << endl;
		cout << "Введите ФИО клиента:" << endl;
		cin >> client;
		cout << "Введите адрес откуда его забрали: " << endl;
		cin >> where_from;
		cout << "Введите адрес куда ему надо: " << endl;
		cin >> where;
		cout << "Введите ФИО его водителя:" << endl;
		cin >> driver;
		fout << client<<"\t" << where_from<<"\t" << where <<"\t" << driver << endl;
	}
	else
	{
		cout << "Не удалось открыть файл!" << endl;
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
		cout << "Файл открыт." << endl;
		cout <<"|    ФИО клиента   |Откуда|Куда |ФИО водителя                   |" << endl;
		while (!fin.eof())
		{
			str = "";
			getline(fin, str);
			cout << str << endl;
		}
	}
	else
	{
		cout << "Ошибка при открытии файла!" << endl;
	}
	fin.close();
}
bool compare(string a, string b)//Сравнение ФИО
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
	cout << "Введите ФИО водителя, которого вы хотите найти?" << endl;
	cin >> value;
	for (int i = 0; i < size; i++)
	{
		if (compare(value, arr[i].driver) == true)
		{
			cout << "ФИО водителя: " << arr[i].driver << endl;
			cout << "Марка машины: " << arr[i].marka << endl;
			cout << "Цвет машины: " << arr[i].colour << endl;
			cout << "Регистрационный знак: " << arr[i].registration_mark << endl;
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
	Driver* a = new Driver [1000];//Будет содержать информацию о всех водителях и при заказе случайно направлять одного из них
	Taxi* arr = new Taxi[1000];
	string path;
	a[0].driver = "Иванов_Иван_Иванович";
	a[0].colour = "Белый";
	a[0].marka = "Renault_Logan";
	a[0].registration_mark = "T248CO";
	a[1].driver = "Лихачёв_Владимир_Анатольевич";
	a[1].colour = "Серый";
	a[1].marka = "Daewoo_Nexia";
	a[1].registration_mark = "Б545БА";
	a[2].driver = "Серов_Евгений_Дмитриевич";
	a[2].colour = "Черный";
	a[2].marka = "Hyunday_Solaris";
	a[2].registration_mark = "А228АА";
	len += 3;
	int size;
	//client* arr2 = new client[1000];//Будет содержать информацию о клиентах
	cout << "\t Вас приветствует Воронеж-такси!\n" << endl;
	while (true)
	{
		cout << "Выберите действие: " << endl;
		cout << "1)Подать заявку на водителя такси" << endl;
		cout << "2)Оформить заказ" << endl;
		cout << "3)Поиск информации по ФИО водителя" << endl;
		cout << "4)Считать и вывести данные с файла" << endl;
		cout << "5)Записать данные в файл." << endl;//В разработке
		cout << "0)Выход" << endl;
		cin >> v;
		switch (v)
		{
		case 1:
			a->application(a, len);
			len++;
			cout << "\n\tДанные о вас записаны." << endl;
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
			cout << "Введите название файла: "<<endl;
			cin >> path;
			readfile(path);
			path = "";
			break;
		case 5:
			cout << "Введите название файла в который вы хотите записать данные:" << endl;
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
