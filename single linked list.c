/* Create a singlr link list with 5 nodes. 
use traversal function to count the number of nodes present in the link list.
insert a node at the beginning of this list.
*/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node*head,*tail=NULL;
void addnode(int data){
	struct node*newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	
	if(head == NULL){
		head=newnode;
		tail=newnode;
	}
	else{
		tail->next=newnode;
		tail=newnode;
	}
}
void display(){
	struct node *current=head;
	if(head==NULL){
		printf("List is empty \n");
		return;
	}
	printf("\n");
	while(current!=NULL){
		printf("%d",current->data);
		current=current->next;
		printf("\t");
	}	
}
int countNodes() {
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void insertAtBeginning(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = head;
    head = newnode;
    if (tail == NULL) {
        tail = newnode;
    }
}
void insertAtEnd(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    
    if (head == NULL) {  
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;  
        tail = newnode;  
    }
}
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    
    if (head == NULL) { 
        tail = NULL;
    }

    free(temp);
    printf("\nNode deleted from the beginning.\n");
}
void deleteAtEnd(){
	    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return;
    }
    
    if (head == tail) {  
        free(head);
        head = tail = NULL;
    } else {
        struct node* current = head;
        while (current->next != tail) { 
            current = current->next;
        }
        free(tail);  
        tail = current; 
        tail->next = NULL;
    }
    printf("\nNode deleted from the end.\n");
}
void randominsert(int value, int n){
    struct node* ptr = malloc(sizeof(struct node));
    ptr->data=value;
    int i;
    struct node* temp = malloc(sizeof(struct node));
    temp=head;
    for(i=1;i<n-1;i++)
	{
        temp=temp->next;
        if(temp==NULL)
		{
            printf("\ncan't insert\n");
            return;
        }
    }

    ptr->next=temp->next;
    temp->next=ptr;
    printf("\nNode inserted");
}
void deleteran(int n) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node* temp = head;
    int i;
    for (i = 1; i < n - 1; i++) {
        if (temp == NULL || temp->next == NULL) {
            printf(" empty linked list.\n");
            return;
        }
        temp = temp->next;
    }
    struct node* nodeToDelete = temp->next;
    if (nodeToDelete == NULL) {
        printf(" No node to delete.\n");
        return;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void reverse() {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    tail = head;  

    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current; 
        current = next;     
    }
    head = prev;
}
void sortList() {
    struct node *current = head, *index = NULL;
    int temp;
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
}
int main(){
	addnode(40);
	addnode(2);
	addnode(3);
	addnode(4);
	addnode(6);
	display();
	printf("\n");
    int nodeCount = countNodes();
    printf("Number of nodes in the linked list: %d\n", nodeCount);
    insertAtBeginning(7);
    display();
    insertAtEnd(8);
    display();
    deleteAtBeginning();
    display();
    deleteAtEnd();
    display();
    randominsert(30,1);
    display();
    deleteran(4);
    display();
    reverse();
    display();
    sortList();
    display();
	return 0;
}
