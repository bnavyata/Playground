#pragma once
#include <iostream>

class TreeNode
{
public:

	int data;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x);

	static void InOrder(TreeNode *root);
	static void PreOrder(TreeNode* root);
	static void PostOrder(TreeNode *root);

	static int findDepth(TreeNode *root);
};