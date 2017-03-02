#include <iostream>
#include "List.h"
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n != 0){
		List<int> *list = new List<int>();
		while (n != 0)
		{
			list->push_front(n);
			cin >> n;
		}

		List<int>::Iterator it = list->begin();
		for (unsigned int i = 0; i < list->size(); i++)
		{
			list->insert(it.elem(), it);
			it.next();
			i++;
		}

		cout << *list << endl;

		delete list;
		cin >> n;
	}
	return 0;
}