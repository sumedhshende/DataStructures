#include "../include/common.h"
#include "../include/utils.h"

int maxprod(vector<int>& v) {
	if(v.empty()) return 0;
	int maxprod=v[0];
	int prev = 1;
	for(int i=0;i<v.size(); i++){
		//prev = max(v[i], v[i]*prev);
		prev = v[i] * prev;
		if(v[i] < 0) {
			prev = v[i] * prev;
			maxprod = min(prev, maxprod);
			cout << prev << " " << v[i]  << " " << maxprod << endl;
		}else {
			prev = v[i] * prev;
			maxprod = max(prev, maxprod); 	
			cout << prev << " " << v[i]  << " " << maxprod << endl;
		}
		
	}
	return maxprod;
}

int main(void) {
	vector<int> vA = {2,3,-2,4};
	vector<int> vB = {-2,3,-4};
	vector<int> vC = {0,-1, -2};
	for(int i=0;i<vA.size(); i++) 
		cout << vA[i] << " ";
	cout << endl;
	cout << maxprod(vA) << endl;

	for(int i=0;i<vB.size(); i++) 
		cout << vB[i] << " ";
	cout << endl;
	cout << maxprod(vB) << endl;

	for(int i=0;i<vC.size(); i++) 
		cout << vC[i] << " ";
	cout << endl;
	cout << maxprod(vC) << endl;

return 0;
}
