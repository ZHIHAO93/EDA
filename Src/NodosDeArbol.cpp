#include <iostream>
#include "Arbin.h"
using namespace std;

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		Arbin<int> *arbol = new Arbin<int>();
		arbol->func();

		
		if (arbol->esVacio())
			throw EArbolVacio();
		else
			cout << arbol->Min() << endl;

		delete arbol;
	}
	return 0;
}