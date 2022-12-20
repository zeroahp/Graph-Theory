#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//  Khai bao hang doi binh thuong
// #define Maxlenght 100
// typedef int ElementType;
// typedef struct {
//     ElementType Elements[Maxlength];
//     int         Front, Rear;
// }Queue; 


/*Khai bao hang doi bang DSLK*/
typedef int ElementType;
typedef struct Node{
    ElementType Element;
    struct Node* Next;
}Node;
typedef struct Node* Position;
typedef struct{
    Position Front, Rear;
}Queue;

void makenullQueue(Queue *pQ){
    Position Header = (Node*)malloc(sizeof(Node));
    Header->Next = NULL;
    pQ->Front = Header;
    pQ->Rear = Header;
} 

int emptyQueue(Queue Q){
    return Q.Front == Q.Rear;
}

// int fullQueue(Queue Q){
//     return (Q.Rear - Q.Front+1) == Maxlength;
// }

void enQueue(ElementType x, Queue *pQ){
    pQ->Rear->Next = (Node*)malloc(sizeof(Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next =  NULL;
}

void deQueue(Queue *pQ){
    if(!emptyQueue(*pQ)){
        Position T = pQ->Front;
        pQ->Front = pQ->Front->Next;
        free(T);
    }
}

int countQueue(Queue Q){
    int count = 0;
    Position T = Q.Front;
    while(T != Q.Rear){
        count ++;
        T = T->Next;
    }
    return count;
}
int main(){
    Queue Q;
    makenullQueue(&Q);
    int n,x;
    char c;
    scanf("%d",&n);
    getchar();
    while(n--){
        scanf("%c",&c);
        if(c == 'E'){
            scanf("%d",&x);
            getchar();
            enQueue(x,&Q);
            printf("%d\n",countQueue(Q));
        } 
        else if(c == 'D'){
            getchar();
            if(!emptyQueue(Q)){
                printf("%d ",Q.Front->Next->Element);
                deQueue(&Q);
                printf("%d\n",countQueue(Q));
            }
            else{
                printf("-1 0\n");
            } 
        }
    }
    return 0;
}