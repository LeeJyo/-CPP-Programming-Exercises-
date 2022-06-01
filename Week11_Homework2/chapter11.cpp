#include <iostream>


using namespace std;

class TimeHMS {
	int hour, min, sec;
public :
	TimeHMS(int h= 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

	void print(const char* msg = "시간 = ")
	{
		printf("%s %d시 %d분 %d초\n", msg, hour, min, sec);
	}
	
	friend TimeHMS operator+(TimeHMS a, TimeHMS b)// 실습문제 1-1
	{
		return TimeHMS(a.hour + b.hour + (a.min + b.min + ((a.sec + b.sec) / 60) )/ 60, (a.min + b.min + ((a.sec + b.sec) / 60)) % 60, (a.sec + b.sec) % 60);
	}

	friend TimeHMS operator-(TimeHMS a, TimeHMS b)// 실습문제 1-2
	{
		return TimeHMS(a.hour - b.hour, a.min - b.min, a.sec - b.sec);
	}

	bool operator==(TimeHMS a)// 실습문제 1-3
	{
		return (hour == a.hour && min == a.min && sec == a.sec);
	}

	bool operator!=(TimeHMS a)// 실습문제 1-3
	{
		return (hour != a.hour && min != a.min && sec != a.sec);
	}

	TimeHMS& operator++()// 실습문제 1-4
	{
		hour += 1;
		return *this;
	}

	TimeHMS& operator--()// 실습문제 1-4
	{
		hour -= 1;
		return *this;
	}

	TimeHMS operator++(int)// 실습문제 1-5
	{
		sec += 1;
		return TimeHMS(hour, min, sec);
	}

	TimeHMS operator--(int)// 실습문제 1-5
	{
		sec -= 1;
		return TimeHMS(hour, min, sec);
	}

	int& operator[](int id)// 실습문제 1-6
	{
		if (id == 0) return hour;
		else if (id == 1) return min;
		else if (id == 2) return sec;
		else exit(0);
	}

	operator int()// 실습문제 1-7
	{
		return(int)(hour * 60 * 60) + (min * 60) + sec;
	}

	operator double()// 실습문제 1-8
	{
		return(double)(double)hour + ((double)min / 60) + ((double)sec / 3600);
	}

	TimeHMS operator*(int s)// 실습문제 1-9
	{
		return TimeHMS(hour*s + ((min*s) + ((sec*s) / 60)) / 60, ((min*s) + ((sec*s) / 60)) % 60, (sec*s) % 60);
	}

	friend ostream& operator<<(ostream& os, const TimeHMS& a)// 실습문제 1-10
	{
		os << a.hour << "시 " << a.min << "분 " << a.sec << "초";
		return os;
	}

	friend istream& operator>>(istream& is, TimeHMS& a)// 실습문제 1-10
	{
		is >> a.hour >> a.min >> a.sec;
		return is;
	}


};

int main(void)
{
	TimeHMS t1(1, 20, 30), t2(4, 35, 46), t3;
	bool s;

	t3 = t1 + t2;
	cout << "실습문제1-1 : ";
	cout << t3 << endl;
	t3 = t1 - t2;
	cout << "실습문제1-2 : ";
	cout << t3 << endl;
	s = t1 == t2;
	cout << "실습문제1-3 : \n";
	cout << "같으면 1 : " << s << endl;
	s = t1 != t2;
	cout << "다르면 1 : " << s << endl;
	cout << "실습문제1-4 : \n";
	t3 = ++t2;
	cout << t3 << endl;
	t3 = --t2;
	cout << t3 << endl;
	cout << "실습문제1-5 : \n";
	t3 = t2++;
	cout << t3 << endl;
	t3 = t2--;
	cout << t3 << endl;
	cout << "실습문제1-6 : ";
	cout << t1[0] << "시 " << t1[1] << "분 " << t1[2] << "초 " << endl;
	cout << "실습문제1-7 : ";
	cout << (int)t1 << "초" << endl;
	cout << "실습문제1-8 : ";
	cout << (double)t1 << "시간" << endl;
	cout << "실습문제1-9 : ";
	t3 = t1 * 2;
	cout << "t1*2는? ";
	cout << t3 << endl;





}