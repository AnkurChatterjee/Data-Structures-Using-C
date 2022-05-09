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
    int ch,m,n,pos;
    while(1)
    {
        printf("1. Create New List\n");
        printf("2. Add at beginning\n");
        printf("3. Add after\n");
        printf("4. Delete\n");
        printf("5. Display List\n");
        printf("6. Reverse List\n");
        printf("7. Search\n");
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
                    for(int i=0;i<n;i++)
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
                    printf("Enter element: ");
                    scanf("%d",&m);
                    addAtBeg(m);
                    break;

            case 3: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    printf("\nEnter the position after which element is to be inserted: ");
                    scanf("%d",&pos);
                    printf("Enter element: ");
                    scanf("%d",&m);
                    addAfter(m,pos);
                    break;

            case 4: if(start==NULL)
                    {
                        printf("List is empty. Nothing to delete.\n\n");
                        continue;
                    }
                    printf("\nEnter the element to be deleted: ");
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
                    reverseList();
                    break;

            case 7: if(start==NULL)
                    {
                        printf("List is empty. Create list first.\n\n");
                        continue;
                    }
                    printf("Enter the element to be searched: ");
                    scanf("%d",&m);
                    searchList(m);
                    break;

            case 8: disposeList();
                    exit(0);

            default: printf("Wrong Choice.\n");
        }
        printf("\n");
    }
}
createList(int data)
{
    node *temp,*q;
    q=start;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    if(start==NULL)
        start=temp;
    else
    {
        while(q->link!=start)
            q=q->link;
        q->link=temp;
    }
    temp->link=start;
}
addAtBeg(int data)
{
    node *temp,*q;
    q=start;
    while(q->link!=start)
        q=q->link;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    temp->link=start;
    start=temp;
    q->link=start;
}
addAfter(int data, int position)
{
    node *q,*temp;
    q=start;
    temp=(node *)malloc(sizeof(node));
    temp->info=data;
    for(int i=1;i<position;i++)
    {
       q=q->link;
       if(q==start)
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
    node *q,*temp,*q1;
    q=start;
    q1=start;
    if(q->info==data)
    {
        while(q1->link!=start)
            q1=q1->link;
        temp=q;
        start=q->link;
        q1->link=start;
        if(q1==q)
            start=NULL;
        free(temp);
        return;
    }
    while(q->link->link!=start)
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
        q->link=start;
        free(temp);
        return;
    }
    printf("\nElement not found in list.\n");
}
display()
{
    node *q=start;
    if(start==NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nThe list is:\n");
    while(q->link!=start)
    {
        printf("%d -> ",q->info);
        q=q->link;
    }
    printf("%d -> ",q->info);
    printf("%d\n",start->info);
}
reverseList()
{
    node *q1,*q2,*q3;
    q1=start;
    q2=q1->link;
    q3=q2->link;

    q2->link=q1;
    while(q3->link!=start)
    {
        q1=q2;
        q2=q3;
        q3=q3->link;
        q2->link=q1;
    }
    q3->link=q2;
    start->link=q3;
    start=q3;
}
searchList(int data)
{
    node *q=start;
    int i=1;
    if(q->info==data)
    {
        printf("\nElement %d found at position 1.\n",data);
        return;
    }
    while(q->link!=start)
    {
        q=q->link;
        i++;
        if(q->info==data)
        {
            printf("\nElement %d found at position %d.\n",data,i);
            return;
        }
    }
    printf("\nElement %d not found in list.\n",data);
}
disposeList()
{
    node *q,*temp;
    q=start;
    while(q->link!=start)
    {
        temp=q;
        q=q->link;
        free(temp);
    }
    temp=q;
    free(temp);
}
