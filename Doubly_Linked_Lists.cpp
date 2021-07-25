#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* root = NULL;
void InsertatEnd(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tEnter the data: ";
    cin>>temp->data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        struct node* p;
        p = root;
        while(p->right != NULL){
            p = p->right;
        }
        p->right = temp;
        temp->left = p;
    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
void InsertatBeg(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    cout<<"\tEnter the data: ";
    cin>>temp->data;
    temp->left = NULL;
    temp->right = NULL;

    if(root == NULL){
        root = temp;
    }
    else{
        root->left = temp;
        temp->right = root;
        root = temp;
    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
void Display(){

    if(root==NULL){
        cout<<"\tLinked List is Empty!!\n";
    }
    else{
        struct node* temp;
        temp = root;
        cout<<"\t";
        while(temp!=NULL){
            cout<<temp->data<<"--> ";
            temp = temp->right;
        }
        cout<<endl;
    }
}
int Count(){
    int count=0;
    if(root==NULL){
        return count;
    }
    else{
        struct node* temp;
        temp = root;
        while(temp!=NULL){
            count++;
            temp = temp->right;
        }
    }
    return count;
}
void InsertatMid(){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    int loc;
    cout<<"\tEnter the Location where node is to be inserted: ";
    cin>>loc;

    int count = Count();
    if(root == NULL){
        cout<<"\tLinked List is Empty!!\n";
    }
    else if(loc>count){
        cout<<"\tINVALID LOCATION!!\n";
    }
    else{
        struct node *p, *q;
        p = root;
        int i=1;
        loc = loc-1;
        while(i<loc){
            p = p->right;
            i++;
        }
        cout<<"\tEnter the data: ";
        cin>>temp->data;
        temp->left = NULL;
        temp->right = NULL;
        q = p->right;

        temp->right = p->right;
        q->left = temp;
        temp->left = p;
        p->right = temp;

    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
int DeleteatEnd()
{
    struct node* temp;
    temp = root;
    if(root == NULL){
        return 0;
    }
    else{
         int del;
        struct node* p;
        int count = Count()-1;           
        int i=1;
        if(count==1){
            del = temp->data;
            root = NULL;
            free(temp);
            return del;
        }
        while(i<count){
            temp = temp->right;
            i++;
        }
        
        temp->right->left = NULL;
        del = temp->right->data;
        free(temp->right);
        temp->right = NULL;
        return del;
    }
}
int DeleteatBeg(){
    
    int del;
    if(root == NULL){
        return 0;
    }
    else{ 
        struct node* temp;
        temp = root;

        root = temp->right;
        temp->right = NULL;
        del = temp->data;
        free(temp);
    }
    return del;
}
int DeleteatMid()
{
    struct node* temp;
    temp = root;
    if(root == NULL){
        return 0;
    }
    else{
        int loc,count;
        cout<<"\tEnter the location from where node to be deleted: ";
        cin>>loc;
        count = Count();
        if(loc>count){
            cout<<"\tINVALID LOCATION\n";
            return 0;
        }
        else{
            int del;
            struct node* p;
            if(loc==1){
                root = temp->right;
                del = temp->data;
                temp->right = NULL;
                free(temp);
                return del;
            }
            else{
                int i=1;
                loc = loc-1;
                while(i<loc){
                    temp = temp->right;
                }
                p = temp->right;

                temp->left->right = temp->right;
                p->left = temp->left;
                del = temp->data;
                
                temp->left = NULL;
                temp->right = NULL;
                free(temp);
                return del;
            }
        }
    }
}
int main()
{
    int n;
    do{
        cout<<"\t**************************************\n"
        <<"\t**        DOUBLY LINKED LIST        **\n"
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
                        cout<<"NODE DELETED SUCCESSFULLY\n\n";
                    }
                    break;
            case 7: del = DeleteatBeg();
                    if(del == -1){
                        cout<<"\tLinked List is empty!!\n";
                    }
                    else{
                        cout<<"\tDeleted Node value is: "<<del<<endl;
                        cout<<"NODE DELETED SUCCESSFULLY\n\n";
                    }
                    break;
            case 8: del = DeleteatMid();
                    if(del == -1){
                        cout<<"\tLinked List is empty!!\n";
                    }
                    else{
                        cout<<"\tDeleted Node value is: "<<del<<endl;
                        cout<<"NODE DELETED SUCCESSFULLY\n\n";
                    }
                    break;
            case 9: exit(1);
                    break;
            default: cout<<"\tINVALID CHOICE!!\nPLEASE TRY AGAIN!!\n";
        }
    }while(n!=9);
    
    return 0;
}