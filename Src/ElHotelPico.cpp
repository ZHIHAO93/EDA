#include <iostream>
using namespace std;

void resolverCaso();
int ingresos(int v[], int n);
int acuIngreso(int v[], int n,int i, int j,int p, int sol);

int acuIngreso(int v[], int n,int i, int j,int p, int sol){
	if (n == 0)
		return sol;
	else{
		return acuIngreso(v, n - 1, i + 1, j - 1, p * 2, sol + (v[i] + v[j]) * p);
	}
}

int ingresos(int v[], int n){
	int sol = 0;
	return acuIngreso(v, n / 2, 0, n - 1, 1, sol);
}

void resolverCaso(){
	int *v, n;
	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << ingresos(v, n) << endl;
	delete[] v;
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