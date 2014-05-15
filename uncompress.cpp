// Sharon Zheng <s5zheng>, Steven Lim <stl054>
#include <fstream>
#include <iostream>
#include <vector>
#include "HCTree.hpp" 
#include <istream>
#include "BitInputStream.hpp"

using namespace std;

int main(int argc, const char *argv[]){
	ifstream input;
	ofstream output;
	vector<int> freqList;
	unsigned int num_decode =0;

	// open files to be decoded
	input.open(argv[1], ios::binary);
	output.open(argv[2], ios::out);

	// make sure there are 3 arguments inputted
	if(argc != 3){
		printf("Please put in correct inputs");
		exit(0);
   	}
	
	unsigned char letter = input.get();
   	
	// check encoded file for the frequency of all Ascii characters
	while(input.good()){
      	//	cout<<"This is the loop for the frequency    "<<endl;	
		if(letter == '!'){
				if(letter != '@')
					input>>num_decode;
					break; 
      		}
      		
		if(letter != ' '){
        		freqList.push_back(letter - '0');
      		} 
      
      		letter = input.get(); 
   	}
   	
	//cout<<"freq size"<<freqList.size()<<endl;
	/*for(int i = 0; i<freqList.size(); i++)
	{
		cout<<"ascii: "<<i<<"freq:"<<freqList[i]<<endl;
	}*/

	// build a tree
	HCTree *tree = new HCTree();
	tree->build(freqList);

	letter = input.get();
	// decode encoded file
	BitInputStream bitFile = BitInputStream(input);
	for(int i = 0; i<num_decode; i++){
	//	cout<<"This is the loop to decode the file     "<<endl;	
		char value = tree->decode(bitFile);
		//cout<<"This is the char value:     "<<num_decode<<endl;

		//cout<<"letter:"<<value<<endl;
		output<<value;
	}
        
	// close the files
	input.close();
	output.close();

	return 0;
}
