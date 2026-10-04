#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double h;
    double ay;
    double t;

    cout << "Введите высоту набора h (м): ";
    cin >> h;

    cout << "Введите вертикальное ускорение ay (м/с^2): ";
    cin >> ay;

    if (h <= 0) {
        cout << "Ошибка: высота должна быть больше 0." << endl;
        return 1;
    }
    if (ay <= 0) {
        cout << "Ошибка: ускорение должно быть больше 0." << endl;
        return 1;
    }

    t = sqrt(2.0 * h / ay);

    cout << fixed << setprecision(2);
    cout << "Время набора высоты t = " << t << " с" << endl;

    return 0;
}