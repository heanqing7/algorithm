#include <iostream>
#include <vector>
using namespace std;
class Clearer {
public:
vector<vector<int> > clearZero(vector<vector<int> > mat, int n) {
        // write code here
	vector<int> zeroRow;	
	vector<int> zeroCol;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j] == 0)
			{
				zeroRow.push_back(i);
				zeroCol.push_back(j);

			}
		}
	}
	for(int i=0;i<zeroRow.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[zeroRow[i]][j] = 0;
		}	
	}
	for(int i=0;i<zeroCol.size();i++)
	{
		for(int j=0;j<n;j++)
		{
			mat[j][zeroCol[i]] = 0;
		}	
	}
	return mat;
}
};
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	vector<int> v2;
	v2.push_back(0);
	v2.push_back(1);
	v2.push_back(2);
	vector<int> v3;
	v3.push_back(0);
	v3.push_back(0);
	v3.push_back(1);
	vector<vector<int> > vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	Clearer c;
	vector<vector<int> > result = c.clearZero(vv,3);
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<result[i][j]<<",";
		}
		cout<<endl;
	}
	return 0;
}
