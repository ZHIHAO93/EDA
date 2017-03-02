#include <iostream>
#include "nComplejos.h"
using namespace std;

int main(){
	int numCaso;
	cin >> numCaso;
	for (int i = 0; i < numCaso; i++)
	{
		complejos complejos, suma;
		int n, z = 0;
		bool enc = false;
		cin >> complejos >> n;
		for (int j = 0; j < n && !enc; j++)
		{
			if (suma.mod() > 2)
				enc = true;
			suma = suma * suma + complejos;
		}
		if (enc)
			cout << "NO" << endl;
		else
			cout << "SI" << endl;

	}
	return 0;
}