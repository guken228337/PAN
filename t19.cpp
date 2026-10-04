#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

struct Aircraft {
    double m;
    double S;
    double T;
    double CL;
    double CD;
};

int main() {
    setlocale(LC_ALL, "Russian");

    const double g = 9.81;
    const double rho = 1.225;
    const double V = 80.0;

    int N;

    cout << "Введите количество самолётов N: ";
    cin >> N;

    Aircraft planes[10];

    for (int i = 0; i < N; i++) {
        cout << "Самолёт " << (i + 1) << ":" << endl;

        cout << "  масса m (кг): ";
        cin >> planes[i].m;

        cout << "  площадь крыла S (м^2): ";
        cin >> planes[i].S;

        cout << "  тяга T (Н): ";
        cin >> planes[i].T;

        cout << "  коэффициент подъёмной силы CL: ";
        cin >> planes[i].CL;

        cout << "  коэффициент сопротивления CD: ";
        cin >> planes[i].CD;
    }

    cout << fixed << setprecision(2);

    cout << "| " << setw(3) << "№" << " | " << setw(10) << "Подъёмная" << " | " << setw(10) << "Сопротивл." << " | " << setw(10) << "Ускорение" << " |" << endl;

    double L;
    double D;
    double a;
    double aMax = 0;
    int bestIndex = 0;

    for (int i = 0; i < N; i++) {
        L = 0.5 * rho * V * V * planes[i].S * planes[i].CL;
        D = 0.5 * rho * V * V * planes[i].S * planes[i].CD;
        a = (planes[i].T - D) / planes[i].m;

        cout << "| " << setw(3) << (i + 1) << " | " << setw(10) << L << " | " << setw(10) << D << " | " << setw(10) << a << " |" << endl;

        if (a > aMax) {
            aMax = a;
            bestIndex = i;
        }
    }

    cout << "Наибольшее ускорение у самолёта " << (bestIndex + 1) << ": a = " << aMax << " м/с^2" << endl;

    return 0;
}