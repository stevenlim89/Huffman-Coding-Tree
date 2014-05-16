// Sharon Zheng <s5zheng>, Steven Lim <stl054>
#include <fstream>
#include <iostream>
#include <vector>
#include "HCTree.hpp" 
#include <istream>
#include "BitInputStream.hpp"
#include <istream>
using namespace std;


int main(int argc, const char *argv[]){
	ifstream input;
	ofstream output;
	vector< int> freqList;
	vector<unsigned int> asciiList;
	unsigned int num_decode =0;
	unsigned int freq = 0; 
	byte temp;

	// open files to be decoded
	input.open(argv[1], ios::binary);
	output.open(argv[2], ios::binary);

	// make sure there are 3 arguments inputted
	if(argc != 3){
		printf("Please put in correct inputs");
		exit(0);
   	}

	
   	
	unsigned int size = 0;
	// check encoded file for the frequency of all Ascii characters
	while(size<256){
		input>>freq;
        	freqList.push_back(freq);
      		
      		size++;

   	}
	input>>num_decode;
		// build a tree
	HCTree *tree = new HCTree();
	tree->build(freqList);
	input.read(reinterpret_cast<char *>(&freq), 1);
	BitInputStream bitFile = BitInputStream(input);
	for(int i = 0; i< num_decode; i++){
		byte value = tree->decode(bitFile);
		if((unsigned int)value != -1)
			output.write(reinterpret_cast<char *>(&value), 1);
	}
        
	// close the files
	input.close();
	output.close();

	return 0;
}
