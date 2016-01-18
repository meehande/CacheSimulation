#include <iostream>
#include <iomanip>
#include "Cache.h"



int addresses[] = 
{
	0x0000,
    0x0004,
    0x000c,
    0x2200,
    0x00d0,
    0x00e0,
    0x1130,
    0x0028,
    0x113c,
    0x2204,
    0x0010,
    0x0020,
    0x0004,
    0x0040,
    0x2208,
    0x0008,
    0x00a0,
    0x0004,
    0x1104,
    0x0028,
    0x000c,
    0x0084,
    0x000c,
    0x3390,
    0x00b0,
    0x1100,
    0x0028,
    0x0064,
    0x0070,
    0x00d0,
    0x0008,
    0x3394,
};

int main(){

	Cache cache1(8,16,1); //128 byte 1-way cache with 16 bytes per line
	bool hit;
	int num_hits = 0;
	for(int i = 0; i<32; i++){
		hit = cache1.accessCache(addresses[i]);
		cout <<hex << "0x" << setfill('0') << setw(4) << addresses[i] << "\t";
		cout << " hit? " << hit << endl;
		if(hit)
			num_hits++;

	}
	cout <<  dec << "HITS: " << num_hits << endl << endl;
	cout << "hit rate: " << ((float)num_hits/32.0)*100 << "%\n";

	Cache cache2(4,16,2);

	num_hits = 0;
	for(int i = 0; i<32; i++){
		hit = cache2.accessCache(addresses[i]);
		cout <<hex << "0x" << setfill('0') << setw(4) << addresses[i] << "\t";
		cout << " hit? " << hit << endl;
		if(hit)
			num_hits++;

	}
	cout <<  dec << "HITS: " << num_hits << endl << endl;
	cout << "hit rate: " << ((float)num_hits/32.0)*100 << "%\n";

	Cache cache4(2,16,4);

	num_hits = 0;
	for(int i = 0; i<32; i++){
		hit = cache4.accessCache(addresses[i]);

		cout <<hex << "0x" << setfill('0') << setw(4) << addresses[i] << "\t";
		cout << " hit? " << hit << endl;
		if(hit)
			num_hits++;

	}
	cout <<  dec << "HITS: " << num_hits << endl << endl;
	cout << "hit rate: " << ((float)num_hits/32.0)*100 << "%\n";
	
	Cache cache8(1,16,8);

	num_hits = 0;
	for(int i = 0; i<32; i++){
		hit = cache8.accessCache(addresses[i]);
		cout <<hex << "0x" << setfill('0') << setw(4) << addresses[i] << "\t";
		cout << " hit? " << hit << endl;
		if(hit)
			num_hits++;

	}
	cout <<  dec << "HITS: " << num_hits << endl << endl;
	cout << "hit rate: " << ((float)num_hits/32.0)*100 << "%\n";

	while(true){
	}
	return 0;
}