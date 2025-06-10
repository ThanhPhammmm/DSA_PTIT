/*Done*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int num){
        value = num;
        left = NULL;
        right = NULL;
    }
};
void LevelOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0;i < size;i++){
            TreeNode* temp_node = q.front();
            q.pop();
            cout<<temp_node->value<<" ";

            if(temp_node->left) q.push(temp_node->left);
            if(temp_node->right) q.push(temp_node->right);
        }
        cout<<endl;
    }
}
TreeNode* CreateBinaryTree(vector<int> tree){
    TreeNode* root = new TreeNode(tree[0]);

    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while(!q.empty() && i < tree.size()){
        TreeNode* temp_node = q.front();
        q.pop();

        if(i < tree.size() && tree[i] != -1){
            temp_node->left = new TreeNode(tree[i]);
            q.push(temp_node->left);
        }
        i++;

        if(i < tree.size() && tree[i] != -1){
            temp_node->right = new TreeNode(tree[i]);
            q.push(temp_node->right);
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
        TreeNode* root = CreateBinaryTree(tree);
        LevelOrderTraversal(root);
    }
}