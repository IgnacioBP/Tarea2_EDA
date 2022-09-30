/*
 * node.hpp
 *
 */

#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>
#include <string>

using namespace std;

namespace eda {

class Node {
private:
	string data;
	Node* ptrNext;
public:
	Node();
	Node(string _data, Node* next = nullptr);
	void setData(int _data);
	void setNext(Node* _next);
	string getData();
	Node* getNext();
	void print();
	virtual ~Node();
};

} /* namespace eda */

#endif /* NODE_HPP_ */
