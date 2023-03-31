#include <iostream>
#include <string>

using namespace std;

string arabicToRoman(int num) {
    if (num <= 0 || num >= 4000) {
        throw "Niepoprawna liczba! Podaj liczbę z przedziału 0..3999.";
    }
    string result = "";
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    for (int i = 0; i < 13; i++) {
        while (num >= value[i]) {
            num -= value[i];
            result += roman[i];
        }
    }

    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Użycie: " << argv[0] << " <liczba arabska>" << endl;
        return 1;
    }

    int num = stoi(argv[1]);

    try {
        string romanNum = arabicToRoman(num);
        cout << romanNum << endl;
    } catch (const char *msg) {
        cerr << msg << endl;
        return 1;
    }

    return 0;
}