#include <iostream>
#include <iomanip>
using namespace std;

const double UMA = 123.22;
const int DIAS_LABORADOS = 30;

struct ISR
{
    double limite_inferior;
    double limite_superior;
    double cuota_fija;
    double porcentaje;
};

ISR tabla_isr[] = {
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
    {291550.01, 1e12, 91435.02, 35.00}};

struct BandaSalarial
{
    int numero;
    double importe_minimo;
    double importe_maximo;
};

BandaSalarial tabla_banda_salarial[] = {
    {1, 5063, 8607},
    {2, 5571, 10693},
    {3, 6710, 15649},
    {4, 8862, 20866},
    {5, 11902, 30123},
    {6, 13927, 52161},
    {7, 17725, 65203},
    {8, 22789, 78244},
    {9, 31652, 91284},
    {10, 11902, 30123}};

double calcular_isr(double sueldo_bruto)
{
    double isr = 0;
    for (int i = 0; i < sizeof(tabla_isr) / sizeof(tabla_isr[0]); i++)
    {
        if (sueldo_bruto >= tabla_isr[i].limite_inferior && sueldo_bruto <= tabla_isr[i].limite_superior)
        {
            double excedente = sueldo_bruto - tabla_isr[i].limite_inferior;
            isr = tabla_isr[i].cuota_fija + (excedente * tabla_isr[i].porcentaje / 100);
            break;
        }
    }
    return isr;
}

double calcular_imss(double sueldo_bruto)
{
    double salario_diario_integrado = sueldo_bruto / DIAS_LABORADOS;
    double cuota_adicional_obrero = max(0.0, salario_diario_integrado - UMA * 3) * DIAS_LABORADOS * 0.011;
    double cuota_prestamo = salario_diario_integrado * DIAS_LABORADOS * 0.25 / 100;
    double gastos_medicos = salario_diario_integrado * DIAS_LABORADOS * 0.004;
    double imss = cuota_adicional_obrero + cuota_prestamo + gastos_medicos;
    return imss;
}

int buscar_banda_salarial(double sueldo_bruto)
{
    for (int i = 0; i < sizeof(tabla_banda_salarial) / sizeof(tabla_banda_salarial[0]); i++)
    {
        if (sueldo_bruto >= tabla_banda_salarial[i].importe_minimo && sueldo_bruto <= tabla_banda_salarial[i].importe_maximo)
        {
            return tabla_banda_salarial[i].numero;
        }
    }
    return -1;
}

void imprimir_recibo(double sueldo_bruto)
{
    double isr = calcular_isr(sueldo_bruto);
    double imss = calcular_imss(sueldo_bruto);
    double sueldo_neto = sueldo_bruto - isr - imss;
    int banda_salarial = buscar_banda_salarial(sueldo_bruto);
    cout << "RECIBO DE PAGO" << endl;
    cout << "===============================" << endl;
    cout << fixed << setprecision(2);
    cout << "Sueldo bruto: $" << sueldo_bruto << endl;
    cout << "Descuento ISR: $" << isr << endl;
    cout << "Descuento IMSS: $" << imss << endl;
    cout << "Sueldo neto: $" << sueldo_neto << endl;
    if (banda_salarial != -1)
    {
        cout << "Banda salarial: " << banda_salarial << endl;
    }
}
int main()
{
    double sueldo_bruto;
    cout << "Ingrese el sueldo bruto: $";
    cin >> sueldo_bruto;
    imprimir_recibo(sueldo_bruto);
    return 0;
}