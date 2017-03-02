#include <iostream>
using namespace std;

void resolverCaso();
void vueltaAtras(int* sol, int* S, int* B, int n, int k, bool* marca, bool& existe);
bool esValida(int* sol, int k);

bool esValida(int* sol, int k){
	int i = 0;
	while (i < k && sol[i] / sol[k] < 2 && sol[k] / sol[i] < 2)
		i++;
	return i == k;
}

void vueltaAtras(int* sol, int* S, int* B, int n, int k, bool* marca, bool& existe){
	for (int i = 0; i < n; i++)
	{
		if (!marca[i]) {
			sol[k] = B[i*n+k];
			if (esValida(sol,k)){
				if (k == n - 1){
					existe = true;
					int salida = 0;
					for (int j = 0; j < n; j++)
					{
						salida += sol[j];
					}
					cout << salida << endl;
				}
				else {
					marca[i] = true;
					vueltaAtras(sol, S, B, n, k + 1, marca, existe);
					marca[i] = false;
				}
			}
			else if (k == n - 1){
				existe = false;
			}
		}
	}
}

void resolverCaso(){
	int n;
	cin >> n;
	int* S = new int[n*n];
	int* B = new int[n*n];
	int* sol = new int[n];
	bool* marca = new bool[n*n];
	for (int i = 0; i < n*n; i++)
	{
		cin >> S[i];
	}
	for (int j = 0; j < n*n; j++)
	{
		cin >> B[j];
	}
	for (int b = 0; b < n; b++)
	{
		marca[b] = false;
	}
	bool existe = false;
	vueltaAtras(sol, S, B, n, 0, marca, existe);
	if (!existe)
		cout << "Sin solucion factible" << endl;


	delete[] S;
	delete[] B;
	delete[] sol;
	delete[] marca;
}

int main(){
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++)
	{
		resolverCaso();
	}
	return 0;
}