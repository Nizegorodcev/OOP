#include <iostream>
#include <locale.h>
using namespace std;
class Lab {
private:
    int raws;
    int cols;
    int intArray;
    int** matrix;

public:
    Lab(int raw, int col, int intArr) {  //����������� ������

        raws = raw;
        cols = col;
        intArray = intArr;
        cout << "����������������� ������� " << raws << " �� " << cols << endl;
        matrix = new int* [raws];
        for (int i = 0; i < raws; i++) {
            matrix[i] = new int[cols];
        }
    }

    void input() {
        cout << "������� �������� �������" << endl;
        for (int i = 0; i < raws; i++) {

            for (int j = 0; j < cols; j++) {

                cout << "Array[" << i << "]" << "[" << j << "] = ";
                cin >> matrix[i][j];
                cout << endl;
            }
        }
    }

    void output() {
        cout << "����� ��������� �������\n\n";
        for (int i = 0; i < raws; i++) {

            for (int j = 0; j < cols; j++) {

                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void summ(int col) {
        int summ = 0;

        for (int i = 0; i < raws; i++) {

            summ += matrix[i][col - 1];
        }

        cout << "\n����� ��������� " << col << " ������� ����� : " << summ << endl;
    }
    int zero_counter() {
        int zeros = 0;
        for (int i = 0; i < raws; i++) {

            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeros += 1;
                }
            }
        }
        return zeros;
    }
    void diagonal() {

        cout << "������ ������� : " << raws * cols << endl;

        for (int i = 0; i < raws; i++) {
            matrix[i][i] = raws * cols;
        }
        for (int i = 0; i < raws; i++) {

            for (int j = 0; j < cols; j++) {

                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void indexator(int raw, int col) {
        if ((raw > raws) || (col > cols)) {
            cout << "������ �������� �� ����������" << endl;
        }
        else {
            cout << "Array[" << raw << "]" << "[" << col << "] = " << matrix[raw][col] << endl;
        }
    }
    Lab  operator ++ (int) {
        Lab temp(*this);
        for (int i = 0; i < temp.raws; i++) {

            for (int j = 0; j < temp.cols; j++) {
                temp.matrix[i][j] += 1;
            }
        }
        return temp;
    }
    Lab  operator -- (int) {
        Lab temp(*this);
        for (int i = 0; i < temp.raws; i++) {

            for (int j = 0; j < temp.cols; j++) {
                temp.matrix[i][j] -= 1;
            }
        }
        return temp;
    }
    Lab  operator + (Lab right) {
        Lab temp(*this);
        if ((temp.raws != right.raws) || (temp.cols != right.cols)) {
            cout << "������� ������ ������������!!" << endl;
        }
        else {
            for (int i = 0; i < temp.raws; i++) {

                for (int j = 0; j < temp.cols; j++) {
                    temp.matrix[i][j] += right.matrix[i][j];
                }
            }
        }
        return temp;
    }
};


int main()
{
    setlocale(LC_ALL, "rus");
    Lab tasks(2, 2, 15);
    tasks.input();
    tasks.output();
    int zeros = tasks.zero_counter();
    cout << "���������� ����� � �������: " << zeros << endl;
    tasks.diagonal();
    int raw, col;
    cout << "� ������ �������� �� ������ ����������? ������� �������: " << endl;
    cin >> raw >> col;
    tasks.indexator(raw, col);
    cout << "\n\n���������� --" << endl;
    tasks--;
    tasks.output();
    cout << "\n\n���������� ++" << endl;
    tasks++;
    tasks.output();
    Lab tasks1(2, 2, 15);
    tasks1.input();
    cout << "\n\n �������� ��������" << endl;
    tasks = tasks + tasks1;
    tasks.output();
}
