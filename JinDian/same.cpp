#include <iostream>
#include <string>
using namespace std;
class Same {
public:
	bool checkSam(string stringA, string stringB) {
		if(stringA.empty()&&stringB.empty())
          {
             return false;
         }
		int hash[53] = {0};
		for(int i=0;i<stringA.size();++i)
		{
			char c = stringA[i];
			if(c==' ')
			{
				++hash[52];
			}
			else if(c<'z'&&c>'a')
			{
				++hash[c-'a'];
			}
			else if(c<'Z'&&c>'A')
			{
				++hash[c-'A'+26];
			}
		}
		for(int i=0;i<stringB.size();++i)
		{
			char c = stringB[i];
			if(c==' ')
			{
				--hash[52];
			}
			else if(c<'z'&&c>'a')
			{
				--hash[c-'a'];
			}
			else if(c<'Z'&&c>'A')
			{
				--hash[c-'A'+26];
			}
		}	
		for(int i=0;i<53;++i)
		{
			if(hash[i]!=0)
				return false;
		}
		return true;
		
	}
};
int main()
{
	Same same;
	cout<<same.checkSam("This is nowcoder","is This nowcoder")<<endl;
	cout<<same.checkSam("Here you are","Are you here")<<endl;
	return 0;
}
