#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
class Time{
	public:
		unsigned int hour;
		unsigned int minute;
		void set_hour(int _hour){
			if(_hour > 24){
				cout<<"Can't update hour";
				return;
			}
			hour  = _hour;
		}
		void set_minute(int _minute){
			if(_minute > 60){
				cout<<"Can't update minutes";
				return;
			}
			minute  = _minute;
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
			return (hour*60+minute);
		}
		bool operator > (Time other){
			if(hour == other.hour)
				return minute > other.minute; 
			return hour > other.hour;
		}

		Time operator + (Time other){
			Time result;
			int minutes = this->passedMinutes();
			int minutesOther = other.passedMinutes();
			if(minutes+minutesOther > 24){
				result.hour = (minutes+minutesOther)/60 - 24;
			}else{
				result.hour = (minutes+minutesOther)/60;
			}
			result.minute = (minutes+minutesOther) - ((minutes+minutesOther)/60)*60;
			return result;
		}

		Time operator - (Time other){
			Time result;
			int minutesThis = this->passedMinutes();
			int minutesOther = other.passedMinutes();
			result.hour = (abs(minutesThis-minutesOther))/60;
			result.minute = (minutesThis-minutesOther) - result.hour*60;
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