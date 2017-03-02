#include <iostream>
#include <vector>
#include <algorithm>

#include "hora.h"
#include "Error.h"

using namespace std;

int main(){
	int num, duracion;
	vector<THours> horas;
	THours aux;
	cin >> num;
	while (num != 0)
	{
		for (int i = 0; i < num; i++)
		{
			cin >> aux;
			horas.push_back(aux);
		}

		sort(horas.begin(), horas.end());

		aux = horas[0];
		duracion = horas[1].numSegundos() - horas[0].numSegundos();

		int seg;
		for (unsigned int i = 1; i < horas.size()-1; i++)
		{
			seg = horas[i + 1].numSegundos() - horas[i].numSegundos();
			if (seg > duracion){
				duracion = seg;
				aux = horas[i];
			}
		}

		THours dura(duracion);
		cout << aux << " " << dura << endl;

		horas.clear();
		cin >> num;
	}
	return 0;
}