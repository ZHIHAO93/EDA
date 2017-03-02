#include <iostream>
using namespace std;

int numCombinacion(int a, int b);

int sumCombinacion(int a, int b, int n, int acu);

int sumCombinacion(int a, int b, int n, int acu){
	int sol;
	if (n == 0)
		sol = acu;
	else
		sol = sumCombinacion(a - 1, b + 1, n - 1, (acu * a / b) % 1000007);
	return sol;
}

int numCombinacion(int a, int b){
	return sumCombinacion(a, 1, b, 1);
}

int main(){
	int numCasos;
	
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++)
	{
		int sol = 0, a, b;
		// entrada de datos
		cin >> a >> b;

		sol = numCombinacion(a, b);

		// salida de solucion
		cout << sol << endl;
	}
	return 0;
}