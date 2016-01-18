#include "Cache.h"
#include <math.h>
#include <limits>
#include <iostream>
#include <algorithm>
// Calculates log2 of number.  
double Log2( double n )  
{  
    // log(n)/log(2) is log2.  
    return log( n ) / log( 2.0 );  
}

Cache::Cache(int n, int l, int k){
	cout << "n: " << n << "\nl: "<<l<<"\nk: "<< k << endl;
	num_directories = k;
	num_sets = n;
	size_line = l;
	set_bits = (int)Log2(n);
	offset_bits = (int)Log2(l);

	//addresses
	int imax = std::numeric_limits<int>::max();
	tags = vector<vector<int>>(num_sets);

	for(int i = 0; i < num_sets; i++){
		
		tags[i] = vector<int>(num_directories, imax);
		
		
	}
/*	for(int i =0; i<k; i++){
		for (int j=0; j<num_sets;j++){
			cout << "vector element " << i<< ","<<j <<" " << tags[i][j] << endl;
		}
	}
	cout << "n: " << num_sets << endl;*/

}

bool Cache::accessCache(int address){
	//if found, return true - hit
	//if not founr, return false and update cache
	//keep some data structure modelling the cache
	int tag = address >> (offset_bits + set_bits); //get the tag on it's own

	int set = (address >> offset_bits) & (num_sets -1);//get the set num
	
	bool full = true;
	//search tags to find hit - just need to search appropriate set!
	for(int i=0; i<num_directories; i++){
		if(tags[set][i] == tag){
			//change order of vector - least recently used element = front, most recently used = back
			tags[set].erase(std::find(tags[set].begin(), tags[set].end(), tag));
			tags[set].push_back(tag);
			return true;
		}
	}
	//cache miss if we get here
	//replace sth in cache
	//for(int i = 0; i<num_directories; i++){
	//	if(tags[set][i] == NULL){
	//		//tags[set][i] = tag;
	//		tags[set].push_back(tag);
	//		full = false;
	//	}
	//}
	//if(full){
		//tags[set][0] = tag;//default replace the 0th member
		tags[set].push_back(tag);
		if (tags[set].size() > num_directories) {
			tags[set].erase(tags[set].begin());
		}
	//}


	return false;
}