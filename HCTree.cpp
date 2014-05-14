#include "HCTree.hpp"
#include "BitOutputStream.hpp"
#include <vector>
#include <queue>
<<<<<<< HEAD
#include "BitInputStream.hpp"
=======
#include "BitOutputStream.hpp"

>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb
using namespace std;

HCTree::~HCTree(){}


void HCTree::build(const vector<int>& freqs)
{
	vector<int> list_ascii;
	vector<int> list_freq;
	vector<HCNode*> list_node;
	priority_queue<HCNode*, vector<HCNode*>, HCNodePtrComp> node_pq;

	//loops through the frequency to create single nodes		
	for( int num =0 ; num < freqs.size(); num++){
		if(freqs[num] != 0){
			list_ascii.push_back(num);
			list_freq.push_back(freqs[num]);
			HCTree::leaves[num]	= new HCNode(freqs[num], 
								num, 0, 0, 0);
			node_pq.push(leaves[num]);
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
			HCNode * combined = new HCNode(sum, 0, low2, low1, 0);
			low1->p = combined;
			low2->p = combined;
			node_pq.push(combined);
		}
	}




}

<<<<<<< HEAD
=======

>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb
void HCTree::encode(byte symbol, BitOutputStream& out) const
{
	HCNode * temp_node = HCTree::leaves[symbol];
	if(temp_node == nullptr)
		return;
	if(temp_node == HCTree::root){
		return;
	}
	else{
		while(temp_node->p != 0){
			if(temp_node == temp_node->p->c0){
				out.BitOutputStream::writeBit(0);
			}
			if(temp_node == temp_node->p->c1){
				out.BitOutputStream::writeBit(1);
			}
	
			temp_node = temp_node->p;

		}
	}
<<<<<<< HEAD
}

int HCTree::decode(BitInputStream& in) const
{
	vector<int> freqV; 
	int num = in.BitInputStream::readBit();
	//cout<<"first c:"<<c<<endl;
    	HCNode *tempNode = HCTree::root; 
    	
	while(tempNode->c0 != 0 && tempNode->c1 != 0 && num != -1){
	cout<<num<<endl;
		if(num == 0){
          		tempNode = tempNode->c0;
			//cout<<"0";
       		}

        	if(num == 1){
        		tempNode = tempNode->c1;
			//cout<<"1";
		} 
       	
		num = in.BitInputStream::readBit();
		//cout<<"second c:"<<c<<endl;
    	} 
	//cout<<'\n';
	//in.putback(num);

    	return tempNode->symbol; 
}

/*
void HCTree::encode(byte symbol, ofstream& out) const
=======
	
}


/*void HCTree::encode(byte symbol, ofstream& out) const
>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb
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

<<<<<<< HEAD
/*int HCTree::decode(ifstream& in) const
=======
int HCTree::decode(ifstream& in) const
>>>>>>> 5f43817e50655b5bddf1ca231dac0a6cf72257fb
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

