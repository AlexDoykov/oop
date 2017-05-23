#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Database.h"
#define MAXARG 100
using namespace std;

void split(const string& s, char delim,vector<string>& v) {
    string help;
    int i = 0;
    while(s[i] != '\0'){
        if(s[i] == ' '){
            v.push_back(help);
            help.clear();
        }else{
            help += s[i];
        }
        i++;
    }
    v.push_back(help);
}

int main(){
    string command,choice;
    vector<string> arguments;
    bool exitProgram = 1;
    map<string, int> commands;
	commands["Showtables"] = 2;
    commands["Load"] = 3;
	commands["Exit"] = 1;
    Database database;
    while(exitProgram){
		getline(cin,command);
        split(command, ' ', arguments);
        switch(commands[arguments[0]]){
            case 1: exitProgram = 0; break;
            case 2: database.printTableNames(); break;
            case 3: database.load(arguments[1]); break;
        }
    }
    return 0;
}