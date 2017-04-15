#include <iostream>
#include <assert.h>

using namespace std;

template <typename T>
class DynArray
{
private:
	T *array; //addressOfFirstElement
	size_t size;

  //за специални случаи: например, за създаване на масив от масиви
	//Това е възможно само в методи на класа
	//в.ж. задачата за "slice" в домашното
	//въпрос: какъв е проблемът на slice, ако този
	//конструктор не съществува?

	DynArray ();

public:

	DynArray (const DynArray<T>& other);
	DynArray (size_t _size);
	T&  operator [] (const size_t index) const;
	void print ();
	void remove (const T& x);
	size_t getsize ();
	~DynArray ();
	void operator += (const DynArray<T>& other);
	DynArray<T> operator + (const DynArray<T>& other);
	DynArray<T>& operator = (const DynArray<T>& other);
	DynArray<DynArray<T>> slice(size_t n);
	void resize(int n);
	bool operator == (const DynArray<T>& other);
};

template <typename T>
T& DynArray<T>::operator [] (const size_t index) const
{
	//assert (index <= 0 || index > size);
	return array[index];
}

template <typename T>
DynArray<T>::DynArray ()
{ //за специални случаи: например, за създаване на масив от масиви
	//Това е възможно само в методи на класа
	//в.ж. задачата за "slice" в домашното
	//въпрос: какъв е проблемът на slice, ако този
	//конструктор не съществува?
	array = new T [1];
	size = 1;
}

template <typename T>
DynArray<T>::DynArray (const DynArray<T>& other)
{
	//как да преодолеем това array = other.array?;

	size = other.size;
	array = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = other.array[i];
	}
}

template <typename T>
DynArray<T>::DynArray (size_t _size)
{
	array = new T [_size];
	size = _size;
}


template <typename T>
void DynArray<T>::print ()
{
	cout << "[";
	for (int count = 0; count < size-1;count++)
	{
		cout << array[count] << ",";
	}
	cout << array[size-1];
	cout << "]" << endl;
}

template <typename T>
void DynArray<T>::remove (const T& x)
{
	size_t index = 0;
	while (index < size && array[index] != x)
	{
			index++;
	}

	assert (index < size);

	T *newarray = new T [size-1];

	size_t i;
	for (i = 0; i < index; i++)//наляво от елемента за изтриване
	{
		newarray[i] = array[i];
	}

	for (i = index+1; i < size; i++)//надясно от елемента за изтриване
	{
		newarray[i-1] = array[i];
	}

	delete array;
	array = newarray;
	size--;
}

template <typename T>
size_t DynArray<T>::getsize ()
{
	return size;
}

template <typename T>
DynArray<T>::~DynArray ()
{
	delete array;
}

template <typename T>
void DynArray<T>::operator += (const DynArray<T>& other)
{
	T *result = new T [size+other.size];
	size_t count;
	for (count = 0; count < size; count++)
		result[count] = array[count];
	for (count = size; count < size+other.size; count++)
		result[count] = other.array[count-size];

	delete array;
	array = result;
	size = size + other.size;

}

template <typename T>
DynArray<T> DynArray<T>::operator + (const DynArray<T>& other)
{
	/*
	DynArray result (*this);
	//result += other;
	*/

	DynArray result(size+other.size);

	size_t i;
	for (i = 0; i < size; i++)
	{
		result.array[i] = array[i];
	}
	for (i = 0; i < other.size; i++)
	{
		result.array[size+i] = other.array[i];
	}
	return result;
}

template <typename T>
DynArray<T>& DynArray<T>::operator = (const DynArray<T>& other)
{
	if (this != &other)
	{
		delete array;

		size = other.size;
		array = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			array[i] = other.array[i];
		}
	}

	return *this;
}

template <typename T>
bool DynArray<T>::operator == (const DynArray<T>& other)
{
	if (size != other.size)
	{
		return false;
	}

	size_t i = 0;
	while (i < size && array[i] == other.array[i])
	{
		i++;
	}

	return i == size;
}


/*******************My code************************************/



template <typename T>
void DynArray<T>::resize(int n){
	int oldSize = size;
	size += n;
	assert(size >= 0);
	T * newArray = new T[size];
	if(n > 0) n = 0;
	else n = n*(-1);
	for(int i = n; i < oldSize; i++){
		newArray[i-n] = array[i];
	}
	delete array;
	array = newArray;
}


template <typename T>
DynArray<DynArray<T>> DynArray<T>::slice(size_t n){
	int it;
	if(size % n != 0){
		it = size / n + 1;
	}else{
		it  = size / n;
	}
	cout<<"it= "<<it<<endl;
	DynArray<DynArray<T>> result(it);
/*	for(int i = 0; i < ??; i++){
		for(int j = ??; j < ??; j++){
			result[i][j] = array[i];
		}
	}*/
	return result;
}
