#pragma once
#include<iostream>
#include <cmath>
#include<string>
using namespace std;
class Driver//��������
{
public:
	string driver, marka, colour, registration_mark;//��������, ����� ������,����,��������������� ����
	void setdriver(string driver,string marka,string colour,string registration_mark)
	{
		this->driver = driver;
		this->colour = colour;
		this->marka = marka;
		this->registration_mark = registration_mark;
	}
	void application(Driver* arr, int size)//������ ��������� �� ����������� ���������
	{
		cout << "������� �������� ������ � ��� " << endl;
		cout << "������� ���� ���:" << endl;
		cin >> arr[size].driver;
		cout << "������� ����� ������: " << endl;
		cin >> arr[size].marka;
		cout << "������� ���� ������: " << endl;
		cin >> arr[size].colour;
		cout << "������� ��������������� ����: " << endl;
		cin >> arr[size].registration_mark;
		arr[size].setdriver(arr[size].driver, arr[size].marka, arr[size].colour, arr[size].registration_mark);
	}
	void getdriver(Driver* arr, int size)//����������� ��� ���������� ������
	{
		int len = rand() % size;
		cout << "� ��� �������� ��������: " << arr[len].driver << endl;
		cout << "����� ������: " << arr[len].marka << endl;
		cout << "���� ������: " << arr[len].colour << endl;
		cout<<"��������������� ����: "<<arr[len].registration_mark<<"\n" << endl;
	}
	
};
class client//������
{
public:
	string client, where_from, where;//��� �������, ������, ����
	
};
class Taxi:public client,public Driver//�����
{
private:
	
	int distance, price;//����������,20 ������ �� ��������
	
public:
	
	Taxi()
	{
		
	}
	~Taxi()
	{

	}
	 void setTaxi(string client,string where_from,string where)//����� ��� �������, �� ������������
	 {
		 this->client = client;
		 this->where_from = where_from;
		 this->where = where;
	 }
	void getTaxi(Taxi*arr,int size)//���������� � ������
	{
		distance = rand() % 100;
		price = 20 * distance;
		cout << "��� �������: " << arr[size].client << endl;
		cout << "������ �����: " << arr[size].where_from << endl;
		cout << "���� �����: " << arr[size].where << endl;
		cout << "����� ����: " << distance<<" ��" << endl;
		cout << "����: " << price <<" ������" << endl;
	
	}
	void order(Taxi* arr, int size)//�����
	{
		cout << "������� �������� ������ � ��� " << endl;
		cout << "������� ��� ���:" << endl;
		cin >> arr[size].client;
		cout << "������� �� ����� ��� �� ����������: " << endl;
		cin >> arr[size].where_from;
		cout << "������� �� ����� ���� ��� ����: " << endl;
		cin >> arr[size].where;
	}
};

