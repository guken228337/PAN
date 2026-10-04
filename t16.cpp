#include <iostream>
#include <iomanip>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    const int N = 5;

    double V[N] = { 70, 75, 80, 85, 90 };
    double rho[N] = { 1.225, 1.150, 1.080, 1.010, 0.945 };

    double S = 16.2;
    double CL = 0.50;

    double L;

    cout << fixed << setprecision(2);

    cout << "| " << setw(3) << "Шаг" << " | " << setw(8) << "Скорость" << " | " << setw(9) << "Плотность" << " | " << setw(14) << "Подъёмная сила" << " |" << endl;

    for (int i = 0; i < N; i++) {
        L = 0.5 * rho[i] * V[i] * V[i] * S * CL;

        cout << "| " << setw(3) << (i + 1) << " | " << setw(8) << V[i] << " | " << setw(9) << rho[i] << " | " << setw(14) << L << " |" << endl;
    }

    return 0;
}