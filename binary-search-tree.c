#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                return NULL;
        }
        if(node->left) 
                return FindMin(node->left);
        else 
                return node;
}
treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                
                return NULL;
        }
        if(node->right) 
                FindMax(node->right);
        else 
                return node;
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
       
        return node;

}

treeNode * Delete(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found");
        }
        else if(data < node->data)
        {
                node->left = Delete(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = Delete(node->right, data);
        }
        else
        {
                
                if(node->right && node->left)
                {
                        temp = FindMin(node->right);
                        node -> data = temp->data; 
                        
                        node -> right = Delete(node->right,temp->data);
                }
                else
                {
                        
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp);  
                }
        }
        return node;

}

treeNode * Find(treeNode *node, int data)
{
        if(node==NULL)
        {
                return NULL;
        }
        if(data > node->data)
        {
                return Find(node->right,data);
        }
        else if(data < node->data)
        {
                return Find(node->left,data);
        }
        else
        {
                return node;
        }
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        treeNode *root = NULL;
        root = Insert(root, 5);
        root = Insert(root, -1);
        root = Insert(root, 3);
        root = Insert(root, -14);
        root = Insert(root, 8);
        root = Insert(root, 10);
        root = Insert(root, 9);
        root = Insert(root, 6);
        PrintInorder(root);
        printf("\n");
        root = Delete(root,5);
        root = Delete(root,-1);
        PrintInorder(root);
        printf("\n");
        treeNode * temp;
        temp = FindMin(root);
        printf("Minimum element is %d\n",temp->data);
        temp = FindMax(root);
        printf("Maximum element is %d\n",temp->data);
        temp = Find(root,8);
        if(temp==NULL)
        {
                printf("Element 8 not found\n");
        }
        else
        {
                printf("Element 8 Found\n");
        }
        temp = Find(root,2);
        if(temp==NULL)
        {
                printf("Element 2 not found\n");
        }
        else
        {
                printf("Element 6 Found\n");
        }
}