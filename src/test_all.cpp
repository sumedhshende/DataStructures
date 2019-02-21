#include "../include/common.h"

void vector_print(vector<int>& vA) {
    for(int i=0; i<vA.size(); i++) 
        cout << vA[i] << " ";
    cout << endl;
}
void reverse(vector<int>& vA, int s, int e) {
    if(vA.empty() || s < 0 || s >= vA.size() || e < 0 || e >= vA.size() || s >= e) {
	 	//cout << "Parameters passed incorrect, check the bounds" << endl;
		return;
	}
    while(s < e) {
        int t = vA[s]; vA[s] = vA[e]; vA[e] = t; ++s;--e;
    }
}

void test_reverse() {
	vector<int> vA = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vB;

	reverse(vB, 0, 10); // empty 
	reverse(vA,-1, 9); // start empty
	reverse(vA, 2,-1); // end empty
	reverse(vA, 9, 7);  // start > end
	reverse(vA,10, 9);  // start out of bound
	reverse(vA, 4, 11); // end out of bound
	vector_print(vA);
	reverse(vA, 0, 9);
	vector_print(vA);
	reverse(vA, 0, 5);
	vector_print(vA);
	reverse(vA, 5, 9);
	vector_print(vA);
	reverse(vA, 5, 6);
	vector_print(vA);
}
void rotate(vector<int>& vA, int point) {
    if(vA.empty() || point < 0 || point >= vA.size()) {
		//cout << "Incorrect parameter passed. ";
		return;
	}		
	cout << vA.size() << " " << point << endl;
	
	reverse(vA, 0, point-1);
	reverse(vA, point, vA.size()-1);
	reverse(vA, 0, vA.size()-1);
}
void test_rotate() {
	vector<int> vA = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vB;
	vector_print(vA);
	rotate(vB, 5);
	vector_print(vA);
	rotate(vA, -1);
	vector_print(vA);
	rotate(vA, 0);
	vector_print(vA);
	rotate(vA, 11);
	vector_print(vA);
	rotate(vA, 9);
	vector_print(vA);

	rotate(vA, 5);
	vector_print(vA);
	
	vector<int> vC = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	rotate(vC, 3);
	vector_print(vC);
	
	vector<int> vD = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	rotate(vD, 7);
	vector_print(vD);
	
	vector<int> vE = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	rotate(vE, 1);
	vector_print(vE);
}

int binarysearch(vector<int>& vA, int l, int r, int elem) {
	if(vA.empty() || l>r) return -1;
	cout << " ----------------------------------" << endl;
	int m=-1;
	while( l<=r) {
		m = l+(r-l)/2;
		//cout << l << " " << r << " " << m << " " << elem << "<" << vA[m] << endl;
		if(elem == vA[m])
			return m;
		else if(elem < vA[m])
			r = m-1;
		else
			l = m+1;
	}
	return -1;
}
int rbinarysearch(vector<int>& vA, int l, int r, int elem) {
	int m = l + (r-l)/2;
	
	if(elem == vA[m]) return m;
	if(l > r) return -1;
	
	if(vA[l] < vA[m]) {
		if(elem >= vA[l] && elem < vA[m]) {
			return rbinarysearch(vA, l, m-1, elem);
		}else {
			return rbinarysearch(vA, m+1, r, elem);
		}
	}
	if(vA[m] < vA[r]) {
		if(elem > vA[m] && elem <= vA[r]) {
			return rbinarysearch(vA, m+1, r, elem);
		}else {
			return rbinarysearch(vA, l, m-1, elem);
		}
	}
	if(vA[l] == vA[m]) {
		if(vA[m] != vA[r]) {
			return rbinarysearch(vA, m+1, r, elem); 
		} else {
			int result =  rbinarysearch(vA, l, m-1, elem);
			if( result == -1) {
					rbinarysearch(vA, m+1, r, elem);
			}else{
				return result;
			}
		}
	}
	return -1;
}

void test_binarysearch() {
	 vector<int> vA = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	 for(int i=0; i<vA.size(); i++) {
		vector<int> vC = vA;
		rotate(vC, i);
		vector_print(vC);
		int idx = rbinarysearch(vC, 0, vC.size()-1, vC[i]);
	 	if(idx == -1) {	
			cout << idx << " " << vC[i] << " FAILED " <<endl;
			//return;
		}
		else if( vC[i] == vC[idx]) 
			cout << idx << " " << vC[idx] << " " << vC[i] << " PASSED " << endl;
	 }
}
int main(void) {
	//test_reverse();
	//test_rotate();
	test_binarysearch();
return 0;
}
