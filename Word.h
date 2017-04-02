#include <iostream>
#include <assert.h>
#include <cstring>
using namespace std;
class Word{
private:
	char word[21];
	int size;
public:
	char operator [] (int index){
		assert (index >= 0 && index < size);
		return word[index];
	}

	Word(char* _word, int n){
		strcpy(word, _word);
		size = n;
	}

	Word(){
		size = 0;
	}

	Word operator + (char add){
		assert (size < 20);
		Word result;
		int i = 0;
		while(word[i] != '\0'){
			result.word[i] = word[i];
			i++;
		}
		result.word[size] = add;
		result.word[size+1] = '\0';
		return result;
	}

	void operator += (char add){
		assert (size < 20);
		word[size] = add;
		word[++size] = '\0';
	}

	bool operator < (Word other){
		int i = 0;
		while(word[i] != '\0'){
			if(word[i] > other[i]){
				return 0;
			}
			i++;
		}
		return 1;
	}

	bool operator == (Word other){
		int i = 0;
		while(word[i] != '\0'){
			if(word[i] != other[i]){
				return 0;
			}
			i++;
		}
		return 1;
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