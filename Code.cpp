#include <stdio.h>
#include <iostream>

struct ADT{
    
    char peopleData; 
    Human* left;
    Human* right;
};

struct Human{
  // The people's id/info
    std::string name;
    int dayBirth, monthBirth, yearBirth;

    Human() = default;
    Human(std::string name, int dayBirth, int monthBirth, int yearBirth){
        this->name = name;
        this->dayBirth = dayBirth;
        this->monthBirth = monthBirth;
        this->yearBirth = yearBirth;
    }
    explicit Human(std::string name) {
        this->name = name;
        this->dayBirth = this->monthBirth = this->yearBirth = -1;
    }

    // Checks if names are equal
    friend bool operator == (const Human &lhs, const Human& rhs) {
        return (lhs.name == rhs.name);
    }

    // Checks if names are'nt equal
    friend bool operator != (const Human &lhs, const Human& rhs){
        return (lhs.name != rhs.name);
    }

    //  toString method that prints name & date of birth
    friend std::ostream& operator << (std::ostream& o, const Human& p){
        return o << p.name << ", " << p.monthBirth << "/" << p.dayBirth << "/" << p.yearBirth;
    }

};

Human* GetNewNode(char peopleData){
    
    Human* newNode = new Human();
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

Human* Insert(Human* root, char peopleData){
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
    
    Human* root = NULL; //Creates a empty tree
    root = Insert(root, const char* "Carl");
    root = Insert(root, const char* "Mike");
    root = Insert(root, const char* "Greg");
    char name;
    std::cout<<"enter name to be searched \n";
    std::cin>>name;
    if(Search(root, name) == true) std::cout<<"Was Found \n";
    else std::cout<<"Was Not Found \n";
}
