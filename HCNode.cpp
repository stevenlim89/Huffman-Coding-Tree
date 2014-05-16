// ---------------------------------------------------------------------------
// Filename: HCNode.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Creates a node that contains the frequency count, symbol, the
// 		parent pointer, and the two children pointers. The nodes are 
// 		then implemented in the Huffman Tree algorithm.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------
#include "HCNode.hpp"

using namespace std;

// --------------------------------------------------------------------------
// bool HCNode::operator<(const HCNode& other): Overwrites the less-than 
// comparison. Reorganizes the std::priority_queue so that small counts will
// have a higher priority and it will break ties.
// Input: const HCNode& other
// Output: bool true or false
// --------------------------------------------------------------------------
bool HCNode::operator<(const HCNode& other){
	if(this->count != other.count)
		return count> other.count;
	else	
		return symbol<other.symbol;
}

