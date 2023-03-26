#include <iostream>
using namespace std;

const double UMA = 123.22;
const int DIAS_LABORADOS = 30;

double calcularCuotaIMSS(double salarioBruto) {
    double salarioDiarioIntegrado = salarioBruto / DIAS_LABORADOS;
    double cuotaAdicionalObrero = 0;
    double cuotaPorPrestamo = salarioDiarioIntegrado * DIAS_LABORADOS * 0.25 / 100;
    double gastosMedicos = salarioDiarioIntegrado * DIAS_LABORADOS * 0.375 / 100;
    double gastoPorInvalidez = salarioDiarioIntegrado * DIAS_LABORADOS * 0.625 / 100;
    double cuotaIMSS = 0;

    if (salarioDiarioIntegrado - UMA * 3 > 0) {
        cuotaAdicionalObrero = (salarioDiarioIntegrado - UMA * 3) * DIAS_LABORADOS * 0.011;
    }

    if (cuotaAdicionalObrero < 0) {
        cuotaAdicionalObrero = 0;
    }

    cuotaIMSS = cuotaAdicionalObrero + cuotaPorPrestamo + gastosMedicos + gastoPorInvalidez;

    return cuotaIMSS;
}

int main() {
    double salarioBruto;

    cout << "Ingrese el salario bruto del empleado: ";
    cin >> salarioBruto;

    // Validación de entrada numérica
    while (cin.fail()) {
        cin.clear(); // limpia la bandera de error
        cin.ignore(10000, '\n'); // descarta la entrada no válida
        cout << "Error: Ingrese un valor numérico." << endl;
        cout << "Ingrese el salario bruto del empleado: ";
        cin >> salarioBruto;
    }

    while (salarioBruto < 0) {
        cout << "Error: Ingrese un valor positivo." << endl;
        cout << "Ingrese el salario bruto del empleado: ";
        cin >> salarioBruto;
    }

    double cuotaIMSS = calcularCuotaIMSS(salarioBruto);
    double salarioNeto = salarioBruto - cuotaIMSS;

    cout << "La cuota correspondiente al IMSS es: " << cuotaIMSS << endl;
    cout << "El salario neto del empleado es: " << salarioNeto << endl;

    return 0;
}
