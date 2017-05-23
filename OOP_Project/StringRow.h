class StringRow : public Row
{
private:
	string* row;
public:
	StringRow(size_t size){
		row = new string[size];
	}
	string& operator [] (const size_t index){
		return row[index];
	}
	~StringRow(){
		delete row;
	}
};