#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* link;
};
struct node* top = NULL;

void Push()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tENTER THE DATA: ";
    cin>>temp->data;
    temp->link = NULL;

    if(top == NULL){
        top = temp;
    }
    else{
        temp->link = top;
        top = temp;
    }

}
int Pop()
{
    int del;
    struct node* temp;
    temp = top;

    if(top==NULL){
        return -1;
    }
    else{
        del = temp->data;
        top = temp->link;
        temp->link = NULL;
        free(temp);
        return del;
    }

}
int Top()
{
    int del;
    struct node* temp;
    temp = top;

    if(top==NULL){
        return -1;
    }
    else{
        del = temp->data;
        return del;
    }
}
void Display()
{
    struct node* temp;
    temp = top;

    if(top==NULL){
        cout<<"\tSTACK IS EMPTY!!\n";
    }
    else{
        
        cout<<"\t";
        while(temp!=NULL){
            cout<<temp->data<<"-->";
            temp = temp->link;
        }
        cout<<endl;
    }

}
int Count()
{
    struct node* temp;
    temp = top;
    int count = 0;
    if(top==NULL){
        return 0;
    }
    else{
        while(temp!=NULL){
            count++;
            temp = temp->link;
        }
    }
    return count;
}
int main()
{
    int n;
    do{
        cout<<"\t*******************************************\n"
        <<"\t**        STACK USING LINKED LIST        **\n"
        <<"\t*******************************************\n"
        <<"\t**       1) PUSH ELEMENT IN A STACK      **\n"
        <<"\t**       2) POP ELEMENT FROM STACK       **\n"
        <<"\t**       3) TOP OF THE STACK             **\n"
        <<"\t**       4) DISPLAY THE STACK            **\n"
        <<"\t**       5) NO. OF NODES IN STACK        **\n"
        <<"\t**       6) EXIT                         **\n"
        <<"\t**                                       **\n"
        <<"\t*******************************************\n"
        <<"\tENTER YOUR CHOICE: ";
        cin>>n;
        int del,count;
        switch(n){
            case 1: Push();
                    cout<<"\tNODE INSERTED SUCCESSFULLY!!\n\n";
                    break;
            
            case 2: del = Pop();
                    if(del==-1){
                        cout<<"\tSTACK IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tDELETED NODE VALUE IS: "<<del<<endl;
                        cout<<"\tNODE DELETED SUCCESSFULLY!!\n\n";
                    }
                    break;
            
            case 3: del = Top();
                    if(del==-1){
                        cout<<"\tSTACK IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tTOP VALUE OF THE STACK IS: "<<del<<endl;
                    }
                    break;

            case 4: Display();
                    break;
            
            case 5: count = Count();
                    if(count == 0){
                        cout<<"\tSTACK IS EMPTY!!\n";
                    }
                    else{
                        cout<<"\tNUMBER OF NODES IN THE STACK IS: "<<count<<endl;
                    }
                    break;
            case 6: exit(1);
                    break;
            default: cout<<"\tINVALID CHOICE!!\nPLEASE TRY AGAIN!!\n";
        }
    }while(n!=6);
    
    return 0;
}