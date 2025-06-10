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

vector<int> dfs;

void DFS(TreeNode* node){
    if(node == NULL){
        return;
    }
    dfs.push_back(node->value);

    if (node->left == NULL && node->right == NULL) {
        for ( int i = 0;i < dfs.size();i++) {
            cout<<dfs[i];
            if(i != dfs.size() - 1){
                cout<<"->";
            }
        }
        cout << endl;   
    }

    DFS(node->left);
    DFS(node->right);

    dfs.pop_back();
}

TreeNode* CreateTree(vector<int>& tree){
    TreeNode* root = new TreeNode(tree[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while(i < tree.size() && !q.empty()){
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
        TreeNode* root = CreateTree(tree);
        DFS(root);
        dfs.clear();
    }
}