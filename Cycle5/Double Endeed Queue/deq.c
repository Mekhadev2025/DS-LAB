#include <stdio.h>
#include <stdlib.h>

struct node

{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL, *tail = NULL;

struct node *createNode(int data)

{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = newnode->prev = NULL;
    return (newnode);
}

void createSentinels()
{

    head = createNode(0);
    tail = createNode(0);
    head->next = tail;
    tail->prev = head;
}

void enqueueAtFront(int data)
{
    struct node *newnode, *temp;
    newnode = createNode(data);
    temp = head->next;
    head->next = newnode;
    newnode->prev = head;

    newnode->next = temp;
    temp->prev = newnode;
}

void enqueueAtRear(int data)

{
    struct node *newnode, *temp;
    newnode = createNode(data);

    temp = tail->prev;
    tail->prev = newnode;
    newnode->next = tail;
    newnode->prev = temp;
    temp->next = newnode;
}

void dequeueAtFront()
{

    struct node *temp;
    if (head->next == tail)

    {
        printf("Queue is empty\n");
    }

    else
    {
        temp = head->next;
        head->next = temp->next;
        temp->next->prev = head;

        free(temp);
    }
    return;
}


void dequeueAtRear()

{
    struct node *temp;
    if (tail->prev == head)

    {
        printf("Queue is empty\n");
    }
    else
    {

        temp = tail->prev;
        tail->prev = temp->prev;
        temp->prev->next = tail;
        free(temp);
    }

    return;
}


void display()
{
    struct node *temp;

    if (head->next == tail)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = head->next;
    while (temp != tail)
    {

        printf("%-3d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int data, ch,c,d;
    
    createSentinels();
    while (1)

    {
        printf("1. Input Restricted Dequeue\n2. Output Restricted Dequeue\n");
        
        printf("3. Display\n4. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {

        case 1:
            c=0;
           while(c<5){
           printf("1. Enqueue at front\n");
           printf("2. Dequeue at front\n3. Dequeue at rear\n4. Display\n 5. Exit\n");
           printf("Enter your choice:");
           scanf("%d", &c);

          switch (c){
           case 1:
            printf("Enter the data to insert:");
            scanf("%d", &data);
            enqueueAtFront(data);
            break;
           case 2:
              dequeueAtFront();
              break;

           case 3:
              dequeueAtRear();
              break;
           case 4:
            display();
            break;
           case 5:
           break;

           
              
          }
           }
           break;

        case 2:
         d=0;
         while(d<5){
         
            printf("1. Enqueue at front\n2. Enqueue at rear\n");
            printf("3. Dequeue at Rear\n4. Display\n5. Exit\n");

            printf("Enter your choice:");
           scanf("%d", &d);

          switch (d){
            case 1:
            printf("Enter the data to insert:");
            scanf("%d", &data);
            enqueueAtFront(data);
            break;
           case 2:
            printf("Enter ur data to insert:");
            scanf("%d", &data);
            enqueueAtRear(data);
            break;

        case 3:
             dequeueAtRear();
            break;

        case 4:
          display();
            break;
        case 5:
           break;          
         }
         }
         break;

        case 3:
            display();
            break;

        case 4:
            exit(0);

        default:
            printf(" enter correct option\n");
            break;
        }
    }
    return 0;
}
