void topView(node* root)
{
    if (root == NULL)
        return;

    queue<pair<node*,int>> q;
    map<int, int> mp;
    int hd = 0;
 
    // push node and horizontal distance to queue
    q.push(make_pair(root,hd));
 
    while (!q.empty()) {
		node* curr = q.front().first;
        hd = q.front().second;

		if(mp.count(hd)==0)
        	mp[hd] = curr->data;
        if (curr->left) {
            q.push(make_pair(curr->left,hd-1));
        }
        if (curr->right) {
            q.push(make_pair(curr->right,hd+1));
        }
        q.pop();
    }
 
    for (auto ele : mp) {
        cout << ele.second << " ";
    }
}



int main() {
	node* root = buildTree();
	topview(root);
	return 0;
}