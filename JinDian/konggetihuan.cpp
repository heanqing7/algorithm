#include <iostream>
using namespace std;
class Solution {
public:
	string replaceSpace(string iniString, int length) {
        // write code here
		int spaceNum = 0;
		for(int i=0;i<iniString.size();++i)
		{
			if(iniString[i]==' ')
			{
				++spaceNum;
			}
		}
		string str;
		for(int i=0;i<iniString.size();++i)
		{
			if(iniString[i]==' ')
			{
				str+="%20";
				
			}
			else
			{
				str+=iniString[i];
			}
		}
		return str;
		
	}
};
int main()
{
	Solution s;
	cout<<s.replaceSpace("Mr John Smith",13);

	return 0;
}
