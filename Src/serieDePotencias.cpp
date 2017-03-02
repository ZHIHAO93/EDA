#include <iostream>
using namespace std;

int main(){
	int x, n;

	cin >> x >> n;

	while (cin){
		int suma = 1, p = 1, i = 0;

		while (i < n){
			p = (p * x) % 1000007;
			suma = (suma + p) % 1000007;
			i = i + 1;
		}
		cout << suma << endl;
		cin >> x >> n;
	}
	return 0;
}