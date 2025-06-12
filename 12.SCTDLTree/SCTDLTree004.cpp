/*Done*/
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

void rightSideView(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        TreeNode* last;
        for(int i = 0;i < size;i++){
            TreeNode* temp = q.front();
            q.pop();
            last = temp;
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        cout<<last->value<<" ";
    }
    cout<<endl;
}


TreeNode* CreateBinaryTree(vector<int>& tree){
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
        rightSideView(root);
    }
}