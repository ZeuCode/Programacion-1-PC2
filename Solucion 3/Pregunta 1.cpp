
#include <iostream>
using namespace std;


void DibujarFigura1(int filas) {
	for (int i = filas; i > 0; i--) {
		cout << "\n";
		for (int e = 0; e < 2; e++) {
			cout << " ";
		}
		for (int j = filas; j > 0; j--) {
			if (i == filas || i == 1) {
				if (i == filas)cout << j << "  ";
				else cout << filas - j + 1 << "  ";
			}
			else if (j == filas || j == 1) {
				if (j == filas)cout << i << "  ";
				else cout << filas - i + 1 << "  ";
			}
			else cout << "   ";
		}
		cout << endl;
	}
}
void DibujarFigura2(int filas) {
	cout << "\n";
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < filas; j++) {
			if (i == 0 || i == filas - 1)cout << "X ";
			else if (j == 0 || j == filas - 1)cout << "X ";
			else if (i == j || j == filas - i - 1)cout << "X ";
			else cout << "  ";
		}
		cout << endl;
	}
}
int main() {
	int opcion;
	int filas;
	bool salir = false;
	while (!salir) {
		cout << "Menu de Opciones" << endl;
		cout << "1. Dibujar Figura 1" << endl;
		cout << "2. Dibujar Figura 2" << endl;
		cout << "3. Salir" << endl;
		cout << "\nIngrese opcion: "; cin >> opcion;
		switch (opcion) {
		case 1:
			do {
				cout << "Ingrese numero de filas: "; cin >> filas;
			} while (filas < 1);
			DibujarFigura1(filas); break;
		case 2:
			do {
				cout << "Ingrese numero de filas: "; cin >> filas;
			} while (filas < 1);
			DibujarFigura2(filas); break;
		case 3:
			salir = true; break;
		default:
			cout<<"La opcion indicada no es válida."<<endl;

		}
		cout << "\n";
	}
	system("pause>nul");
	return 0;
}

