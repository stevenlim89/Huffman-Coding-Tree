#include "HCNode.hpp"

using namespace std;

bool HCNode::operator<(const HCNode& other){
	if(this->count > other.count)
		return true;
	else	
		return false;
}

