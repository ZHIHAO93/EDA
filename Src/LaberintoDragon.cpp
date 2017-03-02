#include <iostream>
#include <string>
#include "Arbin.h"
using namespace std;

Arbin<string>* construirArbol(Arbin<string>* ra, string &puerta, int &p, int acu){
	string nodo;
	cin >> nodo;
	if (nodo == "...")
		return new Arbin<string>("");
	else{
		if (nodo == "Dragon")
			acu++;
		Arbin<string> *iz = NULL;
		iz = construirArbol(iz, puerta, p, acu);

		Arbin<string> *dr = NULL;
		dr = construirArbol(dr, puerta, p, acu);

		if (iz->raiz() == "" && dr->raiz() == "" && acu < p && nodo != "Dragon" && nodo != "Via_libre" && nodo != "Tesoro"){
			puerta = nodo;
			p = acu;
		}

		return new Arbin<string>(*iz, nodo, *dr);
	}
}

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int p = 1000, acu = 0;
		string puerta;

		Arbin<string> *arbol = new Arbin<string>();

		arbol = construirArbol(arbol, puerta, p, acu);
		
		if (p != 1000)
			cout << puerta << " " << p << endl;

		delete arbol;

	}
	return 0;
}