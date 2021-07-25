#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};
struct node *root = NULL;

void InsertatEnd()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    cout << "\tEnter the data: ";
    cin >> temp->data;
    temp->link = NULL;
    if (root == NULL)
    {
        root = temp;
        temp->link = root;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != root)
        {
            p = p->link;
        }

        p->link = temp;
        temp->link = root;
    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
void InsertatBeg()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    cout << "\tEnter the data: ";
    cin >> temp->data;
    temp->link = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != root)
        {
            p = p->link;
        }

        temp->link = root;
        root = temp;
        p->link = root;
    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
void Display()
{

    if (root == NULL)
    {
        cout << "\tLinked List is Empty!!\n";
    }
    else
    {
        struct node *temp;
        temp = root;
        cout << "\t";
        while (temp->link != root)
        {
            cout << temp->data << "--> ";
            temp = temp->link;
        }
        cout << temp->data << endl;
    }
}
int Count()
{
    int count = 0;
    if (root == NULL)
    {
        return count;
    }
    else
    {
        struct node *temp;
        temp = root;
        while (temp->link != root)
        {
            count += 1;
            temp = temp->link;
        }
        count += 1;
    }
    return count;
}
void InsertatMid()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    int loc;
    cout << "\tEnter the Location where node is to be inserted: ";
    cin >> loc;

    int count = Count();
    if (root == NULL)
    {
        cout << "\tLinked List is Empty!!\n";
    }
    else if (loc > count)
    {
        cout << "\tINVALID LOCATION!!\n";
    }
    else
    {
        struct node *p, *q;
        p = root;
        int i = 1;
        loc = loc - 1;
        while (i < loc)
        {
            p = p->link;
            i++;
        }
        cout << "\tEnter the data: ";
        cin >> temp->data;
        temp->link = NULL;
        if (loc == 1)
        {
            struct node *p;
            p = root;
            while (p->link != root)
            {
                p = p->link;
            }

            temp->link = root;
            root = temp;
            p->link = root;
        }
        else
        {
            temp->link = p->link;
            p->link = temp;
        }
    }
    cout<<"NODE INSERTED SUCCESSFULLY\n\n";
}
int DeleteatEnd()
{
    struct node *temp;
    temp = root;
    int del;
    if (root == NULL)
    {
        return 0;
    }
    else if (temp->link == NULL)
    {
        del = temp->data;
        free(temp);
        root = NULL;
        cout<<"NODE DELETED SUCCESSFULLY\n\n";
        return del;
    }
    else
    {
        struct node *p;
        int count = Count() - 1;
        int i = 1;
        if (count == 1)
        {
        }
        while (i < count)
        {
            temp = temp->link;
            i++;
        }
        p = temp->link;

        p->link = NULL;
        temp->link = root;
        del = p->data;
        free(p);
        cout<<"NODE DELETED SUCCESSFULLY\n\n";
        return del;
    }
}
int DeleteatBeg()
{

    int del;
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        return 0;
    }
    else if (temp->link == NULL)
    {
        del = temp->data;
        root = NULL;
        free(temp);
        cout<<"NODE DELETED SUCCESSFULLY\n\n";
        return del;
    }
    else
    {
        struct node *p;
        p = root;
        while (p->link != root)
        {
            p = p->link;
        }

        root = temp->link;
        p->link = root;
        temp->link = NULL;
        del = temp->data;
        free(temp);
    }
    cout<<"NODE DELETED SUCCESSFULLY\n\n";
    return del;
}
int DeleteatMid()
{
    struct node *temp;
    temp = root;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int loc, count;
        cout << "\tEnter the location from where node to be deleted: ";
        cin >> loc;
        count = Count();
        if (loc > count)
        {
            cout << "\tINVALID LOCATION\n";
            return 0;
        }
        else
        {
            int del;
            struct node *p;
            if (loc == 1)
            {
                p = root;
                while (p->link != root)
                {
                    p = p->link;
                }

                root = temp->link;
                p->link = root;
                temp->link = NULL;
                del = temp->data;
                free(temp);
                cout<<"NODE DELETED SUCCESSFULLY\n\n";
                return del;
            }
            else if(count==1){
                del = temp->data;
                free(temp);
                root = NULL;
                cout<<"NODE DELETED SUCCESSFULLY\n\n";
                return del;
            }
            else
            {
                int i = 1;
                loc = loc - 1;
                while (i < loc)
                {
                    temp = temp->link;
                }
                p = temp->link;

                temp->link = p->link;
                p->link = NULL;
                del = p->data;
                free(p);
                cout<<"NODE DELETED SUCCESSFULLY\n\n";
                return del;
            }
        }
    }
}
int main()
{
    int n;
    do
    {
        cout << "\t**************************************\n"
             << "\t**        CIRCULARLY LINKED LIST        **\n"
             << "\t**************************************\n"
             << "\t**       1) INSERTION AT END        **\n"
             << "\t**       2) INSERTION AT BEG        **\n"
             << "\t**       3) INSERTION AT MID        **\n"
             << "\t**       4) DISPLAY                 **\n"
             << "\t**       5) COUNT NO OF NODES       **\n"
             << "\t**       6) DELETE AT END           **\n"
             << "\t**       7) DELETE AT BEG           **\n"
             << "\t**       8) DELETE AT MID           **\n"
             << "\t**       9) EXIT                    **\n"
             << "\t**************************************\n"
             << "\t*ENTER YOUR CHOICE: ";
        cin >> n;
        int del, count;
        switch (n)
        {
        case 1:
            InsertatEnd();
            break;
        case 2:
            InsertatBeg();
            break;
        case 3:
            InsertatMid();
            break;
        case 4:
            Display();
            break;
        case 5:
            count = Count();
            if (count == 0)
            {
                cout << "\tLinked List is Empty!!\n";
            }
            cout << "\tThe number of nodes in the Linked List is: " << count << endl;
            break;
        case 6:
            del = DeleteatEnd();
            if (del == -1)
            {
                cout << "\tLinked List is empty!!\n";
            }
            else
            {
                cout << "\tDeleted Node value is: " << del << endl;
            }
            break;
        case 7:
            del = DeleteatBeg();
            if (del == -1)
            {
                cout << "\tLinked List is empty!!\n";
            }
            else
            {
                cout << "\tDeleted Node value is: " << del << endl;
            }
            break;
        case 8:
            del = DeleteatMid();
            if (del == -1)
            {
                cout << "\tLinked List is empty!!\n";
            }
            else
            {
                cout << "\tDeleted Node value is: " << del << endl;
            }
            break;
        case 9:
            exit(1);
            break;
        default:
            cout << "\tINVALID CHOICE!!\nPLEASE TRY AGAIN!!\n";
        }
    } while (n != 9);

    return 0;
}