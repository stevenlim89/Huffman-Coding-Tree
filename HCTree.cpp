//------------------------------------------------
// Filename: HCTree.cpp
// Author: Steven Lim <stl054>, Sharon Zheng <s5zheng>
// Date: 15 May 2014
// Rev-Date: 15 May 2014
// Description: 
// numbers.
//
// Acknowledgements: Thanks to Ben for helping me
// understand iterative loops.
//------------------------------------------------
//
#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include <vector>
#include <queue>
#include "BitInputStream.hpp"
#include "BitOutputStream.hpp"

using namespace std;

void delete_HCNodes(HCNode* root){
	
    	HCNode *tempNode = root;
	if(tempNode == NULL)
		return;

	delete_HCNodes(tempNode->c0);
	delete_HCNodes(tempNode->c1);


	delete tempNode;
}

HCTree::~HCTree(){
	delete_HCNodes(root);
}


void HCTree::build(const vector<int>& freqs)
{
	vector<unsigned int> list_ascii;
	vector<unsigned int> list_freq;
	vector<HCNode*> list_node;
	priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> node_pq;

	//loops through the frequency to create single nodes		
	for( int num =0 ; num < freqs.size(); num++){
		if(freqs[num] != 0){
			HCTree::leaves[num] = new HCNode(freqs[num], num, 0, 0, 0);				
			if((unsigned int)leaves[num]->symbol != 0){
				node_pq.push(leaves[num]);
			}
		}
	}
	//creates the tree
	while(node_pq.size() != 0){
		if(node_pq.size() == 1){
			HCTree::root = node_pq.top();
			HCTree::root->p = 0;
			node_pq.pop();
			return;
		}
		else{	
			HCNode * low1 = node_pq.top();
			node_pq.pop();
			HCNode * low2 = node_pq.top();
			node_pq.pop();
			int sum = low1->count + low2->count;
			HCNode * combined = new HCNode(sum, 0, low1, low2, 0);
			low1->p = combined;
			low2->p = combined;
			node_pq.push(combined);
		}
	}


	return;

}


void HCTree::encode(byte symbol, BitOutputStream& out) const
{
	vector<unsigned int> bitStack;
	int count = 0;	
	HCNode * temp_node = HCTree::leaves[symbol];
	if(temp_node == nullptr)
		return;
	if(temp_node == HCTree::root){
		return;
	}
	else{
		while(temp_node->p != 0){
			if(temp_node == temp_node->p->c0){
				bitStack.push_back(0);
				count++;	
			}
			if(temp_node == temp_node->p->c1){
				bitStack.push_back(1);	
				count++;	
			}
	
			temp_node = temp_node->p;

		}
	
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

int HCTree::decode(BitInputStream& in) const
{
	vector<unsigned int> freqV; 
    	HCNode *tempNode = HCTree::root; 
    	int num = 0; 	
	while(tempNode->c0 != 0 && tempNode->c1 != 0){
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

	return tempNode->symbol; 
}



/*void HCTree::encode(byte symbol, ofstream& out) const
{

	vector<int> binary_num;
	HCNode * temp_node = HCTree::leaves[symbol];
	if(temp_node == nullptr)
		return;
	if(temp_node == HCTree::root){
		out<<0<<endl;
		return;
	}
	else{
		while(temp_node->p != 0){
			if(temp_node == temp_node->p->c0){
				binary_num.push_back(0);
			}
			if(temp_node == temp_node->p->c1){
				binary_num.push_back(1);
			}
	
			temp_node = temp_node->p;

		}
	}


	//cout<<binary_num.size();
	while(binary_num.size() !=0){
		out<<binary_num.back();
		binary_num.pop_back();
	}
}
*/
/*
int HCTree::decode(ifstream& in) const
{
	vector<int> freqV; 

	unsigned char c = in.get(); 
	//cout<<"first c:"<<c<<endl;
    
    	HCNode *tempNode = HCTree::root; 

    	while(tempNode->c0 != 0 && tempNode->c1 != 0){
       		if(c == '0'){
          		tempNode = tempNode->c0;
			//cout<<"0";
       		}

        	if(c == '1'){
        		tempNode = tempNode->c1;
			//cout<<"1";
		} 
       	
		c = in.get();
		//cout<<"second c:"<<c<<endl;
    	} 
	//cout<<'\n';
	in.putback(c);

    	return tempNode->symbol; 
}*/

