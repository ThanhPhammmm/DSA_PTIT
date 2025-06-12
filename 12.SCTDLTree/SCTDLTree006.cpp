/*Done*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x){
        value = x;
        left = NULL;
        right = NULL;
    }
};

int findDeepestPath(TreeNode* node){
    if(node == NULL){
        return 0;
    }
    return 1 + max(findDeepestPath(node->left), findDeepestPath(node->right));
}
TreeNode* CreateTree(vector<int>& tree){
    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(i < tree.size() && !q.empty()){
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

        TreeNode* root = CreateTree(tree);
        int ans = findDeepestPath(root);
        cout<<ans<<endl;
    }
}