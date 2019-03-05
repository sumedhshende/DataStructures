#include "../include/common.h"
int maxsum(vector<int>& vA) {
	int maxending = 0;
	int maxsofar = 0;
	for(int i=0; i<vA.size(); i++) {
		maxending += vA[i];
		maxending = max(maxending, vA[i]);
		maxsofar = max(maxsofar, maxending);
	}
	if(maxsofar == 0) 
		return maxending;
	else
		return maxsofar;
}
int main(){
	//vector<int> vA = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> vA ={-1};
	for(int i=0; i<vA.size(); i++) 
		cout  << vA[i] << " ";
	cout << endl;
	cout << maxsum(vA) << endl;	
}
