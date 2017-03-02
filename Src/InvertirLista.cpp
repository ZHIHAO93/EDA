#include <iostream>
#include <string>
#include "LinkedListStack.h"
using namespace std;

int main(){
	int n, k;
	string s;
	cin >> n;
	while (cin){
		LinkedListStack<int> *lista = new LinkedListStack<int>();
		for (int i = 0; i < n; i++)
		{
			cin >> k;
			lista->push(k);
		}
		if (n == 0){
			getline(cin, s);
			cout << endl << endl;
		}
		else{
			cout << *lista;
			lista->invertir();
			cout << *lista;
		}
		delete lista;
		cin >> n;
	}
	return 0;
}