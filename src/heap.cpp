#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 20

int arr[MAX_SIZE];
static int size = 0;

void siftup() {
	for(int i=size;i>0;) {

		int p = i/2;
		if(arr[p] <= arr[i]) break;		
		int temp = arr[i];
		arr[i] = arr[p];
		arr[p] = temp;
		i = p;
	}
}

void insert(int item) {
	arr[size++]=item;
	siftup();
}
void print() {
	for(int i=0;i<size; i++) {
		printf("%d ", arr[i]);
	}
}
int main(void) {
	memset(arr, 0, MAX_SIZE);	
	for(int i=0;i<MAX_SIZE; i++){
		printf("\n");
		int r = rand() % 20;
		insert(r);
		print();
	}
	return 0;
}
