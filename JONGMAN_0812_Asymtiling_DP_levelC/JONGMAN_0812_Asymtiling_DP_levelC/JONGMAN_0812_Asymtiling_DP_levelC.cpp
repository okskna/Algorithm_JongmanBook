#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define DIV 1000000007

using namespace std;

// use cache[1] to cache[101]
int cache[101];
int n;

void printCache()
{
	int ten = n / 10;
	int one = n % 10;
	for (int i = 0; i < ten; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout.width(10);
			cout << cache[i * 10 + j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < one; ++j)
	{
		cout.width(10);
		cout << cache[ten * 10 + j] << " ";
	}
	cout << endl;
}
void initCache()
{
	for (int i = 0; i < 101; ++i)
		cache[i] = -1;
}
int Solution(int width)
{
	if (width == n)
		return 1;

	int& ret = cache[width];
	if (ret != -1)
		return ret;

	ret = 0;

	if (width + 1 <= n)
		ret += Solution(width + 1);
	if (width + 2 <= n)
		ret += Solution(width + 2);
	ret %= DIV;
	//ret += (Solution(width + 1) + Solution(width + 2)) % DIV;

	return ret;
}

int main()
{
	int C, ans;
	cin >> C;
	while(C--)
	{
		initCache();
		cin >> n;

		ans = Solution(0);

		if (n == 1)
			;
		if (n % 2 == 1)
		{
			//cout.width(10);
			//cout << ans << " " << Solution(n / 2 + 1) << endl;
			ans = (ans - Solution(n / 2 + 1) + DIV) % DIV;
		}
		else
		{
			//cout.width(10);
			//cout << ans << " " << Solution(n / 2) << " " << Solution(n / 2 + 1) << endl;
			ans = (ans - Solution(n / 2) - Solution(n / 2 + 1) + DIV) % DIV;
			
		}
		//ans %= DIV;
		//printCache();
		ans = (ans + DIV) % DIV;
		cout << ans << endl; 
	}
    return 0;
}

