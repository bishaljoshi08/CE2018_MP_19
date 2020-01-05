#include <iostream> 
using namespace std; 

class node
{
	int data;
	node* left ;
	node* right;
	friend class BinarySearchTree;
public:
	node();
	node(int);
	~node();
};

class BinarySearchTree
{
	
	
public:
    node root;
	BinarySearchTree();
	void add(node*,int);
	~BinarySearchTree();
	void postorderTraversal(node *);
	void preorderTraversal(node *);
	void inorderTraversal(node *);
};


node::node(){
    data=0;
	left=right=nullptr;
}

node::node(int value){
	data=value;
	left=right=nullptr;
}

node::~node(){}

BinarySearchTree::BinarySearchTree(){}

BinarySearchTree::~BinarySearchTree(){}

void BinarySearchTree::add(node* root,int value){
	if (root->data==0){
		root->data=value;
	}else{
    	if (value < root->data){
    		if (!root->left){ 
    			node *newnode=new node(value); 
    			root->left=newnode;
    		}
    		else{
    			add(root->left,value);
    		}
    	}
    	else if (value > root->data){
    		if (!root->right){ 
    			node *newnode=new node(value); 
    			root->right=newnode;
    		}
    		else{
    			add(root->right,value);
    		}
    	}
    }
}


void BinarySearchTree::postorderTraversal(node *root){
	if (!root) {
	    return; 
	}
    
    postorderTraversal(root->left); 
    postorderTraversal(root->right);
    cout << root->data<<"\t";
}
void BinarySearchTree::preorderTraversal(node *root){
	if (!root) {
	    return; 
	}
	cout << root->data<<"\t";
    
    preorderTraversal(root->left); 
    preorderTraversal(root->right);
    
    
}
void BinarySearchTree::inorderTraversal(node *root){
	if (!root) {
	    return; 
	}

    
    inorderTraversal(root->left); 
	cout << root->data<<"\t";
    inorderTraversal(root->right);
    
}



int main(){
	BinarySearchTree tree1;
	int number;
	char character;


	top:
	cout<<"Enter any number"<<endl;
	cin>>number;
	tree1.add(&tree1.root,number);
	cout<<"Do you want to enter again(y/n)??"<<endl;
	cin>>character;
	if((character=='y') || (character=='Y')) goto top;


	cout<<"postorderTraversal of the tree is"<<endl;
	tree1.postorderTraversal(&tree1.root);
	cout<<endl;
	cout<<"preorderTraversal of the tree is"<<endl;
	tree1.preorderTraversal(&tree1.root);
	cout<<endl;
	cout<<"inorderTraversal of the tree is"<<endl;
	tree1.inorderTraversal(&tree1.root);

}


