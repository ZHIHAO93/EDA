#include <iostream>
using namespace std;

int main(){
	int numCasos, longitud, *vector, suma, p;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		suma = 0;
		p = 1;
		cin >> longitud;
		vector = new int[longitud];
		// entrada de datos
		for (int i = 0; i < longitud; i++)
		{
			cin >> vector[i];
		}

		for (int i = 0; i < longitud; i++)
		{
			if (vector[i] == p)
				suma = suma + vector[i];
			p = p * 2;
		}

		// salida de solucion
		cout << suma << endl;
		delete[] vector;
	}
	return 0;
}