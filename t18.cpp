#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>

using namespace std;

struct Aircraft {
    double m;
    double T;
    double CL;
    double CD;
};

int main() {
    setlocale(LC_ALL, "Russian");

    const double g = 9.81;
    const double rho = 1.225;
    const double V = 80.0;
    const double S = 16.2;
    const double h = 1000.0;

    const int N = 3;

    Aircraft planes[N] = {
        {  750, 2000, 0.40, 0.030 },
        { 1100, 3500, 0.50, 0.035 },
        { 1600, 5000, 0.55, 0.040 }
    };

    double t[N];

    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho * V * V * S * planes[i].CL;
        double ay = (L - planes[i].m * g) / planes[i].m;
        t[i] = sqrt(2.0 * h / ay);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (t[j] > t[j + 1]) {
                double tmp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tmp;

                Aircraft tmpP = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = tmpP;
            }
        }
    }

    cout << fixed << setprecision(2);

    cout << "| " << setw(3) << "№" << " | " << setw(8) << "Масса" << " | " << setw(10) << "Ускорение" << " | " << setw(10) << "Время" << " |" << endl;

    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho * V * V * S * planes[i].CL;
        double ay = (L - planes[i].m * g) / planes[i].m;

        cout << "| " << setw(3) << (i + 1) << " | " << setw(8) << planes[i].m << " | " << setw(10) << ay << " | " << setw(10) << t[i] << " |" << endl;
    }

    return 0;
}