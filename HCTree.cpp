#include "HCTree.hpp"
#include <vector>
#include <queue>

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
		cout<<"asfd"<<endl;
		if(node_pq.size() == 1){
			HCTree::root = node_pq.top();
			HCTree::root->p = 0;
			node_pq.pop();
			cout<<"root is"<<HCTree::root<<endl;
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

void HCTree::encode(byte symbol, ofstream& out) const
{

	vector<int> binary_num;
	cout<<binary_num.size();
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
				cout<<"node0"<<temp_node<<endl;
			}
			if(temp_node == temp_node->p->c1){
				binary_num.push_back(1);
				cout<<"one1"<<temp_node<<endl;
			}
	
			temp_node = temp_node->p;

		}
	}



	cout<<binary_num.size();
	out<<'\n';
	while(binary_num.size() !=0){
		out<<binary_num.back();
		binary_num.pop_back();
	}
	out<<'\n';
}


int HCTree::decode(ifstream& in) const
{

}

