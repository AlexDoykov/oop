#include <iostream>
#include <cstring>
using namespace std;
class Rat{
private:
	int denom;
	int nom;
public:
	void set_denom(const int& _denom){
		if(_denom != 0){
			denom = _denom;
		}
		else{
			cout<<"denom can't be 0!";
		}
	}

	void set_nom(const int& _nom){
		nom = _nom;
	}

	int get_nom(){
		return nom;
	}

	int get_denom(){
		return denom;
	}

	Rat(){
		nom = 1;
		denom = 1;
	}

	Rat(const int& _nom, const int& _denom){
		set_nom(_nom);
		set_denom(_denom);
	}

	Rat(int _nom){
		set_nom(_nom);
		set_denom(1);
	}

	Rat operator + (Rat other){
		Rat result;
		result.nom = nom*other.denom + other.nom*denom;
		result.denom = denom*other.denom;
		return result;
	}

	Rat operator * (Rat other){
		Rat result;
		result.nom = nom * other.nom;
		result.denom = denom*other.denom;
		return result;
	}

	void operator += (Rat other){
		*this = *this+other;
	}

	Rat operator ^ (int p){
		Rat result(pow(nom,p),pow(denom,p));
		return result;
	}


};