#include <iostream>
using namespace std;

int dias(int cantidad, int suma);

int main(){
	int numCasos, cantidad, dia, suma;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		dia = 0, suma = 0;
		// entrada de datos
		cin >> cantidad;
		
		while (suma < cantidad){
			dia = dia + 1;
			if (dia % 2 == 0)
				suma = 2 * suma;
			else
				suma = 2 * suma + 1;
		}

		// salida de solucion

		cout << dia << endl;
	}
	return 0;
}