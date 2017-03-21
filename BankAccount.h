#include <iostream>
#include <cstring>
using namespace std;
class BankAccount{
    private:
        char name[51];
        char account[21];
        double amount;
    public:
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
            cout<<"name: ";
            cin.getline(name,50);
            cout<<"account: ";
            cin.getline(account,20);
            cout<<"amount: ";
            cin>>amount;
            cin.ignore();
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

        bool operator > (BankAccount other){
            return this->amount > other.amount;
        }

};