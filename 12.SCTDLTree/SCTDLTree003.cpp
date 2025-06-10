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

void bottomUpLevelOrder(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);

    vector<vector<int>> levels;

    while(!q.empty()){
        int size = q.size();
        vector<int> level;

        for(int i = 0;i < size;i++){
            TreeNode* temp = q.front();
            q.pop();
            level.push_back(temp->value);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        levels.push_back(level);
    }
    
    reverse(levels.begin(), levels.end());

    for(auto level : levels){
        for(auto comp : level){
            cout<<comp<<" ";
        }
        cout<<endl;
    }
}
TreeNode* CreateBinaryTree(vector<int>& node){
    TreeNode* root = new TreeNode(node[0]);

    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while(!q.empty() && i < node.size()){
        TreeNode* temp = q.front();
        q.pop();

        if(i < node.size() && node[i] != -1){
            temp->left = new TreeNode(node[i]);
            q.push(temp->left);
        }
        i++;

        if(i < node.size() && node[i] != -1){
            temp->right = new TreeNode(node[i]);
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
        vector<int> node(n);
        for(int i = 0;i < n;i++){
            cin>>node[i];
        }
        TreeNode* root = CreateBinaryTree(node);
        bottomUpLevelOrder(root);
    }
}