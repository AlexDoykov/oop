#include <iostream>
#include <cstring>

using namespace std;
class Rat{
private:
	int denom;
	int nom;

public:

	Rat(){
		denom = 0;
	}

	Rat(const Rat& init){
		nom = init.nom;
		denom = init.denom;
	}

	Rat operator = (const Rat& other){
		nom = other.nom;
		denom = other.denom;
		return *this;
	}

	Rat(const int& _nom, const int& _denom){
		nom = _nom;
		denom = _denom;
	}

	Rat operator + (const Rat& other){
		Rat result;
		result.nom = nom * other.denom + other.nom * denom;
		result.denom = denom * other.denom;
		return result;
	}

	Rat operator * (const Rat& other){
		Rat result;
		result.nom = nom * other.nom;
		result.denom = denom * other.denom;
		return result;
	}

	void print(){
		cout<<nom<<"/"<<denom<<endl;
	}
};
