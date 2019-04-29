#include "../include/common.h"

bool has_duplicates(vector<int>& vA) {
	unordered_map<int, bool> bmap;
	for(int i=0; i<vA.size(); i++) {
		if(bmap.find(vA[i]) != bmap.end())
			return true;
		bmap.insert(make_pair(vA[i],true));
	} 
}

int main() {
	vector<int> vA = {1,1,3,3,4,3,2,4,2 };
	for(int i=0; i<vA.size(); i++)
		cout << vA[i] << " ";
	cout << endl;
	cout << has_duplicates(vA) << endl;
	
	return 0;
}
