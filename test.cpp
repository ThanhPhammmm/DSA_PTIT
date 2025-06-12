#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        value = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode* buildTree(vector<int>& tree){
    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while(!q.empty() && i < tree.size()){
        TreeNode* temp = q.front();
        q.pop();

        if(i < tree.size() && tree[i] != -1){
            temp->left = new TreeNode(tree[i]);
            q.push(temp->left);
        }
        i++;

        if(i < tree.size() && tree[i] != -1){
            temp->right = new TreeNode(tree[i]);
            q.push(temp->right);
        }
        i++;
    }
    return root;
}
int findDeepestPath(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(findDeepestPath(root->left), findDeepestPath(root->right));
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<int> tree(n);
        for(int i = 0;i < n;i++){
            cin>>tree[i];
        }
        TreeNode* root = buildTree(tree);
        int ans = findDeepestPath(root);
        cout<<ans<<endl;
    }
}