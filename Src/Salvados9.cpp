#include <iostream>
using namespace std;

int main(){
	int numCasos, longitud;
	double num;
	bool media, nueve;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++)
	{
		media = true;
		nueve = false;
		cin >> longitud;
		// entrada de datos
		for (int i = 0; i < longitud; i++)
		{
			cin >> num;
			if (num == 0)
				media = false;
			else if (num >= 9)
				nueve = true;
		}
		if (nueve)
			media = true;
		// salida de solucion
		if (media)
			cout << "MEDIA" << endl;
		else
			cout << "SUSPENSO" << endl;
	}
	return 0;
}