#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const double g = 9.81;
    const double rho = 1.225;
    const double V = 80.0;

    double m;
    double S;
    double CL;
    double h;

    double Tmin;
    double Tmax;
    double dT;

    cout << "Введите массу m (кг): ";
    cin >> m;

    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;

    cout << "Введите коэффициент подъёмной силы CL: ";
    cin >> CL;

    cout << "Введите набираемую высоту h (м): ";
    cin >> h;

    cout << "Введите Tmin (Н): ";
    cin >> Tmin;

    cout << "Введите Tmax (Н): ";
    cin >> Tmax;

    cout << "Введите шаг dT (Н): ";
    cin >> dT;

    double L = 0.5 * rho * V * V * S * CL;
    double ay = (L - m * g) / m;

    double tMin = -1;
    double Tbest = Tmin;

    cout << fixed << setprecision(2);

    for (double T = Tmin; T <= Tmax; T += dT) {
        double a = (T - 0) / m;
        double ay2 = ay + a;
        double t = sqrt(2.0 * h / ay2);

        if (tMin < 0 || t < tMin) {
            tMin = t;
            Tbest = T;
        }
    }

    cout << "Оптимальная тяга: T = " << Tbest << " Н" << endl;
    cout << "Время набора высоты: t = " << tMin << " с" << endl;

    return 0;
}