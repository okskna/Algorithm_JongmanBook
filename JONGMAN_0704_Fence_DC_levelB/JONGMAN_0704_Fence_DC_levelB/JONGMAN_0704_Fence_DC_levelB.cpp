#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N_arr[20000];
void initArr(int* arr)
{
	for (int i = 0; i < 20000; ++i)
		arr[i] = 0;
}

int cuttingFence(int left, int right)
{
	int ret;
	if (left == right) return N_arr[left];
	int mid = (left + right) / 2;
	ret = max(cuttingFence(left, mid), cuttingFence(mid + 1, right));

	int lo, hi;
	int height;
	lo = mid;
	hi = mid + 1;
	if (N_arr[lo] < N_arr[hi])
		height = N_arr[lo];
	else
		height = N_arr[hi];

	ret = max(ret, height * 2);

	while (left < lo || hi < right)
	{
		if (hi < right && (left == lo || N_arr[lo - 1] < N_arr[hi + 1]))
		{
			hi++;
			height = min(height, N_arr[hi]);
		}
		else
		{
			lo--;
			height = min(height, N_arr[lo]);
		}
		ret = max(ret, (hi - lo + 1) * height);
	}
	return ret;
}

int main()
{
	int C, Ccnt;
	int N;

	cin >> C;
	Ccnt = C;

	while (Ccnt--)
	{
		initArr(N_arr);
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> N_arr[i];

		cout << cuttingFence(0, N - 1) << endl;;
	}



    return 0;
}

