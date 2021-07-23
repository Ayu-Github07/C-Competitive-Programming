#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};
struct node* root = NULL;

void InsertatEnd()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tEnter the data: ";
    cin>>temp->data;
    temp->link = NULL;

    if(root == NULL)
    {
        root = temp;
    }
    else{
        struct node* p;
        p = root;

        while(p->link!=NULL){
            p = p->link;
        }
        p->link = temp;
    }
}
void InsertatBeg()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tEnter the data: ";
    cin>>temp->data;
    temp->link = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        temp->link = root;
        root = temp;
    }

}
void Display()
{
    struct node* temp;
    temp = root;
    if(root == NULL){
        cout<<"\tLinked List is Empty!!\n";
    }
    else{
        cout<<"\tNodes in the Linked List: \n";
        while(temp!=NULL){
        cout<<"\t"<<temp->data<<"--> ";
        temp = temp->link;
        }
    cout<<endl;
    }
}
int Count()
{
    struct node* temp;
    temp = root;
    int count=0;
    while(temp!=NULL){
        count++;
        temp = temp->link;
    }
    return count;
}
void InsertatMid()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int loc,count;
    cout<<"\tEnter the location: ";
    cin>>loc;
    
    count = Count();
    if(count==0){
        cout<<"\tLinked List is Empty!!\n";
    }
    else if(loc>count){
        cout<<"\tInvalid Location!!\n";
    }
    else{

        //To find the location where node to be added.
        struct node *p, *q;
        if(loc>=1){
            loc = loc-2;
        }
        p = root;
        while(loc!=0){
            p = p->link;
            loc--;
        }
        q = p->link;
        cout<<"\tEnter the data: ";
        cin>>temp->data;
        temp->link = NULL;
        //To add/insert the node in the desired location.
        temp->link = q;
        p->link = temp;
    }
}

int DeleteatEnd(){
    struct node*p, *q;
    int del;
    int count = Count();
    if(root == NULL){
        return -1;
    }
    else{
        //To find the desired location!!
        int i=1;
        p = root;
        if(p->link == NULL){
            del = p->data;
            root = NULL;
            free(p);
            return del;
        }
        while(i<count-1){
            p = p->link;
            i++;
        }
        q = p->link;
        //Delete the node
        p->link = q->link;
        q->link = NULL;
        del = q->data;
        free(q);
    }
    return del;
}
int DeleteatBeg()
{
    struct node* temp;
    temp = root;
    int del;
    if(root == NULL){
        return -1;
    }
    else{
        root = temp->link;
        temp->link = NULL;
        del = temp->data;
        free(temp);
    }
    return del;
}
int DeleteatMid()
{
    struct node*p, *q;
    int del;
    int count = Count();
    int loc;
    cout<<"\tEnter the location: ";
    cin>>loc;

    if(root == NULL){
        return -1;
    }
    else if(loc>count){
        cout<<"\tInvalid Location \n";
        return -1;
    }
    else{
        //To find the desired location!!
        int i=1;
        p = root;
        if(loc==1){
            p->link = NULL;
            del = p->data;
            root = NULL;
            free(p);
            return del;
        }
        while(i<loc-1){
            p = p->link;
            i++;
        }
        q = p->link;
        //Delete the node
        p->link = q->link;
        q->link = NULL;
        del = q->data;
        free(q);

    }
    return del;
}


int main()
{
    int n;
    do{
        cout<<"\t**************************************\n"
        <<"\t**        SINGLY LINKED LIST        **\n"
        <<"\t**************************************\n"
        <<"\t**       1) INSERTION AT END        **\n"
        <<"\t**       2) INSERTION AT BEG        **\n"
        <<"\t**       3) INSERTION AT MID        **\n"
        <<"\t**       4) DISPLAY                 **\n"
        <<"\t**       5) COUNT NO OF NODES       **\n"
        <<"\t**       6) DELETE AT END           **\n"
        <<"\t**       7) DELETE AT BEG           **\n"
        <<"\t**       8) DELETE AT MID           **\n"
        <<"\t**       9) EXIT                    **\n"
        <<"\t**************************************\n"
        <<"\t*ENTER YOUR CHOICE: ";
        cin>>n;
        int del,count;
        switch(n){
            case 1: InsertatEnd();
                    break;
            case 2: InsertatBeg();
                    break;
            case 3: InsertatMid();
                    break;
            case 4: Display();
                    break;
            case 5: count = Count();
                    if(count==0){
                        cout<<"\tLinked List is Empty!!\n";
                    }
                    cout<<"\tThe number of nodes in the Linked List is: "<<count<<endl;
                    break;
            case 6: del = DeleteatEnd();
                    if(del == -1){
                        cout<<"\tLinked List is empty!!\n";
                    }
                    else{
                        cout<<"\tDeleted Node value is: "<<del<<endl;
                    }
                    break;
            case 7: del = DeleteatBeg();
                    if(del == -1){
                        cout<<"\tLinked List is empty!!\n";
                    }
                    else{
                        cout<<"\tDeleted Node value is: "<<del<<endl;
                    }
                    break;
            case 8: del = DeleteatMid();
                    if(del == -1){
                        cout<<"\tLinked List is empty!!\n";
                    }
                    else{
                        cout<<"\tDeleted Node value is: "<<del<<endl;
                    }
                    break;
            case 9: exit(1);
                    break;
            default: cout<<"\tINVALID CHOICE!!\nPLEASE TRY AGAIN!!\n";
        }
    }while(n!=9);
    
    return 0;
}