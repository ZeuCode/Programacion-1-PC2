#include<iostream>
using namespace std;

int Calcular_PesoExacto(float peso1,float peso2,float peso3) {
	int contador = 0;
	if (peso1 == 5)contador += 1;
	if (peso2 == 5)contador += 1;
	if (peso3 == 5)contador += 1;
	return 3-contador; //el numero de bolsas -las que si cumplen con el peso
}
int main() {
	float peso1, peso2, peso3;
	do {
		cout << "Ingrese el peso 1:"; cin >> peso1;
	} while (peso1 <=0);
	do {
		cout << "Ingrese el peso 2:"; cin >> peso2;
	} while (peso2 <= 0);
	do {
		cout << "Ingrese el peso 3:"; cin >> peso3;
	} while (peso3 <= 0);
	cout << "Numero de bolsas que no cumplen con el peso:" << Calcular_PesoExacto(peso1, peso2, peso3);
	system("pause>nul");
	return 0;
}