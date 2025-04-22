#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = right = nullptr;
    }
};

static int idx = -1;

Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);
    return root;

}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }

    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL){
            if(!q.empty()){
                cout<<endl;
                q.push(NULL);
                continue;
            }else{
              break;
            }
        }

        cout<<frontNode->data<<" ";

        if(frontNode->left){
            q.push(frontNode->left);
        }

        if(frontNode->right){
            q.push(frontNode->right);
        }
    }
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return max(leftHt , rightHt) + 1;
}

int count(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHt = height(root->left);
    int rightHt = height(root->right);
    return (leftHt + rightHt) + 1;
}
int sum(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftSum = sum(root->left);
    int rightSum = sum(root->right);
    return (leftSum + rightSum) + root->data;
}
int main(){
    vector<int> preorder = {1 , 2 , 3 , -1 , -1 , 4 , -1 , -1 , 5 , 6 , -1 , -1 , 7 , -1 , -1};

    Node* root = buildTree(preorder);
    cout<<root->data<<endl;
    // cout<<root->left->data<<endl;
    // cout<<root->right->data<<endl;

    // preOrder(root);
    // cout<<endl;
    // inOrder(root);
    // cout<<endl;
    // postOrder(root);
    // cout<<endl;
    // levelOrder(root);
//     cout<<height(root)<<endl;
//     cout<<count(root);
       cout<<sum(root)<<endl;
  }