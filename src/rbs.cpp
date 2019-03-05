#include "../include/common.h"
int rbs(vector<int>& nums, int l, int r, int t) {
	int m = l + (r-l)/2;

	if(nums[m] == t) return m;
	if(l>r) return -1;
	
	if(nums[l] < nums[m]) {
		if(t >= nums[l] && t < nums[m]) 
			return rbs(nums, l, m-1, t);
		else
			return rbs(nums, m+1, r, t);
	}
	else if(nums[m] < nums[r]) {
		if(t > nums[m] && t <= nums[r])
			return rbs(nums,m+1, r, t);
		else
			return rbs(nums,l, m-1, t);
	}
	else if(nums[l] == nums[m]) {
		if(nums[m] != nums[r])
			return rbs(nums, m+1, r, t);
		else{
			int result = rbs(nums,l, m-1, t);
			if(result == -1)
				return rbs(nums, m+1, r, t);
			else
				return result;
		}
	}
	return -1;
}
int findMin(vector<int>& nums) {
        int l=0; int r=nums.size()-1;
        
        while(l<r){
            int m = l +(r-l)/2;
            if(nums[m] > nums[r])
                l = m+1;
            else
                r = m;
        }
        return l;
    }

    int search(vector<int>& nums, int target) {
        int l=0; int r=nums.size() -1;
        int rot = findMin(nums);
        
        while(l<=r) {
            int m = l + (r-l)/2;
            int rm = (m+rot) % nums.size();
            if(nums[rm] == target) return m;
            else if( target < nums[rm]) r = m-1;
            else  l = m+1;
        }
        return -1;
    }

int main(){
	vector<int> vA = {4,5,6,7,0,1,2};
	vector<int> vB ={4,5,6,7,0,1,2};
	vector<int> vC ={2,2,2,3,4,2};

	for(int i=0; i<vA.size(); i++) 
		cout  << vA[i] << " ";
	cout << endl;
	cout << search(vA,0) << endl;	
	
	for(int i=0; i<vB.size(); i++) 
		cout  << vB[i] << " ";
	cout << endl;
	cout << search(vB, 3) << endl;	
	
	for(int i=0; i<vC.size(); i++) 
		cout  << vC[i] << " ";
	cout << endl;
	cout << search(vC,2) << endl;	
}
