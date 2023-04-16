#include <iostream>

using namespace std;

int main()
{
    int numero;
    int variable1 = 0;
    int variable2 = 1;
    int variable3 = 1;

    cout << "Ingresa el numero de la serie deseado: ";
    cin >> numero;

    cout << "1 ";

    for (int i = 1; i < numero; i++) {
        variable3 = variable1 + variable2;
        cout << variable3 << " ";
        variable1 = variable2;
        variable2 = variable3;
    }

    cout << endl;

    return 0;
}
