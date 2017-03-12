#include <iostream>
#include <cstring>
#include "BankAccount.h"
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
    
}

int main(){
    cin>>choise;
    switch(choise){
        case 1: task1(); break;
        case 2: task2(); break;
    }
    return 0;
}
