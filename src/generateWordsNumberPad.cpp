#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <locale>
#include <iostream>
#include <map>
#include <sstream>
#include <stdlib.h>
#include <climits>
using namespace std;

const char hashTable[10][5] = { "", "", "abc", "def", "ghi", "jkl",
"mno", "pqrs", "tuv", "wxyz" };

void  printWordsUtil(vector<int> number, int curr_digit, string output, int n)
{
	int i;
	if (curr_digit == n)
	{
		cout << output;
		return;
	}

	for (i = 0; i<strlen(hashTable[number[curr_digit]]); i++)
	{
		output[curr_digit] = hashTable[number[curr_digit]][i];
		printWordsUtil(number, curr_digit + 1, output, n);
	}
}

void printWords(vector<int> number, int n)
{
	string result;
	result.resize(n + 1);
	printWordsUtil(number, 0, result, n);
}

int main()
{
	vector <int> number = { 2, 3, 4 };
	int n = number.size();
	printWords(number, n);
	return 0;
}