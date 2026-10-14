#include<bits/stdc++.h>
#define comma " , "
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data = data;
            left = right = nullptr;
        }
};

class BST{
    public:
        Node* root;

        BST(){root = nullptr;}

        Node* findMin(Node* root){
            // basecase
            if(root->left == nullptr)
                return root;

            // recursion
            return findMin(root->left);
        }

        void addNode(Node* temp,int data){
            while(true){
                if(temp == nullptr){
                    root = new Node(data);
                    return;
                }

                if(data < temp->data && temp->left != nullptr){
                    temp = temp->left;
                }else if(data > temp->data && temp->right != nullptr){
                    temp = temp->right;
                }else if(data < temp->data && temp->left == nullptr){
                    temp->left = new Node(data);
                    return;
                }else if(data > temp->data && temp->right == nullptr){
                    temp->right = new Node(data);
                    return;
                }else{
                    break;
                }
            }
        }

        Node* delNode(Node* root,int tar){
            if(root == nullptr)
                return nullptr;

            if(tar < root->data && root->left != nullptr){
                root->left = delNode(root->left,tar);
            }else if(tar > root->data && root->right != nullptr){
                root->right = delNode(root->right,tar);
            }

            else{
                if(root->left == nullptr && root->right == nullptr){
                    return nullptr;
                }else if(root->left != nullptr && root->right == nullptr){
                    return root->left;
                }else if(root->left == nullptr && root->right != nullptr){
                    return root->right;
                }else{
                    Node* min = findMin(root->right);
                    root->data = min->data;

                    root->right = delNode(root->right,min->data);
                }
            }
        }

        void preorder(Node* root){
            // basecase
            if(root == nullptr) return;

            // recursion
            cout << root->data << comma;
            preorder(root->left);
            preorder(root->right);
        }

        void inorder(Node* root){
            // basecase
            if(root == nullptr) return;

            // recursion
            inorder(root->left);
            cout << root->data << comma;
            inorder(root->right);
        }

        void postorder(Node* root){
            // basecase
            if(root == nullptr) return;

            // recursion
            postorder(root->left);
            postorder(root->right);
            cout << root->data << comma;
        }

        string BFS(Node* root){
            if(root == nullptr)
                return "";

            string ans = "";

            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                Node* temp = q.front();

                //cout << temp->data << comma;
                ans += to_string(temp->data);
                ans += comma;

                q.pop();

                if(temp->left != nullptr)
                    q.push(temp->left);

                if(temp->right != nullptr)
                    q.push(temp->right);
            }

            return ans;
        }
};

int main(){
    BST bst;
    int arr[7] = {50,30,70,20,40,60,80};

    for(int i=0;i<7;i++){
        bst.addNode(bst.root,arr[i]);
    }

    string ans = bst.BFS(bst.root);

    cout << ans.substr(0,ans.length()-3);

    return 0;
}