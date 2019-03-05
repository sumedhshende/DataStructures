#include"../include/common.h"
#include "../include/utils.h"

int sum3_1(void) {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> vv;
	sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size(); i++)
		cout << nums[i] << " ";
	cout <<endl;	
    for (int i = 0; i < nums.size(); i++) {
		if(i>0 && nums[i] == nums[i-1]) continue;
        for (int j = i+1; j < nums.size(); j++) {
			if(j>i+1 && nums[j] == nums[j-1]) continue;
           	for (int k = j+1; k<nums.size(); k++) {
				if(k>j+1 && nums[k] == nums[k-1]) continue;
            	//cout << nums[i] << " " << nums[j] << " " << nums[k] << " = " << (nums[i] + nums[j] + nums[k]) << endl;
                if((nums[i] + nums[j] + nums[k]) == 0) {
                    vector<int> tmp = {nums[i], nums[j], nums[k]};
                    vv.push_back(tmp);
                }
            }
        }
	}
	for(int i=0; i<vv.size(); i++) 
		cout << "[" << vv[i][0] << ", " << vv[i][1] << ", " << vv[i][2] << "]" << endl;
	return 0;
}
int main() {
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> vv;
    sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size(); i++)
		cout << nums[i] << " "; 
	cout <<endl;
	for (int i = 0; i < nums.size(); i++) {
		if(i>0 && nums[i] == nums[i-1]) continue;
		int start=i+1;
		int end = nums.size()-1;
		while( start < end) {
			int sum = nums[i] + nums[start] + nums[end];
			if(sum <= 0) {
				if(sum == 0)
					vv.push_back({nums[i], nums[start], nums[end]});
				++start;
			}else {
				--end;
			}
		}
	}
	for(int i=0; i<vv.size(); i++)
		cout << "[" << vv[i][0] << ", " << vv[i][1] << ", " << vv[i][2] << "]" << endl;
	return 0;
}	
