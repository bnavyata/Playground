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

bool precedence(char a, char b)
{
	// if top has higher precedence than current then solve it then add current
	if ((a == '*' || a == '/') && (b == '+' || b == '-'))
		return false;
	if (b == '(')
		return false;
	else
		return true;
}

double convertToNumber(char c) {
	return c - '0';
}

bool isNumber(char c)
{
	if (c >= '0' && c <= '9')
		return true;
	return false;
}

vector<string> split_string(string s) {
	vector<string> result;
	stringstream ss(s);
	string buffer;
	while (ss >> buffer)
		result.push_back(buffer);
	return result;
}

double evaluate(char op, double arg1, double arg2)
{
	switch (op)
	{
	case '+':
		return arg1 + arg2;
		break;
	case '-':
		return arg1 - arg2;
		break;
	case '*':
		return arg1 * arg2;
		break;
	case '/':
	{
		if (arg2 == 0)
			cout << " Error, attemp to divide by 0";
		else
			return arg2 / arg1;
		break;
	}

	default:
		break;

	}
}

double calculate(string s)
{
	stack<double> operands;
	stack<char> operators;
	vector<string> input = split_string(s);
	for (int i = 0; i < input.size(); i++)
	{
		char c = input[i].c_str()[0];
		if (isNumber(c)) {
			operands.push(convertToNumber(c));
		}
		else if (c == '(')
			operators.push(c);
		else if (c == ')')
		{
			while (operators.top() != '(')
			{
				double operand1 = operands.top();
				operands.pop();
				double operand2 = operands.top();
				char op = operators.top();
				double result = evaluate(op, operand1, operand2);
				operands.pop();
				operands.push(result);
				operators.pop();
			}
			operators.pop();
		}
		else if(c == '+' || c == '-' || c == '*' || c == '/')
		{
			while (!operators.empty() && precedence(c, operators.top())) {
				double operand1 = operands.top();
				operands.pop();
				double operand2 = operands.top();
				char op = operators.top();
				operators.pop();
				double result = evaluate(op, operand2, operand1);
				operands.pop();
				operands.push(result);
			}
			operators.push(c);
		}
	}
	while (!operators.empty()) {
		double operand1 = operands.top();
		operands.pop();
		double operand2 = operands.top();
		char op = operators.top();
		operators.pop();
		double result = evaluate(op, operand2, operand1);
		operands.pop();
		operands.push(result);
	}
	return operands.top();
}

int main()
{
	string s = "3 + ( 5 * 4 / 2 ) - 1";
	double result = calculate(s);
	cout << result << endl;
	return 0;
}