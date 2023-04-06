#include <iostream>
#include <string>
#include <fstream>
const int N = 2;
using namespace std;
void z1();
void z2();
void z3();
struct ZNAK
{
    int TIME[2];
    int BDAY[3];
    string NAME[2];
    string ZODIAK;
};

int main()
{
    system("chcp 1251"); //setlocale( LC_ALL, "RUS" );
    system("cls");
    z2();
}
void z1() {
    cout << "\tВведите строку с числами и quit для завершения\n";
    string s; int t = 0;

    while (1) {
        cout << ">> ";  cin >> s;
        for (int i = 0; i < s.length(); i++) {
            for (int j = 48; j <= 57; j++) {
                if ((int)s[i] == j) cout << "Обнаружено: " << s[i] << '\n';
            }
            if ((int)s[i] == 113) t++;
            if ((int)s[i] == 117) t++;
            if ((int)s[i] == 105) t++;
            if ((int)s[i] == 116) t++;
        } if (t == 4) break;

    }
}
void z2() {
    string text[30]; int len[30] = { 0 }; int minn = 999, maxx = 0, inn = 0, ixx = 0;
    std::string line;

    std::ifstream in("text.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        int i = 0;
        while (getline(in, line)) { text[i] = line; i++; }
        for (int i = 0; i < 30; i++) len[i] = text[i].length();
        for (int i = 0; i < 30; i++) {
            if (minn > len[i]) { minn = len[i]; inn = i; }
            if (maxx < len[i]) { maxx = len[i]; ixx = i; }
        }
        string str = text[inn];
        text[inn] = text[ixx];
        text[ixx] = str;
    }
    in.close();

    std::ofstream out;          // поток для записи
    out.open("text.txt");  // окрываем файл для записи
    if (out.is_open())
    {
        for (int i = 0; i < 30; i++) out << text[i] << "\n";
    }

    std::cout << "Теперь проверь файл)";
    out.close();
}
void z3() {
    cout << "\tЗаполним данные по людям";
    ZNAK BOOK[N];
    for (int i = 0; i < N; i++) {
        cout << endl;
        cout << "Введите фамилию и имя: ";
        cin >> BOOK[i].NAME[0] >> BOOK[i].NAME[1];
        //cout <<"\n" << BOOK[i].NAME[0] << BOOK[i].NAME[1];
        cout << "Введите дату рождения: ";
        cin >> BOOK[i].BDAY[0] >> BOOK[i].BDAY[1] >> BOOK[i].BDAY[2];
        cout << "Введите время: ";
        cin >> BOOK[i].TIME[0] >> BOOK[i].TIME[1];
        cout << "Введите знак зодиака: "; cin >> BOOK[i].ZODIAK;

    }
    cout << endl; char yy = '+';

    while (1) {
        cout << "\tВывести данные? (+)"; cin >> yy;
        if (yy == '+') {
            cout << "\tФамилия? "; string nonn; cin >> nonn;
            for (int i = 0; i < N; i++) {
                if (nonn == BOOK[i].NAME[0]) {
                    cout << "Зовут - " << BOOK[i].NAME[0] << " " << BOOK[i].NAME[1] << '\n';
                    cout << "Родился - " << BOOK[i].BDAY[0] << "го числа " << BOOK[i].BDAY[1] << "го месяца в " << BOOK[i].BDAY[2] << "м\n";
                    cout << "В " << BOOK[i].TIME[0] << ':' << BOOK[i].TIME[1] << " по МСК\n";
                    cout << BOOK[i].ZODIAK << " по зодиаку \n";
                    break;
                }
                if (i == N - 1 && nonn != BOOK[i].NAME[0]) { cout << "Мы такого не знаем"; }
            }
        }
        else break;
    }
}
