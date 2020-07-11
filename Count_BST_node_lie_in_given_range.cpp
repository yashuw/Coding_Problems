#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
//Inserting a Node in BST
Node* insert(Node *root,int data)
{
  if(root==NULL)
    root=New Node(data);
  else if(data<root->data)
    root->left=insert(root->left,data);
  else
    root->right=insert(root->right,data);
  return root;
}

//Give Count of Nodes In a given range

int getCountOfNode(Node *root, int l, int h)
{
    queue<Node *>q;
    if(root->data>=h)
    {
        q.push(root->left);
    }
    else if(root->data<=l)
    {
        q.push(root->right);
    }
    else
    {
        q.push(root);
    }
    int count=0;
    while(!q.empty())
    {
        Node *node=q.front();
        q.pop();
        if(node->data>=l && node->data<=h)
        {
            count++;
        }
        if(node->left!=NULL)
        {
            q.push(node->left);
        }
        if(node->right!=NULL)
        {
            q.push(node->right);
        }
    }
    return count;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    Node *root=NULL;
    int n;
    cin>>;
    int arr[n];
    for(int i=0;i<n;i++)
      cin>>arr[i];
    for(int i=0;i<n;i++)
    {
      root=insert(root,arr[i]);
    }
    int l,h;
    cin>>l>>h;
    cout<<getCountofNode(root,l,h)<<"\n";
  }
}


/* Approach
--Its Done using Algorithm Of Level Order Traversal
--Queue DataStructure is used to Store the Level Wise Nodes in it.
  --If root_data > upper limit ,then push root->left node into queue
  --If root_data< lower limit,the push root->right node into queue
  --else we push root node into queue
--Next follow Level Order Traversal to count the nodes.
*/
