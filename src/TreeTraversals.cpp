#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

int findHeight(TreeNode* root) {
	return (!root ? 0 : (1 + max(findHeight(root->left), findHeight(root->right))));
}

void printLevelOrder(TreeNode* root,int level) {
	if (level == 1)
		cout << root->val;
	else {
		printLevelOrder(root->left, level - 1);
		printLevelOrder(root->right, level - 1);
	}
}

void InOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	InOrder(root->left);
	cout << root->val << " ";
	InOrder(root->right);
}

void PreOrder(TreeNode* root)
{
	if (root == NULL)
		return;

	cout << root->val << " ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(TreeNode *root)
{
	if (root == NULL)
		return;

	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->val << " ";

}
int main() {
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	int height = findHeight(root);
	cout << height << endl;
	for (int i = 1; i <= height; i++)
		printLevelOrder(root, i);	
	return 0;

}