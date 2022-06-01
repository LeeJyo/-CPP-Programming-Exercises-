#include <iostream>


using namespace std;

class TimeHMS {
	int hour, min, sec;
public :
	TimeHMS(int h= 0, int m = 0, int s = 0) : hour(h), min(m), sec(s) {}

	void print(const char* msg = "�ð� = ")
	{
		printf("%s %d�� %d�� %d��\n", msg, hour, min, sec);
	}
	
	friend TimeHMS operator+(TimeHMS a, TimeHMS b)// �ǽ����� 1-1
	{
		return TimeHMS(a.hour + b.hour + (a.min + b.min + ((a.sec + b.sec) / 60) )/ 60, (a.min + b.min + ((a.sec + b.sec) / 60)) % 60, (a.sec + b.sec) % 60);
	}

	friend TimeHMS operator-(TimeHMS a, TimeHMS b)// �ǽ����� 1-2
	{
		return TimeHMS(a.hour - b.hour, a.min - b.min, a.sec - b.sec);
	}

	bool operator==(TimeHMS a)// �ǽ����� 1-3
	{
		return (hour == a.hour && min == a.min && sec == a.sec);
	}

	bool operator!=(TimeHMS a)// �ǽ����� 1-3
	{
		return (hour != a.hour && min != a.min && sec != a.sec);
	}

	TimeHMS& operator++()// �ǽ����� 1-4
	{
		hour += 1;
		return *this;
	}

	TimeHMS& operator--()// �ǽ����� 1-4
	{
		hour -= 1;
		return *this;
	}

	TimeHMS operator++(int)// �ǽ����� 1-5
	{
		sec += 1;
		return TimeHMS(hour, min, sec);
	}

	TimeHMS operator--(int)// �ǽ����� 1-5
	{
		sec -= 1;
		return TimeHMS(hour, min, sec);
	}

	int& operator[](int id)// �ǽ����� 1-6
	{
		if (id == 0) return hour;
		else if (id == 1) return min;
		else if (id == 2) return sec;
		else exit(0);
	}

	operator int()// �ǽ����� 1-7
	{
		return(int)(hour * 60 * 60) + (min * 60) + sec;
	}

	operator double()// �ǽ����� 1-8
	{
		return(double)(double)hour + ((double)min / 60) + ((double)sec / 3600);
	}

	TimeHMS operator*(int s)// �ǽ����� 1-9
	{
		return TimeHMS(hour*s + ((min*s) + ((sec*s) / 60)) / 60, ((min*s) + ((sec*s) / 60)) % 60, (sec*s) % 60);
	}

	friend ostream& operator<<(ostream& os, const TimeHMS& a)// �ǽ����� 1-10
	{
		os << a.hour << "�� " << a.min << "�� " << a.sec << "��";
		return os;
	}

	friend istream& operator>>(istream& is, TimeHMS& a)// �ǽ����� 1-10
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
	cout << "�ǽ�����1-1 : ";
	cout << t3 << endl;
	t3 = t1 - t2;
	cout << "�ǽ�����1-2 : ";
	cout << t3 << endl;
	s = t1 == t2;
	cout << "�ǽ�����1-3 : \n";
	cout << "������ 1 : " << s << endl;
	s = t1 != t2;
	cout << "�ٸ��� 1 : " << s << endl;
	cout << "�ǽ�����1-4 : \n";
	t3 = ++t2;
	cout << t3 << endl;
	t3 = --t2;
	cout << t3 << endl;
	cout << "�ǽ�����1-5 : \n";
	t3 = t2++;
	cout << t3 << endl;
	t3 = t2--;
	cout << t3 << endl;
	cout << "�ǽ�����1-6 : ";
	cout << t1[0] << "�� " << t1[1] << "�� " << t1[2] << "�� " << endl;
	cout << "�ǽ�����1-7 : ";
	cout << (int)t1 << "��" << endl;
	cout << "�ǽ�����1-8 : ";
	cout << (double)t1 << "�ð�" << endl;
	cout << "�ǽ�����1-9 : ";
	t3 = t1 * 2;
	cout << "t1*2��? ";
	cout << t3 << endl;





}