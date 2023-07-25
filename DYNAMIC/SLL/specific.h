NODE specific_pos(NODE head,int pos,NODE newnode)
{
    int i;
    NODE temp;
    temp=head;
    int n;
    n=count(head);
    //printf("%d",n);
    if(pos>=1 && pos<=n+1)
    {
        if(pos==1)
        {
            newnode->next=head;
            head=newnode;
            return head;
        }
        if(pos==n+1)
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            return head;
        }
        if(pos>1 && pos<n+1)
        {
            for(i=1;i<pos;i++)
            {
                temp=temp->next;
            }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
        }
    }
    else 
    {
        printf("invalid position\n");
        return head;
    }

}
int count(NODE head)
{
    int cnt=0;
    NODE temp;
    while(temp!=NULL)
    {
        cnt++;
        temp=temp->next;
        
    }
    printf("%d\n",cnt);
return cnt;
}          