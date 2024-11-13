#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to insert a node at the beginning
struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

// Function to insert a node at the end
struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    return head;
}

// Function to insert a node in sorted order
struct Node *sortedInsert(struct Node *head, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    if (head->data >= value)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    struct Node *current = head;
    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL)
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;

    return head;
}

// Function to display the linked list
void display(struct Node *head)
{
    struct Node *current = head;
    printf("Doubly Linked List: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to delete a node by value
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            if (current->prev != NULL)
            {
                current->prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            if (current->next != NULL)
            {
                current->next->prev = current->prev;
            }
            free(current);
            break;
        }
        current = current->next;
    }
    return head;
}

// Function to count the number of nodes in the list
int count(struct Node *head)
{
    struct Node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        c++;
    }
    return c;
}

// Function to find and display the middle node(s)
void middle(struct Node *head)
{
    int i;
    int n = count(head);
    struct Node *temp = head;
    if (n % 2 != 0)
    {
        for (i = 1; i < (n + 1) / 2; i++)
        {
            temp = temp->next;
        }
        printf("The middle node data is: %d\n", temp->data);
    }
    else
    {
        for (i = 1; i < n / 2; i++)
        {
            temp = temp->next;
        }
        printf("The data of middle nodes are: %d and %d\n", temp->data, temp->next->data);
    }
}

// Function to check if the list is a palindrome
void palindrome(struct Node *head) 
{
    if (head == NULL) {
        printf("The list is a palindrome.\n");
        return;
    }

    struct Node *left = head;
    struct Node *right = head;

    // Move right to the end of the list
    while (right->next != NULL) {
        right = right->next;
    }

    // Compare nodes from the start and end
    while (left != NULL && right != NULL && left != right && left->prev != right) {
        if (left->data != right->data) {
            printf("The list is not a palindrome.\n");
            return;
        }
        left = left->next;
        right = right->prev;
    }

    printf("The list is a palindrome.\n");
}

int main()
{
    struct Node *head = NULL;

    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    display(head);

    head = sortedInsert(head, 35);
    display(head);

    head = deleteByValue(head, 35);
    display(head);
    middle(head);
    palindrome(head);  // Corrected function call
    return 0;
}
