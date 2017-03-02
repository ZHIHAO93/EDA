#include <iostream>
using namespace std;

void resolverCaso();
long long int inversion(int v[], int n);
long long int numInversion(int v[], int i, int j);
long long int suman(int v[], int a, int b, long long int sol);

long long int suman(int v[], int a, int b, long long int sol){
	int m = (a + b) / 2;
	for (int p = a; p < m + 1; p++){
		for (int q = m + 1; q <= b; q++){
			if (v[p] > v[q])
				sol++;
		}
	}
	return sol;
}

long long int numInversion(int v[], int i, int j){
	long long int sol = 0;
	if (i + 1 >= j){
		if (v[i] > v[j])
			return 1;
		else
			return 0;
	}
	else{
		int m = (i + j) / 2;
		return numInversion(v, i, m) + numInversion(v, m + 1, j) + suman(v, i, j, sol);
	}
}

long long int inversion(int v[], int n){
	return numInversion(v, 0, n - 1);
}

void resolverCaso(){
	int *v, n;
	cin >> n;
	v = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	cout << inversion(v,n) << endl;
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