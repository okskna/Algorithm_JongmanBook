#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> triangle;
vector<int> row;
int n;
int cache[100][100];

void printTriangle()
{
	for (auto &e : triangle)
	{
		for (auto &ee : e)
			cout << ee << " ";
		cout << endl;
	}
}

void initCache()
{
	for (int i = 0; i < 100; ++i)
		for (int j = 0; j < 100; ++j)
			cache[i][j] = 0;
}

int searchMaxSum(int x, int y)
{
	int& ret = cache[x][y];
	if (x >= n || y >= n)
		return 0;
	if (ret != 0)
		return ret;

	ret = max(searchMaxSum(x, y + 1), searchMaxSum(x + 1, y + 1));

	return ret += triangle[y][x];
}

int main()
{
	int C;
	int temp;
	cin >> C;
	while (C--)
	{
		cin >> n;
		triangle.clear();
		/*memset(cache, 0, sizeof(cache));*/
		initCache();
		for (int i = 0; i < n; ++i)
		{
			row.clear();
			for (int j = 0; j <= i; ++j)
			{
				cin >> temp;
				row.push_back(temp);
			} 
			triangle.push_back(row);
		}

		cout << searchMaxSum(0, 0) << endl;


		//printTriangle();
	}

	
    return 0;
}

