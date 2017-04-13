#include <iostream>
class NumbersSummator{
private:
	int init;
	int sumHolder;
	int changed;
public:
	NumbersSummator(int s){
		init = s;
		sumHolder = s;
		changed = 0;
	}

	NumbersSummator operator = (const NumbersSummator& other){
		init = other.init;
		sumHolder = other.init;
		changed = other.changed;
	}

	int sum(){
		return sumHolder;
	}

	void add(int a){
		sumHolder += a;
		changed++;
	}

	void sub(int a){
		sumHolder -= a;
		changed++;
	}

	int num(){
		return changed;
	}

	double average(){
		return (sumHolder-init)/changed;
	}

};