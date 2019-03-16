#include <iostream>

using namespace std;

struct heap_node{
	int data, dist;
	heap_node *left, *right;
	heap_node() = default;
	heap_node(const heap_node &h) = default;
	heap_node(int d = 0, int di = 0, heap_node *l = NULL, heap_node *r = NULL): data(d), dist(di), left(l), right(r){}
};

heap_node *merge(heap_node *l, heap_node *r){
	if(l == NULL && r == NULL) return 0;
	if(l == NULL) return r;
	if(r == NULL) return l;
	if(l->data > r->data) swap(l, r);
	l->right = merge(l->right, r);
	if((l->right != NULL && l->left == NULL) || l->right->dist > l->left->dist) 
		swap(l->right, l->left);
	if(l->right != NULL) l->dist = l->right->dist + 1;
	else l->dist = 0;
	return l;
}

heap_node *push(heap_node *sub, int n){
	heap_node *temp = new heap_node(n);
	return merge(sub, temp);
}

int pop(heap_node *&root){
	if(root == NULL) return 0;
	int temp = root->data;
	root = merge(root->left, root->right);
	return temp;
}

void traverse(heap_node *sub_root){
	if(sub_root == NULL) return;
	traverse(sub_root->left);
	cout << sub_root->data << ' ';
	traverse(sub_root->right);
}

int main(){
	int array[] = {7, 6, 1, 32, 43, 12, 11};
	heap_node *root = new heap_node(3);
	for(int i = 0; i < 7; i++)
		root = push(root, array[i]);
	while(root != NULL) cout << pop(root) << ' ';
}