#include<stdio.h>
#include<vector>
using namespace std;

struct _node {
	_node *left;
	_node *right;
	char data;
};
_node *newNode(char data) {
	_node *pnode = new _node;
	pnode->left = NULL;
	pnode->right =  NULL;
	pnode->data = data;
	return pnode;
}/*
void build(_node **root) {
	*root = newNode(100);
	(*root)->left = newNode(50);
	(*root)->left->left = newNode(20);
	(*root)->left->right = newNode(40);
	(*root)->right = newNode(200);
	(*root)->right->left = newNode(150);
	(*root)->right->right = newNode(200);
}*/
vector<_node *> queue;

void bfs(_node **root) {
	if(*root == NULL) return;
	queue.push_back(*root);
	while(queue.size()>0) {
		_node *pnode = queue.front();
		queue.erase(queue.begin());

		printf("%c", pnode->data);
		if(pnode->left != NULL)
			queue.push_back(pnode->left);
		if(pnode->right != NULL)
			queue.push_back(pnode->right);
	}
}
void InOrder(_node **root) {
	if(*root == NULL) 
		return;
	InOrder(&((*root)->left));
	printf(" %d ", (*root)->data);
	InOrder(&((*root)->right));
}
int search(char in[], char data, int s, int e) {
	for(int i=s; i<e; i++)
		if(in[i] == data) return i;

	return -1;
}/*
_node* buildTree(char in[], char pre[],int ins, int ine){
	static int pindex =0;
	if(ins > ine) return NULL;

	char ch = pre[pindex++];
	_node *tnode = newNode(ch);
	
	if(ins == ine) return tnode;

	int iindex = search(in, ins, ine, tnode->data);
	tnode->left = buildTree(in,  pre, ins, ine, iindex-1);
	tnode->right = buildTree(in, pre, ins, iindex+1, ine );
	
}*/

_node * createMBST(char arr[], int start, int end) {
	if( start > end ) return NULL;

	int mid = start + ( end - start)/2;
	_node *tnode = newNode(arr[mid]);
	tnode->left = createMBST(arr, start, mid-1);
	tnode->right = createMBST(arr, mid+1, end);
	return tnode;	
}
int main(void) {
	char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
	char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
	char arr[] ={'A', 'B', 'C', 'D', 'E', 'F', 'G'};

	_node *root;
	
	printf("%s\n", arr);

	//build(&root);
//	bfs(&root);
	root = createMBST(arr, 0, 6);
	bfs(&root);	
	//printf("\n");
	//InOrder(&root);
	
	return 0;
}
