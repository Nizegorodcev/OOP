#include <iostream>
#include <cmath>
#define e 2.7182818284
using namespace std;
double fact(double n)
{
	double res=1;
	for (int i = 1; i < n+1; i++)
	{
		res = res * i;
	}
	return res;
}
double step(double x, int n)
{
	double f;
	f = x;
	for (int i = 0; i < n-1; i++)
	{
		f = f * x;
	}
	return f;
}
double func2(double x,int i)
{
	double res;
	res = step(x, (2 * i) - 1) / fact((2 * i) - 1);
	return res;
}
void function(double a, double b)
{
	double z;
	z = (17.8 * a + pow(cos(13.2*pow(b,2) + 2.4 * b + 3.7),2))/(sqrt(e+(13.7-sin(pow(a,2)+b))/(-17.478*a+13,2*b)));
	cout << z;
	
}
int main()
{
	int v;
	setlocale(LC_ALL, "RUS");
	double a,b,x,chislo;
	double eps = 0.001;
	cout << "�������� ��������:" << endl;
	cout << "1)����� �������� ��������������� ���������"<<endl;
	cout << "2)���������� ������� F(x) ����������� � ���"<<endl;
	cout << "3)��������� ��� ����������� ����� ���������� �����"<<endl;
	cin >> v;
	switch (v)
	{
	case 1:
		cout << "������� ���������� a: ";
		cin >> a;
		cout << "������� ���������� b: ";
		cin >> b;
		function(a, b);
		break;
	case 2:
		cout << "������� x: ";
		cin >> x;
		for (int i = 1; i < 10000; i++)
		{
			if (fabs(func2(x, i) - func2(x, i + 1)) <= eps)
			{
				cout << func2(x, i + 1);
				break;
			}
		}
		break;
	case 3:
		cout << "������� �����:";
		cin >> chislo;
		if (chislo == 0)
		{
			cout << "������ ����";
		}
		if (chislo > 0)
		{
			cout << " ������� ������������� �����";
		}
		else cout << "������� ������������� �����";
	}
	

}