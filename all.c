#include <stdio.h>
#include <stdlib.h>

#define MAX 100

/*=========================================================
                    LINKED LIST
=========================================================*/

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertLinkedList(int value)
{
    struct Node *newNode;
    struct Node *temp;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if(newNode == NULL)
    {
        printf("\nMemory Allocation Failed!\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node Inserted Successfully.\n");
}

void displayLinkedList()
{
    struct Node *temp = head;

    if(head == NULL)
    {
        printf("\nLinked List is Empty.\n");
        return;
    }

    printf("\nLinked List:\n");

    while(temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void searchLinkedList(int value)
{
    struct Node *temp = head;
    int position = 1;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            printf("Element Found at Position %d\n", position);
            return;
        }

        temp = temp->next;
        position++;
    }

    printf("Element Not Found.\n");
}

void deleteLinkedList(int value)
{
    struct Node *temp = head;
    struct Node *previous = NULL;

    while(temp != NULL)
    {
        if(temp->data == value)
        {
            if(previous == NULL)
            {
                head = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }

            free(temp);

            printf("Node Deleted Successfully.\n");
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    printf("Element Not Found.\n");
}

/*=========================================================
                    STACK
=========================================================*/

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
    {
        printf("\nStack Overflow.\n");
        return;
    }

    top++;
    stack[top] = value;

    printf("Element Pushed.\n");
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow.\n");
        return;
    }

    printf("Deleted Element : %d\n", stack[top]);
    top--;
}

void peek()
{
    if(top == -1)
    {
        printf("\nStack Empty.\n");
        return;
    }

    printf("Top Element : %d\n", stack[top]);
}

void displayStack()
{
    int i;

    if(top == -1)
    {
        printf("\nStack Empty.\n");
        return;
    }

    printf("\nStack:\n");

    for(i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}
/*=========================================================
                    QUEUE
=========================================================*/

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int value)
{
    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow.\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    queue[rear] = value;

    printf("Element Enqueued Successfully.\n");
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow.\n");
        return;
    }

    printf("Deleted Element : %d\n", queue[front]);
    front++;

    if(front > rear)
    {
        front = -1;
        rear = -1;
    }
}

void displayQueue()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue Empty.\n");
        return;
    }

    printf("\nQueue Elements:\n");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

void queueFront()
{
    if(front == -1)
    {
        printf("\nQueue Empty.\n");
        return;
    }

    printf("Front Element : %d\n", queue[front]);
}

/*=========================================================
                BINARY SEARCH TREE
=========================================================*/

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *root = NULL;

struct TreeNode* createNode(int value)
{
    struct TreeNode *newNode;

    newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct TreeNode* insertBST(struct TreeNode *node, int value)
{
    if(node == NULL)
        return createNode(value);

    if(value < node->data)
        node->left = insertBST(node->left, value);

    else if(value > node->data)
        node->right = insertBST(node->right, value);

    return node;
}

int searchBST(struct TreeNode *node, int value)
{
    if(node == NULL)
        return 0;

    if(node->data == value)
        return 1;

    if(value < node->data)
        return searchBST(node->left, value);

    return searchBST(node->right, value);
}

void inorder(struct TreeNode *node)
{
    if(node == NULL)
        return;

    inorder(node->left);
    printf("%d ", node->data);
    inorder(node->right);
}
/*=========================================================
        BST PREORDER & POSTORDER TRAVERSAL
=========================================================*/

void preorder(struct TreeNode *node)
{
    if(node == NULL)
        return;

    printf("%d ", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(struct TreeNode *node)
{
    if(node == NULL)
        return;

    postorder(node->left);
    postorder(node->right);
    printf("%d ", node->data);
}

/*=========================================================
                        MAIN
=========================================================*/

int main()
{
    int choice;
    int value;

    while(1)
    {
        printf("\n====================================\n");
        printf(" DATA STRUCTURES IMPLEMENTATION\n");
        printf("====================================\n");

        printf("1. Linked List Insert\n");
        printf("2. Linked List Delete\n");
        printf("3. Linked List Search\n");
        printf("4. Display Linked List\n");
        printf("5. Stack Push\n");
        printf("6. Stack Pop\n");
        printf("7. Stack Peek\n");
        printf("8. Display Stack\n");
        printf("9. Queue Enqueue\n");
        printf("10. Queue Dequeue\n");
        printf("11. Display Queue\n");
        printf("12. Queue Front\n");
        printf("13. BST Insert\n");
        printf("14. BST Search\n");
        printf("15. BST Inorder\n");
        printf("16. BST Preorder\n");
        printf("17. BST Postorder\n");
        printf("18. Exit\n");

        printf("\nEnter Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter Value : ");
                scanf("%d",&value);
                insertLinkedList(value);
                break;

            case 2:
                printf("Enter Value : ");
                scanf("%d",&value);
                deleteLinkedList(value);
                break;

            case 3:
                printf("Enter Value : ");
                scanf("%d",&value);
                searchLinkedList(value);
                break;

            case 4:
                displayLinkedList();
                break;

            case 5:
                printf("Enter Value : ");
                scanf("%d",&value);
                push(value);
                break;

            case 6:
                pop();
                break;

            case 7:
                peek();
                break;

            case 8:
                displayStack();
                break;

            case 9:
                printf("Enter Value : ");
                scanf("%d",&value);
                enqueue(value);
                break;

            case 10:
                dequeue();
                break;

            case 11:
                displayQueue();
                break;

            case 12:
                queueFront();
                break;

            case 13:
                printf("Enter Value : ");
                scanf("%d",&value);
                root = insertBST(root, value);
                printf("Node Inserted Successfully.\n");
                break;

            case 14:
                printf("Enter Value : ");
                scanf("%d",&value);

                if(searchBST(root,value))
                    printf("Node Found.\n");
                else
                    printf("Node Not Found.\n");

                break;

            case 15:
                printf("\nBST Inorder : ");
                inorder(root);
                printf("\n");
                break;

            case 16:
                printf("\nBST Preorder : ");
                preorder(root);
                printf("\n");
                break;

            case 17:
                printf("\nBST Postorder : ");
                postorder(root);
                printf("\n");
                break;

            case 18:
                printf("\nThank You!\n");
                return 0;

            default:
                printf("\nInvalid Choice.\n");
        }
    }

    return 0;
}