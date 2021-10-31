#include <stdio.h>
#include <iostream>

struct BstNode{
    
    char peopleData; 
    BstNode* left;
    BstNode* right;
};

BstNode* GetNewNode(char peopleData){
    
    BstNode* newNode = new BstBode();
    newNode->peopleData = peopleData; 
    newNode->left = newNode->right = NULL;
    return newNode;
}

bool Search(BstNode* root, char peopleData){
    
    if(root == NULL) return false;
    else if(root->peopleData == peopleData) return true;
    else if (peopleData<=root->peopleData) return Search(root->left, peopleData);
    else return Search (root->right, peopleData);
}

BstNode* Insert(BstNode* root, char peopleData){
    if(root == NULL){
        root = GetNewNode(peopleData); // sets root as the adress of new node
    }
    else if(peopleData<=root->peopleData){
        root->left = Insert(root->left, peopleData);
    }
    else{
        root->right = Insert(root->right, peopleData);
    }
    return root;
}

int main(){
    
    BstNode* root = NULL; //Creates a empty tree
    root = Insert(root, const char* "Carl");
    root = Insert(root, const char* "Mike");
    root = Insert(root, const char* "Greg");
    char name;
    std::cout<<"enter name to be searched \n";
    std::cin>>name;
    if(Search(root, name) == true) std::cout<<"Was Found \n";
    else std::cout<<"Was Not Found \n";
}
