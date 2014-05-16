// ---------------------------------------------------------------------------
// Filename: HCTree.cpp
// Authors: Steven Lim, Sharon Zheng
// Date: 5/5/2014
// Rev-Date: 5/16/2014
// Description: Implements the Huffman Coding Tree algorithm by pushing the 
// 		nodes into a priority queue and combining those of the lowest
// 		counts repeatedly. This tree allows for an efficient search
// 		of encoding and decoding.
// Acknowledgements: Thank you, tutors!
// ---------------------------------------------------------------------------

#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include <vector>
#include <queue>
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

using namespace std;

/** Helper method to delete the nodes */
void delete_HCNodes(HCNode* root){
	//set the node to the node passed in
    	HCNode *tempNode = root;
	if(tempNode == NULL)
		return;
	//recursively deletes it
	delete_HCNodes(tempNode->c0);
	delete_HCNodes(tempNode->c1);


	delete tempNode;
}

//HCTree destructor that deletes all nodes
HCTree::~HCTree(){
	delete_HCNodes(root);
}

// --------------------------------------------------------------------------
// void HCTree::build(const vector<int>& freqs): Uses the Huffman algorithm 
// build a Huffman coding trie by passing in a vector of integers such that
// freq[i] is the frequency of the occurrence of byte i in the message.
// Input: const vector<int>& freqs)-vector of ints
// Output: <none>
// --------------------------------------------------------------------------
void HCTree::build(const vector<int>& freqs)
{
	//creates a priority queue to store a vector of nodes
	priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> node_pq;

	//loops through the vector of frequencies		
	for( int num =0 ; num < freqs.size(); num++){
		if(freqs[num] != 0){
			//creates a node if the there is a frequency
			HCTree::leaves[num] = new HCNode(freqs[num], num, 0, 0, 0);				if((unsigned int)leaves[num]->symbol != 0){
				//pushes on to the priority queue
				node_pq.push(leaves[num]);
			}
		}
	}
	
	//creates the tree and
	while(node_pq.size() != 0){
		//checks if there's only one node left in the priority queue
		if(node_pq.size() == 1){
			//sets the root for the last node
			HCTree::root = node_pq.top();
			//sets parent pointer
			HCTree::root->p = 0;
			//pops the last node
			node_pq.pop();
			return;
		}
		else{	
			//obtains the first two node in the priority queue	
			HCNode * low1 = node_pq.top();
			node_pq.pop();
			HCNode * low2 = node_pq.top();
			node_pq.pop();

			//adds the two counts and creates a new parent node
			//and connects the pointers
			int sum = low1->count + low2->count;
			HCNode * combined = new HCNode(sum, 0, low1, low2, 0);
			low1->p = combined;
			low2->p = combined;

			//pushes the pointer back into the priority queue
			node_pq.push(combined);
		}
	}


	return;

}

// --------------------------------------------------------------------------
// void HCTree::encode(byte symbol, BitOutputStream& out) const: Writes to 
// the given BitOutputStream in the sequence of bits coding the given symbol.
// Input: byte symbol-the symbol to encode
// 	  BitOutputStream& out-the BitOutputStream file that is being written
// Output: <none>
// --------------------------------------------------------------------------
void HCTree::encode(byte symbol, BitOutputStream& out) const
{	
	//vector to store the binary conversion
	vector<unsigned int> bitStack;
	//set the temp node to the symbol of the leaves
	HCNode * temp_node = HCTree::leaves[symbol];
	
	//check if temp node is null or if it's the root
	if(temp_node == nullptr)
		return;
	if(temp_node == HCTree::root){
		return;
	}
	else{	
		//loops while it's not the root
		while(temp_node->p != 0){
			//checks if the node is on the left or right 
			//and push the number into the vector
			if(temp_node == temp_node->p->c0){
				bitStack.push_back(0);
			}
			if(temp_node == temp_node->p->c1){
				bitStack.push_back(1);	
			}
	
			temp_node = temp_node->p;

		}
	
		//rewrites the vector backwards to store the bits correctly
		while(!bitStack.empty()){	
			if(bitStack.back() == 0){
				out.BitOutputStream::writeBit(0);
				bitStack.pop_back();
			}
			else if(bitStack.back() == 1){
				out.BitOutputStream::writeBit(1);
				bitStack.pop_back();
			}

		}
	}

}

// --------------------------------------------------------------------------
// int HCTree::decode(BitInputStream& in) const: Returns the symbol coded in
// the next sequence of bits from the stream.
// Input: BitInputStream& in-the BitInputStream file that is being read and
// decoded
// Output: returns an integer value of the symbol stored in the node
// --------------------------------------------------------------------------
int HCTree::decode(BitInputStream& in) const
{
    	//sets the tempnode to the root
	HCNode *tempNode = HCTree::root; 
    	int num = 0; 	
	
	//continuously loops until it reaches the leave with no children
	while(tempNode->c0 != 0 && tempNode->c1 != 0){
		//reads the bit
		num = in.BitInputStream::readBit();

		if(num == -1)
		{
			return -1;
		}

		if(num == 0){
          		tempNode = tempNode->c0;
       		}

        	if(num == 1){
        		tempNode = tempNode->c1;
		} 
		
    	}
	
	//returns the node symbol
	return (int)(tempNode->symbol); 
}
