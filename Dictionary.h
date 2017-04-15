#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
struct Word
{
	char word[101];
	char meaning[501];
};

class Dictionary{

	private:
		Word* words;
		size_t cnt,n;

		void _sort(){
			for(int i = 0; i < cnt; i++){
				if(strcmp(words[i].word, words[i+1].word) == 1){
					Word swap;
					swap = words[i];
					words[i+1] = words[i];
					words[i] = words[i+1];
				}
			}
		}

		void copyOld(int size){
			Word* newWords =  new Word[size];
			for(int i = 0; i < cnt; i++){
				newWords[i] = words[i];
			}
			delete words;
			words = newWords;
			n = size;
		}

		void init(const Dictionary& other){
			cnt = other.cnt;
			n = other.n;
			words = new Word[n];
			for(int i = 0; i < n; i++){
				strcpy(words[i].word, other.words[i].word);
				strcpy(words[i].meaning, other.words[i].meaning);
			}
		}

	public:

		Dictionary(unsigned int N){
			n = N;
			cnt = 0;
			words = new Word[n];
		}

		~Dictionary(){
			delete words;
		}

		Dictionary& operator = (const Dictionary& other){
			if(this != &other){
				delete words;
				init(other);

			}
			return *this;
		}

		Dictionary(const Dictionary& other){
			init(other);
		}

		void print(){
			for(int i = 0; i < cnt; i++){
				cout<<words[i].word<<" - "<<words[i].meaning<<endl;
			}
		}

		void add(const char* _word, const char* _meaning){
			if(cnt == n){
				int size = n*2;
				copyOld(size);
			}
			strcpy(words[cnt].word, _word);
			strcpy(words[cnt].meaning, _meaning);
			cnt++;
		}

		int find(const char* _word){
			int idx = -1;
			for(int i = 0; i < cnt; i++){
				if(strcmp(words[i].word, _word) == 0){
					idx = i;
					break;
				}
			}
			return idx;
		}

		void remove(const char* _word){
			int idx = find(_word);
			for(int i = idx; i < cnt-1; i++){
				strcpy(words[i].word, words[i+1].word);
				strcpy(words[i].meaning, words[i+1].meaning);
			}
			cnt--;
		}

		const char* checkMeaning(const char* _word){
			int idx = find(_word);
			if(idx > -1)
				return words[idx].meaning;
			else return "not found";
		}

		void printSorted(){
			_sort();
			print();
		}

		void operator += (const Dictionary& other){
			if(cnt+other.cnt >= n){
				int size = cnt+other.cnt;
				copyOld(size);
			}
			int found = 0;
			for(int i = cnt; i < other.cnt; i++){
				for(int j = 0; j < cnt; j++){
					if(strcmp(words[j].word, other.words[i].word)){
						found = 1;
					}
				}
				if(found == 0){
					words[i] = other.words[i-cnt];
				}
				found = 0;

			}
			cnt += other.cnt;
		}

		Dictionary operator + (const Dictionary& other){
			Dictionary result(cnt+other.cnt);
			result += *this;
			result += other;
			result.cnt = cnt+other.cnt;
			return result;
		}

};

