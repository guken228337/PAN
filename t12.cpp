#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

double dragForce(double r, double V, double S, double CD) {
    double L = 0.5 * r * V * V * S * CD;
    return L;
}

int main() {
    setlocale(LC_ALL, "Russian");

    double S;
    double V;
    double r;
    double CD;
    double L;

    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;

    cout << "Введите скорость полёта V (м/с): ";
    cin >> V;

    cout << "Введите плотность воздуха r (кг/м^3): ";
    cin >> r;

    cout << "Введите коэффициент сопротивления CD: ";
    cin >> CD;

    L = dragForce(r, V, S, CD);

    cout << fixed << setprecision(2);
    cout << "L = " << L << " Н" << endl;

    return 0;
}