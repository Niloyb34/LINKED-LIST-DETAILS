#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;///Node typer akta pointer ja kina next node ke point korbe
    Node(int data)///mane jkoni kono new node pabo tathe data er value dukie dibo and tar address e null reke dibo
    {
        this->data=data;
        this->next=NULL;
    }
    ///destructor
    ~Node()
    {
        ///muloto je Node take delete korbo take memeory teke free korte ata use korbo jathe oi node ta memory te onno kauke denote na kore
        int value=this->data;
        ///MEmory free korar code
        if(this->next!=NULL)
        {
            delete next;
            this->next=NULL;
        }
        cout<<"Memory is free from node with data "<<value<<endl;
    }
};
void insertAtHead(Node* &head,int d)///aikane & dia reference pass korci mane ja kicu change korbo sbgula main link list e change hoi jabe copy type er kicu hbe na
{
    /// new node creation
    Node* temp=new Node(d);
    //akon new node jeta create korlam take amra temp e reke dilam jekane data hbe d
    ///and initially new node er next ta NUll thake amra jehuto head side e add korbo new node ke tie amra new node er next jeta null chilo oitate ager head er bsie dibo
    /// tie temp er next e amra aher head ta reke dibo
    temp->next=head;
    ///akon nton head ta hbe new node ta tie head take change kore banie dibo temp name new node ta
    head=temp;///head updation
}
void insertATtail(Node* &tail,int d)
{
    ////new node creation
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void print(Node* &head)///aikaneo reference dici jathe mainlinked list e change hoi
{
    Node * temp = head;///aikane mane amra temp name arekta node typer pointer baniye akebare 1st node take denote korlam tie temp=head reke dilam
    ///current node er data ke print krie dao
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    //////////////////insert at starting
    if(position==1)
    {
        insertAtHead(head,d);
        return;
    }
   Node* temp=head;
   int cnt=1;
   while(cnt<position-1)
   {
       temp=temp->next;
       cnt++;
   }
   ////inserting at last position
   if(temp->next==NULL)
   {
       insertATtail(tail,d);
       return;
   }

   ////creating a new code
   Node* nodeToinsert=new Node(d);
   nodeToinsert->next=temp->next;
   temp->next=nodeToinsert;
}
void deleteNode(int position,Node* &head)
{
    ////deleting first or start node
    if(position==1)
    {
        Node*temp=head;
    //mane 1st position er node take delete korte hole tar head take next node er head banie dibo tie new head=head->next
        head=head->next;///mane 1st akebare head take 2nd node er head banie disi and 1st node take memory teke tarpor free kore dimu
        ///memory free of start node
        temp->next=NULL;
        delete temp;
    }
    else
    {
        ///deleting any middle node or last node
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    Node* node1=new Node(10);
    //cout<<node1->data<<endl;///mane no de 1 er data dekabe aikane 10 dekabe
    //cout<<node1->next<<endl;///mane node 1 er address dekabe and node 1 er address e NULL dekabe
    ///HEAD POINTED TO NODE 1
    Node *head=node1;
    Node *tail=node1;
    print(head);
    insertATtail(tail,12);
    print(head);
    insertATtail(tail,15);
    print(head);
    insertAtPosition(tail,head,4,22);///12 and 15 er modde 22 dukieci
///ager line e amra jdi 1 tmo position e 22  dukate cietam hbe na tie if(position==1) hole amra oi line ta liklam
///1 tmo position mane aikane n1 dite hbe,2 tmo position mane oikane 2 dite hbe ,3 tmo position mane oikane 3 dite hbe
    print(head);
    cout<<"HEAD "<<head->data<<endl;
    cout<<"Tail  "<<tail->data<<endl;
    deleteNode(3,head);///atar dara jekono node ke delete kora possible easily first second third jekona ta
    print(head);

}
//////////  j   u    s   t    akta node create korlam jar jnno amra data and element gulake dukie dilam
///initially eigular  modde muloto kono node er data nei and address ba link e next node er kono value o nei
