
#include "Taxi.h"
#include<Windows.h>
#include<fstream>
#include<iomanip>
#include <algorithm>
void printmas(Taxi* arr, int size) {//Печать массива
	int fiodr, otkyda, kyda, fiocl;
	fiocl = 10;
	otkyda = 17;
	kyda = 12;
	fiodr = 25;
	string cl, ot, ky, dr;
	cl = "ФИО клиента";
	ot = "Откуда";
	ky = "Куда";
	dr = "ФИО водителя";
	fiocl = 40 - cl.length();
	otkyda = 40 - ot.length();
	kyda = 40 - ky.length();
	fiodr = 40 - dr.length();
	cout << "_________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "|" << cl << setw(fiocl) << "|" << ot << setw(otkyda) << "|" << ky << setw(kyda) << "|" << dr << setw(fiodr) << "|" << endl;
	for (int i = 0; i < size; i++) {

		cout << "|" << arr[i].client << setw(40 - arr[i].client.length()) << "|" << arr[i].where_from << setw(40 - arr[i].where_from.length()) << "|" << arr[i].where << setw(40 - arr[i].where.length()) << "|" << arr[i].driver << setw(40 - arr[i].driver.length()) << "|" << "\n";
		cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}
int del(Taxi* arr,int size)//Удаление записи
{

	int fiodr, otkyda, kyda, fiocl;
	int index;
	string cl, ot, ky, dr;
	cl = "ФИО клиента";
	ot = "Откуда";
	ky = "Куда";
	dr = "ФИО водителя";
	fiocl = 40 - cl.length();
	otkyda = 40 - ot.length();
	kyda = 40 - ky.length();
	fiodr = 40 - dr.length();
	int price1, price2;
	cout << "___________________________________________________________________________________________________________________________________________________________________" << endl;
	cout << "  |" << cl << setw(fiocl) << "|" << ot << setw(otkyda) << "|" << ky << setw(kyda) << "|" << dr << setw(fiodr) << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++) {
		
		cout <<i<<" |" << arr[i].client << setw(40 - arr[i].client.length()) << "|" << arr[i].where_from << setw(40 - arr[i].where_from.length()) << "|" << arr[i].where << setw(40 - arr[i].where.length()) << "|" << arr[i].driver << setw(40 - arr[i].driver.length()) << "|" << "\n";
		cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "Какую строку вы хотите удалить?" << endl;
	cin >> index;
	if (index > size)
	{
		cout << "Такого элемента не существует" << endl;
	}
	else
	{
		
		for (int i = index; i < size-1; i++)
		{
			arr[i].client = arr[i + 1].client;
			arr[i].where_from = arr[i + 1].where_from;
			arr[i].where = arr[i + 1].where;
			arr[i].driver = arr[i + 1].driver;
			arr[i].colour = arr[i + 1].colour;
			arr[i].marka = arr[i + 1].marka;
			arr[i].registration_mark = arr[i + 1].registration_mark;
			arr[i].distance = arr[i + 1].distance;
			price1 = arr[i].distance * 20;
			price2 = arr[i + 1].distance * 20;
			arr->setprice(price2, arr, i);
		}
		size--;
		cout << "_________________________________________________________________________________________________________________________________________________________________" << endl;
		cout << "|" << cl << setw(fiocl) << "|" << ot << setw(otkyda) << "|" << ky << setw(kyda) << "|" << dr << setw(fiodr) << "|" << endl;
		for (int i = 0; i < size; i++) {

			cout <<i<<" |" << arr[i].client << setw(40 - arr[i].client.length()) << "|" << arr[i].where_from << setw(40 - arr[i].where_from.length()) << "|" << arr[i].where << setw(40 - arr[i].where.length()) << "|" << arr[i].driver << setw(40 - arr[i].driver.length()) << "|" << "\n";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		
		return size;
	}
	
}
void writefile(Taxi* arr,string path,int size)//Запись в файл
{
	ofstream fout;
	int fiodr, otkyda, kyda, fiocl;
	fiocl = 10;
	otkyda = 17;
	kyda = 12;
	fiodr = 25;
	string cl, ot, ky, dr;
	cl = "ФИО клиента";
	ot = "Откуда";
	ky = "Куда";
	dr = "ФИО водителя";
	fiocl = fiocl - cl.length() + 1;
	otkyda = otkyda + 1 - ot.length();
	kyda = kyda + 5 - ky.length();
	fiodr = fiodr + 4 - dr.length();
	string client, where_from, where, driver;
	fout.open(path,ofstream::app);
	if (fout.is_open())
	{
		/*cout << "Файл открыт." << endl;
		cout << "Введите ФИО клиента:" << endl;
		cin >> client;
		cout << "Введите адрес откуда его забрали: " << endl;
		cin >> where_from;
		cout << "Введите адрес куда ему надо: " << endl;
		cin >> where;
		cout << "Введите ФИО его водителя:" << endl;
		cin >> driver;
		fout <<"|" << client << setw(40 - client.length()) << "|" << where_from << setw(40 - where_from.length()) << "|" << where << setw(40 - where.length()) << "|" << driver << setw(40 - driver.length()) << "|" << "\n";*/
		for (int i = 0; i < size; i++)
		{
			fout << "|" << arr[i].client << setw(40 - arr[i].client.length()) << "|" << arr[i].where_from << setw(40 - arr[i].where_from.length()) << "|" << arr[i].where << setw(40 - arr[i].where.length()) << "|" << arr[i].driver << setw(40 - arr[i].driver.length()) << "|" << "\n";
		}
	}
	else
	{
		cout << "Не удалось открыть файл!" << endl;
	}
	fout.close();
}
void readfile(string path)//Чтение
{
	ifstream fin;
	string str;
	int fiodr, otkyda, kyda, fiocl;
	string cl, ot, ky, dr;
	cl = "ФИО клиента";
	ot = "Откуда";
	ky = "Куда";
	dr = "ФИО водителя";
	fiocl = 40 - cl.length();
	otkyda =  40 - ot.length();
	kyda =  40 - ky.length();
	fiodr =  40 - dr.length();
	fin.open(path);
	if ((fin.is_open()))
	{	
		cout << "Файл открыт." << endl;
		cout << "_________________________________________________________________________________________________________________________________________________________________" << endl;
		cout <<"|"<<cl<< setw(fiocl)<<"|"<< ot <<setw(otkyda)<<"|"<<ky<<setw(kyda)<<"|"<<dr<<setw(fiodr)<<"|" << endl;
		
		/*printf("|%20S|%21S|%21S|%24S|\n", fiocl, otkyda, kyda, fiodr);*/
		while (!fin.eof())
		{
			str = "";
			cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
bool compare(string a, string b)//Сравнение ФИО водителя
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
void searchDriver(Driver* arr, int size)//Функция поиска водителя по ФИО
{
	string value;
	cout << "Введите ФИО водителя, которого вы хотите найти:" << endl;
	cin >> value;
	int kol = 0;
	for (int i = 0; i < size; i++)
	{
		if (compare(value, arr[i].driver) == true)
		{
			cout << "ФИО водителя: " << arr[i].driver << endl;
			cout << "Марка машины: " << arr[i].marka << endl;
			cout << "Цвет машины: " << arr[i].colour << endl;
			cout << "Регистрационный знак: " << arr[i].registration_mark << endl;
		}
		else kol++;
	}
	if (kol == size) cout << "Такого в нашей базе данных нет" << endl;
}
void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("chcp 1251");
	system("cls");
	int len = 0;//Длина массива водителей
	int len1 = 0;
	int len2 = 0;//Для массива такси
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
	cout << "\t Вас приветствует Воронеж-такси!\n" << endl;
	while (true)
	{
		cout << "Выберите действие: " << endl;
		cout << "1)Подать заявку на водителя такси" << endl;
		cout << "2)Оформить заказ" << endl;
		cout << "3)Поиск информации по ФИО водителя" << endl;
		cout << "4)Считать и вывести данные с файла" << endl;
		cout << "5)Записать данные массива в файл." << endl;
		cout << "6)Удаление записи массива" << endl;
		cout << "7)Печать массива" << endl;
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
			len1 = a->getdriver(a, len);
			arr[len2].driver = a[len1].driver;
			arr[len2].colour = a[len1].colour;
			arr[len2].marka = a[len1].marka;
			arr[len2].registration_mark = a[len1].registration_mark;
			len2++;
			break;
		case 3:
			searchDriver(a, len);
			break;
		case 4:
			cout << "Введите название файла: " << endl;
			cin >> path;
			readfile(path);
			path = "";
			break;
		case 5:
			cout << "Введите название файла в который вы хотите записать данные:" << endl;
			cin >> path;
			writefile(arr, path, len2);

			break;
		case 6:
			len2 = del(arr, len2);
			break;
		case 7:
			printmas(arr, len2);
			break;
		}
		if (v == 0)
		{
			delete[] arr;
			delete[] a;
			break;
		}
		
}   }
	
