#include <iostream>
#include <queue>
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

void printlevel(vector<int> s,int level){
	if(level%2==0){
		for(int i=s.size()-1;i>=0;i--){
			cout<<s[i]<<" ";
		}
	}
	else{
		for(int i=0;i<s.size();i++){
			cout<<s[i]<<" ";
		}
	}
}


void print(node* root){
	if(root==NULL){
		return;
	}

	queue<pair<node*,int>> q;
	vector<pair<node*,int>> v;
	q.push(make_pair(root,1));
	while(!q.empty()){
		pair<node*,int> f = q.front();
		v.push_back(f);
		q.pop();
		if(f.first->left!= NULL){
			q.push(make_pair(f.first->left,f.second+1));
		}
		if(f.first->right!= NULL){
			q.push(make_pair(f.first->right,f.second+1));
		}
	}

	vector<int> s;
	int prevlevel = 1;
	int level;
	for(int j=0;j<v.size();j++){
		level= v[j].second;
		if(level!= prevlevel){
			printlevel(s,prevlevel);
			s.clear();
			prevlevel++;
		}
		s.push_back(v[j].first->data);
	}

	//printing the last level
	printlevel(s,level);
}


int main()
{
	/*build binary tree : input is like - :10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false */
    node *root = build("true");
	print(root);
    return 0;
}