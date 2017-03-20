#include <iostream>
#include <cstring>
#include "BankAccount.h"
#include "Time.h"
#include "Dictionary.h"
#include "Line.h"
using namespace std;

Time operator * (int num, Time t){
    Time result;
    int minutes = num;
    int minutesTime = t.passedMinutes();
    result.hour = (minutes*minutesTime)/60;
    result.minute = (minutes*minutesTime) - result.hour*60;
    return result;
}

void task1(){
    BankAccount ba1,ba2;
    ba2.read();
    ba2.print();
    ba2.withdraw(10);
    ba2.print();
    ba1.read();
    ba1.print();
    ba1.deposit(10);
    ba1.print();
    cout<<(ba1 > ba2);
}

void task2(){
    Time time1, time2, time3;
    time1.set_hour(12);
    time1.set_minute(33);
    time2.set_hour(14);
    time2.set_minute(44);
    time3 = time1+time2;
    cout<<"+: ";
    cout<<time3.get_hour()<<" "<<time3.get_minute()<<endl;
    cout<<"-: ";
    time3 = time2-time1;
    cout<<time3.get_hour()<<" "<<time3.get_minute()<<endl;
    cout<<"*num: ";
    time3 = time2*10;
    cout<<time3.get_hour()<<" "<<time3.get_minute()<<endl;
    cout<<"+time: ";
    time3 = 10*time2;
    cout<<time3.get_hour()<<" "<<time3.get_minute()<<endl;
}

void task3(){
    Dictionary dict1,dict2,dict3;
    dict1.init();
    dict2.init();
    dict3.init();
    dict1.add("shoe", "wear it on your feets");
    dict1.add("job", "money, money");
    dict1.print();
    dict2.add("shoe", "wear it on your feets");
    dict2.add("hat", "something");
    dict2.print();
    cout<<dict2.checkMeaning("box")<<endl;
    cout<<dict2.checkMeaning("hat")<<endl;
    dict3 = dict1 + dict2;
    dict3.print();
    dict3.remove("shoe");
    dict3.print();

}

void task4(){
    Line l1,l2;
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    l1.init(x1,y1,x2,y2);
    cin>>x1>>y1>>x2>>y2;
    l2.init(x1,y1,x2,y2);

    if(l1.isHorizontal(l2)){
        cout<<"parallel\n";
    }else{
        cout<<"point of intersection: ";
        Point p = l1.findPointOfIntersection(l2);
        cout<<p.x<<" "<<p.y<<endl;
    }
    cin>>p.x>>p.y;
    if(l1.isPointOnLine(p) == 1){
        cout<<"is on line\n";
    }else{
        cout<<"is not on line\n";
    }

    if()
}

int main(){
    int choice;
    bool exitProgram = 1;
    cin>>choice;
    while(exitProgram){
        switch(choice){
            case 0: exitProgram = 0; break;
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
        }
        return 0;
    }
}
