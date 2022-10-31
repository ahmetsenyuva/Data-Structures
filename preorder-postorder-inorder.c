#include <stdio.h>
#include <stdlib.h>

//AHMET SENYUVA 181180067

struct BST {//create a struct
    struct BST* left;
    int data;
    struct BST* right;
};

typedef struct BST node;

node* createNode(int n){//create a node
    node* newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->left=newnode->right=NULL;
    return newnode;
}

node* insert(node* root, int n){//add numbers to the node
    if(root==NULL)
    {
        root=createNode(n);
    }
    else if(n<=root->data){
        root->left=insert(root->left,n);
    }
    else{
        root->right=insert(root->right,n);
    }
    return root;
}

void print_preorder(node * root)//print numbers by preorder method
{
    if (root)
    {
        printf("%d\t",root->data);
        print_preorder(root->left);
        print_preorder(root->right);
    }
   // printf("\n");

}

void print_inorder(node * root)//print numbers by inorder method
{
    if (root)
    {
        print_inorder(root->left);
        printf("%d\t",root->data);
        print_inorder(root->right);
    }
   // printf("\n");
}

void print_postorder(node * root)//print numbers by postorder method
{
    if (root)
    {
        print_postorder(root->left);
        print_postorder(root->right);
        printf("%d\t",root->data);
    }
    //printf("\n");
}

int main()
{
    srand(time(NULL));//have different values for each running time
    int randomnumber;
    node* root = NULL;
    //struct treeNode root = NULL;
int i = 0;
int array[10];

while ( i < 10 ) {//to have different random values
      int r = rand() % 25 + 1;
      int j;


      for ( j = 0; j < i; j++ ) {
        if ( array[j] == r )
          break;}
      if ( j == i )
        array[i++] = r;
}

printf("The numbers being placed in three are:\n");

for(int i=0; i<10; i++){//different values to root
    root=insert(root,array[i]);
    printf("%d\t", array[i]);
}


    printf("\n");

    printf("The preorder traversal is:\n");
    print_preorder(root);
    printf("\n");

    printf("The inorder traversal is:\n");
    print_inorder(root);
    printf("\n");

    printf("The postorder traversal is:\n");
    print_postorder(root);
    printf("\n");

    return 0;
}
