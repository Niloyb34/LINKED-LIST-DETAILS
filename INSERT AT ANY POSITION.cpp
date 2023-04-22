#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};
void print(Node*&head)
{
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void insertAThead(Node*&head,int d)
{
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;

}
void insertATtail(Node*&tail,int d)
{
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;

}
void insertATposition(Node*&head,Node *&tail,int value,int position)
{

    if(position==1)///starting position e add kora mane head e add kora tahole first position e add kora hoi jabe
    {
        insertAThead(head,value);
        return;///akta value ke majkane input korar por tou sesh just
    }
    Node *temp=head;///mane head take akon temp namok arekta pointer point kore
    int cnt=1;//mane head node tar jnno cnt er man 1 hobe
    while(cnt<position-1)
    {
       temp=temp->next;
       cnt++;
    }
    if(temp->next==NULL)
    {
        insertATtail(tail,value);
        return ;
    }
    ////creating a new node which we have to insert
    Node *nodeTOinsert=new Node(value);
    nodeTOinsert->next=temp->next;
    temp->next=nodeTOinsert;
}
int main()
{
    int n,i,k,m;
    Node *node1=new Node(10);
    ///mane new dia akta node typer object create korlam jeta constructor ke call kore Node er value take 10 assign kore dibe
    Node *head=node1;
    Node *tail=node1;
    cout<<"Initially the linked list: ";
    print(head);
    cout<<endl;
    cout<<"How many numbers you want to add at head-->";
    cin>>k;
    cout<<"Enter the numbers:"<<endl;
    for(i=0;i<k;i++)
    {
        cin>>m;
        insertAThead(head,m);
    }
    cout<<"After head insertion : ";print(head);cout<<endl;
    cout<<"How many numbers you want to add at tail ?  ";
    cin>>m;
    cout<<"Enter the numbers : "<<endl;
    for(i=0;i<m;i++)
    {
        cin>>k;
        insertATtail(tail,k);
    }
    print(head);
    cout<<endl;
    cout<<"INSERT AT ANY POSITION"<<endl;
    cout<<"Which number you want to add ?";
    cin>>n;
    cout<<endl;
    cout<<"In which position?";
    cin>>i;
    insertATposition(head,tail,n,i);
    cout<<endl;
    cout<<"Now the final linked list is ";
    print(head);
    cout<<endl;
    cout<<"Finally ! "<<endl;
    cout<<"Head data is: "<<head->data<<endl;
    cout<<"Tail data is : "<<tail->data<<endl;
}
