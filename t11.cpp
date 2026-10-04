#include <iostream>
#include <iomanip>
#include <clocale>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    double S;    
    double V;     
    double r; 
    double CL;    
    double L;    

    cout << "Введите площадь крыла S (м^2): ";
    cin >> S;

    cout << "Введите скорость полёта V (м/с): ";
    cin >> V;

    cout << "Введите плотность воздуха r (кг/м^3): ";
    cin >> r;

    cout << "Введите коэффициент подъёмной силы CL: ";
    cin >> CL;

    L = 0.5 * r * V * V * S * CL;

    cout << fixed << setprecision(2);
    cout << "Подъёмная сила L = " << L << " Н" << endl;

    return 0;
}