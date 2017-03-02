#include <iostream>
#include "Queue.h"
using namespace std;

int main(){
	int n, k, p;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
	Queue<int> *cola = new Queue<int>();
	Queue<int> *q = new Queue<int>();

	cin >> k;
	while (k != -1)
	{
		cola->push_back(k);
		cin >> k;
	}
	cin >> p;

	cin >> k;
	while (k != -1){
		q->push_back(k);
		cin >> k;
	}

	cout << *cola;
	cola->insert(p,q);
	cout << *cola;

	delete cola;
	delete q;
	}
	return 0;
}