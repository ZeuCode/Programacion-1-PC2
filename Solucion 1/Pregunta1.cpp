
#include <iostream>
using namespace std;

float Calcular_Perimetro(int r) {
    return 2 * 3.1416 * r;
}
void Graficar(int filas) {
    for (int i = 1; i <= filas; i++) {
        for (int e = 0; e <filas-i; e++) {
            cout << "  ";
        }
        for (int j = 0; j < i; j++) {
            cout << j + 1 << " ";
        }
        if (i > 1) {
            for (int k = i - 1; k > 0; k--) {
                cout << k << " ";
            }
        }
        cout << endl;
    }
    for (int i = 1; i < filas; i++) {
        for (int e = 0; e < i; e++) {
            cout << "  ";
        }
        for (int j = 0; j < filas - i; j++) {
            cout << j + 1 << " ";
        }
        for (int k = filas - i-1; k > 0; k--) {
            cout << k << " ";
        }
        cout << endl;
    }
}

int main()
{
    bool salir = false;
    int opcion;
    int radio;
    int filas;
   
    while (!salir) {
        cout << "Menu de opciones" << endl;
        cout << "1. Calcular_Perimetro" << endl;
        cout << "2. Graficar" << endl;
        cout << "3. Fin" << endl;
        do {
            cout << "Ingrese opcion: "; cin >> opcion;
        } while (opcion < 1 || opcion>3);
        switch (opcion) {
        case 1:
            do {
                cout << "Ingrese el valor de r: "; cin >> radio;
            } while (radio < 1);
            cout << "El perimetro es: " << Calcular_Perimetro(radio)<<endl;
            break;
        case 2:
            do {
                cout << "Ingrese el numero de filas: "; cin >> filas;
            } while (filas < 2 || filas>9);
            Graficar(filas);
            break;
        case 3:salir = true;
            break;
        }
        cout << "\n";
    }
    system("pause>nul");
    return 0;
}