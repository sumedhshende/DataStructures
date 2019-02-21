#include<iostream>
#include<map>
#include<unordered_map>
#include <vector>
using namespace std;

int main() {
    int target = 9;
    vector<int> nums = { 1,2,3,4};
    vector<int> res(nums.size(), 1);
    vector<int> lt(nums.size(), 1);
    vector<int> rt(nums.size(), 1);
    for (int i=1; i < nums.size(); i++) {
		lt[i] *= nums[i-1];
		rt[i] *= nums[nums.size() - 1 - i];
	}
	return 1;
}