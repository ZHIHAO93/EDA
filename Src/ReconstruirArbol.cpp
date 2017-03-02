#include <iostream>
#include "Arbin.h"
using namespace std;

int main(){
	int n1, n2;
	bool fin = false;
	while (!fin)
	{
		int cont = 0;
		Arbin<int> *arbol = new Arbin<int>();
		List<int> *listaPre = new List<int>();
		List<int> *listaIn = new List<int>();
		List<int> *lista = new List<int>();

		cin >> n1;
		while (n1 != -1){
			listaPre->push_back(n1);
			cin >> n1;
		}

		cin >> n2;

		while (n2 != -1){
			listaIn->push_back(n2);
			cin >> n2;
		}

		if (!listaIn->empty() && !listaPre->empty()){

			arbol->func(listaPre,listaIn);

			lista = arbol->niveles();

			List<int>::Iterator it = lista->begin();

			for (unsigned int i = 0; i < lista->size() - 1; i++)
			{
				cout << it.elem() << " ";
				it.next();
			}
			cout << it.elem() << endl;
		}
		else
			fin = true;

		delete lista;
		delete listaPre;
		delete listaIn;
		delete arbol;
	}
	return 0;
}