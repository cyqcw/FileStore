#include<bits/stdc++.h>
using std::vector;
typedef struct node{
    int val;
    struct node* left;
    struct node* right;
}TreeNode;
TreeNode* buildTree(int* preorder,int* inorder,int Size){
    if(Size==0)return NULL;
    int num=preorder[Size-1];
    // printf("(%d)",num);
    int i;
    for(i=0;i<Size;i++)
        if(inorder[i]==num)break;
    int leftSize=i,rightSize=Size-i-1;
    TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
    root->val=num;
    root->left=buildTree(preorder,inorder,leftSize);
    root->right=buildTree(preorder+i,inorder+i+1,rightSize);
    return root;
}
void mid(TreeNode* root){
    if(root){
        mid(root->left);
        printf("%d ",root->val);
        mid(root->right);
    }
}
void later(TreeNode* root){
    if(root){
        later(root->left);
        later(root->right);
        printf("%d ",root->val);
    }
}
void before(TreeNode* root){
    if(root){
        printf("%d ",root->val);
        before(root->left);
        before(root->right);
    }
}
//  层序遍历
void LevelOrderTraverse(TreeNode* root){
    TreeNode* array[100];
    int top=0,tail=0,tempTail=0;
    array[tail++]=root;
    while(top<tail){
        tempTail=tail;
        while(top<tempTail){
            printf("%d ",array[top]->val);
            if(array[top]->left){
                array[tail++]=array[top]->left;
            }
            if(array[top]->right){
                array[tail++]=array[top]->right;
            }top++;
        }
    }printf("\n");
}
int main(){
    int n;
    scanf("%d",&n);
    int* postOrder=(int*)malloc(n*sizeof(int));
    int* innerOrder=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&postOrder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&innerOrder[i]);
    }
    TreeNode* root=buildTree(postOrder,innerOrder,n);
    // before(root);
    // printf("\n");
    // mid(root);
    // printf("\n");
    // later(root);
    // printf("\n");
    LevelOrderTraverse(root);
}