#include <iostream>
using namespace std;

double sueldoBruto(int banda)
{
    double tablaBanda[9][2] = {
        {5063, 8607},
        {5571, 10693},
        {6710, 15649},
        {8862, 20866},
        {11902, 30123},
        {13927, 52161},
        {17725, 65203},
        {22789, 78244},
        {31652, 91284}};

    if (banda < 1 || banda > 9)
    {
        cout << "Error: Banda salarial inválida." << endl;
        return 0;
    }

    double sueldo = tablaBanda[banda - 1][0] + tablaBanda[banda - 1][1];
    return sueldo;
}

double ISR(double sueldo)
{
    double tablaISR[11][4] = {
        {0.01, 578.52, 0.00, 0.0192},
        {578.53, 4910.18, 11.11, 0.064},
        {4910.19, 8629.20, 288.33, 0.1088},
        {8629.21, 10031.07, 692.96, 0.16},
        {10031.08, 12009.94, 917.26, 0.1792},
        {12009.95, 24222.31, 1271.87, 0.2136},
        {24222.32, 38177.69, 3880.44, 0.2352},
        {38177.70, 72887.50, 7162.74, 0.3},
        {72887.51, 97183.33, 17575.69, 0.32},
        {97183.34, 291550.00, 25350.35, 0.34},
        {291550.01, -1, 91435.02, 0.35}};

    double isr = 0;
    for (int i = 0; i < 11; i++)
    {
        if (sueldo >= tablaISR[i][0] && (sueldo <= tablaISR[i][1] || tablaISR[i][1] == -1))
        {
            isr = (sueldo - tablaISR[i][2]) * tablaISR[i][3];
            break;
        }
    }

    return isr;
}

int main()
{
    /*  int banda;
     cout << "Ingresa el número de la banda salarial (1-9): ";
     cin >> banda;

     double sueldo = sueldoBruto(banda);
     cout << "El sueldo bruto es: $" << sueldo << endl;

     double isr = ISR(sueldo);
     cout << "El ISR es: $" << isr << endl;

     return 0; */
    double sueldo;
    cout << "Ingrese sueldo bruto: ";
    cin >> sueldo;

    double isr = ISR(sueldo);
    cout << "ISR a retener: $" << isr << endl;

    return 0;
}
