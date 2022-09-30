/*
 * stack.hpp
 *
 *  Created on: Aug 18, 2022
 *      Author: jsaavedr
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include "lLists/node.hpp"
#include <iostream>
#include <string>

using namespace std;

namespace eda {

class Stack {
private:
	Node* head;
public:
	Stack();
	void push(string val);
	void push(Node* node);
	void pop();
	Node* top();
	bool isEmpty();
	void clear();
	virtual ~Stack();
};

} /* namespace eda */

#endif /* STACK_HPP_ */
