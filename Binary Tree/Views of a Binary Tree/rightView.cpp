
void rightViewUtil(node *root, int level, int &max_level)
{
    // Base Case
    if (root == NULL) return;
  
    // If this is the last Node of its level
    if (*max_level < level)
    {
        cout << root->data << " ";
        *max_level = level;
    }
  
    // Recur for right subtree first, 
    // then left subtree
    rightViewUtil(root->right, level + 1, max_level);
    rightViewUtil(root->left, level + 1, max_level);
}

int max_level=-1;