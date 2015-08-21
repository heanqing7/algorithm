#include "sort.h"
void insertSort(int array[],int size)
{
	for(int i=1; i<size; ++i)
	{
		int j = 0;
		int tmp = array[i]; //notice
		for(j=i-1; j>=0; --j)
		{
			if(tmp<array[j])
			{
				array[j+1] = array[j];
			}
			else
			{
				array[j+1] = tmp;
				break;
			}
		}
		if(j==-1)  //notice
		{
			array[j+1] = tmp;
		}
	}
}
void selectSort(int array[],int size)
{
	for(int i=0; i<size; ++i)
	{
		int minloc = i;
		for(int j=i+1; j<size; j++)
		{
			if(array[j] < array[minloc])
			{
				minloc = j;
			}
		}
		int tmp = array[i];
		array[i] = array[minloc];
		array[minloc] = tmp;
	}
}
void bubbleSort(int array[],int size)
{
	for(int i=size;i>0;--i)
	{
		bool exchanged = false;
		for(int j=1;j<i;++j)
		{
			if(array[j]<array[j-1])
			{
				int t = array[j];
				array[j] = array[j-1];
				array[j-1] = t;
				exchanged = true;
			}
			else
			{
				continue;
			}
		}
		if(!exchanged)
		{
			break;
		}
		
	}
}
void shellSort(int array[],int size)
{
	for(int gap = size/2; gap>0; gap/=2)
	{
		for(int i=gap;i<size;i++)
		{
			int tmp = array[i];
			int j = 0;
			for(j = i-gap; j>=0;j-=gap)
			{
				if(array[j]>tmp)
				{
					array[j+gap] = array[j];
				}
				else
				{
					array[j+gap] = tmp;	
					break;
				}

			}
			if(j<0)
			{
				array[j+gap] = tmp;

			}

		}
	}	
}

void jishuSort(int array[],int size)
{

}
