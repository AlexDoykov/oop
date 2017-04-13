#include <iostream>
#include <cstring>
#include <cmath>
#include "Rat.h"
#include "NumbersSummator.h"
#include "Word.h"
#include "BrowserHistory.h"
#define MAXN 10
using namespace std;

Rat poly(Rat coef[], int n, Rat x){
    Rat sum;
    sum = coef[0] * x + coef[1];
    for(int i = 2; i <= n; i++){
        sum = ((sum * x) + coef[i]);
    }
    return sum;
}

void task1(){
    Rat coefs[MAXN];
    int n, nom, denom;
    cin>>n;
    for(int i = 0; i <= n; i++){
        cin>>nom>>denom;
        coefs[i] = Rat(nom,denom);
    }
    cin>>nom>>denom;
    Rat x(nom,denom);
    Rat answer = poly(coefs,n,x);
    answer.print();
}

void task2(){
    char word[21];
    cin.ignore();
    cin.getline(word,21);
    Word w(word);
    cout<<"Test for [] operator and constructor\n";
    w.print();
    Word v;
    v += 'J';
    v += 'a';
    cout<<"Test for += operator and default constructor\n";
    v.print();

    cout<<"Test for < and == operators\n";
    if(w < v){
        cout<<"v\n";
    }else{
        cout<<"w\n";
    }

    if(w == v){
        cout<<"equal\n";
    }else{
        cout<<"not equal\n";
    }

    w = v;
    if(w == v){
        cout<<"equal\n";
    }else{
        cout<<"not equal\n";
    }

    cout<<"Test for + and = operators\n";
    Word r;
    r = (w + 'b');
    r.print();
}

void task3(){
    NumbersSummator seq1(10);
    seq1.add(10);
    seq1.add(5);
    seq1.sub(15);
    cout<<seq1.sum()<<endl;  //−>10 (10+10+5−15)
    cout<<seq1.average()<<endl;  //−>0 (10+5−15)/3
}

void task4(){
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