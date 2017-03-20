#include <iostream>
using namespace std;
struct Point
{
	int x,y;
};

class Line{
private:
	Point p1,p2;
public:
	void init(int x1,int y1, int x2,int y2){
		p1.x = x1;
		p1.y = y1;
		p2.x = x2;
		p2.y = y2;
	}

	double findSlope(int x1, int y1, int x2, int y2){
		//cout<<y2<<" "<<y1<<" "<<x2<<" "<<x1<<endl;
		return double((y2-y1))/double((x2-x1));
	}

	bool isHorizontal(Line other){
		double slope1 = findSlope(other.p1.x,other.p1.y,other.p2.x,other.p2.y);
		double slope2 = findSlope(this->p1.x,this->p1.y,this->p2.x,this->p2.y);
		//cout<<"slope1="<<slope1<<" slope2="<<slope2<<endl;
		return slope1 == slope2;
	}

	bool isPointOnLine(Point p){
		double a1 = findSlope(this->p1.x,this->p1.y,this->p2.x,this->p2.y);
		double cross = (a1*(p.x-p1.x)+p1.y-p.y);
		if(cross == 0)
			return 1;
		return 0;
	}

	bool findPointOfIntersection(line other){
		double y = (a1*(other.x-p1.x)+p1.y)

	}

};