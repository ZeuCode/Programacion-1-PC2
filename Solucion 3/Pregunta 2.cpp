#include<iostream>
using namespace std;

void SimularProcesosTiempos(char procesos[], int tiempos[]) {
	char aplicaciones[6] = { 'C','E','M','P','S','W' };
	for (int i = 0; i < 100; i++) {
		procesos[i] = aplicaciones[rand() % 6];
		tiempos[i] = rand() % 10 + 1;
	}
	cout << "\tProcesos\tTiempos" << endl;
	for (int i = 0; i < 100; i++) {
		cout.width(15);
		switch (procesos[i]) {
		case 'C':cout << "Calculadora"; break;
		case 'E':cout << "Excel"; break;
		case 'M':cout << "Media Player"; break;
		case 'P':cout << "Paint"; break;
		case 'S':cout << "Starcraft"; break;
		case 'W':cout << "Word"; break;
		}
		cout << "\t\t   ";
		cout << tiempos[i] << endl;
	}
}

int calcularTiempoTotalPorProceso(char procesos[], int tiempos[], char proceso) {
	int tiempoProceso = 0;
	for (int i = 0; i < 100; i++) {
		if (proceso == procesos[i])tiempoProceso += tiempos[i];
	}
	return tiempoProceso;
}
char ObtenerProcesoMayorOcurrencia(char procesos[]) {
	int ocurrencias[6];
	for (int i = 0; i < 6; i++) {
		ocurrencias[i] = 0;
	}//iniciales de cada proceso
	for (int i = 0; i < 100; i++) {
		switch (procesos[i]) {
		case 'C':ocurrencias[0]++; break;
		case 'E':ocurrencias[1]++; break;
		case 'M':ocurrencias[2]++; break;
		case 'P':ocurrencias[3]++; break;
		case 'S':ocurrencias[4]++; break;
		case 'W':ocurrencias[5]++; break;
		}
	}
	int mayorOcurrencia = ocurrencias[0];
	char aplicaciones[6] = { 'C','E','M','P','S','W' };
	for (int i = 1; i < 6; i++) {
		if (ocurrencias[i] > mayorOcurrencia)mayorOcurrencia = ocurrencias[i];
	}
	int pos = 0;
	for (int i = 0; i < 6; i++) {
		if (ocurrencias[i] == mayorOcurrencia)pos = i; break;
	}
	return aplicaciones[pos];
}
void ListarTiempoTotalParaCadaProceso(char procesos[], int tiempos[]) {
	int tiempoC = 0, tiempoE = 0;
	int tiempoM = 0, tiempoP = 0;
	int tiempoS = 0, tiempoW = 0;
	for (int i = 0; i < 100; i++) {
		switch (procesos[i]) {
		case 'C':tiempoC += tiempos[i]; break;
		case 'E':tiempoE += tiempos[i]; break;
		case 'M':tiempoM += tiempos[i]; break;
		case 'P':tiempoP += tiempos[i]; break;
		case 'S':tiempoS += tiempos[i]; break;
		case 'W':tiempoW += tiempos[i]; break;
		}
	}
	cout << "Calculadora se ejecuto en " << tiempoC << " milisegundos" << endl;
	cout << "Excel se ejecuto en " << tiempoE << " milisegundos" << endl;
	cout << "Media Player se ejecuto en " << tiempoM << " milisegundos" << endl;
	cout << "Paint se ejecuto en " << tiempoP << " milisegundos" << endl;
	cout << "Starcraft se ejecuto en " << tiempoS << " milisegundos" << endl;
	cout << "Word se ejecuto en " << tiempoW << " milisegundos" << endl;
}

void ProcesosPesados(char procesos[], int tiempos[]) {
	int tiempoC = 0, tiempoE = 0;
	int tiempoM = 0, tiempoP = 0;
	int tiempoS = 0, tiempoW = 0;
	for (int i = 0; i < 100; i++) {
		switch (procesos[i]) {
		case 'C':tiempoC += tiempos[i]; break;
		case 'E':tiempoE += tiempos[i]; break;
		case 'M':tiempoM += tiempos[i]; break;
		case 'P':tiempoP += tiempos[i]; break;
		case 'S':tiempoS += tiempos[i]; break;
		case 'W':tiempoW += tiempos[i]; break;
		}
	}
	cout << "Procesos que ocurrieron durante mas de 300 ms: " << endl;
	if (tiempoC > 300)cout << "Calculadora se ejecuto en " << tiempoC << " milisegundos" << endl;
	if (tiempoE > 300)cout << "Excel se ejecuto en " << tiempoE << " milisegundos" << endl;
	if (tiempoM > 300)cout << "Media Player se ejecuto en " << tiempoM << " milisegundos" << endl;
	if (tiempoP > 300)cout << "Paint se ejecuto en " << tiempoP << " milisegundos" << endl;
	if (tiempoS > 300)cout << "Starcraft se ejecuto en " << tiempoS << " milisegundos" << endl;
	if (tiempoW > 300)cout << "Word se ejecuto en " << tiempoW << " milisegundos" << endl;
}
int main() {
	srand(time(NULL));
	char procesos[100];
	int tiempos[100];
	bool salir = false;
	int opcion;
	while (!salir) {
		cout << "Menu de Opciones" << endl;
		cout << "1. Simular Procesos Tiempos" << endl;
		cout << "2. Calcular Tiempo Total Por Proceso" << endl;
		cout << "3. Obtener Proceso Mayor Ocurrencia" << endl;
		cout << "4. Listar Tiempo Total Para Cada Proceso" << endl;
		cout << "5. Procesos Pesados" << endl;
		cout << "6. Salir" << endl;
		do {
			cout << "Ingrese opcion: "; cin >> opcion;
		} while (opcion < 1 || opcion>6);
		switch (opcion) {
		case 1:
			SimularProcesosTiempos(procesos, tiempos);
			break;
		case 2:
		{
			char proceso;
			do {
				cout << "Ingrese proceso(c,e,m,p,s,w):"; cin >> proceso;
				proceso = toupper(proceso);
			} while (proceso != 'C' && proceso != 'E' && proceso != 'M' && proceso != 'P' && proceso != 'S' && proceso != 'W');
			cout << "\nEl proceso se ejecuto en :" << calcularTiempoTotalPorProceso(procesos, tiempos, proceso)<<" milisegundos" << endl;
			break;
		}
		case 3:
			cout << "El proceso con mayor ocurrencia es ";
			switch (ObtenerProcesoMayorOcurrencia(procesos)) {
			case 'C':cout << "Calculadora"; break;
			case 'E':cout << "Excel"; break;
			case 'M':cout << "Media Player"; break;
			case 'P':cout << "Paint"; break;
			case 'S':cout << "Starcraft"; break;
			case 'W':cout << "Word"; break;
			}
			cout << endl;
			break;
		case 4:
			ListarTiempoTotalParaCadaProceso(procesos, tiempos);
			break;
		case 5:
			ProcesosPesados(procesos, tiempos);
			break;

		case 6:
			salir = true;
			break;
		}
		cout << "\n";
	}


	system("pause>nul");
	return 0;
}