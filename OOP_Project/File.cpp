#include <iostream>
#include <map>
#include <fstream>
#include <sstream> //sstream auto-includes string.h, so no need to include that too
using namespace std;

string open(){
	string input,fileName;
	fstream file;
	cin>>fileName;
	file.open( fileName+".txt");
	if(file){
		if(file.is_open())
		{
			cout << "File open.\n";
			getline(file, input);	//get the text line
			file.close();
			return input;
		}
	}
	else{
		cout<<"Can't open file\n";

		//не съм сигурен че това е най добрия начин за създаването на празен файл
		file.open(fileName+".txt",  fstream::in | fstream::out | fstream::trunc);
        file <<'\n';
        file.close();
        return {};
	}
}

int main(){
	map<string, int> commands;
	commands["open"] = 0;
	commands["Showtables"] = 1;
	string choice = "open";
	//cin>>choice;
	switch(commands[choice]){
		case 0: open();
		case 1: database.printNames();
	}
	return 0;
}