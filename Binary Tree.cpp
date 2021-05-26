#include<iostream>
#include<queue>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Btree{
	public:
		T data;
		Btree* left;
		Btree* right;
		
		Btree(T data){
			this->data = data;
			left = NULL;
			right = NULL; 
		}
		
		~Btree(){
			delete left;
			delete right;
		}
	
};

int count_leafNode(Btree<int>* root){
	if(root == NULL)
	{
		return 0;
	}
	
	if(root->left == NULL && root->right == NULL){
		return 1;
	}
	
	return count_leafNode(root->left)+count_leafNode(root->right);
}


bool symmetric_Btree(Btree<int>* n1 , Btree<int>* n2){
	if(n1== NULL && n2 != NULL) return false;
	if(n1!= NULL && n2== NULL) return false;
	if(n1 == NULL && n2== NULL) return true;
	if(n1->data != n2->data) return false;
	
	return symmetric_Btree(n1->left, n2->right) && symmetric_Btree(n1->right,n2->left);
}

bool symmetric(Btree<int>* root){
	if(root == NULL){
		return true;
	}
	return symmetric_Btree(root->left,root->right);
}


void deepnode_Btree(Btree<int>* root, int height){
	if(!root){
		return;
	}
	
	if(height == 1){
		cout<<root->data<<endl;
	}
	else if(height > 1)
	{
	
	deepnode_Btree(root->left,height-1);
	deepnode_Btree(root->right,height-1);
}

}

void inorder_rec(Btree<int> *root){
	if(root != NULL){
		inorder_rec(root->left);
		cout<<root->data<<" ";
		inorder_rec(root->right);
	}
}

void postorder_rec(Btree<int>* root){
	if(root != NULL){
		postorder_rec(root->left);
		postorder_rec(root->right);
		cout<<root->data<<" ";
	}
}

void inorder_iter(Btree<int> *root){
	stack<Btree<int>* > s;
	
	while(true){
		while(root != NULL){
			s.push(root);
			root = root->left;
		}
		if(s.empty()){
			return;
		}
		root = s.top();
		s.pop();
		cout<<root->data<<" ";
		root = root->right;
	} 
}

void preorder_treversal(Btree<int>* root){
	stack<Btree<int>* > s;
	while(true){
		while(root != NULL){
			cout<<root->data<<" ";
			s.push(root);
			root = root->left;
		}
		
		if(s.empty()){
			return;
		}
		root = s.top();
		s.pop();
		root = root->right;
	}
}

void preorder_rec(Btree<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder_rec(root->left);
	preorder_rec(root->right);
}



Btree<int>* takeinput(){
	cout<<"ENTER DATA"<<endl;
	int rootdata;
	cin>>rootdata;
	
	if(rootdata == -1){
		return NULL;
	}
	
	Btree<int>* root = new Btree<int>(rootdata);
	root->left = takeinput();
	root->right = takeinput();
	/* instead of above two lines we can also write it like
	Btree<int>* leftchidl = takeinput();
	Btree<int>* rightchild = takeinput();
	root->left = leftchild;
	root->right = rightchild;
	*/
	/*when we call root->left = takeinput(); 
	it creates left Btree node and added rootdata is stored to it.
	again recursion call this for its left if we add -1 then 
	Btree nodes right Btree nodes gets created i think you get the idea
	*/

	return root;
	
}

void printvector(std::vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout<<v.at(i)<<" ";
	}
	
	cout<<endl;
}

void lvlorderprint(Btree<int>* root){
	if(root == NULL){
		cout<<"tree doesnot exists"<<endl;
		return;
	}
	
	vector<int> v;
	queue<Btree<int>* > q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Btree<int>* f= q.front();
		q.pop();
		
		if(f == NULL){
			printvector(v);
			v.clear();
			
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			v.push_back(f->data);
			if(f->left){
				q.push(f->left);
			}
			
			if(f->right){
				q.push(f->right);
			}
		}
	}
}

void printTree(Btree<int>* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	if(root->left != NULL){
		cout<<"L:-"<<root->left->data<<" ";
	}
	if(root->right != NULL){
		cout<<"R:-"<<root->right->data<<" ";
		}
		cout<<endl;
		printTree(root->left);
		printTree(root->right);
}

int count_node(Btree<int>* root){
	if(root == NULL){
		return 0;       
	}
	
	return count_node(root->left) + count_node(root->right) +1;
}

Btree<int>* takeinputlvlwise(){
	int rootdata;
	cout<<"ENTER ROOT DATA"<<endl;
	cin>>rootdata;
	
	Btree<int>* root = new Btree<int>(rootdata);
	
	queue<Btree<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		Btree<int>* f = q.front();
		q.pop();
		
		cout<<"ENTER LEFT CHILD OF: "<<f->data<<endl;
		int leftchild;
		cin>>leftchild;
		if(leftchild != -1){
			Btree<int>* child= new Btree<int>(leftchild);
			q.push(child);
			f->left = child;
		}
		
		cout<<"ENTER RIGHT CHILD OF: "<<f->data<<endl;
		int rightchild;
		cin>>rightchild;
		if(rightchild != -1){
			Btree<int>* child = new Btree<int>(rightchild);
			q.push(child);
			f->right = child;
		}
	}
	
	return root;
}

int max_Btree(Btree<int>* root){
	int val,left,right;
	int max_value=0;
	if(root != NULL){
		val = root->data;
		left = max_Btree(root->left);
		right = max_Btree(root->right);
	     max_value = max(left,right);
	     max_value = max(max_value,val);
	}
	
	return max_value;
}


int min_Btree(Btree<int>* root){
	int val,left,right,min_val=0;
	
	if(root != NULL){
		val = root->data;
		left = min_Btree(root->left);
		right= min_Btree(root->right);
	    min_val = min(left,right);
	    min_val = min(min_val,val);
	}
	
	return val;
}

bool search_Btree(Btree<int>* root, int val){
	if(root == NULL){
		return false;
	}
	else{
		
		if(val == root->data){
			return true;
		}
		else{
			search_Btree(root->left,val);
			search_Btree(root->right,val);
		}
		
	}
	
}

int height_Btree(Btree<int>*root){
	if(root == NULL){
		return 0;
	}
	int level=0;
	
	queue<Btree<int>* > q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty()){
		Btree<int>* f = q.front();
		q.pop();
		
		if(f==NULL){
			level++;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
		  if(f->left){
		  	q.push(f->left);
		  }
		  
		  if(f->right){
		  	q.push(f->left);
		  }
		}
	}
	
	return level;
}

int main()
{

Btree<int>* root = takeinputlvlwise();

cout<<"level order print"<<endl;
lvlorderprint(root);
cout<<endl;
bool s = symmetric(root);

if(s){
	cout<<"Btree is symmetric"<<endl;
}
else{
	cout<<"Btree is not symmetric"<<endl;
}

int no = count_leafNode(root);

cout<<"no of leaf node is: "<<no<<endl;


return 0;
}
