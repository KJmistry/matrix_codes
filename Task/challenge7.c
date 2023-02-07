#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int num1, int num2)
{
    if(num1 > num2)
        return num1;
    return num2;
}

struct node
{
    int data;
    struct node *next;
};

void *addNode(struct node *ptr, int value)
{
    ptr->next = (struct node *)malloc(sizeof(struct node));
    ptr->data = value - '0';
    ptr->next->next = NULL;
    return ptr->next;
}

void creatlist(struct node *head, char *list, int maxLen)
{
    struct node *temp;
    temp = addNode(head, list[strlen(list)-1]);

    for (int index = strlen(list)-2 ; index >= 0 ; index--)
    {
        temp = addNode(temp, list[index]);
    }
    if(strlen(list)<maxLen)
    {
        for (int index = 0 ; index < maxLen - strlen(list); index++)
        {
            temp = addNode(temp, '0');
        }
    }
}

void printList(struct node *ptr)
{
    printf("[ ");
    while (ptr->next != NULL)
    {
        printf("%d, ", ptr->data);
        ptr = ptr->next;
    }
    printf("]\n");
}

void* addTwoNumbers(struct node* iList1_Ptr, struct node* iList2_Ptr)
{   
    int carry = 0 , temp ;
    struct node *head3 = (struct node *)malloc(sizeof(struct node));
    struct node *tempPtr = head3;

    while (iList1_Ptr->next != NULL)
    {   
        temp = (iList1_Ptr->data + iList2_Ptr -> data) + carry;
        carry = 0;
        if(temp > 9)
        {
            temp %= 10;
            carry = 1;
        }
        // printf("%d\n", temp );
        tempPtr = addNode(tempPtr,temp+'0');
        iList1_Ptr = iList1_Ptr -> next;
        iList2_Ptr = iList2_Ptr -> next;
    }
    if(carry == 1)
    {
        // printf("1\n");
        tempPtr = addNode(tempPtr,1 +'0');

    }

    return head3;
}

void freeList(struct node *ptr)
{
    struct node *tPtr;
    while( ptr -> next != NULL)
    {
        tPtr = ptr -> next ;
        free(ptr); 
        ptr = tPtr;
    }
}
int main()
{

    char list1[] = "9999999";
    char list2[] = "999";

    struct node *head1 = (struct node *)malloc(sizeof(struct node));
    struct node *head2 = (struct node *)malloc(sizeof(struct node));

    struct node *ptr = NULL;
    int maxLen = max(strlen(list1),strlen(list2));
    creatlist(head1, list1, maxLen);
    creatlist(head2, list2, maxLen);

    
    printf("List1 (Number 1):  "); printList(head1);
    printf("List2 (Number 2):  "); printList(head2);

    ptr = addTwoNumbers(head1,head2);
    printf("List3 (Addition):  "); printList(ptr);

    freeList(head1);
    freeList(head2);
    freeList(ptr);
}