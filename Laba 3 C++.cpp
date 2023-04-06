#include <iostream>
const unsigned int N = 6;
// размер [4;16]!
using namespace std;
int f_dump(int array[N][N]);
int f_trans(int array[N][N]);
int f_fill(int arr[N][N]);
double f_opred(int** a, int n);
void f_clean(int** a, int n);
int main()
{
	setlocale(0, "");
	int array[N][N] = { 0 };
	f_fill(array);
	cout << "\tИсходная матрица размером " << N << '*' << N << '\n';
	f_dump(array);
	cout << "\n\tТРАНС! матрица размером " << N << '*' << N << '\n';
	f_trans(array);
	f_dump(array);
	int** a = new int* [N]; //дин.мас
	for (int i = 0; i < N; i++) a[i] = new int[N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = array[i][j];
		}
	}
	cout << "\n\tОпределитель матрицы -> " << f_opred(a, N) << "\n";

}
int f_dump(int arr[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) std::cout << arr[i][j] << "\t";
		std::cout << std::endl;
	}
	return 0;
}
int f_trans(int arr[N][N]) {
	int temp = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}

	}
	return 0;
}
int f_fill(int arr[N][N]) {
	int temp = N * N; int N1 = N - 1;
	for (int moment = 0; moment < N * 2; moment++) {
		if (moment % 4 == 0) {
			for (int i = N - 1; i >= 0; i--) {
				if (arr[N1][i] == 0) {
					arr[N1][i] = temp;
					temp--;
				}
			}
		}
		if (moment % 4 == 1) {
			for (int i = N - 1; i >= 0; i--) {
				if (arr[i][N - N1 - 1] == 0) {
					arr[i][N - N1 - 1] = temp;
					temp--;
				}
			}
		}
		if (moment % 4 == 2) {
			for (int i = 0; i < N; i++) {
				if (arr[N - N1 - 1][i] == 0) {
					arr[N - N1 - 1][i] = temp;
					temp--;
				}
			}
		}
		if (moment % 4 == 3) {
			for (int i = 0; i < N; i++) {
				if (arr[i][N1] == 0) {
					arr[i][N1] = temp;
					temp--;
				}
			}
		}
		if (moment % 4 == 3) N1--;
	}
	return 0;
}
double f_opred(int** a, int n) {
	if (n == 2) return a[0][0] * a[1][1] - a[0][1] * a[1][0];
	else {
		double d = 0;
		for (int k = 0; k < n; k++) {// для каждой строки
			int** mas = new int* [n - 1];
			for (int i = 0; i < n - 1; i++) {
				mas[i] = new int[n - 1];
			}
			// создаем новую дин.матрицу
			for (int i = 1; i < n; i++) {
				int t = 0;
				for (int j = 0; j < n; j++) {
					if (j == k) continue;
					mas[i - 1][t] = a[i][j];
					t++;
				}
			}
			//заполняем из дин.копии
			d += pow(-1, k + 2) * a[0][k] * f_opred(mas, n - 1);
			f_clean(mas, n - 1); //очистка из-под алг. дополнения
		}
		return d;
	}
}
void f_clean(int** a, int n) { //чистка в текущем дин. массиве
	for (int i = 0; i < n; i++) {
		delete[] a[i];
	}
	delete[] a;
}