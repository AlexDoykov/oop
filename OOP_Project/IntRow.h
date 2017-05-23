class IntRow : public Row
{
private:
	int* row;
public:
	IntRow(size_t size){
		row = new int[size];
	}
	IntRow(const IntRow& other){
		row = other.row;
	}
	int& operator [] (const size_t index){
		return row[index];
	}
	~IntRow(){
		delete row;
	}
};