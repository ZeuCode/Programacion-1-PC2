#include<iostream>
using namespace std;


void GenerarDatos(int VPuntos[], int VEdad[], char VDistrito[]) {
	char distritos[4] = { 'm','c','y','v' };
	for (int i = 0; i < 20; i++) {
		VPuntos[i] = rand() % 101;
		VEdad[i] = rand() % 8 + 13;
		VDistrito[i] = distritos[rand() % 4];
	}
}
void ImprimeDatos(int VPuntos[], int VEdad[], char VDistrito[]) {
	cout << "\nPuntaje\t\tEdad\t\tDistrito" << endl;
	for (int i = 0; i < 20; i++) {
		cout << VPuntos[i] << "\t\t";
		cout << VEdad[i] << "\t\t";
		switch (VDistrito[i]) {
		case 'm':
			cout << "manantay"; break;
		case 'c':
			cout<<"calleria"; break;
		case 'y':
			cout<<"yarinococha"; break;
		case 'v':
			cout<<"campo verde"; break;
		}
		cout << endl;
	}
}
void PorcentajeAprobados(int VPuntos[], int VEdad[], char VDistrito[]) {
	int menoresAprobados = 0, mayoresAprobados = 0;
	for (int i = 0; i < 20; i++) {
		if (VPuntos[i] >= 65) {
			if (VEdad[i] < 18)menoresAprobados += 1;
			else mayoresAprobados += 1;
		}
	}
	cout << "\n";
	cout << "El porcentaje de menores de edad aprobados: " << menoresAprobados * 100 / float(20)<<" %"<<endl;
	cout << "El porcentaje de mayores de edad aprobados: " << mayoresAprobados * 100 / float(20)<<" %"<<endl;
}
void ContarxDistrito(int VPuntos[], int VEdad[], char VDistrito[]) {
	int deManantay = 0, deCalleria = 0;
	int deYarinococha = 0, deCampoVerde = 0;
	for (int i = 0; i < 20; i++) {
		switch (VDistrito[i]) {
		case 'm':
			deManantay += 1; break;
		case 'c':
			deCalleria += 1; break;
		case 'y':
			deYarinococha += 1; break;
		case 'v':
			deCampoVerde += 1; break;
		}
	}
	cout << "\n";
	cout << deManantay << " alumnos de Manantay dieron la prueba" << endl;
	cout << deCalleria << " alumnos de Calleria dieron la prueba" << endl;
	cout << deYarinococha << " alumnos de Yarinococha dieron la prueba" << endl;
	cout << deCampoVerde << " alumnos de Campo Verde dieron la prueba" << endl;
}

void OrdenadoDescendentexPuntaje(int VPuntos[], int VEdad[], char VDistrito[]) {
	int aux;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (VPuntos[i] > VPuntos[j]) {
				aux=VPuntos[i];
				VPuntos[i] = VPuntos[j];
				VPuntos[j] = aux;

				aux = VEdad[i];
				VEdad[i] = VEdad[j];
				VEdad[j] = aux;

				aux = VDistrito[i];
				VDistrito[i] = VDistrito[j];
				VDistrito[j] = aux;

			}
		}
	}
	cout << "\nDATOS ORDENADOS DESCENDENTEMENTE POR PUNTAJE\n" << endl;
	ImprimeDatos(VPuntos, VEdad, VDistrito);
}

int main() {
	srand(time(NULL));
	int VPuntos[20];
	int VEdad[20];
	char VDistrito[20];
	GenerarDatos(VPuntos, VEdad, VDistrito);
	ImprimeDatos(VPuntos, VEdad, VDistrito);
	PorcentajeAprobados(VPuntos, VEdad, VDistrito);
	ContarxDistrito(VPuntos, VEdad, VDistrito);
	OrdenadoDescendentexPuntaje(VPuntos, VEdad, VDistrito);
	system("pause>nul");
	return 0;
}