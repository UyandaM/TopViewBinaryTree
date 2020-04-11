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
void treeDepth(node* node, int depth, vector<int>& depths, vector<int>& data);
void treeWidth(node* node, int width, vector<int>& widths);
void widthSort(vector<int>& widths, vector<int>& depths, vector<int>& data);

// Driver code
int main()
{
    node *root = newNode(1);

    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    vector<int> depths;
    vector<int> widths;
    vector<int> data;

    int depth = 0;

    treeDepth(root, depth, depths, data);

    cout << endl << endl << endl;

    int width = 0;
    treeWidth(root, width, widths);

    cout << endl << endl << endl;

    widthSort(widths, depths, data);




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



void treeDepth(node* node, int depth, vector<int>& depths, vector<int>& data)
{
    if(node == NULL)
    {
        return;
    }


    depth++;
    cout << node->data << " " << depth << endl;
    data.push_back(node->data);
    depths.push_back(depth);
    treeDepth(node->left, depth, depths, data);
    treeDepth(node->right, depth, depths, data);

}


void treeWidth(node* node, int width, vector<int>& widths)
{
    if(node == NULL)
    {
        return;
    }

    cout << node->data << " " << width<< endl;
    widths.push_back(width);
    width--;
    treeWidth(node->left, width, widths);
    width += 2;
    treeWidth(node->right, width, widths);
}

void widthSort(vector<int>& widths, vector<int>& depths, vector<int>& data)
{
    cout << "width\tdepth\tdata\n";
    for(int i = 0; i < data.size(); i++)
    {
        cout << widths.at(i) << "\t" << depths.at(i) << "\t"<< data.at(i) << endl;
    }
    cout << endl << endl << endl;
    cout << endl << endl << endl;

    int temp = 0;
    int mysize = data.size();
    for(int i = 0; i < data.size() - 1; i++)
    {
        for (int j = i + 1; j < data.size(); j++)
        {
            if (widths.at(i) > widths.at(j))
            {
                temp = widths.at(i);
                widths.at(i) = widths.at(j);
                widths.at(j) = temp;

                temp = data.at(i);
                data.at(i) = data.at(j);
                data.at(j) = temp;

                temp = depths.at(i);
                depths.at(i) = depths.at(j);
                depths.at(j) = temp;
            }
        }
    }
    cout << endl << endl << endl;
    cout << endl << endl << endl;
    cout << "width\tdepth\tdata\n";
    for(int i = 0; i < data.size(); i++)
    {
        cout << widths.at(i) << "\t" << depths.at(i) << "\t"<< data.at(i) << endl;
    }
}



