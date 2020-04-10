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

int maxDepth(node* node);
node* newNode(int data);
void treeDepth(node* node, int depth);
void treeWidth(node* node, int width);


// Driver code
int main()
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int depth = 0;

    //treeDepth(root, depth);

    int width = 0;
    treeWidth(root, width);

    return 0;
}

int maxDepth(node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);

        /* use the larger one */
        if (lDepth > rDepth)
        {
            return(lDepth + 1);
        }else
        {
            return(rDepth + 1);
        }
    }
}


node* newNode(int data)
{
    node* Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return(Node);
}



void treeDepth(node* node, int depth)
{
    if(node == NULL)
    {
        return;
    }


    depth++;
    cout << node->data << " " << depth << endl;
    treeDepth(node->left, depth);
    treeDepth(node->right, depth);

}


void treeWidth(node* node, int width)
{
    if(node == NULL)
    {
        return;
    }

    cout << node->data << " " << width<< endl;
    width++;
    treeWidth(node->left, width);
    width = width - 1;
    treeWidth(node->right, width);
}
