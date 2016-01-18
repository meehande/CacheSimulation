#include<vector>
using namespace std;
class Cache{

public:
	Cache(int n, int l, int k);
	bool accessCache(int address);
	
//private:
	int num_sets, size_line, num_directories;
	int set_bits, offset_bits;
	
	vector<vector<int>> tags;
	
};