#include <iostream>
#include <string>
#include "List.h"
#include "persona.h"
using namespace std;

int main(){
	int n, min, max;
	cin >> n;
	while (n != 0){
		cin >> min >> max;
		List<persona> *lista = new List<persona>();
		persona aux;
		for (int i = 0; i < n; i++)
		{
			cin >> aux;
			lista->push_back(aux);
		}
		List<persona>::Iterator it = lista->begin();

		for (unsigned int i = 0; i < lista->size(); i++)
		{
			aux = it.elem();
			if (aux.edades() < min || aux.edades() > max){
				it = lista->erase(it);
				i--;
			}
			else
				it.next();
		}
		if (!lista->empty())
			cout << *lista;
		cout << "---" << endl;

		delete lista;
		cin >> n;
	}
	return 0;
}