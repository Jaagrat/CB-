void printLeftView(node* root,int level,int &maxlevel){
	if(root == NULL){
		return;
	}

	if(maxlevel<level){
		//we have discovered a new level
		cout<<root->data<<" ";
		maxlevel=level;
	}

	//Left
	printLeftView(root->left,level+1,maxlevel);
	//Right
	printLeftView(root->right,level+1,maxlevel);
}

int main() {
	node* root = buildTree();
	int maxlevel=-1;
	printLeftView(root,0,maxlevel);
	return 0;
}