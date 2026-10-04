#include <iostream>
#include <iomanip>
#include <clocale>
#include <cmath>

using namespace std;

struct Plane {
    double m;
    double S;
    double T;
    double CL;
    double CD;
};

double liftForce(double rho, double V, double S, double CL) {
    return 0.5 * rho * V * V * S * CL;
}

double dragForce(double rho, double V, double S, double CD) {
    return 0.5 * rho * V * V * S * CD;
}

double verticalAccel(double L, double m, double g) {
    return (L - m * g) / m;
}

double timeToClimb(double h, double ay) {
    return sqrt(2.0 * h / ay);
}

int main() {
    setlocale(LC_ALL, "Russian");

    double g = 9.81;
    double rho = 1.225;
    double V = 80.0;
    double h = 1000.0;

    Plane planes[3] = {
        {  750, 16.2, 2000, 0.40, 0.030 },
        { 1100, 17.0, 3500, 0.50, 0.035 },
        { 1600, 21.0, 5000, 0.55, 0.040 }
    };

    double times[3];
    int bestIndex = 0;

    cout << fixed << setprecision(2);

    for (int i = 0; i < 3; i++) {
        double L = liftForce(rho, V, planes[i].S, planes[i].CL);
        double D = dragForce(rho, V, planes[i].S, planes[i].CD);
        double ay = verticalAccel(L, planes[i].m, g);
        double t = timeToClimb(h, ay);

        times[i] = t;
    }

    for (int i = 0; i < 3; i++) {
        if (times[i] < times[bestIndex]) {
            bestIndex = i;
        }
    }

    cout << "Быстрее всех самолёт " << (bestIndex + 1)
        << ", t = " << times[bestIndex] << " с" << endl;

    return 0;
}