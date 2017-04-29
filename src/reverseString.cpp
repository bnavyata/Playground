#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

stack<int> myStack;
stack<int> myMinStack;

void reverse(string &str) {
	char temp;
	int length = str.length();
	for (int i = 0; i < length/2; i++){
		temp = str[i];
		int offset = length - i - 1;
		str[i] = str[offset];
		str[offset]= temp;
	}
}

int main() {
	char * str = "NavyataBawa";
	string s = str;
	reverse(s);
	return 0;
}