class DoubleColomn : public Colomn
{
private:
	double* colomn;
public:
	DoubleRow(size_t size){
		colomn = new double[size];
	}
	double& operator [] (const size_t index){
		return colomn[index];
	}
	~DoubleRow(){
		delete colomn;
	}
};