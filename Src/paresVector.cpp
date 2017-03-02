#include <iostream>
using namespace std;

void resolverCaso();

void resolverCaso(){
	int num, longitud, par = 0;
	// entrada de datos
	cin >> longitud;
	for (int i = 0; i < longitud; i++)
	{
		cin >> num;
		if (num % 2 == 0)
			par = par + 1;
	}
	// salida de datos
	cout << par << endl;
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