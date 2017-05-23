#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Table.h"
#include "IntRow.h"
#include "DoubleRow.h"
#include "StringRow.h"
#define MAX 100
class Database
{

private:
	Table* tables;
	size_t size;

	string open(const string& fileName){
		cout<<fileName<<endl;
		string input;
		fstream file;
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
	template <typename T, typename S>
	void fillRow(Table& newTable, T& row, stringstream& ss, int cntRows, int numRows, S value){
		while(cntRows < numRows){
			ss>>value;
			cout<<value<<endl;
			ss.ignore(3);
			row[cntRows] = value;
			cntRows++;
		}
		//newTable.addRow(row, numRows);
	}

public:
	~Database(){
	}

	void printTableNames(){
		for(int i = 0; i < size; i++){
			cout<<tables[i].getName()<<endl;
		}
	}
	void load(const string& fileName){
		string tableName, content, colType;
		int numCol, numRows, cnt = 0, cntRows = 0;
		content = open(fileName);
		cout<<content<<endl;
		stringstream ss(content);
		ss>>tableName;
		ss.ignore(3);
		ss>>numCol;
		ss.ignore(3);
		ss>>numRows;
		ss.ignore(3);
		Table newTable(tableName, numRows, numCol);
		while(cnt < numCol){
			ss>>colType;
			ss.ignore(3);
			if(colType == "int"){
				IntRow row(numRows);
				int value;
				fillRow(newTable, row, ss, cntRows, numRows, value);

			}else if(colType == "double"){
				DoubleRow row(numRows);
				double value;
				fillRow(newTable, row, ss, cntRows, numRows, value);
			}else if(colType == "string"){
				StringRow row(numRows);
				string value;
				fillRow(newTable, row, ss, cntRows, numRows, value);
			}
			cnt++;
		}
	}
};