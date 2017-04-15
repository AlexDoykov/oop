#include <iostream>
#include <assert.h>
#include <cstring>

struct HistoryEntry
{
	int month;
	//според stackoverflow повечето браузъри не поддаржат url над 2000 символа :)
	char url[2049];
};

class BrowserHistory{
private:

	HistoryEntry* websites;
	size_t n,curSize;

	void copyOld(int size){
		HistoryEntry* newWebsites =  new HistoryEntry[size];
		for(int i = 0; i < curSize; i++){
			newWebsites[i] = websites[i];
		}
		delete websites;
		websites = newWebsites;
		n = size;
	}

	void init(const BrowserHistory& other){
		n = other.n;
		curSize = other.curSize;
		websites = new HistoryEntry[n];
		for(int i = 0; i < n; i++){
			websites[i] = other.websites[i];
		}
	}


public:
	
	BrowserHistory(){
		n = curSize = 0;
		//за тоя конструктор не съм много сигурен дали така е правилно
		websites = new HistoryEntry[n];

	}

	BrowserHistory& operator = (const BrowserHistory& other){
		if(this != &other){
			delete websites;
			init(other);

		}
		return *this;
	}

	BrowserHistory(const BrowserHistory& other){
		if(this != &other){
			init(other);
		}
	}

	BrowserHistory(size_t _n){
		websites = new HistoryEntry[_n];
		n = _n;
		curSize = 0;
	}

	int getSize(){
		return curSize;
	}

	int getCapacity(){
		return n;
	}

	void add(const HistoryEntry& site){
		if(curSize == n){
			int size = n*2;
			copyOld(size);
		}
		websites[curSize] = site;
		curSize++;
	}

	
	//тъй като става колизия с домашно 5 за този оператор кода от домашно 4 за него го оставям в коментар
	/*void operator +=(const HistoryEntry& site){
		add(site);
	}*/

	void operator += (const BrowserHistory& other){
		if(curSize+other.curSize >= n){
			int size = curSize+other.curSize;
			copyOld(size);
		}
		for(int i = curSize; i < other.curSize; i++){
			websites[i] = other.websites[i-curSize];
		}
		curSize += other.curSize;
	}

	void print(){
		for(int i = 0; i < curSize; i++){
			cout<<websites[i].month<<" "<<websites[i].url<<endl;
		}
	}

	int countSitesPerMonth(int _month){
		int cnt = 0;
		for(int i = 0; i < curSize; i++){
			if(_month == websites[i].month){
				cnt++;
			}
		}
		return cnt;
	}

	int mostSitesVisitedPerMonth(){
		int months[12], month,m = 0;
		for(int i = 0; i < 12; i++){
			months[i] = 0;
		}

		for(int i = 0; i < curSize; i++){
			months[websites[i].month]++;
		}

		for(int i = 0; i < 12; i++){
			if(months[i] > m){
				month = i;
				m = months[i];
			}
		}

		return month;
	}

	void removeResent(){
		if(curSize > 0) curSize--;
	}

	BrowserHistory operator + (const BrowserHistory& other){
		BrowserHistory result(n+other.n);
		result += *this;
		result += other;
		return result;
	}

	~BrowserHistory(){
		//a за тук се замислих не трябва ли да имам и n = 0 и curSize = 0;
		delete websites;
	}

};