#ifndef HORA_H_
#define HORA_H_
#include <iostream>
#include <iomanip>

#include "Error.h"

using namespace std;

class THours{
public:
	THours(){};
	THours(int h, int m, int s){
		_hour = h;
		_minute = m;
		_second = s;
	}

	THours(int segundo){
		_hour = segundo / 3600;
		segundo = segundo % 3600;
		_minute = segundo / 60;
		_second = segundo % 60;
	}

	int numSegundos() const{
		return (_hour * 60 + _minute) * 60 + _second;
	}

	THours& operator=(const THours& hora){
		_hour = hora._hour;
		_minute = hora._minute;
		_second = hora._second;
		return *this;
	}

	THours& operator+(const THours& hora){
		_second += hora._second;
		if (_second >= 60){
			_second -= 60;
			_minute++;
		}
		_minute += hora._minute;
		if (_minute >= 60){
			_minute -= 60;
			_hour++;
		}
		_hour += hora._hour;
		if (_hour > 23) throw Error("Error");
		return *this;
	}

	bool operator<(const THours& hora) const{
		if (_hour > hora._hour)
			return false;
		else if (_hour < hora._hour)
			return true;
		else{
			if (_minute > hora._minute)
				return false;
			else if (_minute < hora._minute)
				return true;
			else{
				if (_second >= hora._second)
					return false;
				else
					return true;
			}
		}
	}

	bool operator==(const THours& hora)const{
		return _hour == hora._hour && _minute == hora._minute && _second == hora._second;
	}

	friend ostream& operator<<(ostream& sOut, const THours& hour){
		cout << setfill('0');
		sOut << setw(2) << hour._hour << ":" << setw(2) << hour._minute << ":" << setw(2) << hour._second;
		return sOut;
	}

	friend istream& operator>>(istream& sIn, THours& hour){
		sIn >> hour._hour;
		sIn.ignore();
		sIn >> hour._minute;
		sIn.ignore();
		sIn >> hour._second;
		if (hour._hour <0 || hour._hour>23 || hour._minute<0 || hour._minute>59 || hour._second<0 || hour._second>59)
			throw Error("Error");
		return sIn;
	}

private:
	int _hour;
	int _minute;
	int _second;
};
#endif