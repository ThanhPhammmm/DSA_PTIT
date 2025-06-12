#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int x){
        value = x;
        left = NULL;
        right = NULL;
    }
};

map<int,Node*> nodeMap;

Node* buildTree(int N){
    Node* root;

    for(int i = 0;i < N;i++){
        int x, y;
        char dir;
        cin>>x>>y>>dir;

        if(nodeMap.find(x) == nodeMap.end()){
            nodeMap[x] = new Node(x);
        }
        if(nodeMap.find(y) == nodeMap.end()){
            nodeMap[y] = new Node(y);
        }

        if(dir == 'L'){
            nodeMap[x]->left = nodeMap[y];
        }
        else{
            nodeMap[x]->right = nodeMap[y];
        }
        if(i == 0){
            root = nodeMap[x];
        }
    }
    return root;
}
void spiralOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    int LeftRight = 0;

    while(!q.empty()){
        int size = q.size();
        vector<int> level(size);

        for(int i = 0;i < size;i++){
            Node* node = q.front();
            q.pop();

            int index;
            if(LeftRight){
                index = i;
            }
            else{
                index = size - i - 1;
            }
            level[index] = node->value;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        for(int num : level){
            cout<<num<<" ";
        }
        LeftRight = !LeftRight;
    }
    cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Node* root = buildTree(N);
        spiralOrder(root);
        nodeMap.clear();
    }
}