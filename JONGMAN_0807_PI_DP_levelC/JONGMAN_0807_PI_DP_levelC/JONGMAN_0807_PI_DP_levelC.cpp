#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string myString;
unsigned long long cache[10001];

bool pattern_1(string sub)
{
	for(int i = 1 ; i < sub.size(); ++i)
		if(sub[i - 1] != sub[i])
			return false;
	return true;
}

bool pattern_2(string sub)
{
	for (int i = 1; i < sub.size(); ++i)
	{
		if (sub[i - 1] + 1 == sub[i])
		{
			if (i == sub.size() - 1)
				return true;
			continue;
		}
		else
			break;
	}

	for (int i = 1; i < sub.size(); ++i)
	{
		if (sub[i - 1] - 1 == sub[i])
		{
			if (i == sub.size() - 1)
				return true;
			continue;
		}
		else
			break;
	}

	return false;
}

bool pattern_3(string sub)
{
	for (int i = 2; i < sub.size(); ++i)
		if (sub[i - 2] != sub[i])
			return false;
	return true;
}

bool pattern_4(string sub)
{
	int temp_gab = sub[0] - sub[1];

	for (int i = 1; i < sub.size(); ++i)
		if (sub[i - 1] - sub[i] != temp_gab)
			return false;
	return true;
}

bool pattern_5(string sub) // 나머지의 경우 모두 pattern_5 -> 때문에 그냥 만들어둠
{
	return true;
}

void initCache()
{
	for (int i = 0; i < 10001; ++i)
		cache[i] = -1;
}

void printCache()
{
	for (int i = 0; i < 10; ++i)
		cout << cache[i] << " ";
	cout << endl;
}

int calcLoD(string sub)
{
	if (pattern_1(sub))
		return 1;
	else if (pattern_2(sub))
		return 2;
	else if (pattern_3(sub))
		return 4;
	else if (pattern_4(sub))
		return 5;
	else
		return 10;
	
}

unsigned long long Solution(int start, int end)
{
	//cout << "start: " << start << ", end: " << end << endl;
	if (start == end) return 0;

	unsigned long long& ret = cache[start];
	if (ret != -1) return ret;
	//if (start + 3 == end)
	//	return ret = calcLoD(myString.substr(start, 3));
	//if (start + 4 == end)
	//	return ret = calcLoD(myString.substr(start, 4));
	//if (start + 5 == end)
	//	return ret = calcLoD(myString.substr(start, 5));
	
	ret = 99999999;
	if (start + 3 <= end)
		ret = min(Solution(start + 3, end) + calcLoD(myString.substr(start, 3)), ret);
	if (start + 4 <= end)
		//cout << "ret: " << ret << ", Solution: " << Solution(start + 4, end) << ", CalcLoD: " << calcLoD(myString.substr(start, 4)) << endl;
		ret = min(Solution(start + 4, end) + calcLoD(myString.substr(start, 4)), ret);
	if (start + 5 <= end)
		ret = min(Solution(start + 5, end) + calcLoD(myString.substr(start, 5)), ret);

	return ret;
}

int main()
{
	char mybuffer[32768];
	setvbuf(stdin, mybuffer, _IOFBF, sizeof(mybuffer));

	int C;
	cin >> C;
	while (C--)
	{
		cin >> myString;
		unsigned long long ans = 0LL;
		initCache();
		
		ans = Solution(0, myString.size());
		cout << ans << endl;
	}

    return 0;
}

