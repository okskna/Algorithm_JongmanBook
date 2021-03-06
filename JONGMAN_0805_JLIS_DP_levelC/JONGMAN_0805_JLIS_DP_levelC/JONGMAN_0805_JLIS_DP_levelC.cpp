#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const long long NEGINF = numeric_limits<long long>::min();
vector<long long> A;
vector<long long> B;
int n, m;
int cache[101][101];

//1. 완전탐색
//2. 부분 문제 정의
//3. 중복 문제 최대화
//4. 메모이제이션 적용(불가능 할 경우 변환유도)

void initCache()
{

	for (int i = 0; i < 101; ++i)
		for(int j = 0 ; j < 101; ++j)
			cache[i][j] = -1;
}

void printCache()
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			cout.width(3);
			cout << cache[i][j] << " ";
		}
		cout << endl;
	}
}

int JLIS(int idxA, int idxB)
{
	int& ret = cache[idxA+1][idxB+1];
	if (ret != -1)
	{
		//cout << "idxA: " << idxA << ", idxB: " << idxB << endl << "ret" << endl;
		return ret;
	}
	ret = 2;

	long long a = (idxA == -1) ? NEGINF : A[idxA];
	long long b = (idxB == -1) ? NEGINF : B[idxB];
	long long ele = max(a, b);

	//cout << "idxA: " << idxA << ", idxB: " << idxB << ", ele: " << ele << ", ret: " << ret << endl;
	//printCache();
	//cout << endl;

	for (int nextA = idxA + 1; nextA < n; ++nextA)
		if (ele < A[nextA])
		{
			//cout << "In A: " << idxA << " " << idxB << " " << nextA << " " << ele << " " << ret << endl;
			ret = max(JLIS(nextA, idxB) + 1, ret);
			//printCache();
			//cout << endl;
		}
	for(int nextB = idxB + 1; nextB < m; ++nextB)
		if (ele < B[nextB])
		{
			//cout << "In B: " << idxA << " " << idxB << " " << nextB << " " << ele << " " << ret << endl;
			ret = max(JLIS(idxA, nextB) + 1, ret);
			//printCache();
			//cout << endl;
		}
	return ret;
}


//int LIS(int start, const vector<int> seq)
//{
//	int& ret = cache[start];
//	if (ret != -1)
//		return ret;
//
//	ret = 1;
//
//	for (int i = 0; i < n; ++i)
//	{
//		if (seq[i] > seq[start])
//			ret = max(LIS(i, seq) + 1, ret);
//	}
//	return ret;
//}

int main()
{
	int C;
	int temp_in;
	cin >> C;
	while (C--)
	{
		int ans = 0;
		cin >> n >> m;
		initCache();
		A.clear();
		B.clear();
		for (int i = 0; i < n; ++i)
		{
			cin >> temp_in;
			A.push_back(temp_in);
		}
		for (int i = 0; i < m; ++i)
		{
			cin >> temp_in;
			B.push_back(temp_in);
		}

		ans = JLIS(-1, -1);
		//ans = LIS(0, A);
		//ans = Solution();
		cout << ans - 2 << endl;
	}
    return 0;
}

