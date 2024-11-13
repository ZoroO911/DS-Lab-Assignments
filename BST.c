#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};


struct node* createNode(int data){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct node* search(struct node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    } else if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inorderTraversal(struct node* root){
    if (root==NULL){
        return ;
    }
    inorderTraversal(root->left);
    printf("%d",root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct node* root){
    if (root==NULL){
        return ;
    }
    printf("%d",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct node* root){
    if (root==NULL){
        return ;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d",root->data);
}

void count(struct node* root,int *n){
    if (root==NULL){
        return ;
    }
    count(root->left,n);
    (*n)++;
    count(root->right,n);
}

void treetosll(struct node* root, struct node** head, struct node** tail) {
    if (root == NULL) {
        return;
    }

    treetosll(root->left, head, tail);
    struct node* newnode = createNode(root->data);
    
    if (*head == NULL) {
        *head = newnode;
    } else {
        (*tail)->right = newnode;
    }
    *tail = newnode;
    treetosll(root->right, head, tail);
}

struct node* minimum(struct node* root) {
    if (root == NULL) {
        return NULL;  
    }
    struct node* temp=root;
    while (temp->left != NULL) {
        temp = temp->left;  
    }
    return temp;
}

struct node* maximum(struct node* root){
	if(root == NULL){
		return NULL;
	}
	struct node* temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	return temp;
}

struct node* deletenode(struct node* root, int key) {
    if (root == NULL) {
        return root;  
    }

    // Search the node to be deleted
    if (key < root->data) {
        root->left = deletenode(root->left, key);
    } else if (key > root->data) {
        root->right = deletenode(root->right, key);
    } else {
        // No left child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        //No right child
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        //Node has two children
        // Minimum value in right subtree
        struct node* temp = minimum(root->right);

        //put next value in the deleted node 
        root->data = temp->data;

        // Delete the in-order successor
        root->right = deletenode(root->right, temp->data);
    }
    
   return root;
}

void ksmall(struct node* root, int n, int k){
    struct node* tail=NULL;
    struct node* head=NULL; 
    treetosll(root,&head,&tail);
    if(k==0){}
    else{
        int i;
        for(i=1;i<k;i++){
            head=head->right;
        }
        printf("%d",head->data);
    }
}

void klarge(struct node* root, int n, int k){
    struct node* tail=NULL;
    struct node* head=NULL; 
    treetosll(root,&head,&tail);
    if(k==0){}
    else{
        int i;
        for(i=1;i<n-k+1;i++){
            head=head->right;
        }
        printf("%d",head->data);
    }
}

int checkBST(struct node* root, int minimum, int maximum) {
    if (root == NULL) {
        return 1;
    }
    if (root->data <= minimum || root->data >= maximum) {
        return 0;
    }
    return checkBST(root->left, minimum, root->data) &&
           checkBST(root->right, root->data, maximum);
}

void isBST(struct node* root) {
    if (checkBST(root, 0, 9) == 1) {
        printf("The tree is a binary search tree.\n");
    } else {
        printf("The tree is not a binary search tree.\n");
    }
}

void pred_succ(struct node* root, int value) {
    struct node* temp= root;
    while (temp->left != NULL && temp->right!=NULL) {
        if (temp->left->data == value) {
            printf("Parent node: %d\n",temp->data);
            if(temp->left->left!=NULL){
                printf("Succesor: %d",temp->left->left->data);
            }
            if(temp->left->right!=NULL){
                printf("Succesor: %d",temp->left->right->data);
            }
            return;
        } else if(temp->right->data == value){
            printf("Parent node: %d\n",temp->data);
            if(temp->right->left!=NULL){
                printf("Succesor: %d",temp->right->left->data);
            }
            if(temp->right->right!=NULL){
                printf("Succesor: %d",temp->right->right->data);
            }            
            return;
        }else if (value < temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }  
}

int findHeight(struct node* root) {
    if (root == NULL) {
        return -1;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

struct node* arrtotree(int arr[], int n) {
    struct node* root = NULL;
    int i;
    for ( i = 0; i < n; i++) {
        root = insertNode(root, arr[i]);
    }
    return root;
}

struct node* sllToBST(struct node* head) {
    if (head == NULL) 
	{return NULL;}

    struct slltoBST* root = NULL;
    struct node* temp = head;
    
    while (temp != NULL) {
        root = insertNode(root, temp->data);
        temp = temp->right;
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int arr[10] = {4, 2, 1, 7, 5, 6, 3, 9, 8, 0};
    root = arrtotree(arr, 10);
    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");
    printf("Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postorderTraversal(root);
    printf("\n");
    isBST(root);
    int k = 2;
    printf("The %d-th smallest element: ", k);
    ksmall(root, 10, k);
    printf("\n");
    k = 3;
    printf("The %d-th largest element: ", k);
    klarge(root, 10, k);
    printf("\n");
    int value = 7;
    struct node* foundNode = search(root, value);
    if (foundNode) {
        printf("Node %d found in the tree.\n", value);
    } else {
        printf("Node %d not found in the tree.\n", value);
    }
    int deleteValue = 5;
    printf("Deleting node %d...\n", deleteValue);
    root = deletenode(root, deleteValue);

    printf("Inorder Traversal after deletion: ");
    inorderTraversal(root);
    printf("\n");
    int height = findHeight(root);
    printf("Height of the tree: %d\n", height);

    return 0;
}
