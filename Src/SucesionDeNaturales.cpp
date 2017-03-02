#include<iostream>
using namespace std;

int Fibonacci(int n, int x, int y);
int acuFibonacci(int n, int x, int y);

int acuFibonacci(int n, int x, int y){
	int sol;
	if (n == 0)
		sol = x;
	else if (n == 1)
		sol = y;
	else{ // n >= 2
		sol = acuFibonacci(n - 1, y, x + y) % 1000000007;
	}
	return sol;
}

int Fibonacci(int n, int x, int y){
	return acuFibonacci(n, x, y);
}

int main(){
	int n;
	cin >> n;
	while (n != -1){
		int x, y;

		cin >> x >> y;

		cout << Fibonacci(n, x, y) << endl;
		cin >> n;
	}
	return 0;
}