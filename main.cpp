/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: uyanda
 *
 * Created on 11 April 2020, 12:21 PM
 */

#include <iostream>
#include <vector>



using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;
};

class keyvalue
{
    public:
    int data;
    int width;
    int depth;
};

keyvalue keypair;
node* newNode(int data);

void topView(node * root);
void loadTopView(node* root, int width, int depth, vector<keyvalue>& treelist);
// Driver code
int main(int argc, char** argv)
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    topView(root);



    return 0;
}


node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}

void loadTopView(node* root, int width, int depth, vector<keyvalue>& treelist)
{
    if(root == NULL)
        return;

    if(treelist.size() == 0)
    {
        keypair.data = root->data;
        keypair.depth = depth;
        keypair.width = width;
        treelist.push_back(keypair);

    }else
    {
        bool isFound = false;

        for (int i = 0; i < treelist.size(); i++)
        {
            if(treelist.at(i).width == width)
            {
                isFound = true;

                if (treelist.at(i).depth > depth)
                {
                    treelist.at(i).width = width;
                    treelist.at(i).depth = depth;
                    treelist.at(i).data = root->data;
                }
            }
        }


        if (isFound == false)
        {
            if (width < 0)
            {
                keypair.data = root->data;
                keypair.depth = depth;
                keypair.width = width;
                treelist.insert(begin(treelist), keypair);
            }else
            {
                keypair.data = root->data;
                keypair.depth = depth;
                keypair.width = width;
                treelist.push_back(keypair);
            }
        }

    }
    depth++;
    width -= 1;

    loadTopView(root->left, width,  depth, treelist);
    width += 2;
    loadTopView(root->right, width,  depth, treelist);


}

void topView(node * root) {

    int width = 0;
    int depth = 0;
    int data = 0;
    vector<keyvalue> treelist;
    loadTopView(root,  width, depth, treelist);

    for (int i = 0; i < treelist.size(); i++)
    {
        cout << treelist.at(i).data << " "<<endl;
    }
}
