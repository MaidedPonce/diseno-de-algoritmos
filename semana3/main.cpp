#include <iostream>
using namespace std;

double cuotaIMSS(double sueldoBruto) {
    double cuota = 0.0; // Inicializamos la cuota en cero

    // Definimos los límites y tasas de cuotas como constantes para facilitar la lectura del código
    const double limites[] = {0.01, 578.53, 4910.19, 8629.21, 10031.08, 12009.95, 24222.32, 38177.70, 72887.51, 97183.34, 291550.01};
    const double tasas[] = {0.0192, 0.0640, 0.1088, 0.1600, 0.1792, 0.2136, 0.2352, 0.3000, 0.3200, 0.3400, 0.3500};

    // Buscamos el límite adecuado para el sueldo bruto y calculamos la cuota correspondiente
    for (int i = 0; i < sizeof(limites) / sizeof(double); i++) {
        double excedente = sueldoBruto - limites[i];
        if (excedente > 0) {
            cuota += excedente * tasas[i];
            sueldoBruto -= excedente;
        } else {
            break;
        }
    }

    return cuota;
}


int main() {
    double sueldo;
    
    cout << "Ingresa el sueldo bruto: ";
    cin >> sueldo;
    
    double cuota = cuotaIMSS(sueldo);
    
    cout << "La cuota del IMSS es: " << cuota << endl;
    
    return 0;
}
