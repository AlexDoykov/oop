#include <string>
#include <iostream>
#include "Row.h"
#include "IntRow.h"
#include "DoubleRow.h"
#include "StringRow.h"
#define COLUMN_TYPES 100
using namespace std;

class Table{
private:
	string name;
	int numberOfColumns;
	string types[COLUMN_TYPES];
	Row** rows;
public:
	
	Table(string _name, int _rows, int _col){
		name = _name;
		numberOfColumns = _col;
		rows = new Row* [_col];
	}
	
	void describe();
	
	bool save();
	
	string getName(){
		return name;
	}
	template <typename T>
	void addRow(T& row, size_t pos){
		rows[pos] = &(row);
	}
	~Table(){
		//delete rows;
	}

	void print(){
		cout<<"name: "<<name<<endl;
		cout<<"№ col: "<<numberOfColumns<<endl;
		for(int i = 0; i < numberOfColumns; i++){
			cout<<types[i]<<" ";
		}
		cout<<endl;
		for(int i = 0; i < numberOfColumns; i++){
			cout<<rows[i]<<endl;
		}
		cout<<endl;
	}
};