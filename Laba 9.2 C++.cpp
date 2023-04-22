#include <iostream>
#include <cstddef>
#include <typeinfo>
#include <cstring>
using namespace std;

//Шаблонный класс Array
template <typename  T>
class Array
{
private:
	T* myArray;
	size_t n;
public:
	explicit Array(size_t size = 0, const T& value = T())
	{
		n = size;
		myArray = new T[n];
		for (size_t i = 0; i < n; i++)
			myArray[i] = value;
	}

	Array(const Array& mas)
	{
		n = mas.n;
		myArray = new T[n];
		for (size_t i = 0; i < n; i++)
			myArray[i] = mas.myArray[i];
	}

	~Array()
	{
		delete[] myArray;
	}

	Array& operator=(const Array& mas)
	{
		if (this == &mas)
			return *this;
		this->~Array();
		n = mas.n;
		myArray = new T[n];
		for (size_t i = 0; i < n; i++)
			myArray[i] = mas.myArray[i];
		return *this;
	}

	T& operator[](size_t idx)
	{
		return myArray[idx];
	}

	const T& operator[](size_t idx) const
	{
		return myArray[idx];
	}

	size_t size() const
	{
		return n;
	}
};

//Произвольный тип данных Student
class Student
{
private:
	string name;
	int numberZachet;
public:
	Student() :name("undefined"), numberZachet(0)
	{}
	Student(string name, int numberZachet)
	{
		this->name = name;
		this->numberZachet = numberZachet;
	}

	string showName()
	{
		return name;
	}
	int showNumber()
	{
		return numberZachet;
	}
};

//Базовый класс для класса ValueHolder
struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

//Шаблонный класс, возвращающий адрес копии начального объекта
template <typename  T>
struct ValueHolder :public ICloneable
{
public:
	T data_;

	ValueHolder(T data) :data_(data)
	{}

	ICloneable* clone() const
	{
		return new ValueHolder(*this);
	}

};

//Класс Any
class Any {
	ICloneable* data_;
public:
	Any() : data_(nullptr) {}

	template <typename T>
	Any(const T& data) : data_(new ValueHolder<T>(data)) {}

	Any(const Any& other) : data_(nullptr) {
		if (other.data_) {
			data_ = other.data_->clone();
		}
	}

	Any& operator=(const Any& other) {
		if (this != &other) {
			Any(other).swap(*this);
		}
		return *this;
	}

	~Any() {
		delete data_;
	}

	template <typename T>
	Any& operator=(const T& data) {
		Any(data).swap(*this);
		return *this;
	}

	void swap(Any& other) {
		std::swap(data_, other.data_);
	}

	template <typename T>
	T* cast() {
		ValueHolder<T>* ptr = dynamic_cast<ValueHolder<T>*>(data_);
		if (ptr) {
			return &ptr->data_;
		}
		return nullptr;
	}

	template <typename T>
	T* showData()
	{
		return data_;
	}
};

//Компаратор Compare для поиска минимального значения
template <typename  T>
bool Compare(T a, T b)
{
	return a < b;
}

//Структура Greater с перегруженным оператором () для поиска максимального значения
template <typename  T>
struct Greater
{
	bool operator ()(T a, T b)
	{
		return b < a;
	}
};

//Структура для разных типов
template<typename T, typename U>
struct SameType {
	static const bool value = false;
};

//Структура для одинаковых типов
template<typename T>
struct SameType<T, T> {
	static const bool value = true;
};

template <typename T, size_t N>
constexpr size_t array_size(T(&)[N]) noexcept {
	return N;
}

//Объявление шаблонной функции копирования элементов массива
template <typename T, typename U>
T* copy_n(T arrayNew[], U arrayOld[], int size);

//Объявление шаблонной функции поиска минимального/максимального элемента шаблонного класса
template <typename T, typename Comparator>
T minimum(const Array<T>& arr, Comparator comp);

//Оюъявление шаблонной функции flatten для одномерного массива
template <typename T>
void flatten(const Array<T>& arr, ostream& out);

//Объявление шаблонной функции flatten для многомерного массива
template <typename T>
void flatten(const Array<Array<T>>& arr, ostream& out);




int main()
{
	setlocale(LC_ALL, "RUS");
	int menu;
	do {
		cout << "\"Шаблоны\"\n"
			"Выберите действие\n"
			"1-Задание 1. Вывод шаблонного класса Array для различных типов данных\n"
			"2-Задание 2. Реализация оператора присваивания\n"
			"3-Задание 3. Копирование значение в новый адрес. Вывод значения, старого и нового адреса\n"
			"4-Задание 4. Копирование элементов массива одного типа в массив другого типа\n"
			"5-Задание 5. Поиск максимального и минимального значения элемента массива для разных типов\n"
			"6-Задание 6. Вывод элементов массива для одномерных и вложенных массивов разных типов\n"
			"7-Задание 7. Реализация класса Any\n"
			"8-Задание 8. Проверка типов данных. Если они одинаковые, то 1, иначе 0\n"
			"9-Задание 9. Узнать размер массива разных типов данных\n"
			"0-Выход" << endl;
		cin >> menu;
		system("cls");

		switch (menu)
		{
		case 1:
		{
			cout << "Массив из двух элементов, каждый из которых цифра 5" <<
				endl;
			Array<int> objectInt(2, 5);
			for (int i = 0; i < objectInt.size(); i++)
				cout << "objectInt[" << i << "] = " << objectInt[i] << endl;
			cout << endl;

			cout << "Массив из трёх элементов, каждый их которых число 12.56" <<
				endl;
			Array<double> objectDouble(3, 12.56);
			for (int i = 0; i < objectDouble.size(); i++)
				cout << "objectDouble[" << i << "] = " << objectDouble[i] << endl;
			cout << endl;

			cout << "Массив из одного элемента, каждый из которых слово Hello"
				<< endl;
			Array<string> objectString(1, "Hello");
			for (int i = 0; i < objectString.size(); i++)
				cout << "objectString[" << i << "] = " << objectString[i] << endl;
			cout << endl;

			cout << "Массив из двух элементов, каждый из которых слово World!"
				<< endl;
			char text[] = { "World!" };
			Array<char*> objectChar(2, text);
			for (int i = 0; i < objectChar.size(); i++)
				cout << "objectChar[" << i << "] = " << objectChar[i] << endl;
			cout << endl;

			Student IST("Ivanov Ivan Ivanovich", 958234);//Объект IST с name = Ivanov Ivan Ivanovich, numberZachet = 958234
				cout << "Массив из двух элементов, каждый из которых объект IST" <<
				endl;
			Array<Student> objectStudent(2, IST);
			for (int i = 0; i < objectStudent.size(); i++)
				cout << "objectStudent[" << i << "].name = " <<
				objectStudent[i].showName() << "\n" << "objectStudent[" << i << "].numberZachet = " <<
				objectStudent[i].showNumber() << endl;
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "Реализация оператора присвоения класса Array\nРазмер массива = 4" << endl;
				Array<int> a(4, 0);
			Array<int> b(4, 0);

			for (int i = 0; i < 4; i++)
				cout << "A[" << i << "] = " << a[i] << "  " << "B[" << i << "] = " << b[i]
				<< endl;

			for (int i = 0; i < 4; i++)
			{
				cout << "Введите элемент A[" << i << "]" << endl;
				cin >> a[i];
			}
			for (int i = 0; i < 4; i++)
				cout << "A[" << i << "] = " << a[i] << "  " << "B[" << i << "] = " << b[i]
				<< endl;

			cout << "b = a" << endl << endl;
			b = a;
			for (int i = 0; i < 4; i++)
				cout << "A[" << i << "] = " << a[i] << "  " << "B[" << i << "] = " << b[i]
				<< endl;

			break;
		}
		case 3:
		{
			cout << "Копирование числа\nВведите число" << endl;
			int intCopy;
			cin >> intCopy;

			ValueHolder<int> original(intCopy);
			cout << "Старый адрес: " << &(original.data_) << endl;
			cout << "Значение по адресу = " << original.data_ << endl;

			ValueHolder<int>* copy =
				dynamic_cast<ValueHolder<int>*>(original.clone());
			cout << "Новый адрес:  " << copy << endl;
			cout << "Значение по адресу = " << copy->data_ << endl << endl;
			delete copy;

			break;
		}
		case 4:
		{
			cout << "Копирование элементов массива одного типа в массив другого типа" << endl;
				int arrayInt[] = { 1, 2, 3, 4 };
			double arrayDouble[4] = {};

			copy_n(arrayDouble, arrayInt, 4);
			cout << "\nInt->Double" << endl;
			for (int i = 0; i < 4; i++)
				cout << arrayInt[i] << " | " << arrayDouble[i] << endl;

			float arrayFloat[] = { 5.65f, 6.12f, 7.92f, 8.22f };
			int arrayInt2[4] = {};

			copy_n(arrayInt2, arrayFloat, 4);
			cout << "\nFloat->Int" << endl;
			for (int i = 0; i < 4; i++)
				cout << arrayFloat[i] << " | " << arrayInt2[i] << endl;

			copy_n(arrayDouble, arrayFloat, 4);
			cout << "\nFloat->Double" << endl;
			for (int i = 0; i < 4; i++)
				cout << arrayFloat[i] << " | " << arrayDouble[i] << endl;

			break;
		}
		case 5:
		{
			cout << "Поиск максимального/минимального значения элементов массива" << endl;
			Array<int> ints(3);
			ints[0] = 10;
			ints[1] = 2;
			ints[2] = 15;

			cout << "Массив целых чисел:" << endl;
			for (int i = 0; i < 3; i++)
				cout << "intArray[" << i << "] = " << ints[i] << endl;

			int minInt = minimum(ints, Compare<int>);
			int maxInt = minimum(ints, Greater<int>());

			cout << "Минимальное значение элементов массива int = " << minInt <<
				"\nМаксимальное значение элементов массива int = " << maxInt << endl << endl;

			Array<double> doubleArr(6);
			doubleArr[0] = 5.67;
			doubleArr[1] = 1.68;
			doubleArr[2] = 9.02;
			doubleArr[3] = 4.98;
			doubleArr[4] = 11.67;
			doubleArr[5] = 0.55;

			cout << "Массив вещественных чисел:" << endl;
			for (int i = 0; i < 5; i++)
				cout << "doubleArray[" << i << "] = " << doubleArr[i] << endl;

			double minDouble = minimum(doubleArr, Compare<double>);
			double maxDouble = minimum(doubleArr, Greater<double>());

			cout << "\nМинимальное значение элементов массива double = " <<
				minDouble <<
				"\nМаксимальное значение элементов массива double = " <<
				maxDouble << endl << endl;

			break;
		}
		case 6:
		{
			Array<int> oneIntArray(2, 0);
			oneIntArray[0] = 10;
			oneIntArray[1] = 20;

			cout << "IntArray[2]. Все элементы массива:" << endl;
			flatten(oneIntArray, cout);
			cout << endl;

			Array<Array<int>> manyIntArray(2, oneIntArray);
			cout << "manyIntArray[2][IntArray]. Все элементы массива:" << endl;
			flatten(manyIntArray, cout);
			cout << endl;

			Array<double> oneDoubleArray(3, 2.52);
			cout << "DoubleArray[3]. Все элементы массива:" << endl;
			flatten(oneDoubleArray, cout);
			cout << endl;

			Array<Array<double>> manyDoubleArray(4, oneDoubleArray);
			cout << "manyDoubleArray[4][DoubleArray]. Все элементы массива:" <<
				endl;
			flatten(manyDoubleArray, cout);
			cout << endl;

			break;
		}
		case 7:
		{
			Any empty; // empty ничего не хранит
			cout << "Any empty;\nempty = " << empty.cast<Any>() << endl << endl;;

			Any intAny(10); // хранит значение 10
			int* intAny_ptr = intAny.cast<int>(); // *intAny_ptr == 10
			cout << "Any intAny(10);\nЗначение " << *intAny_ptr << " хранится по адресу " << intAny_ptr << endl << endl;

			Any doubleAny(3.14); // d хранит значение 3.14
			double* doubleAny_ptr = doubleAny.cast<double>(); // *doubleAny_ptr == 3.14
			cout << "Any doubleAny(3.14);\nЗначение " << *doubleAny_ptr << "хранится по адресу " << doubleAny_ptr << endl << endl;

			Any stringAny(string("hello")); // хранит строку "hello"
			string* stringAny_ptr = stringAny.cast<string>(); // *stringAny_ptr == "hello"
				cout << "Any stringAny(string(\"hello\"));\nЗначение " << *stringAny_ptr
				<< " хранится по адресу " << stringAny_ptr << endl << endl;

			char* cptr = intAny.cast<char>(); // cptr == 0, потому что intAny хранит int, а не char
			cout << "char* cptr = intAny.cast<char>();" << endl;
			if (cptr == nullptr)cout << "cptr = nullptr" << endl << endl;
			else cout << "cptr = " << cptr << endl << endl;

			Any empty2;
			int* p = empty2.cast<int>(); // p == 0
			cout << "int* p = empty2.cast<int>();\np = " << p << endl << endl;

			break;
		}
		case 8:
		{
			struct Dummy { };
			typedef int type;
			cout << "Если одинаковые типы данных, value = 1, иначе value = 0\ntypedef int type; \n" << endl;
				cout << "SameType<int, int>, value = " << SameType<int, int>::value <<
				endl;
			cout << "SameType<int, type>, value = " << SameType<int, type>::value <<
				endl;
			cout << "SameType<int, int&>, value = " << SameType<int, int&>::value <<
				endl;
			cout << "SameType<Dummy, Dummy>, value = " << SameType<Dummy,
				Dummy>::value << endl;
			cout << "SameType<int, const int>, value = " << SameType<int, const
				int>::value << endl << endl;

			break;
		}
		case 9:
		{
			int intArray9[] = { 1, 2, 3, 4 };
			cout << "Все элементы массива intArray" << endl;
			for (int i = 0; i < 4; i++)
				cout << intArray9[i] << " ";
			cout << endl;

			double doubleArray9[] = { 3.14 };
			cout << "Все элементы массива intArray" << endl;
			for (int i = 0; i < 1; i++)
				cout << doubleArray9[i] << " ";
			cout << endl;

			char charArray9[] = { "Hello" };
			cout << "Все элементы массива charArray" << endl;
			for (int i = 0; i < 6; i++)
				cout << charArray9[i] << " ";
			cout << endl;

			cout << "Размер массива типа int = " << array_size(intArray9) << endl; // вернет 4
				cout << "Размер массива типа double = " << array_size(doubleArray9) <<
				endl; // вернет 1
			cout << "Размер массива типа char (включая \\0) = " <<
				array_size(charArray9) << endl; // вернёт 6

			//int* int_ptr = intArray9;
			//cout << array_size(int_ptr) << endl; // тут должна произойти ошибка компиляции
				break;
		}
		cin.get();
		}
	} while (menu != 0);
}

//Шаблонная функция копирования элементов массива разных типов
template <typename T, typename U>
T* copy_n(T arrayNew[], U arrayOld[], int size)
{
	for (int i = 0; i < size; i++)
		arrayNew[i] = (T)arrayOld[i];

	return arrayNew;
}

//Шаблонная функция поиска минимального/максимального значения массива
template <typename T, typename Comparator>
T minimum(const Array<T>& arr, Comparator comp) {
	T min = arr[0];
	for (size_t i = 1; i < arr.size(); ++i)
		if (comp(arr[i], min)) min = arr[i];

	return min;
}

// Шаблон flatten для одномерного массива
template<typename T>
void flatten(const Array<T>& arr, ostream& out) {
	for (size_t i = 0; i < arr.size(); ++i) {
		out << arr[i] << ' ';
	}
}

// Шаблон flatten для многомерного массива
template<typename T>
void flatten(const Array<Array<T>>& arr, ostream& out) {
	for (size_t i = 0; i < arr.size(); ++i) {
		flatten(arr[i], out);
	}
}