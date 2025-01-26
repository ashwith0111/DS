#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}n;
n* createnode(int data){
    n *p = malloc(sizeof(n)*1);
    p->data = data;
    p->next = NULL;
    return p;
}
int *array(n* link,int size){
    int i=0,*a = calloc(size,sizeof(int));
    n* temp = link;
    while(temp!=NULL){
        a[i] = temp->data;
        temp = temp->next;
        i++;
    }
    return a;
}
int main()
{
    int var,size=0;
    printf("Give the first element and when you want to stop the pres -1: ");
    scanf("%d",&var);
    n* head = createnode(var),*temp = head;
    while(1){
        scanf("%d",&var);
        if(var==-1){
            break;
        }
        temp->next = createnode(var);
        temp = temp->next;
        size++;
    }
    int *p = array(head,size);
    int i=0;
    while(size>=i){
        printf("%d ",p[i]);
        i++;
    }
}