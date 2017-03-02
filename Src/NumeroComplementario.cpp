#include <iostream>
using namespace std;

int numeroComplementario(int num);
void numeroComplementario(int num, int &complementario, int p);

int numeroComplementario(int num){ 
	int complementario = 0, p = 1;
	numeroComplementario(num, complementario, p);
	return complementario;
}

void numeroComplementario(int num, int &complementario, int p){
	if (num < 10)
		complementario = complementario + (9 - num) * p;
	else{
		complementario = complementario + (9 - num % 10) * p;
		numeroComplementario(num / 10,complementario, p * 10);
	}
}

int main(){
	int num;

	cin >> num;
	while (num != -1){
		int sol;

		sol = numeroComplementario(num);

		// salida de solucion
		cout << sol << endl;
		cin >> num;
	}

	return 0;
}