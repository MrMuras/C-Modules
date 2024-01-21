#include "RPN.hpp"

void checkExpression(std::string rpn){
	int digitcounter = 0, operationcounter = 0;
	for(size_t i = 0; i <rpn.size(); i ++){
		if(i % 2 == 1){
			if(rpn[i] != ' ')
				throw std::runtime_error("No spaces beetwen");
		}
		else
			if(!isdigit(rpn[i]) && rpn[i] != '*' && rpn[i] != '/' && rpn[i] != '-' && rpn[i] != '+')
				throw std::runtime_error("You entered characters that are not allowed");
			if(isdigit(rpn[i]))
				digitcounter ++;
			if(rpn[i] == '*' || rpn[i] == '/' || rpn[i] == '-' || rpn[i] == '+')
				operationcounter ++;
			if(i == 2 && !isdigit(rpn[i]))
				throw std::runtime_error("First you need to provide two opperands");
	}
	if(digitcounter - operationcounter != 1)
		throw std::runtime_error("Digits - operators != 1");
}

int evaluateRPN(const std::string& expression) {
	std::stack<int> operandStack;
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token) {
		if (isdigit(token[0])) {
			operandStack.push(std::stoi(token));
		} else {
			int operand2 = operandStack.top(); operandStack.pop();
			int operand1 = operandStack.top(); operandStack.pop();
			if (token == "+") operandStack.push(operand1 + operand2);
			else if (token == "-") operandStack.push(operand1 - operand2);
			else if (token == "*") operandStack.push(operand1 * operand2);
			else if (token == "/") operandStack.push(operand1 / operand2);
		}
	}
	return operandStack.top();
}