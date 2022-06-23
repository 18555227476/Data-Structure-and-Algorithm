#include<iostream>
using namespace std;

int calculate(int value1, int value2) { //欧几里得算法求最大公约数
	if (value1 == 0 || value2 == 0) {
		return 0;
	}
	else
	{
		value1 < 0 ? (value1 = -value1) : value1;
		value2 < 0 ? (value2 = -value2) : value2;
		int larger = value1 > value2 ? value1 : value2;
		int smaller = value1 < value2 ? value1 : value2;
		int temp = larger % smaller;
		while (temp)
		{
			larger = smaller;
			smaller = temp;
			temp = larger % smaller;  
		};
		return smaller;
	};
};

int main() {
	int value1 = 136;
	int value2 = -51;
	cout << calculate(value1, value2) << endl;
	return 0;
};