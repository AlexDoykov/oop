#include <iostream>
#include <string>
using namespace std;
class Worker{
private:
	string name;
	int experience;
public:
	void hire(Worker);
	void fire(Worker);
	void print();
};