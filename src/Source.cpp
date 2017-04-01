#include <iostream>
#include "TreeNode.h"
#include <algorithm>
#include <vector>


using namespace std;


int maxDifference(vector <int> a)
{
	int minVal = a[0];
	int maxDiff = INT_MIN;

	for (int i = 1; i < a.size(); i++) {
		maxDiff = max(maxDiff, a[i] - minVal);
		minVal = min(minVal, a[i]);
	}
	return maxDiff;

}
int main() {
	
	vector <int> input = { 1000000, -1000000 };
	cout << maxDifference(input) << endl;
	return 0;
}                       