// A C Program to implement circular queue.
// In circular Queue we use Circular increment of the front and rear using % 

#include<stdio.h>
#define Max_Size 5

int Queue[Max_Size];
int front=-1,rear=-1;

//Function to Insert an Element into the Queue
void enqueue(int element){

    if ((front==0 && rear==Max_Size-1)||(rear==front-1)){
        printf("Queue is Full\n");
    }
    
    else{
        if (front==-1 && rear==-1){
        front=0;
        rear=0;
        Queue[rear]=element;
        }

        else{
            rear=(rear+1)%Max_Size;
            Queue[rear]=element;
        }
        printf("%d added to Queue\n",element);
    }
}

// Function to Remove an Element from the Queue
void dequeue(){
    if (front==-1){
        printf("Queue is Empty\n");
    }
    else{
        int del=Queue[front];
        if (front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%Max_Size;
        }     
        printf("%d removed from the Queue\n",del);    
    }  
}

// Function to display the First element in the Queue
void Front(){
    if (front==rear){
      printf("Queue is Empty\n");  
    }
    else{
        printf("Front : %d\n",Queue[front]);
    }
}

// Function to display the Last element in the Queue
void Rear(){
    if (front==rear){
        printf("Queue is Empty\n");
    }
    else{
        printf("Rear : %d\n",Queue[rear]);
    }
}

//Function to Display the Queue
void display(){
    if (front==-1){
        printf("Queue is Empty\n");
    }
    else{
        int i;
        printf("Queue :");
        for (i = front; i!=rear; i=(i+1)%Max_Size){
            printf("%d ",Queue[i]);
        }   
        printf("%d\n",Queue[i]);
    }
    
}

// Main Function to inplement Circular Queue

#include<stdio.h>
#include<stdlib.h>

void main(){

    int option,data;
        printf("\n+---------------------------------------------------------+\n");
        printf("|  1 : Enqueue                                            |\n");
        printf("|  2 : Dequeue                                            |\n");
        printf("|  3 : Front                                              |\n");
        printf("|  4 : Rear                                               |\n");
        printf("|  5 : Display                                            |\n");
        printf("|  6 : exit                                               |\n");
        printf("+---------------------------------------------------------+\n");

    while (1){     
        printf("Choose a Option: ");
        scanf("%d",&option);
        
        switch (option){
        
        case 1:
            printf("Enter the Element: ");
            scanf("%d",&data);
            enqueue(data);
            break;

        case 2:
            dequeue();
            break;
        case 3:
            Front();
            break;

        case 4:
            Rear();
            break;

        case 5:
            display();
            break;

        case 6:
            exit(0);
            break;

        default:
            printf("\nChoose a Valid Option\n");
            break;
        }
    }
}
