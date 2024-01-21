#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

void checkExpression(std::string rpn);
int evaluateRPN(const std::string& expression);

#endif