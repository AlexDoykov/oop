class DoubleRow : public Row
{
private:
	double* row;
public:
	DoubleRow(size_t size){
		row = new double[size];
	}
	double& operator [] (const size_t index){
		return row[index];
	}
	~DoubleRow(){
		delete row;
	}
};