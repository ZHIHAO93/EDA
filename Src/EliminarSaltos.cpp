#include <iostream>
#include "List.h"
using namespace std;

int main(){
	int n, salto;
	cin >> salto;
	while (salto != 0){
		List<int> *list = new List<int>();
		cin >> n;
		while (n != 0){
			list->push_front(n);
			cin >> n;
		}

		if (list->empty())
			cout << endl;
		else{
			List<int>::Iterator it1 = list->begin();
			List<int>::Iterator it2 = list->begin();
			it2.next();
			unsigned int i = 0;
			while (i < list->size() - 1){
				if (it1.elem() - it2.elem() <= salto){
					it1.next();
					it2.next();
				}
				else{
					//borrar
					it2 = list->erase(it2);
					i--;
				}
				i++;
			}
			cout << *list << endl;
		}

		cin >> salto;
		delete list;
	}
	return 0;
}