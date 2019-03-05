#include"../include/common.h"
#include "../include/utils.h"

int main() {
	//vector<int> nums= { 1, 8, 6 ,2, 5, 4, 8, 3, 7};
	vector<int> height= { 1,2,1};
	long long area=0;
	int finalarea =0;
	for (int i=0; i<height.size(); i++) {
		for (int j=0; j<height.size(); j++) {
			//if( i>j) continue;
			long long lowest = min(height[i], height[j]);
			long long totalarea = (long long) (lowest*lowest * (j-i));
			cout << i << ", " << j << " - " <<lowest*lowest*(j-i) << endl;
			if(totalarea > area ){	
			   area = totalarea;												                      finalarea = lowest*lowest;
			}																		            }
	}
	return 0;
}	
