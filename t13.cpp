#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double m;
    double L;
    double D;
    double T;
    double g = 9.81;

    double a;
    double ay;

    cout << "Введите массу m (кг): ";
    cin >> m;

    cout << "Введите подъёмную силу L (Н): ";
    cin >> L;

    cout << "Введите сопротивление D (Н): ";
    cin >> D;

    cout << "Введите тягу двигателя T (Н): ";
    cin >> T;

    a = (T - D) / m;
    ay = (L - m * g) / m;

    cout << fixed << setprecision(2);
    cout << "Ускорение по направлению движения a  = " << a << " м/с^2" << endl;
    cout << "Вертикальное ускорение         ay = " << ay << " м/с^2" << endl;

    return 0;
}