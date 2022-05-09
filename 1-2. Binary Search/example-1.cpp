#include <bits/stdc++.h>

class Node {
    public:
        int data; 
        Node *left;
        Node *right;
        Node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution{
    public: 
    void displayOrder(Node *);
    Node * insert(Node *, int);
    
};

void Solution::displayOrder(Node *root){
    if (root == NULL)
        return;
    
    std::cout << root->data << " ";
    displayOrder(root->left);
    displayOrder(root->right);
}

Node * Solution::insert(Node *root, int data){
    if (root == NULL)
        root = new Node(data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else 
        root->left = insert(root->left, data);

    return root;
}

//Find an ancestor vector of any number
std::vector<Node *> findAncestorVector(Node *root, int num){
    std::vector<Node *> ancVec; 
    Node * temp = root;

    while(temp->data != num){
        if (num > temp->data){
            ancVec.push_back(temp);
            temp = temp->right;
        }
        else if (num < temp->data){                
            ancVec.push_back(temp);
            temp = temp->left;
        }       
    }
    ancVec.push_back(temp); // push_back itself
    return ancVec;  
}

Node * searchEle(std::vector<Node *> av, int d){

    int size = av.size();

    for (int i = 0; i < size; i++)
    {
        if(av[i]->data == d)
            return av[i];
    }

    return NULL;
    
}

Node *lca(Node *root, int v1,int v2) {
    //if (v1 > v2)
    //    swap(v1,v2);
    Node * ret = NULL;
    Solution exp;
    std::vector<Node *> _v1 = findAncestorVector(root, v1);
    std::vector<Node *> _v2 = findAncestorVector(root, v2); 

    if (_v1.size() > _v2.size()){
    std::cout << "fine " << __LINE__ << std::endl; 
        for (int i = _v2.size()-1; i >= 0; i--) {
            ret = searchEle(_v1, _v2[i]->data);
            if (ret)
                return ret;
        }
    }
    else {
    std::cout << "fine " << __LINE__ << std::endl; 
        for (int i = _v1.size()-1; i >= 0; i--) {
            ret = searchEle(_v2, _v1[i]->data);
            if (ret)
                return ret;
        } 
    
    }
    return ret; 
}

int main(){
    Solution myTree; 
    Node* root = NULL;

    int t;
    int data; 

    std::cin >> t;

    while (t-- > 0){
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.displayOrder(root);

    Node* ret = lca(root, 1, 2);
    if (ret)
        std::cout << ret->data << std::endl;
    return 0;
}