
#include <iostream>
using namespace std;

int Factorial(int n) {
	int factorial = 1;
	for (int i = 1; i <= n; i++) {
		factorial *= i;
	}
	return factorial;
}
double CalculaSerie(int n, int b) {
	double sumatoria = 0;
	int factor = 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			sumatoria += Factorial(factor) * b / float(3);
		else
			sumatoria -= Factorial(factor) * b / float(2);
		factor += 3;
	}
	return sumatoria;
}
int main2()
{
	int n,b;
	do {
		cout << "Ingrese el valor de n: "; cin >> n;
	} while (n < 1 || n>19);
	do {
		cout << "Ingrese el valor de b: "; cin >> b;
	} while (b < 1 || b>5);
	cout << "El valor de la sumatoria es: ";
	cout.precision(10); cout<<CalculaSerie(n, b);
	system("pause>nul");
	return 0;
}

