#include <iostream>
using namespace std;

void resolverCaso();
int colados(int longitud);
int numColadao(int inicio, int fin);

int numColadao(int inicio, int fin, int vector[]){
	int colados = 0;
	for (int i = inicio; i < fin; i++)
	{
		if (vector[fin] < vector[i])
			colados++;
	}
	return colados;
}

int colados(int longitud){
	int vector[100000];
	int colados = 0, ini = 0, mayor = 0;
	for (int i = 0; i < longitud; i++)
	{
		cin >> vector[i];
	}
	for (int i = 0; i < longitud; i++)
	{
		if (vector[i] < mayor){
			colados = colados + numColadao(ini, i, vector);
			ini = i;
		}
		mayor = vector[i];
	}
	return colados;
}

void resolverCaso(){
	int longitud;
	// entrada de datos
	cin >> longitud;
	// salida de datos
	cout << colados(longitud) << endl;
}

int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		resolverCaso();
	}
	return 0;
}