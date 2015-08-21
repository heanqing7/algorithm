#include <iostream>
#include "sort.h"
using namespace std;
void print(int i)
{
	cout<<i<<endl;
}
void for_each(int array[],int start,int end,void (*func)(int))
{
	for(int i=start;i<end;++i)
	{
		func(array[i]);
	}
}
int main()
{
	int array[] = {6,5,4,3,2,8,7,1,9,0};
	//insertSort(array,10);
	//selectSort(array,10);
	//bubbleSort(array,10);
	shellSort(array,10);
	for_each(array,0,10,print);	
	return 0;
}
