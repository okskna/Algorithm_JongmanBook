#include <iostream>
#include <algorithm>
using namespace std;
int switchState[10] = { 0, };
int minAns;
const int switchInfo[10][5] = 
{
	{ 0, 1, 2, -1, -1 },
	{ 3, 7, 9, 11, -1 },
	{ 4, 10, 14, 15, -1 },
	{ 0, 4, 5, 6, 7 },
	{ 6, 7, 8, 10, 12 },

	{ 0, 2, 14, 15 , -1 },
	{ 3, 14, 15 , -1, -1 },
	{ 4, 5, 7, 14, 15 },
	{ 1, 2, 3, 4, 5 },
	{ 3, 4, 5, 9, 13 }
};

void printSwitch()
{
	for (int i = 0; i < 10; ++i)
		cout << switchState[i] << " ";
	cout << endl;
}

void printClock(int *clock)
{
	for (int i = 0; i < 16; ++i)
		cout << clock[i] << " ";
	cout << endl;
}

void doSwitching(int num_sw, int *clock, int dir, int time)
{
	for (int t = 0; t < time; ++t)
	{
		if (dir == 0)
		{
			for (int i = 0; i < 5; ++i)
				if (switchInfo[num_sw][i] >= 0)
				{
					clock[switchInfo[num_sw][i]] += 3;
					if (clock[switchInfo[num_sw][i]] == 15)
						clock[switchInfo[num_sw][i]] = 3;
				}
		}
		else
		{
			for (int i = 0; i < 5; ++i)
				if (switchInfo[num_sw][i] >= 0)
				{
					clock[switchInfo[num_sw][i]] -= 3;
					if (clock[switchInfo[num_sw][i]] == 0)
						clock[switchInfo[num_sw][i]] = 12;
				}
		}
	}
	return;
}

bool isEnd(const int *clock)
{
	for (int i = 0; i < 16; ++i)
	{
		if (clock[i] != 12)
			return false;
	}
	return true;
}

int sumSwitching()
{
	int sum = 0;
	for (int i = 0; i < 10; ++i)
		sum += switchState[i];
	return sum;
}

void clockSwitch (int clock[16], int num_sw)
{
	if (isEnd(clock) == true)
	{
		//cout << num_sw << endl;
		//printSwitch();
		//printClock(clock);
		if (minAns == 0)
			minAns = sumSwitching();
		else
			minAns = min(sumSwitching(), minAns);
		return;
	}
	if (num_sw >= 10)
		return;

	for (int i = 0; i < 4; ++i)
	{
		switchState[num_sw] = i;
		doSwitching(num_sw, clock, 0, i);
		clockSwitch(clock, num_sw + 1);
		switchState[num_sw] = 0;
		doSwitching(num_sw, clock, 1, i);
	}
	return;
}

int main()
{
	int c, Ccnt;
	int clock[16] = { 0, };

	cin >> c;
	Ccnt = c;
	while (Ccnt--)
	{
		minAns = std::numeric_limits<int>::max();
		for (int i = 0; i < 10; ++i)
			switchState[i] = 0;
		for (int i = 0; i < 16; ++i)
			cin >> clock[i];
		clockSwitch(clock, 0);
		if (minAns == std::numeric_limits<int>::max())
			cout << -1 << endl;
		else
			cout << minAns << endl;

	}

    return 0;
}

