#include <iostream>
#include <string>
#include "Manger"
using namespace std;

void print(){
	cout<<name<<endl;
	if(knowsC++){
		cout<<"Knows C++\n";
	}else{
		cout<<"Doesn't know C++\n";
	}
	if(knowsC++){
		cout<<"Knows C#\n";
	}else{
		cout<<"Doesn't know C#\n";
	}
	cout<<experience<<endl;
}