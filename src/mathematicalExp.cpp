#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool precedenceGreater(char op1, char op2) {
	if (op1 == '*' && op2 == '+')
		return true;
	return false;
}

int eval(int val1, int val2, char op) {
	return op == '+' ? (val1 + val2) : (val1*val2);
}
int main() {
	string s;
	cin >> s;
	size_t sz;
	stack<int> numberStack;
	stack<char> operatorStack;
	string temp;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*' || s[i] == '+') {
			int numVal = stoi(temp, &sz);
			numberStack.push(numVal);
			temp = "";
			if (operatorStack.empty()) {
				operatorStack.push(s[i]);
			}
			else {
				char op = operatorStack.top();
				while (!precedenceGreater(s[i], op) && (operatorStack.size()!=0))//returns true if s[i[] is higher precendence
				{
					int val1 = numberStack.top();
					numberStack.pop();
					int val2 = numberStack.top();
					numberStack.pop();
					char tempOp = operatorStack.top();
					operatorStack.pop();
					int result = eval(val1, val2, tempOp);
					numberStack.push(result);					
				}
				operatorStack.push(s[i]);
			}
		}
		else {
			temp += s[i];
		}
	}
	int numVal = stoi(temp, &sz);
	numberStack.push(numVal);

	while(!operatorStack.empty()){
		int val1 = numberStack.top();
		numberStack.pop();
		int val2 = numberStack.top();
		numberStack.pop();
		char op1 = operatorStack.top();
		operatorStack.pop();
		int result = eval(val1, val2, op1);
		numberStack.push(result);
	}
	cout << numberStack.top();
	return 0;
}