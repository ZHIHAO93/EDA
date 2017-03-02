#include <iostream>
#include <stdexcept>
#include <time.h>
#include "Libros.h"
using namespace std;

bool resuelveCaso(){
	int n, cantidad;
	string libro, accion;
	Libros libreria;

	cin >> n;
	if (!cin){
		return false;
	}
	else{
		for (int i = 0; i < n; i++)
		{
			cin >> accion;
			if (accion == "nuevoLibro"){
				cin >> cantidad;
				cin.ignore();
				getline(cin, libro);
				libreria.nuevoLibro(libro, cantidad);
			}
			else if (accion == "comprar"){
				cin.ignore();
				getline(cin, libro);
				try{
					libreria.comprar(libro);
				}
				catch (out_of_range e){
					cout << e.what() << endl << "---" << endl;
				}
				catch (invalid_argument e){
					cout << e.what() << endl << "---" << endl;
				}
			}
			else if (accion == "estaLibro"){
				cin.ignore();
				getline(cin, libro);
				if (libreria.estaLibro(libro))
					cout << "El libro " << libro << " esta en el sistema" << endl;
				else
					cout << "No existe el libro " << libro << " en el sistema" << endl;
				cout << "---" << endl;
			}
			else if (accion == "elimLibro"){
				cin.ignore();
				getline(cin, libro);
				libreria.elimLibro(libro);
			}
			else if (accion == "numEjemplares"){
				cin.ignore();
				getline(cin, libro);
				try{
					cout << "Existen " << libreria.numEjemplares(libro) << " ejemplares del libro " << libro << endl;
				}
				catch (invalid_argument e){
					cout << "No existe el libro " << libro << " en el sistema" << endl;
				}
				cout << "---" << endl;
			}
			else if (accion == "top10"){
				List<string> top = libreria.top10();
				int i = 0;
				while (i < 10 && !top.empty()){
					cout << top.front() << endl;
					top.pop_front();
					i++;
				}
				cout << "---" << endl;
			}
		}
		cout << "------" << endl;
	}
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}