#include <iostream>
using namespace std;

void resolverCaso();
bool parImpar(int v[], int n, int &p);

bool parImpar(int v[], int n, int &p){
	bool existe = true, trozoImp = false;
	for (int i = 0; i < n && existe; i++)
	{
		if (v[i] % 2 != 0 && !trozoImp){
			p = i;
			trozoImp = true;
		}
		else if (v[i] % 2 == 0 && trozoImp)
			existe = false;
	}
	return existe;
}

void resolverCaso(){
	int n, p = -1, *v;
	bool existe = true;
	
	cin >> n;
	
	v = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	existe = parImpar(v, n, p);
	if (existe){
		if (p == -1)
			p = n;
		cout << "Si " << p << endl;
	}
	else
		cout << "No" << endl;
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