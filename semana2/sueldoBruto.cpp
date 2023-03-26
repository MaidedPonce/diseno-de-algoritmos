#include <iostream>
using namespace std;

int main() {
    float banda_salarial, cuota_fija, porcentaje, excedente, cuota_variable, cuota_total, sueldo_bruto, sueldo_neto;
    
    float limites_inferiores[] = {0.01, 578.53, 4910.19, 8629.21, 10031.08, 12009.95, 24222.32, 38177.70, 72887.51, 97183.34, 291550.01};
    float cuotas_fijas[] = {0.00, 11.11, 288.33, 692.96, 917.26, 1271.87, 3880.44, 7162.74, 17575.69, 25350.35, 91435.02};
    float porcentajes[] = {1.92, 6.40, 10.88, 16.00, 17.92, 21.36, 23.52, 30.00, 32.00, 34.00, 35.00};
    
    // Paso 1
    cout << "Ingrese la banda salarial del empleado: ";
    cin >> banda_salarial;
    
    // Validación de entrada numérica y positiva
    while (cin.fail() || banda_salarial < 0) {
        cin.clear(); // limpia la bandera de error
        cin.ignore(10000, '\n'); // descarta la entrada no válida
        cout << "Error: Ingrese un valor numérico y positivo." << endl;
        cout << "Ingrese la banda salarial del empleado: ";
        cin >> banda_salarial;
    }
    
    // Paso 3
    int i = 0;
    while (banda_salarial >= limites_inferiores[i] && i < 11) {
        cuota_fija = cuotas_fijas[i];
        porcentaje = porcentajes[i];
        i++;
    }
    
    // Paso 4
    excedente = banda_salarial - limites_inferiores[i-1];
    
    // Paso 5
    cuota_variable = (excedente * porcentaje) / 100;
    
    // Paso 6
    cuota_total = cuota_fija + cuota_variable;
    
    // Paso 7
    cout << "Ingrese el sueldo bruto del empleado: ";
    cin >> sueldo_bruto;
    
    // Paso 8
    sueldo_neto = sueldo_bruto - cuota_total;
    
    // Paso 9
    cout << "El sueldo neto del empleado es: $" << sueldo_neto << endl;
    
    return 0;
}
