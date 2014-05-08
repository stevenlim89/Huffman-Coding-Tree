// Sharon Zheng <s5zheng>, Steven Lim <stl054>

#include <fstream>
#include <iostream>
#include <vector>
#include <array>
#include "HCTree.hpp"
#define MAX 256

using namespace std;

 


int main( int argc, const char *argv[])
{
	ofstream outputFile;
	vector<int> list_freq;	


	if( argc != 3 ){
		printf("Please put in correct input");
		exit(0); 
	}

	ifstream ifs;
	ifs.open(argv[1], ios::binary);
	
	int asciiArray[MAX];
	
	for(int i =0 ; i < MAX; i++){
		asciiArray[i]=0;
	}
	
	while(ifs.good()){
		unsigned char letter = ifs.get();
	
		for(int index = 0; index < MAX; index++){
			if(index == letter){
				asciiArray[index]++;
			}
		}
	}
	
	for( int k =0 ; k < MAX; k++){
		//if(asciiArray[k]!=0)
			list_freq.push_back(asciiArray[k]);
			//list_ascii.push_back(k);
		
	}

	HCTree * tree = new HCTree();
	tree->build(list_freq);

	
	outputFile.open(argv[2]);
	/*for( int f =0 ; f < list_freq.size(); f++){
		//outputFile<<list_ascii[f];
		
	}*/


	ifs.close();
	outputFile.close();
	return 0;

}
