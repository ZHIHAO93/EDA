#include <iostream>
using namespace std;

void resolverCaso();
int concava(int v[], int n);
int numCentro(int v[], int i, int j, int k);

int numCentro(int v[], int i, int j, int k){
	if (i == j)
		k = v[i];
	else if (v[i] >= v[i + 1] && v[j - 1] <= v[j])
		k = numCentro(v, i + 1, j - 1, k);
	else if (v[i] >= v[i + 1])
		k = numCentro(v, i + 1, j, k);
	else
		k = numCentro(v, i, j - 1, k);
	return k;
}

int concava(int v[], int n){
	return numCentro(v, 0, n - 1, 0);
}

void resolverCaso(){
	int *v, n;

	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << concava(v, n) << endl;

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