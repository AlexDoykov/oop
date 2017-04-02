#include <iostream>
#include <assert.h>
#include <cstring>
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