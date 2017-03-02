#include <iostream>
#include <string>
using namespace std;

int main(){
	string palabra = "";
	int longitud, p, cont, size;
	while (palabra != "XXX"){
		p = 0;
		longitud = 1;
		cont = 1;
		// entrada de datos
		cin >> palabra;
		size = palabra.length();
		for (int i = 0; i < size; i++)
		{
			if (palabra[i] <= palabra[i + 1]){
				cont++;
			}
			else {
				if (cont >= longitud){
					longitud = cont;
					p = i - cont + 1;
				}
				cont = 1;
			}
		//salida de solucion
		}
		if (palabra != "XXX"){
			cout << palabra.length() << " " << longitud << " ";
			for(int i = 0; i < longitud; i++)
			{
				cout << palabra[i + p];
			}
			cout << endl;
		}
	}
	return 0;
}