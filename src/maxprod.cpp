#include "../include/common.h"
int maxprod(vector<int>& nums) {
	if(nums.empty()) return 0;
	int minp = nums[0];
	int maxp = nums[0];
	int result = nums[0];
	for(int i=1; i<nums.size(); i++) {
		if(nums[i] < 0) {
			int t = minp;
			minp = maxp;
			maxp = t;
		}
		minp = min(nums[i], minp*nums[i]);
		maxp = max(nums[i], maxp*nums[i]);
		result = max(result, maxp);
	}
	return result;
}
int main(){
	vector<int> vA = {2,3,-2,4};
	vector<int> vB ={-1,0,-2};
	vector<int> vC ={0,-2};

	for(int i=0; i<vA.size(); i++) 
		cout  << vA[i] << " ";
	cout << endl;
	cout << maxprod(vA) << endl;	
	
	for(int i=0; i<vB.size(); i++) 
		cout  << vB[i] << " ";
	cout << endl;
	cout << maxprod(vB) << endl;	
	
	for(int i=0; i<vC.size(); i++) 
		cout  << vC[i] << " ";
	cout << endl;
	cout << maxprod(vC) << endl;	
}
