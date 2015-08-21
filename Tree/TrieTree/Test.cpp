#include <iostream>
#include "TrieTree.h"
using namespace std;
int main()
{	
	TrieTree tree;
	tree.add("helloworld");	
	tree.add("helloworld");	
	tree.add("helloworld");	
	tree.add("helloshanpao");	
	tree.add("helloshanpao");	
	tree.add("hellosb");	
	tree.add("hellosb");	
	tree.add("abcd");	
	tree.add("abcd");	
	tree.add("a");	
	//tree.travel(tree.getRoot());
	cout<<"hellosb"<<tree.find("hellosb")<<endl;
	cout<<"helloworld"<<tree.find("helloworld")<<endl;
	cout<<"helloshanpao"<<tree.find("helloshanpao")<<endl;
	cout<<"helloduzi"<<tree.find("helloduzi")<<endl;
	cout<<"abc"<<tree.find("abc")<<endl;
	cout<<"abcd"<<tree.find("abcd")<<endl;
	return 0;
}
