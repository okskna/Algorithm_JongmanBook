#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#define INF 987654321

using namespace std;

int N, S;
int seq[101];
int cache[101][10];

int psum[101];
int psqsum[101];

void printCache()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 10; ++j)
			cout << cache[i][j] << " ";
		cout << endl;
	}
}

void printArr(int *arr)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

void initCache()
{
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < 10; ++j)
			cache[i][j] = -1;
}

void initArr(int n, int* arr)
{
	for (int i = 0; i < n; ++i)
		seq[i] = 0;
}

void preCalc()
{
	sort(seq, seq + N);

	psum[0] = seq[0];
	psqsum[0] = seq[0] * seq[0];
	for (int i = 1; i < N; ++i)
	{
		psum[i] = psum[i - 1] + seq[i];
		psqsum[i] = psqsum[i - 1] + seq[i] * seq[i];
	}
}

int calcError(int lo, int hi)
{
	int sum, sqsum;

	sum = psum[hi] - (lo == 0 ? 0 : psum[lo - 1]);
	sqsum = psqsum[hi] - (lo == 0 ? 0 : psqsum[lo - 1]);

	int avg =  int(0.5 + (double)sum / (hi - lo + 1));
	int ret = avg * avg * (hi - lo + 1) - 2 * avg * sum + sqsum;

	//cout << "hi: " << hi << ", lo :" << lo;
	//cout << ", sum: " << sum << ", sqsum: " << sqsum << ", avg: " << avg << ", ret: " << ret << endl;
	return ret;
}

int Solution(int start, int k)
{
	if (start == N)
		return 0;
	if (k == 0)
		return INF;
	int& ret = cache[start][k];
	if (ret != -1)
		return ret;

	ret = INF;

	for (int kSize = 1; kSize + start <= N; ++kSize)
		ret = min(ret, calcError(start, start + kSize - 1) + Solution(start + kSize, k - 1));
	

	return ret;
}


int main()
{
	int C, temp_in;
	int ans = 0;

	cin >> C;
	while (C--)
	{
		initArr(100, seq);
		initArr(100, psum);
		initArr(100, psqsum);
		initCache();
		cin >> N >> S;
 		for (int i = 0; i < N; ++i)
		{
			cin >> temp_in;
			seq[i] = temp_in;
		}
		preCalc();
		ans = Solution(0, S);
		//printArr(seq);
		//printArr(psum);
		//printArr(psqsum);
		//printCache();
		cout << ans << endl;
	}

	return 0;
}
