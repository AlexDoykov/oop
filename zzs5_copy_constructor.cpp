#include <iostream>
#include <cstring>
#include "Dictionary.h"
#include "BrowserHistory.h"
using namespace std;

void task1(){
    int n,m;
    cin>>n>>m;
    BrowserHistory history1(n);
    BrowserHistory history2(m);
    HistoryEntry entry1;
    cin>>entry1.month;
    cin.ignore();
    cin.getline(entry1.url,2048);
    history1.add(entry1);
    history1.print();
    history2 += history1;
    history2.print();
    BrowserHistory history3 = history2 + history1;
    history3.print();
    history3.removeResent();
    cout<<"after remove\n";
    history3.print();
}

void task2(){
    int n;
    cin>>n;
    Dictionary dict1(n);
    dict1.add("shoe","sth you wear");
    dict1.add("shoe1","sth you wear1");
    dict1.print();
    Dictionary dict2 = dict1;
    //dict2.print();
    /*dict2 += dict1;
    dict2.add("music","sth you listen");
    Dictionary dict3 = dict1 + dict2;
    dict3.print();*/
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
        }
        return 0;
    }
}