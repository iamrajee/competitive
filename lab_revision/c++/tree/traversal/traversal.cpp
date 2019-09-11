#include<bits/stdc++.h> 
using namespace std; 
struct Node { //like a class
	int data; 
	struct Node* left, *right; 
	Node(int d){ //method??
		this->data = d;
		this->left = this->right = NULL; 
	} 
}; 
void Post(struct Node* node) { 
	if (node == NULL) return; 
	Post(node->left); 
	Post(node->right); 
	cout << node->data << " "; 
} 
void In(struct Node* node) { 
	if (node == NULL) return; 
	In(node->left); 
	cout << node->data << " "; 
	In(node->right); 
} 
void Pre(struct Node* node) { 
	if (node == NULL) return; 
	cout << node->data << " "; 
	Pre(node->left); 
	Pre(node->right); 
} 
int main() { 
	struct Node *root = new Node(1); 
	root->left			 = new Node(2); 
	root->right		 = new Node(3); 
	root->left->left	 = new Node(4); 
	root->left->right = new Node(5); 
	cout << "\nPreorder traversal of binary tree is \n"; 
	Pre(root); 
	cout << "\nInorder traversal of binary tree is \n"; 
	In(root); 
	cout << "\nPostorder traversal of binary tree is \n"; 
	Post(root); 
	return 0; 
} 
