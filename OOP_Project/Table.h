#include <string>
#include <iostream>
#include "Row.h"
#define COLUMN_TYPES 100
using namespace std;

class Table{
private:
	string name;
	int numberOfColumns;
	string types[COLUMN_TYPES];
	Row* rows;
public:
	
	Table(string _name, int _rows, int _col){
		name = _name;
		rows = new Row[_rows];
		numberOfColumns = _col;
	}
	
	void describe();
	
	bool save();
	
	string getName(){
		return name;
	}

	void addRow(const Row* row, size_t pos){
		rows[pos] = row;
	}
	~Table(){
		delete rows;
	}
};