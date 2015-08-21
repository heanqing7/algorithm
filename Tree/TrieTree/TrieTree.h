#ifndef __TRIETREE_H__
#define __TRIETREE_H__
#include <queue>
#include <iostream>
#include <string>
#include <cstdlib>
class TreeNode
{
friend class TrieTree;
public:
	TreeNode(char val='\0');		
	~TreeNode();	
	TreeNode(const TreeNode& node);
private:
	enum constValue
	{
		BRANCH = 26
	};
	char c;
	TreeNode* child[BRANCH];
	int nums;
	TreeNode* parent;
	bool isLevel;
};
TreeNode::TreeNode(char val):c(val),nums(0),parent(NULL)
{
	isLevel = true;
	for(int i=0;i<BRANCH;i++)
	{
		child[i] = NULL;
	}
}
TreeNode::TreeNode(const TreeNode& node):nums(node.nums),parent(node.parent),c(node.c)
{
	for(int i=0;i<BRANCH;i++)
	{
		this->child[i] = node.child[i];
	}	
}
TreeNode::~TreeNode()
{

}


class TrieTree
{
public:
	TrieTree();
	~TrieTree();
	TrieTree(const TrieTree& tt);
	TrieTree& operator=(const TrieTree& tt);
	const TreeNode* getRoot() const
	{
		return this->root;
	}
public:
	void add(const std::string &s);
	void travel(const TreeNode *tree);
	int find(const std::string& str);
private:
	void copyTree();
private:
	TreeNode *root;
	enum constValue
	{
		BRANCH = 26
	};
};
/*
void TrieTree::copyTree(TreeNode* root)
{
	std::queue<TreeNode*> q;	
	q.push_back(root);
	while(!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop_front();
		for(int i=0;i<BRANCH;i++)
		{
			if(tmp->child[i]!=NULL)
			{
				q.push_back(tmp->child[i]);
			}
		}
	}

}
*/
TrieTree::TrieTree():root(new TreeNode())
{

}
TrieTree::~TrieTree()
{
	std::queue<TreeNode*> q;	
	q.push(root);
	while(!q.empty())
	{
		TreeNode* tmp = q.front();
		q.pop();
		for(int i=0;i<BRANCH;i++)
		{
			if(tmp->child[i]!=NULL)
			{
				q.push(tmp->child[i]);
			}
		}
		if(tmp!=NULL)
		{
			delete tmp;
			tmp = NULL;
		}
	}
}
TrieTree::TrieTree(const TrieTree& tt):root(new TreeNode(*tt.root))
{
}
TrieTree& TrieTree::operator=(const TrieTree& tt)
{
/*
	if(this == &tt)
	{
		return *this;
	}
	else
	{
		if(root!=NULL)
		{
			delete root;
			root = NULL;
		}
		root = new TreeNode(*tt.root);
		return *this;
	}
*/
}

void TrieTree::add(const std::string &s)
{
	TreeNode *tmp = root;
	for(int i=0;i<s.size();i++)
	{
		int index = s[i] - 'a';
		if(tmp->child[index]==NULL)
		{
			TreeNode *newNode = new TreeNode(s[i]);
			tmp->child[index] = newNode;		
			tmp->isLevel = false;
			newNode->parent = tmp;
			++newNode->nums;
			tmp = tmp->child[index];
		}
		else
		{
			tmp = tmp->child[index];
		}
	}
	++tmp->nums;	
}
void TrieTree::travel(const TreeNode *root)
{
	if(root!=NULL)
	{
		std::cout<<root->c<<std::endl;
		for(int i=0;i<BRANCH;i++)
		{
			travel(root->child[i]);	
		}

	}

}
int TrieTree::find(const std::string& str)
{
	TreeNode *tmp = root;
	for(int i=0;i<str.size();i++)
	{
		int index = str[i] - 'a';
		if(tmp->child[index]==NULL)
		{
			return 0;
		}
		else if(str[i]==tmp->child[index]->c)
		{
			tmp = tmp->child[index];
		}
	}
	if(tmp->isLevel)
		return tmp->nums;
	else
		return 0;

}
#endif
