#include <iostream>
#include <vector>
#include <string>

using namespace std;
int cache[101][101];

string & W;
string & S;

bool match(int w, int s)
{
	int & ref = cache[w][s];
	while ((W[w] == S[s] || W[w] == '?') && W.size() > w && S.size() > s)
	{
		w++; s++;
	}
	if(ref)



}


int main()
{
	int C, N_in;
	string W_in;
	string S_in;
	vector<int> N_vec;
	vector<string> W_vec, S_vec;

	cin >> C;
	int C_cnt = C;
	while (C_cnt--)
	{
		cin >> W_in;
		W_vec.push_back(W_in);
		cin >> N_in;
		N_vec.push_back(N_in);

		for (int n = 0; n < N_in; ++n)
		{
			cin >> S_in;
			S_vec.push_back(S_in);
		}

	}
	int temp = 0;
	for (int w = 0; w < W_vec.size(); ++w)
	{
		for (int s = temp; s < temp + N_vec[w]; ++s)
		{
			W = W_vec[w];
			S = S_vec[s];
			if (match())
				cout << S_vec[s] << endl;
		}
		temp += N_vec[w];
	}
	


	return 0;
}






































///////////////////////////////////////
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//
//bool match(const string & W, const string & S)
//{
//	int pos = 0; //position
//	while ((W[pos] == S[pos] || W[pos] == '?') && W.length() > pos && S.length() > pos)
//		pos++;
//	if (pos == W.length())
//		return pos == S.length();
//	if (W[pos] == '*')
//	{
//		for (int skip = 0; pos + skip <= S.length(); ++skip)
//		{
//			if (match(W.substr(pos + 1), S.substr(pos + skip)))
//				return true;
//		}
//	}
//	return false;
//}
//
//void sort2Dict(vector<string> & myVec)
//{
//	string temp;
//	for (int i = 0; i < myVec.size(); ++i)
//	{
//		for (int j = i; j < myVec.size(); ++j)
//		{
//			//cout << myVec[i] << " vs " << myVec[j] << endl;
//			if (myVec[i].compare(myVec[j]) > 0)
//			{
//				temp = myVec[i];
//				myVec[i] = myVec[j];
//				myVec[j] = temp;
//			}
//		}
//	}
//}
//
//void printVec(const vector<string> &myVec)
//{
//	for (int i = 0; i < myVec.size(); ++i)
//		cout << myVec[i] << " ";
//	cout << endl;
//}
//
//int main()
//{
//	int C, N_in;
//	string W_in;
//	string S_in;
//	vector<int> N_vec;
//	vector<string> W_vec, S_vec;
//
//	cin >> C;
//	int C_cnt = C;
//	while (C_cnt--)
//	{
//		cin >> W_in;
//		W_vec.push_back(W_in);
//		cin >> N_in;
//		N_vec.push_back(N_in);
//
//		for (int n = 0; n < N_in; ++n)
//		{
//			cin >> S_in;
//			S_vec.push_back(S_in);
//		}
//
//	}
//	int temp = 0;
//	for (int w = 0; w < W_vec.size(); ++w)
//	{
//		for (int s = temp; s < temp + N_vec[w]; ++s)
//		{
//			if (match(W_vec[w], S_vec[s]))
//				cout << S_vec[s] << endl;
//		}
//		temp += N_vec[w];
//	}
//	
//
//
//	return 0;
//}
