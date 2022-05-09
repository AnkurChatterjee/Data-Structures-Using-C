#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int info;
    struct node *link;
}node;
node *start=NULL;
int main()
{
    int ch,m,n,i,pos;
    while(1)
    {
        printf("1. Create New List\n");
        printf("2. Add at beginning\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display\n");
        printf("6. Search\n");
        printf("7. Reverse List\n");
        printf("8. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: if(start!=NULL)
                    {
                        disposeList();
                        start=NULL;
                    }
                    printf("\nEnter the number of nodes required: ");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                    {
                       printf("Enter element: ");
                       scanf("%d",&m);
                       createList(m);
                    }
                    break;

            case 2: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    printf("Enter the element: ");
                    scanf("%d",&m);
                    addAtBeg(m);
                    break;

            case 3: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    printf("Enter the position after which element is to be inserted: ");
                    scanf("%d",&pos);
                    printf("Enter the element: ");
                    scanf("%d",&m);
                    addAfter(m,pos);
                    break;

            case 4: if(start==NULL)
                    {
                        printf("List is empty. Nothing to delete.\n\n");
                        continue;
                    }
                    printf("Enter the element to be deleted: ");
                    scanf("%d",&m);
                    deleteNode(m);
                    break;

            case 5: display();
                    break;

            case 6: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    printf("Enter the element to be searched: ");
                    scanf("%d",&m);
                    searchList(m);
                    break;

            case 7: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    reverseList();
                    break;

            case 8: disposeList();
                    exit(0);

            default: printf("Wrong Choice!\n");
        }
        printf("\n");
    }
}
createList(int data)
{
    node *temp, *q;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else
    {
        q=start;
        while(q->link!=NULL)
        {
            q=q->link;
        }
        q->link=temp;
    }
}
addAtBeg(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->link=start;
    start=temp;
}
addAfter(int data, int position)
{
    node *temp, *q;
    int i;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    q=start;
    for(i=1;i<position;i++)
    {
        q=q->link;
        if(q==NULL)
        {
            printf("\nThere are less than %d elements in the list.\n",position);
            return;
        }
    }
    temp->link=q->link;
    q->link=temp;

}
deleteNode(int data)
{
    node *temp, *q;
    q=start;
    if(start->info==data)
    {
        temp=start;
        start=temp->link;
        free(temp);
        return;
    }
    while(q->link->link!=NULL)
    {
        if(q->link->info==data)
        {
            temp=q->link;
            q->link=temp->link;
            free(temp);
            return;
        }
        q=q->link;
    }
    if(q->link->info==data)
    {
        temp=q->link;
        q->link=NULL;
        free(temp);
        return;
    }
    printf("Element %d not found in list.\n",data);
}
display()
{
    node *q;
    q=start;
    if(start==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nThe list is:\n");
    while(q!=NULL)
    {
        printf("%d -> ",q->info);
        q=q->link;
    }
    printf("NULL\n");
}
searchList(int data)
{
    node *q;
    int i=1;
    q=start;
    while(q!=NULL)
    {
        if(q->info==data)
        {
            printf("\nElement %d found at position %d.\n",data,i);
            return;
        }
        i++;
        q=q->link;
    }
    if(q==NULL)
        printf("\nElement %d not found in list.\n",data);
}
reverseList()
{
    node *q1,*q2,*q3;
    if(start->link==NULL)
        return;
    q1=start;
    q2=q1->link;
    q3=q2->link;

    q1->link=NULL;
    q2->link=q1;
    while(q3!=NULL)
    {
        q1=q2;
        q2=q3;
        q3=q3->link;
        q2->link=q1;
    }
    start=q2;
}
disposeList()
{
    node *temp,*q;
    q=start;
    while(q!=NULL)
    {
        temp=q;
        q=q->link;
        free(temp);
    }
}
