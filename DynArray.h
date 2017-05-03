#pragma once
#include <iostream>

template<typename T>
class DynamicArray {
private:
	T* arr;
	unsigned size;
	unsigned capacity;

/*	void resize() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}*/
	void copy(const DynamicArray<T>& other) {
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
public:
	DynamicArray() {
		size = 0;
		capacity = 20;
		arr = new T[capacity];
	}

	DynamicArray(size_t n){
		size = n;
		capacity = n;
		arr = new T[n];
	}

	DynamicArray(const DynamicArray<T>& other) {
		copy(other);
	}

	DynamicArray& operator = (const DynamicArray<T>& other) {
		if (this != &other) {
			delete[] arr;
			copy(other);
		}
		return *this;
	}
	~DynamicArray() {
		delete[] arr;
	}
	
	void push_back(const T& new_element) {
		if (size == capacity) {
			resize();
		}
		arr[size] = new_element;
		size++;
	}
	
	T& operator [] (unsigned i) {
		return arr[i];
	}
	T operator[](unsigned i) const {
		return arr[i];
	}

	unsigned get_size() const {
		return size;
	}
	void set_size(size_t n) {
		size = n;
	}

	void resize(int n){
		int oldSize = size;
		size += n;
		assert(size >= 0);
		T * newArray = new T[size];
		if(n > 0) n = 0;
		else n = n*(-1);
		for(int i = n; i < oldSize; i++){
			newArray[i-n] = arr[i];
		}
		delete arr;
		arr = newArray;
	}

	DynamicArray<DynamicArray<T>> slice(size_t n){
		size_t it;
		int start = 0, stop = n;
		if(size % n != 0){
			it = size / n + 1;
		}else{
			it  = size / n;
		}
		DynamicArray<DynamicArray<T>> result(it);
		for(int i = 0; i < it; i++){
			for(int j = start; j < stop; j++){
				result[i][j-start] = arr[j];
			}
			start += n;
			if(stop + n >= size){
				stop = size;
			} else{
				stop += n;
			}
			result[i].set_size(n);
		}
		return result;
	}
};



