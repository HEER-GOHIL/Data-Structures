
#include <iostream>
#include<queue>
using namespace std;

//node structure
struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent; //to store the address of the parent - not used anywhere else in the code except one function
};
// Creating a Node
Node* createnode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
Node* insert(Node* root, int data)
{
    if(root==NULL)
    {
        root = createnode(data);
    }
    else if(data>root->data)
    {
        root->right = insert(root->right,data);
    }
    else
    {
        root->left = insert(root->left,data);
    }
    return root;
}
// boolean search 
bool search(Node* root, int data)
{
    if(root==NULL)
    {
        return false;
    }
    if(data == root->data)
    {
        return true;
    }
    else if(root->data > data)
    {
       return search(root->left,data);
    }
    else
    {
        return search(root->right,data);
    }
}
    //--------------------------------------find minimum element------------------------------------------------
int searchmin(Node* root)
{
    Node* current = root;
    while(current->left!=NULL)
    {
        current = current->left;
    }
    return current->data;
}
//--------------------------------------find maximum element------------------------------------------------
    int searchmax(Node* root)
{
    Node* current = root;
    while(current->right!=NULL)
    {
        current = current->right;
    }
    return current->data;
}
//--------------------------------------HEIGHT OF THE TREE ------------------------------------------------
int findheight(struct Node* root)
{
    if(root == NULL)
    {
        return -1;
    }
    return(max(findheight(root->left),findheight(root->right)) + 1);
}
//--------------------------------------LEVEL ORDER FUNCTION ------------------------------------------------
void levelorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<Node*>q; //queue to a pointer
    q.push(root); 
    while(!q.empty()) //while there is atleast one discovered node run the loop
    {
        Node* current = q.front(); //data type is ptr to node
        cout<<current->data<<endl;
        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}
//--------------------------------------PREORDER FUNCTION------------------------------------------------
void preorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<endl; // preorder prints the data first
    preorder(root->left);
    preorder(root->right);
}
//--------------------------------------INORDER FUNCTION------------------------------------------------
void inorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
//--------------------------------------POSTORDER FUNCTION------------------------------------------------
void postorder(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<endl;

}
//-----------------------CHECK WHETHER A GIVEN SUBTREE IS BST OR NOT-----------------------------------------------
bool issubtreelesser(struct Node* root,int value)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<=value && issubtreelesser(root->left,value) && issubtreelesser(root->right,value))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool issubtreegreater(struct Node* root,int value)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data>value && issubtreegreater(root->left,value) && issubtreegreater(root->right,value))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool istreebstcheck(struct Node* root)
{
    if(root==NULL)
    {
        return true;
    }
    if(issubtreelesser(root->left,root->data) && issubtreegreater(root->right,root->data) && istreebstcheck(root->left) && istreebstcheck(root->right) )
    {
        return true;
    }
    else
    {
        return false;
    }
    
}
//---------------------------------------DELETE A NODE FROM A TREE-------------------------------------
//Function to find minimum in a tree. 
Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
struct Node* Delete(struct Node *root, int data) {
	if(root == NULL) return root;  //if leaf node is reached than return root
	else if(data < root->data) root->left = Delete(root->left,data);
	else if (data > root->data) root->right = Delete(root->right,data);
	// Wohoo... I found you, Get ready to be deleted	
	else {
		// Case 1:  No child
		if(root->left == NULL && root->right == NULL) { 
			delete root;
			root = NULL;
		}
		//Case 2: One child 
		else if(root->left == NULL) {
			struct Node *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL) {
			struct Node *temp = root;
			root = root->left;
			delete temp;
		}
		// case 3: 2 children
		else { 
			struct Node *temp = FindMin(root->right);
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		} 
	}
	return root;
}
//Find the inorder successor in a binary search tree

// driver code
int main()
{
    Node* root = NULL;
    root = insert(root,10);
    root = insert(root,2);
    root = insert(root,3);
    root = insert(root,4);
    root = insert(root,1);
    // root = insert(root,5); //to see the change in the height 
    root = insert(root,6);
    root = insert(root,31);
    root = insert(root,47);
    root = insert(root,9);
    //--------------------------------------search------------------------------------------------
    // int snum;
    // cout<<"Enter the number to bhe searched : ";
    // cin>>snum; //input the search number 
    // //call the search function
    // if(search(root,snum) == true) 
    // {
    //     cout<<"Found\n";
    // }
    // else 
    // {
    //     cout<<"Not Found\n";
    // }
    //--------------------------------------Minimum and maximum value------------------------------------------------
    // int fuck = 0;
    // fuck = searchmin(root);
    // cout<<fuck<<endl;
    // fuck = searchmax(root);
    // cout<<fuck;
    //--------------------------------------HEIGHT OF THE TREE------------------------------------------------
    // int htree;
    // htree = findheight(root);
    // cout<<htree; 
    //--------------------------------------LEVEL ORDER PRINT ------------------------------------------------
    // levelorder(root);
    //--------------------------------------PREORDER TRAVERSAL------------------------------------------------
    // preorder(root);
    //--------------------------------------INORDER FUNCTION------------------------------------------------
    // inorder(root);
    //--------------------------------------POSTORDER FUNCTION------------------------------------------------
    //postorder(root);
    //--------------------------------------CHECKING IF TREE IS BST------------------------------------------------
    // int bstans = istreebstcheck(root);
    // cout<<bstans<<endl;
    //--------------------------------------Deleting a Node------------------------------------------------
    // if the node has 2 children - Find minimum in the right subtree and delete the minimum node from the subtree
    //or or or find maximum in left subtree and replace the node to be deleted by that value and than delete the max in left subtree
    root = Delete(root,6);
    inorder(root);
    return 0;
    
}
