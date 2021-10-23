#include<iostream>
using namespace std;

void GenerarMostrarDatos(float VTiempos[]) {
	for (int i = 0; i < 35; i++) {
		VTiempos[i] = (rand() % 15000 + 45000)/float(1000);
	}
	for (int i = 0; i < 35; i++) {
		cout << VTiempos[i] << "  ";
		if (i == 10 || i == 20)cout << "\n";
	}
	cout << "\n\n";
}
int Mostrar_PrimerTiempo(float VTiempos[]) {
	float mejor1 = VTiempos[0];
	int pos = 0;
	for (int i = 1; i < 35; i++) {
		if (VTiempos[i] < mejor1) {
			pos = i;
			mejor1 = VTiempos[i];
		}
	}
	cout << "El 1er mejor tiempo del concurso es: " << mejor1 <<" minutos" << endl;
	return pos;
}
void Mostrar_SegundoTiempo(float VTiempos[],int posMejorTiempo1) {
	float mejor2 = VTiempos[0];
	for (int i = 1; i < 35; i++) {
		if (i != posMejorTiempo1) {
			if (VTiempos[i] < mejor2)mejor2 = VTiempos[i];
		}
	}
	cout << "El 2do mejor tiempo del concurso es: " << mejor2 << " minutos" << endl;
}
int main() {
	srand(time(NULL));
	float VTiempos[35];
	int pos;
	GenerarMostrarDatos(VTiempos);
	pos=Mostrar_PrimerTiempo(VTiempos);
	Mostrar_SegundoTiempo(VTiempos,pos);
	system("pause>nul");
	return 0;
}