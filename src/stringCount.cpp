#include <iostream>
#include <string>
#include <map>
using namespace std;


// input: aaaabbcddddeeffff
// output: a4b2c1d4e2f4


string stringCodify(string str) {
	int i = 0;
	int count;
	string result;
	for (int i = 0; i < str.length();)
	{
		char temp = str[i];
		result.push_back(temp);
		count = 0;
		while (str[i] == temp) {
			count++;
			i++;
		}
		
		result.append(to_string(count));
	}
	return result;
}


int main() {

	string str = "aaaabbcddddeeffffaaa";
	string result = stringCodify(str);
	cout << result << endl;

	return 0;
}