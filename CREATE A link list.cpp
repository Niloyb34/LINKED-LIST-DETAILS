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
    ~Node()
    {
        int value = this->data;
        cout << "Memory is free from node with data " << value << endl;
        if (this->next != NULL)
        {
            this->next = NULL;
        }
        delete this;
        cout<<endl;
         cout<<"Memory is free from node with data"<<value<<endl;
    }
};
void insertAtHead(Node* &head,int d)///mane patano head ta pointer ja Node typer and jake dukabo seta integer jar name d
{
    ///tahole nton matake rakar jnno nton akta Node create korbo jathe d dukbe ga data part e
    Node* temp=new Node(d);
    temp->next=head;///nton temp node ta jehuto head e add hbe tie puran head ta thakbe newly added temp er link
    head=temp;///mane akon nton je temp ta add korci seta akta head hoye jabe
}
void print(Node* &head)///mane head ta node typer pointer and & dia dilam jathe main tie change hoi copy na
{
    ///akon head take akta temp er modde reke amra pura linked list take traverse korbo
    Node* temp=head;///mane head pointer take arekta pointer temp er modde raklam
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;///brtoman temp er address ta ager temp er next e thakbe
    }
}
void deleteNode(int position, Node* &head)
{
    ////deleting first or start node
    if (position == 1)
    {
        Node* temp = head;
        //mane 1st position er node take delete korte hole tar head take next node er head banie dibo tie new head=head->next
        head = head->next; ///mane 1st akebare head take 2nd node er head banie disi and 1st node take memory teke tarpor free kore dimu
        ///memory free of start node
        temp->next = NULL;
        delete temp;
    }
    else
    {
        ///deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* node1=new Node(10);
    Node *head=node1;
    insertAtHead(head,12);///mane function aitake call korci and head and 12 ke patieci
    insertAtHead(head,13);
    insertAtHead(head,15);
    print(head);
    deleteNode(3,head);
}
