pair<int,bool> isHeightBalancedOptimised(node *root)
{
    // Write your code here
    pair<int,bool> p;
    if(root==NULL){
        p.first=0;
        p.second=true;
        return p;
    }

    //rec
    pair<int,bool> ls= isHeightBalancedOptimised(root->left);
    pair<int,bool> rs= isHeightBalancedOptimised(root->right);
    p.first = max(ls.first,rs.first)+1;

    if(ls.second and rs.second and abs(ls.first-rs.first)<=1){
        p.second=true;
    }
    else{
        p.second = false;
    }
    return p;
}