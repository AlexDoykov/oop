#include <iostream>
#include <cstring>
using namespace std;
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