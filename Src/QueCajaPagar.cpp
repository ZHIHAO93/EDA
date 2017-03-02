#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
	int nCliente, nVecino, n;
	cin >> nCliente >> nVecino;
	while (nCliente != 0 && nVecino != 0){
		int cajas[3] = {0, 0, 0};
		queue<int> *cola = new queue<int>();
		queue<int> *colaVecino = new queue<int>();
		for (int i = 0; i < nCliente; i++)
		{
			cin >> n;
			cola->push(n);
		}

		for (int i = 0; i < nVecino; i++)
		{
			cin >> n;
			colaVecino->push(n);
		}
		int cont = 1;
		while (!colaVecino->empty()){
			if (cajas[0] == 0 && !cola->empty() && !colaVecino->empty()){
				cajas[0] = cola->front();
				cola->pop();
				if (cont == colaVecino->front()){
					colaVecino->pop();
					if (colaVecino->size() >= 1)
						cout << "1 ";
					else
						cout << "1" << endl;
				}
				cont++;
			}
			if (cajas[1] == 0 && !cola->empty() && !colaVecino->empty()){
				cajas[1] = cola->front();
				cola->pop();
				if (cont == colaVecino->front()){
					colaVecino->pop();
					if (colaVecino->size() >= 1)
						cout << "2 ";
					else
						cout << "2" << endl;
				}
				cont++;
			}
			if (cajas[2] == 0 && !cola->empty() && !colaVecino->empty()){
				cajas[2] = cola->front();
				cola->pop();
				if (cont == colaVecino->front()){
					colaVecino->pop();
					if (colaVecino->size() >= 1)
						cout << "3 ";
					else
						cout << "3" << endl;
				}
				cont++;
			}
			cajas[0]--;
			cajas[1]--;
			cajas[2]--;
		}

		delete colaVecino;
		delete cola;
		cin >> nCliente >> nVecino;
	}
	return 0;
}