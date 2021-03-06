#include"../include/common.h"
#include "../include/utils.h"
const int CHAR_COUNT = 26;
bool uniqueChars(char* str) {
	if(str == NULL) return false;
	vector<bool> bm(CHAR_COUNT, false);
	for(char* p=str; p!='\0'; p++) {
		if(bm[*p-'a'] == true)
			return false;
		else
			bm[*p] = true;
	}
	return false;
}

int main() {
	char* nstr = NULL;
	cout << "NULL" << " : " << uniqueChars(nstr) << endl;
	char* nstr1 = "s";
	cout << nstr1 << " : " << uniqueChars(nstr1) << endl; 
	char* nstr2 = "sumedhhende";
	cout << nstr2 << " : " << uniqueChars(nstr2) << endl; 
	char* nstr3 = "shil";
	cout << nstr3 << " : " << uniqueChars(nstr3) << endl; 
	return 0;
}	
