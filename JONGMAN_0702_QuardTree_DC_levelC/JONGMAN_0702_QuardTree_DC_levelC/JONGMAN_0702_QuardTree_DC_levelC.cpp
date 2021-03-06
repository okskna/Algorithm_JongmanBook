#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<char> pic;

class picTree
{
public:
	picTree* ppar = nullptr;
	char val = '\0';
	picTree* pson[4] = { nullptr, nullptr, nullptr, nullptr };

};
picTree* makingTree(picTree* preTree)
{
	picTree* myTree = new picTree;

	myTree->val = pic[0];
	myTree->ppar = preTree;
	if (myTree->val == 'b' || myTree->val == 'w')
		return myTree;

	if (myTree->val == 'x')
	{
		for (int i = 0; i < 4; ++i)
		{
			pic.erase(pic.begin());
			myTree->pson[i] = makingTree(myTree);
		}
	}
	return myTree;
}

void printPic()
{
	for (auto &e : pic)
		cout << e << " ";
	cout << endl;

	//cout << pic[0] << " " << pic[1] << " " << pic[2] << " " << pic[3];
}

void printTreeVer(picTree myTree, int depth, int target)
{
	if(depth == target)
		cout << myTree.val << " ";
	if (myTree.pson[0] != nullptr && myTree.val == 'x')
	{
		for (int i = 0; i < 4; ++i)
		{
			printTreeVer(*myTree.pson[i], depth + 1, target);
		}
	}
}

void reversePicPrint(picTree* myTree)
{
	cout << myTree->val;
	if (myTree->val == 'x')
	{
		for (int i = 2; i < 4; ++i)
			reversePicPrint(myTree->pson[i]);
		for (int i = 0; i < 2; ++i)
			reversePicPrint(myTree->pson[i]);
	}
}

//void printTree(picTree myTree)
//{
//	//printPic();
//	cout << myTree.val << " ";
//
//	if (myTree.pson[0] != nullptr && myTree.val == 'x')
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			printTree(*myTree.pson[i]);
//		}
//	}
//}

int main()
{
	int C, Ccnt;
	string temp;
	picTree base;
	cin >> C;
	Ccnt = C;
	while (Ccnt--)
	{
		cin >> temp;
		for (int i = 0; i < temp.size(); ++i)
			pic.push_back(temp[i]);
		base.val = pic[0];
		if (base.val == 'x')
		{
			for (int i = 0; i < 4; ++i)
			{
				//printPic();
				pic.erase(pic.begin());
				base.pson[i] = makingTree(&base);
				//cout << base.pson[i] << endl;
			}
		}
		reversePicPrint(&base);
		cout << endl;

		pic.clear();

		//for (int i = 0; i < 5; ++i)
		//{
		//	printTreeVer(base, 0, i);
		//	cout << endl;
		//}


		//printTree(base);
	}

    return 0;
}

