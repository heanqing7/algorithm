#include <iostream>
#include <sstream>
using namespace std;
class Zipper {
public:
	string zipString(string iniString) {
        // write code here
		int nums = 1;
		int val = iniString[0];
		string str;
		for(int i=1;i<iniString.size();i++)
		{
			if(iniString[i]!=val)
			{
				str+=val;
				//notice !!!!!! if nums > 10
				str+=itoa(nums);	
				val = iniString[i];
				nums = 1;
			}	
			else
			{
				nums++;
			}
		}
		//!!!!!!!!!!!!!!!!!!!!!!!!
		str+=val;
		//notice !!!!!! if nums > 10
		str+=itoa(nums);		
		if(str.size()<iniString.size())
			return str;
		else
			return iniString;
	}
	string itoa(int i)
	{
		stringstream ss;
		ss<<i;
		string result;
		ss>>result;
		return result;
	}
};
int main()
{
	Zipper z;
	cout<<z.zipString("jjjjjjxxxxxxxooZLLLLLLLLQQQQQQQQQLLLLLLLLECXXXXXXXIIIIIIIIIhjjyyySSooooooooommmuuEEEEEEEEEnnnnnnnffffffAAAAAllllllllbbbbkkkkkkkkkkkkKKKKKKhhhhhhhhhooooooooooYCCCCCCOOOOOOOOOMMMMMMMMMMiiiiiivvvvvvvWWWWkkkkkkwwwwwwwMmmmmmmmmLLLwwwwwwwkkkjjjjjjttttQQQQQQQQQaaaaaaaFFFFFFFlllllllllggggggggggPPPPPPuuuuuuuuaYYYYYYwQQQFFFFFFFFFFaaaaapXXXXXXXxxxxxxQQQQQQQQQsssssGGGGfffffffddddddpppQQQQQQHHHTTTaaaaaaGGGGGGddyyyyyMhhllllllllllNNNNNNNNUUUWWWWWWLLLLLLLLLYYYYYYYYYYTTKKKKKKKKiiiiiiitttttttXXXXXXXXXLLLHZZZZZZZssssjjJJJEEEEEOOOOOttttttttttBBttttttTTTTTTTTTTrrrrttttRRRRRyyooooooaaaaaaaaarrrrrrrPPPPPPPjjPPPPddddddddddHHHHnnnnnnnnnnSSSSSSSSSSzzHHHHHHHHHddddddDDDzzzhhhhhfffffffffftttttteeeeeeeeEEEEEEEEEaaaaaaccccccccccFFFFFFFF")<<endl;	
	return 0;
}
