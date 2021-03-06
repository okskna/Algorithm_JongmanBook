#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N;
vector<int> mySequence;
int cache[500];

void initCache()
{
	for (int i = 0; i < 500; ++i)
		cache[i] = -1;
}

void printSequence()
{
	for (auto &e : mySequence)
		cout << e << " ";
	cout << endl;

	return;
}

int Solution(int idx)
{
	int &ret = cache[idx];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = idx + 1; i < N; ++i)
		if (mySequence[idx] < mySequence[i])
			ret = max(Solution(i) + 1, ret);
	return ret;
}

int main()
{
	int C;
	int n_temp;
	
	mySequence.reserve(500);

	cin >> C;
	while (C--)
	{
		cin >> N;
		mySequence.clear();
		//memset(cache, -1, sizeof(cache));
		initCache();
		for (int i = 0; i < N; ++i)
		{
			cin >> n_temp;
			mySequence.push_back(n_temp);
		}

		//printSequence();
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			ans = max(Solution(i), ans);
		}
		cout << ans << endl;
	}

    return 0;
}

