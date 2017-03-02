#include<iostream>
using namespace std;

bool resuelveCaso(int *vector, int longitud, int &pos);

bool resuelveCaso(int *vector, int longitud, int &pos){
	int i = 0;
	bool baja = false, sube = false;
	while (i < longitud - 1 && vector[i] < vector[i + 1] && vector[i] != vector[i + 1])
	{
		sube = true;
		i++;
	}

	pos = i;
	while (i < longitud - 1 && vector[i] > vector[i + 1]){
		baja = true;
		i++;
	}

	if (sube && baja && i == longitud - 1)
		return true;
	else
		return false;
}

int main(){
	int numCasos, *vector, longitud, pos;
	bool existe;

	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		existe = false;
		pos = -1;
		cin >> longitud;
		// entrada de datos
		vector = new int[longitud];
		for (int i = 0; i < longitud; i++)
		{
			cin >> vector[i];
		}

		existe = resuelveCaso(vector, longitud, pos);

		// salida de solucion
		if (existe)
			cout << "Si " << pos << endl;
		else
			cout << "No" << endl;
		delete[] vector;
	}
	return 0;
}