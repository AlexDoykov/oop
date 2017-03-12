#include <iostream>
#include <cstring>
using namespace std;
class Time{
	unsigned int hour;
	unsigned int minute;
	void set_hour(_hour){
		if(_hour > 24){
			cout<<"Can't update hour";
			return;
		}
		hour  = _hour;
	}
	void set_minute(_minute){
		if(_hour > 60){
			cout<<"Can't update minutes";
			return;
		}
		minutes  = _minute;
	}
	int get_hour(){
		return hour;
	}
	int get_minute(){
		return minute;
	}
	void addMinutes(int minutes){
		minute += minutes;
	}
	int passedMinutes(){
		return (hour*60+mintes);
	}
	bool operator > (Time other){
		if(hour == other.hour)
			return minute > other.minute; 
		return hour > other.time;
	}

	Time operator + (Time other){
		Time result;
		int minutes = this->passedMinutes();
		int minutesOther = other.passedMinutes();
		result.hour = (minutes+minutesOther)/60;
		result.minute = (minutes+minutesOther) - result.hour*60;
	}

	Time operator - (Time other){
		Time result;
		int minutes = this->passedMinutes();
		int minutesOther = other.passedMinutes();
		result.hour = (minutes-minutesOther)/60;
		result.minute = (minutes-minutesOther) - result.hour*60;
		return result;
	}

	Time operator * (Time other){
		Time result;
		int minutes = this->passedMinutes();
		int minutesOther = other.passedMinutes();
		result.hour = (minutes*minutesOther)/60;
		result.minute = (minutes*minutesOther) - result.hour*60;
		return result;
	}
	Time operator * (int num){
		Time result;
		int minutes = this->passedMinutes();
		int minutesOther = num;
		result.hour = (minutes+minutesOther)/60;
		result.minute = (minutes+minutesOther) - result.hour*60;
		return result;
	}

};