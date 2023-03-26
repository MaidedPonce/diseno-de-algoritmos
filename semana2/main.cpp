#include <iostream>;
using namespace std;

int main (){    
    float radio, altura, volumen;

    cout << "Ingrese el radio del cilindro";
    cin >> radio;

    cout << "Ingrese la altura del cilindro";
    cin >> altura;

    volumen = 3.1416 * radio * radio * altura;

    cout << "El volumen del cilindro es: " << volumen << endl;

    return 0;
}
