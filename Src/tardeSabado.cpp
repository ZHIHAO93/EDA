#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#include "Error.h"
#include "hora.h"
#include "pelicula.h"

using namespace std;

int main(){
	int num;
	vector<pelicula> pelis;
	pelicula aux;
	cin >> num;
	while (num != 0){

		for (int i = 0; i < num; i++)
		{
			try{
				cin >> aux;
				pelis.push_back(aux);
			}
			catch (Error e){}
		}

		sort(pelis.begin(), pelis.end());

		for (unsigned int i = 0; i < pelis.size(); i++)
		{
			cout << pelis[i] << endl;
		}
		cout << "---" << endl;
		pelis.clear();

		cin >> num;
	}
	return 0;
}