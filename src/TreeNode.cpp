#include "TreeNode.h"
#include <iostream>
#include <algorithm>

using namespace std;


TreeNode::TreeNode(int x)
{
	data = x;
	left = NULL;
	right = NULL;
}

void TreeNode::InOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	cout << root->data<<" ";
	InOrder(root->right);
}

void TreeNode::PreOrder(TreeNode* root)
{	
	if (root == NULL)
		return;

	cout << root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void TreeNode::PostOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data<<" ";

}

int TreeNode::findDepth(TreeNode *root)
{
	if (root == NULL) return 0;                   	
	return max(1 + findDepth(root->left), 1 + findDepth(root->right));
}



