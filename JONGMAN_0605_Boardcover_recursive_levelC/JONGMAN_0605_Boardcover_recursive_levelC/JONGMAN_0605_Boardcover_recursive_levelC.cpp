#include <iostream>
using namespace std;
int H, W;

//bool isFull(bool HW[20][20])
//{
//	for (int h = 0; h < H; h++)
//		for (int w = 0; w < W; ++w)
//			if (HW[h][w] == 0)
//				return false;
//	return true;
//}

int boardCover(int h_in, int w_in, bool HW[20][20])
{
	int ret = 0;
	int h_first = -1, w_first = -1;

	if (h_in < 1 || w_in < 1)
		return 0;

	for (int h = 0; h < H; h++)
		for (int w = 0; w < W; ++w)
			if (HW[h][w] == 0)
			{
				h_first = h;
				w_first = w;
			}


	if (h_first == -1 && w_first == -1)
		return 1;

	for(int h = h_first; h < H; ++h)
		for (int w = w_first; w < W; ++w)
		{
			if (HW[h][w] == 0 && HW[h - 1][w] == 0 && HW[h][w - 1] == 0)
			{
				HW[h][w] = HW[h - 1][w] = HW[h][w - 1] = 1;
				ret += boardCover(h, w, HW);
				HW[h][w] = HW[h - 1][w] = HW[h][w - 1] = 0;
			}
			if (HW[h - 1][w] == 0 && HW[h][w - 1] == 0 && HW[h - 1][w - 1] == 0)
			{
				HW[h - 1][w] = HW[h][w - 1] = HW[h - 1][w - 1] = 1;
				ret += boardCover(h, w, HW);
				HW[h - 1][w] = HW[h][w - 1] = HW[h - 1][w - 1] = 0;
			}
			if (HW[h][w - 1] == 0 && HW[h - 1][w - 1] == 0 && HW[h][w] == 0)
			{
				HW[h][w - 1] = HW[h - 1][w - 1] = HW[h][w] = 1;
				ret += boardCover(h, w, HW);
				HW[h][w - 1] = HW[h - 1][w - 1] = HW[h][w] = 0;
			}
			if (HW[h - 1][w - 1] == 0 && HW[h][w] == 0 && HW[h - 1][w] == 0)
			{
				HW[h - 1][w - 1] = HW[h][w] = HW[h - 1][w] = 1;
				ret += boardCover(h, w, HW);
				HW[h - 1][w - 1] = HW[h][w] = HW[h - 1][w] = 0;
			}
		}

	return ret;
}

int main()
{
	int C, Ccnt;
	int blank;
	char pattern;
	bool HW[20][20];

	cin >> C;
	Ccnt = C;
	while (Ccnt--)
	{
		cin >> H >> W;
		blank = 0;
		for (int h = 0; h < 20; ++h)
			for (int w = 0; w < 20; ++w)
				HW[h][w] = 0;
		for(int h = 0; h < H; ++h)
			for (int w = 0; w < W; ++w)
			{
				cin >> pattern;
				if (pattern == '#')
					HW[h][w] = 1;
				else if (pattern == '.')
				{
					blank++;
					HW[h][w] = 0;
				}
			}
		if (blank % 3 == 0 && blank != 0)
			cout << boardCover(1, 1, HW) << endl;
		else
			cout << 0 << endl;
	}


    return 0;
}