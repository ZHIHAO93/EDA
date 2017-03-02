#include <iostream>
#include <iomanip>
#include "Error.h"
using namespace std;

class THours{
private:
	int hours;
	int minute;
	int second;

public:
	THours(){};
	THours(int h, int m, int s);
	bool operator<(const THours& hora);
	THours& operator==(const THours& hora);
	friend istream& operator>>(istream &sIn, THours &h);
	friend ostream& operator<<(ostream &sOut, const THours &h);
};

// public

THours::THours(int h, int m, int s){
	hours = h;
	minute = m;
	second = s;
}

bool THours::operator<(const THours& hora){
	if (hours > hora.hours)
		return false;
	else if (hours < hora.hours)
		return true;
	else{
		if (minute > hora.minute)
			return false;
		else if (minute < hora.minute)
			return true;
		else{
			if (second >= hora.second)
				return false;
			else
				return true;
		}
	}
}

THours&THours::operator==(const THours& hora){
	hours = hora.hours;
	minute = hora.minute;
	second = hora.second;
	return *this;
}

istream& operator>>(istream &sIn, THours &h){
	sIn >> h.hours;
	sIn.ignore();
	sIn >> h.minute;
	sIn.ignore();
	sIn >> h.second;
	if (h.hours < 0 || h.hours > 23 || h.minute < 0 || h.minute > 60 || h.second < 0 || h.second> 60) {
		throw Error("ERROR");
	}
	return sIn;
}

ostream& operator<<(ostream& sOut, const THours& h){
	cout << setfill('0');
	sOut << setw(2) << h.hours << ":" << setw(2) << h.minute << ":" << setw(2) << h.second << endl;
	return sOut;
}