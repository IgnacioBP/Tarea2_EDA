/*
 * nodo.cpp
 */

#include "lLists/node.hpp"
#include <iostream>
#include <string>

using namespace std;


namespace eda {


Node::Node(): data("HOLDER"), ptrNext(nullptr) {
}

Node::Node(string val, Node* next): data(val), ptrNext(next) {

}

void Node::setData(int _data){
	data = _data;
}

void Node::setNext(Node* next){
	ptrNext = next;
}

string Node::getData(){
	return data;
}
Node* Node::getNext(){
	return ptrNext;
}

void Node::print(){
	std::cout << data ;
}

Node::~Node() {

}

} /* namespace eda */
