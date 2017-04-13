#include <iostream>
#include <cstring>
using namespace std;
class Word{
private:
	char word[21];
	size_t size;


	bool comparator(const Word& other,bool (*comp)(char, char)){
		int count = 0;
		while(count < size && count < other.size){
			if(comp(word[count],other.word[count])){
				return 0;
			}
			count++;
		}	
		return 1;
	}

public:

	Word(){
		word[0] = '\0';
		size = 0;
	}

	Word(char* _word){
		strcpy(word, _word);
		size = strlen(word);
	}

	Word& operator = (const Word& init){
		if(this != (&init)){
			strcpy(word, init.word);
			size = init.size;
		}
		return *this;
	}

	Word(const Word& init){
		*this = init;
	}

	//тъй като от това, което прочетох size_t отговаря донякъде на unsigned int ще предположа, че тази проверка е достатъчна
	char operator [] (const size_t& index){
		if(index > size){
			return '\0';
		}
		return word[index];
	}

	void operator += (const char& add){
		if(size == 20){
			return;
		}
		word[size++] = add;
		word[size] = '\0';
	}

	Word operator + (const char& add){
		Word result;
		if(size < 20){
			result = *this;
			result.word[size++] = add;
			result.word[size] = '\0';
			return result;
		}
	}

	bool operator == (const Word& other){
		if(size != other.size) return 0;
		comparator(other, [](char a, char b) {return a != b;});
	}

	bool operator < (const Word& other){
		comparator(other, [](char a, char b) {return a >= b;});
	}

	void print(){
		int i = 0; 
		while(word[i] != '\0'){
			cout<<word[i]<<" ";
			i++;
		}
		cout<<endl;
	}
};