#include <iostream>
#include <vector>
using namespace std;
class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		transform(mat,0,n-1);	
		return mat;
	}
	void transform(vector<vector<int> > &mat,int start,int n)
	{
		if(start>=n)
		{
			return;
		}
		vector<int> tmp;
		vector<int> tmp2;
		//save 1;
		for(int i=start;i<=n;++i)
		{
			tmp.push_back(mat[start][i]);
		}
		//save 2;
		for(int i=start;i<=n;++i)
		{
			tmp2.push_back(mat[i][n]);
		}
		//4->1
		for(int i=start;i<=n;i++)
		{
			mat[start][n-i] = mat[i][start];
		}
		//3->4
		for(int i=start;i<=n;i++)
		{
			mat[i][start] = mat[n][i];
		}
		//tmp2->3
		for(int i=start;i<=n;i++)
		{
			mat[n][n-i] = tmp2[i];
		}
		// tmp->2
		for(int i=start;i<=n;++i)
		{
			mat[i][n] = tmp[i];
		}
		transform(mat,start+1,n-1);
		
	}
	

};
int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	vector<int> v2;
	v2.push_back(4);
	v2.push_back(5);
	v2.push_back(6);
	vector<int> v3;
	v3.push_back(7);
	v3.push_back(8);
	v3.push_back(9);
	vector<vector<int> > vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	Transform tr;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<vv[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;
	vector<vector<int> > result = tr.transformImage(vv,3);
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
