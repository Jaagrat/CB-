#include <iostream>
#include<string>
#include<cstring>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

node* build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        node *root = new node(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

string structure(node* root){
	if(root==NULL){
		string s= "N";
		return s;
	}
	string s = "Y";
	s+= structure(root->left);
	s+= structure(root->right);
	return s;
}

int main() {
	/*input of a tree will be in the form :10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false */

	node *root1 = build("true");
	node *root2 = build("true");
	string s1 = structure(root1);
	string s2 = structure(root2);
	
	if(s1==s2){
		cout<<"true";
	}
	else{
		cout<<"false";
	}
	return 0;
}