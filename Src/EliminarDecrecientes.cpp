#include <iostream>
#include "SinglyLinkedList.h"
#include "time.h"
using namespace std;

int main(){
	int n;
	THours hora;
	cin >> n;
	while (cin){
		SinglyLinkedList<THours> *list = new SinglyLinkedList<THours>();
		for (int i = 0; i < n; i++)
		{
			cin >> hora;
			list->push_front(hora);
		}

		list->deleteDec();

		cout << *list << endl;

		delete list;
		cin >> n;
	}
	return 0;
}