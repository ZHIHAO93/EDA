#include <iostream>
using namespace std;

int mayorVidente(int vector[], int longitud);

int mayorVidente(int vector[], int longitud){
	int pos = -1, suma = 0;
	bool encontrado = false;
	for (int i = longitud-1; i >= 0 && !encontrado; i--)
	{
		if (vector[i] == suma){
			encontrado = true;
			pos = i;
		}
		else{
			suma = suma + vector[i];
		}
	}
	return pos;
}

int main(){
	int numCasos, longitud, *vector;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		int pos = -1;
		cin >> longitud;
		// entrada datos
		vector = new int[longitud];
		for (int i = 0; i < longitud; i++)
		{
			cin >> vector[i];
		}
		pos = mayorVidente(vector, longitud);
		// salida solucion
		if (pos >= 0)
			cout << "Si " << pos << endl;
		else
			cout << "No" << endl;
		delete[] vector;
	}
	return 0;
}