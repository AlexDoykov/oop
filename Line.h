#include <iostream>
using namespace std;
struct Point
{
	int x,y;
};

class Line(){
private:
	Point p1,p2;
public:
	bool isHorizontal(Line other){
		if((other.y-y)/(other.x-x) == 0) return 0;
	}
}