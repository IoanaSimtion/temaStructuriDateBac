#pragma once

#include <iostream>

using namespace std;


template<typename N>
struct Node {

	N data;

	Node<N>* next;

};