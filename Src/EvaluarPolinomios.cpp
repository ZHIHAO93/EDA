#include <iostream>
using namespace std;

template <class T>
class Polinomio {
private:
	T _polinomio[12];
	int grado;
public:
	Polinomio(){};

	void leer() {
		cin >> grado;
		for (int i = 0; i <= grado; i++) {
			cin >> _polinomio[i];
		}
	}

	T resultado(const int & valor) {
		T sol = 0;
		long long int exp = 1;
		for (int i = grado; i >= 0; i--) {
			sol = sol + _polinomio[i] * exp;
			exp *= valor;
		}
		return sol;
	}
};

bool resuelveCaso() {
	Polinomio<long long int> poli;
	int valor;
	if (!cin) {
		// fin de la entrada
		return false;
	}
	poli.leer();
	do {
		cin >> valor;
		if (valor != 0) {
			cout << (poli.resultado(valor)) << endl;
		}
	} while (valor != 0);
	return true;
}


int main() {
	while (resuelveCaso());
	return 0;
}
