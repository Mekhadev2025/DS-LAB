 #include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
}*head = NULL;

void insert_e(int value)
{
    struct Node *newNode;
    struct Node *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (head == NULL)
    {
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
    }
}
void insert_a(int value,int data){
    struct Node *newNode;
    struct Node *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    while(temp->data != data && temp->next != NULL){
        temp = temp->next;
    }
    if (temp->data == data){
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
    }
    else{
        printf("Data not found\n");
    }
}
void insert_b(int value,int data){
    struct Node *newNode;
    struct Node *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    while(temp->next->data != data && temp->next != NULL){
        temp = temp->next;
    }
    if (temp->next->data == data){
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
    }
    else{
        printf("Data not found\n");
    }
}
void insert_p(int value,int position){
    struct Node *newNode;
    struct Node *temp = head;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    int i = 1;
    while(i < position && temp->next != NULL){
        temp = temp->next;
        i++;
    }
    if (i == position){
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;
        }
    }
    else{
        printf("Position not found\n");
    }
}
int delete_e(){
    struct Node *temp = head;
    int value;
    if(head == NULL){
        printf("List is empty\n");
    }
    else{
        value = temp->data;
        head = temp->next;
        head->prev = NULL;
        free(temp);
    }
    return value;
}
int delete_a(int data){
    struct Node *temp = head;
    int value;
    while(temp->data != data && temp->next != NULL){
        temp = temp->next;
    }
    if (temp->data == data){
        value = temp->data;
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    else{
        printf("Data not found\n");
    }
    return value;
}
int delete_p(int position){
    struct Node *temp = head;
    int value;
    int i = 0;
    while(i < position && temp->next != NULL){
        temp = temp->next;
        i++;
    }
    if (i == position){
        value = temp->data;
        temp->prev->next = temp->next;
        if(temp->next != NULL){
            temp->next->prev = temp->prev;
        }
        free(temp);
    }
    else{
        printf("Position not found\n");
    }
    return value;
}
int delete_min(){
    struct Node *temp = head;
    int value;
    int min = temp->data;
    while(temp->next != NULL){
        if(temp->data < min){
            min = temp->data;
        }
        temp = temp->next;
    }
    if(temp->data < min){
        min = temp->data;
    }
    printf("\nMinimum element is %d\n",min);
    temp = head;
    int element = delete_a(min);
    return element;
}
void display(){
    struct Node *temp = head;
    if (head == NULL){
        printf("List is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d --> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main()
{
    int choice, value, data, position, element;
    while(1){
        printf("---------------MENU---------------\n1. Insert at end\n2. Insert after\n3. Insert before\n4. Insert at position\n5. Delete at end\n6. Delete node\n7. Delete at position\n8. Delete minimum\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                insert_e(value);
                display();
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                printf("Enter the data after which the value is to be inserted: ");
                scanf("%d",&data);
                insert_a(value,data);
                display();
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                printf("Enter the data before which the value is to be inserted: ");
                scanf("%d",&data);
                insert_b(value,data);
                display();
                break;
            case 4:
                printf("Enter the value to be inserted: ");
                scanf("%d",&value);
                printf("Enter the position at which the value is to be inserted: ");
                scanf("%d",&position);
                insert_p(value,position);
                display();
                break;
            case 5:
                element = delete_e();
                printf("Deleted element is %d\n",element);
                display();
                break;
            case 6:
                printf("Enter the data of the element that is to be deleted: ");
                scanf("%d",&data);
                element = delete_a(data);
                printf("Deleted element is %d\n",element);
                display();
                break;
            case 7:
                printf("Enter the position at which the element is to be deleted: ");
                scanf("%d",&position);
                element = delete_p(position);
                printf("Deleted element is %d\n",element);
                display();
                break;
            case 8:
                element = delete_min();
                printf("Deleted element is %d\n",element);
                display();
                break;
            case 9:
                exit(0);
            default:    
                printf("Invalid choice\n");
        }
    }
}



