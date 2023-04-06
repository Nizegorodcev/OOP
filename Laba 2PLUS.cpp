#include <iostream>
#include <locale.h>
#define SIZE 12
using namespace std;
void task1() {
    int array[SIZE];
    cout << "Массив будет заполнен случайными числами\n";
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand();
        cout << "Элемент массива array[" << i << "] = " << array[i] << "\n";
    }
    int max = 0;
    for (int i = 0; i < SIZE; i++) {
        if ((max < array[i]) && (array[i] > 0)) {
            max = array[i];
        }
    }
    cout << "Максимальный элемента массива равен :" << max << "\n";
    int sum = 0;
    for (int i = 1; i < SIZE; i++) {
        sum += array[i];
    }
    cout << "Сумма элементов массива :" << sum << "\n";
    cout << "Вывод ненулевых элемнтов в обратном порядке :";
    for (int i = SIZE - 1; i >= 0; i--) {
        if (array[i] != 0) {
            cout << array[i] << " ";
        }
    }
    cout << "\n";
}
void task2() {
    int array[5][6];
    cout << "Ввод чисел с клавиатуры\n";
    for (int raw = 0; raw < 5; raw++) {
        for (int col = 0; col < 6; col++) {
            cout << "Введите array[" << raw << "]" << "[" << col << "]\n";
            cin >> array[raw][col];
            //array[raw][col] = rand(); для автозаполнения
        }
    }
    cout << "Вывод массива\n";
    for (int raw = 0; raw < 5; raw++) {
        for (int col = 0; col < 6; col++) {
            cout << array[raw][col] << " ";
        }
        cout << "\n";
    }
    int j = 0;
    int maxes[5];
    for (int i = 0; i < 5; i++) {
        int local_max = array[j][0];
        for (; j < 6; j++) {
            if (local_max < array[j][i]) {
                local_max = array[j][i];
            }

        }
        j = 0;
        maxes[i] = local_max;
        cout << "\nМаксимум в " << i + 1 << " столбце : " << local_max;
    }
}
void sift_down(int* numbers, int root, int bottom)
{
    int maxChild;
    int done = 0;
    while ((root * 2 <= bottom) && (!done))
    {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root];
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
        }
        else
            done = 1;
    }
}
void heap_sort(int* numbers, int array_size)
{

    for (int i = (array_size / 2); i >= 0; i--)
        sift_down(numbers, i, array_size - 1);

    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        sift_down(numbers, 0, i - 1);
    }
}
void task3() {
    int array[10];

    for (int i = 0; i < 10; i++) {
        array[i] = rand();
    }
    cout << "Изначальный массив:\n";
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << "\nОтсортированный массив:\n";
    heap_sort(array, 10);
    for (int i = 0; i < 10; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
int main()
{
    setlocale(LC_ALL, "rus");
    int choice;
    cout << "Выберите задание для проверки:\n";
    cin >> choice;
    switch (choice)
    {
    case 1:task1(); break;
    case 2:task2(); break;
    case 3:task3(); break;
    default:
        break;
    }

    return 0;

}
