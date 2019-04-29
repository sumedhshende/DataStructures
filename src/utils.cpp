#include "../include/common.h"
#include "../include/utils.h"

void printv(vector<int>& vA) {
	for(int i=0; i<vA.size(); i++) {
		cout << vA[i] << " ";
	}
	cout << endl;
}
void reverse(vector<int>& vA, int s, int e) {
	if(vA.empty() || s < 0 || s >= vA.size() || e < 0 || e >= vA.size() || s >= e) return;
	while(s < e) {
		int t = vA[s]; vA[s] = vA[e]; vA[e] = t;
	}
}
