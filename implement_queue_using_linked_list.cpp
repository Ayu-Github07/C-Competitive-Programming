#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};
struct node* front = NULL;
struct node* rear = NULL;

void Enqueue()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tENTER THE DATA: ";
    cin>>temp->data;
    temp->link = NULL;

    if(front==NULL && rear==NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->link = temp;
        rear = temp;
    }
}
int Dequeue()
{
    int del;
    struct node* temp;
    temp = front;
    if(front==NULL && rear==NULL){
        return -1;
    }
    else if(front==rear){
        del = front->data;
        front=rear=NULL;
        free(temp);
        return del;
    }
    else{
        front = temp->link;
        del = temp->data;
        temp->link = NULL;
        free(temp);
        return del;
    }

}
int Top()
{
    int top;
    struct node* temp;
    temp = front;
    if(front==NULL && rear==NULL){
        return -1;
    }
    else{
        top = front->data;
        return top;
    }
}
void Display()
{
    struct node* temp;
    temp = front;
    if(front==NULL && rear==NULL){
        cout<<"\tQUEUE IS EMPTY!!\n";
    }
    else{
        cout<<"\t";
        while(temp!=rear){
            cout<<temp->data<<"-->";
            temp = temp->link;
        }
        cout<<temp->data<<endl;
    }

}
int Count()
{
    int count=0;
    struct node* temp;
    temp = front;
    if(front==NULL && rear==NULL){
        return count;
    }
    else{
       
        while(temp!=rear){
            count++;
            temp = temp->link;
        }
        count++;
        return count;
    }
}
int main()
{
    int n;
    do{
        cout<<"\t*******************************************\n"
        <<"\t**        QUEUE USING LINKED LIST        **\n"
        <<"\t*******************************************\n"
        <<"\t**       1) ENQUEUE ELEMENT IN A QUEUE   **\n"
        <<"\t**       2) DEQUEUE ELEMENT FROM QUEUE   **\n"
        <<"\t**       3) FIRST ELEMENT OF THE QUEUE   **\n"
        <<"\t**       4) DISPLAY THE QUEUE            **\n"
        <<"\t**       5) NO. OF NODES IN QUEUE        **\n"
        <<"\t**       6) EXIT                         **\n"
        <<"\t**                                       **\n"
        <<"\t*******************************************\n"
        <<"\tENTER YOUR CHOICE: ";
        cin>>n;
        int del,count;
        switch(n){
            case 1: Enqueue();
                    cout<<"\tNODE INSERTED SUCCESSFULLY!!\n\n";
                    break;
            
            case 2: del = Dequeue();
                    if(del==-1){
                        cout<<"\tQUEUE IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tDELETED NODE VALUE IS: "<<del<<endl;
                        cout<<"\tNODE DELETED SUCCESSFULLY!!\n\n";
                    }
                    break;
            
            case 3: del = Top();
                    if(del==-1){
                        cout<<"\tQUEUE IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tFRONT VALUE OF THE QUEUE IS: "<<del<<endl;
                    }
                    break;

            case 4: Display();
                    break;
            
            case 5: count = Count();
                    if(count == 0){
                        cout<<"\tQUEUE IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tNUMBER OF NODES IN THE QUEUE IS: "<<count<<endl;
                    }
                    break;
            case 6: exit(1);
                    break;
            default: cout<<"\tINVALID CHOICE!!\nPLEASE TRY AGAIN!!\n";
        }
    }while(n!=6);
    
    return 0;
}