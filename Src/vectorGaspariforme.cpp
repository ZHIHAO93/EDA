#include <iostream>
using namespace std;

void resolverCaso();

void resolverCaso(){
	int longitud, num, sumaTotal = 0, sumaParcial = 0;
	bool gaspariforme, parcialPositivo = true;

	// entrada de datos
	cin >> longitud;
	if (longitud > 0){
		for (int i = 0; i < longitud - 1; i++)
		{
			cin >> num;
			sumaParcial = sumaParcial + num;
		}
		cin >> num;
		sumaTotal = sumaParcial + num;
		if (sumaTotal == 0)
			gaspariforme = true;
		else
			gaspariforme = false;
	}

	// salida de datos
	if (gaspariforme)
		cout << "1" << endl;
	else
		cout << "0" << endl;
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