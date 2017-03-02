#include <iostream>
#include <stack>
#include <list>
using namespace std;

int main(){
	char c;
	int n;
	bool p = false;
	cin >> c;
	while (cin){
		list<int> *lista = new list<int>();
		stack<int> *pila1 = new stack<int>();
		stack<int> *pila2 = new stack<int>();

		while (c != 'F'){
			n = c - '0';
			pila1->push(n);
			cin >> c;
		}

		cin >> c;
		while (c != 'F'){
			n = c - '0';
			pila2->push(n);
			cin >> c;
		}

		while (!pila1->empty() || !pila2->empty() || p){
			if (p){
				n = 1;
				p = false;
			}
			else
				n = 0;
			if (!pila1->empty()){
				n += pila1->top();
				pila1->pop();
			}
			if (!pila2->empty()){
				n += pila2->top();
				pila2->pop();
			}
			if (n >= 10){
				n = n % 10;
				p = true;
			}
			lista->push_back(n);
		}

		while (!lista->empty()){
			cout << lista->back();
			lista->pop_back();
		}
		cout << endl;
		
		delete pila1;
		delete pila2;
		delete lista;
		cin >> c;
	}
	return 0;
}