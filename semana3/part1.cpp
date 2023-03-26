#include <iostream>
#include <cmath>
using namespace std;
#define PI 3.1416
int main() {
 double radio, altura, dato1, volumen_cono;
 cout << "--Calculo de volumen de un Cono--" << endl;
 cout << "\nDatos Cono" << endl;
 cout << "Ingrese el valor del radio: ";
 cin >> radio;
 cout << "Ingrese el valor de la altura: ";
 cin >> altura;
 dato1 = PI * pow(radio, 2);
  volumen_cono = (dato1 * altura) / 3;
 cout << "\n---El volumen del cono es: " << volumen_cono << endl;
 return 0;
}
