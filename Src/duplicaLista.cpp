#include <iostream>
#include "LinkedListStack.h"
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n != 0){
		LinkedListStack<int> *lista = new LinkedListStack<int>();
		while (n != 0){
			lista->push(n);
			cin >> n;
		}

		lista->duplica();

		cout << *lista << endl;

		delete lista;
		cin >> n;
	}
	return 0;
}