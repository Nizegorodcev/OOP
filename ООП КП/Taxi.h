#pragma once
#include<iostream>
#include <cmath>
#include<string>
using namespace std;
class Driver//Водитель
{
public:
	string driver, marka, colour, registration_mark;//Водитель, марка машины,цвет,регистрационный знак
	void setdriver(string driver,string marka,string colour,string registration_mark)
	{
		this->driver = driver;
		this->colour = colour;
		this->marka = marka;
		this->registration_mark = registration_mark;
	}
	void application(Driver* arr, int size)//Подача заявления на становление таксистом
	{
		cout << "Давайте заполним данные о вас " << endl;
		cout << "Введите ваше ФИО:" << endl;
		cin >> arr[size].driver;
		cout << "Укажите марку машины: " << endl;
		cin >> arr[size].marka;
		cout << "Укажите цвет машины: " << endl;
		cin >> arr[size].colour;
		cout << "Укажите регистрационный знак: " << endl;
		cin >> arr[size].registration_mark;
		arr[size].setdriver(arr[size].driver, arr[size].marka, arr[size].colour, arr[size].registration_mark);
	}
	void getdriver(Driver* arr, int size)//Срабатывает при оформлении заказа
	{
		int len = rand() % size;
		cout << "К вам подьедет водитель: " << arr[len].driver << endl;
		cout << "Марка машины: " << arr[len].marka << endl;
		cout << "Цвет машины: " << arr[len].colour << endl;
		cout<<"Регистрационный знак: "<<arr[len].registration_mark<<"\n" << endl;
	}
	
};
class client//Клиент
{
public:
	string client, where_from, where;//ФИО клиента, откуда, куда
	
};
class Taxi:public client,public Driver//Такси
{
private:
	
	int distance, price;//Расстояние,20 рублей за километр
	
public:
	
	Taxi()
	{
		
	}
	~Taxi()
	{

	}
	 void setTaxi(string client,string where_from,string where)//Чисто для красоты, не используется
	 {
		 this->client = client;
		 this->where_from = where_from;
		 this->where = where;
	 }
	void getTaxi(Taxi*arr,int size)//Информация о заказе
	{
		distance = rand() % 100;
		price = 20 * distance;
		cout << "ФИО клиента: " << arr[size].client << endl;
		cout << "Откуда ехать: " << arr[size].where_from << endl;
		cout << "Куда ехать: " << arr[size].where << endl;
		cout << "Длина пути: " << distance<<" км" << endl;
		cout << "Цена: " << price <<" рублей" << endl;
	
	}
	void order(Taxi* arr, int size)//Заказ
	{
		cout << "Давайте заполним данные о вас " << endl;
		cout << "Введите своё ФИО:" << endl;
		cin >> arr[size].client;
		cout << "Укажите то место где вы находитесь: " << endl;
		cin >> arr[size].where_from;
		cout << "Укажите то место куда вам надо: " << endl;
		cin >> arr[size].where;
	}
};

