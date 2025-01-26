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
int main()
{
    int no,var;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&no);
    int a[no];
    for(int i=0;i<no;i++){
        scanf("%d",&a[i]);
    }
    n* temp_head = createnode(a[0]),*temp = temp_head;
    for(int i=1;i<no;i++){
        temp->next = createnode(a[i]);
        temp = temp->next;
    }
    printf("linked list created successfully\n");
    printf("Give the data of node to be inserted at starting: ");
    scanf("%d",&var);
    n* head = createnode(var);
    head->next = temp_head;
    temp = head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}