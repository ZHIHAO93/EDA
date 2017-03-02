#include <vector>
#include "time.h"
using namespace std;

void resolverCaso(int numTren, int numCaso);
void buscaBin(vector<THours> horarios, THours& consulta, int c, int f, int &p);

void buscaBin(vector<THours> horarios, THours& consulta, int c, int f, int &p){
	int m;
	
	if (c == f)
		p = c;
	else{
		m = (c + f) / 2;
		if (horarios[m] < consulta)
			buscaBin(horarios, consulta, m + 1, f, p);
		else if (consulta < horarios[m])
			buscaBin(horarios, consulta, c, m, p);
		else
			p = m;
	}
}

void resolverCaso(int numTren, int numCaso){
	vector<THours> horarios;
	THours consulta;
	for (int i = 0; i < numTren; i++)
	{
		cin >> consulta;
		horarios.push_back(consulta);
	}
	for (int j = 0; j < numCaso; j++)
	{
		try{
			int p;
			cin >> consulta;
			buscaBin(horarios, consulta, 0, horarios.size(), p);
			if (p == horarios.size())
				cout << "NO" << endl;
			else
				cout << horarios[p];
		}
		catch (Error e){
			cout << e.getMessage() << endl;
		}
	}
	cout << "---" << endl;
}

int main(){
	int numTren, numHora;
	
	cin >> numTren >> numHora;

	while (numTren != 0 && numHora != 0){
		resolverCaso(numTren, numHora);
		cin >> numTren >> numHora;
	}
	
	return 0;
}