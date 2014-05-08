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
			HCNode * node = new HCNode(HCNode(freqs[num], 
										num, nullptr, nullptr, nullptr));
			node_pq.push(node);
			HCTree::leaves.push_back(node);
		}
	}

	//creates the tree
	while(node_pq.size() != 0){
		if(node_pq.size() == 1){
			HCTree::root = node_pq.top();
			node_pq.pop();
			return;
		}
		else{	
			HCNode * low1 = node_pq.top();
			node_pq.pop();
			HCNode * low2 = node_pq.top();
			node_pq.pop();
			int sum = low1->count + low1->count;
			HCNode * combined = new HCNode(sum, '0', low1, low2, nullptr);
			low1->p = combined;
			low2->p = combined;
			node_pq.push(combined);
		}
	}




}

void encode(byte symbol, ofstream& out) const
{

}

