#include <iostream>

using namespace std;

int main() {
    double ingreso_mensual, isr = 0;
    double lim_inf, lim_sup, cuota_fija, porcentaje, excedente, isr_rango;

    // Tabla del ISR
    double tabla_isr[11][4] = {
        {0.01, 578.52, 0.00, 1.92},
        {578.53, 4910.18, 11.11, 6.40},
        {4910.19, 8629.20, 288.33, 10.88},
        {8629.21, 10031.07, 692.96, 16.00},
        {10031.08, 12009.94, 917.26, 17.92},
        {12009.95, 24222.31, 1271.87, 21.36},
        {24222.32, 38177.69, 3880.44, 23.52},
        {38177.70, 72887.50, 7162.74, 30.00},
        {72887.51, 97183.33, 17575.69, 32.00},
        {97183.34, 291550.00, 25350.35, 34.00},
        {291550.01, -1, 91435.02, 35.00}
    };

    cout << "Ingrese el ingreso mensual del contribuyente: ";
    cin >> ingreso_mensual;

    // Calcular el impuesto sobre la renta
    for (int i = 0; i < 11; i++) {
        lim_inf = tabla_isr[i][0];
        lim_sup = tabla_isr[i][1];
        cuota_fija = tabla_isr[i][2];
        porcentaje = tabla_isr[i][3];

        if (ingreso_mensual >= lim_inf && ingreso_mensual <= lim_sup) {
            excedente = ingreso_mensual - lim_inf;
            isr_rango = cuota_fija + (porcentaje / 100) * excedente;
            isr += isr_rango;
            break;
        } else if (ingreso_mensual > lim_sup) {
            excedente = lim_sup - lim_inf;
            isr_rango = cuota_fija + (porcentaje / 100) * excedente;
            isr += isr_rango;
        } else {
            break;
        }
    }

    // Imprimir el impuesto sobre la renta total
    cout << "El impuesto sobre la renta total es: $" << isr << endl;

    return 0;

}
