#include<iostream>
#include"List.h"
using namespace std;

int main(){
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		List<int> *list = new List<int>();
		cin >> k;
		while (k != -1){
			list->push_back(k);
			cin >> k;
		}

		if (list->empty())
			cout << endl;
		else{
			List<int>::Iterator it = list->begin();
			List<int>::Iterator it2 = list->begin();
			it2.next();

			for (unsigned int i = 0; i < list->size() - 1; i++)
			{
				if (it2.elem() < it.elem()){
					it2 = list->erase(it2);
					i--;
				}
				else{
					it.next();
					it2.next();
				}
			}
			cout << *list << endl;
		}
		delete list;
	}
	return 0;
}