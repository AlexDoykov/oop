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
	int n,curSize;

public:
	BrowserHistory(int _n){
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

	void add(HistoryEntry site){
		HistoryEntry* newWebsites;
		if(curSize == n){
			newWebsites =  new HistoryEntry[n*2];
			for(int i = 0; i < n; i++){
				newWebsites[i] = websites[i];
			}
			n *= 2;
			delete websites;
			websites = newWebsites;
		}
		websites[curSize] = site;
		curSize++;
	}

	void operator +=(HistoryEntry site){
		add(site);
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
		HistoryEntry* newWebsites =  new HistoryEntry[n];

		for(int i = 0; i < curSize-1; i++){
			newWebsites[i] = websites[i];
		}
		curSize--;
		delete websites;
		websites = newWebsites;
	}

	BrowserHistory operator + (BrowserHistory other){
		BrowserHistory result(n+other.n);
		for(int i = 0; i < curSize; i++){
			result.websites[i] = websites[i];
		}

		for (int i = 0; i < other.curSize; i++)
		{
			result.websites[i+curSize] = other.websites[i];
		}

		result.n  = n+other.n;
		result.curSize = curSize+other.curSize;
		return result;
	}

};