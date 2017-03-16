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
		Word words[500];
		int cnt;

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
	public:
		void init(){
			cnt = 0;
		}

		void print(){
			for(int i = 0; i < cnt; i++){
				cout<<words[i].word<<" - "<<words[i].meaning<<endl;
			}
		}

		void add(const char* _word, const char* _meaning){
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

		Dictionary operator + (Dictionary dict){
			Dictionary result;
			int k = 0;
			for(int i = 0; i < cnt; i++){
				strcpy(result.words[k].word, words[i].word);
				strcpy(result.words[k].meaning, words[i].meaning);
				k++;
			}
			bool found = 0;
			for(int i = 0; i < dict.cnt; i++){
				for(int j = 0; j < cnt; j++){
					if(strcmp(dict.words[i].word, result.words[j].word) == 0){
						strcat(result.words[j].meaning, dict.words[i].meaning);
						found = 1;
					}
				}
				if(found == 0){
					strcpy(result.words[k].word, dict.words[i].word);
					strcpy(result.words[k].meaning, dict.words[i].meaning);
					k++;
					if(k == 500) break;
				}else{
					found = 0;
				}
			}
			cout<<k<<endl;
			result.cnt = k;
			return result;
		}

};

