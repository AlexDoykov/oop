#include <iostream>
#include <cstring>
using namespace std;
class BankAccount{
    public:
        char name[51];
        char account[21];
        double amount;
        void set_name(char name[]){
            strcpy(this->name, name);
        }
        void set_account(char account[]){
            strcpy(this->account, account);
        }
        void set_amount(double amount){
            this->amount = amount;
        }
        char* get_name(){
            return name;
        }
        char* get_account(){
            return account;
        }
        double get_amount(){
            return amount;
        }
        void read(){

        }
        void print(){
            cout<<get_name()<<" "<<get_account()<<" "<<get_amount()<<endl;
        }
        void deposit(double amount){
            this->amount += amount;
        }
        void withdraw(double amount){
            this->amount -= amount;
        }

};
int main(){
    BankAccount ba1,ba2;
    ba1.read();
    ba2.read();
    ba1.print();
    ba1.deposit(10);
    ba1.print();
    ba2.print();
    ba2.withdraw(10);
    ba2.print();
    return 0;
}
