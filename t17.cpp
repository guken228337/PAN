#include <iostream>
#include <clocale>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double m;
    double L;
    double g = 9.81;
    double ay;

    cout << "Введите массу m (кг): ";
    cin >> m;

    cout << "Введите подъёмную силу L (Н): ";
    cin >> L;

    ay = (L - m * g) / m;

    if (ay > 0.5) {
        cout << "Режим: набор высоты" << endl;
    }
    else if (ay >= 0) {
        cout << "Режим: горизонтальный полёт" << endl;
    }
    else {
        cout << "Режим: снижение" << endl;
    }

    return 0;
}