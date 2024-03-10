#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
int main(){
     int choice = 0;
    while (choice != 9)
    {
        printf("\n\n*********Main Menu*********\n");
        printf("\nChoose one option from the following list ...\n");
        printf("\n===============================================\n");
        printf("\n1.Insert in beginning`\n2.Insert at last\n3.Random insert anywhere.\n4.Delete from begining\n5.Delete from last\n6.delete from any where.\n7.Show\n8.search element in the list\n9.Exit\n");
        printf("\nEnter your choice?\n");
        scanf("\n%d", &choice);
        switch (choice)
        {
        case 1:
            beginsert();
            break;
        case 2:
            lastinsert();
            break;
            case 3:
            randominsert();
            break;
            case 4:
            begin_delete();
            break;
            case 5:
            last_delete();
            break;
            case 6:
            random_delete();
            break;
            case 7:
           display();
           break;
           case 8:
           search();
           break;
           case 9:
            exit(0);
            break;
        default:
            printf("Please enter valid choice..");
        }
    }
    return 0;
}

  void beginsert(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr == NULL){
        printf("\nOverFlow.");
    }
    else{
        printf("Enter the data : ");
        scanf("%d",&item);
        ptr->data = item;
        if(head==NULL){
            ptr->next=ptr;
            head=ptr;
        }
        else
         {
            temp = head;
            while(temp->next != head){
                temp= temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
            head = ptr;
         }
    }
    
}

void lastinsert(){
    struct node *ptr,*temp;
    int item;
    ptr = (struct node*)malloc(sizeof(struct node*));
    if(ptr == NULL){
        printf("\nOverFlow.");
    }
    else{
        printf("Enter the data : ");
        scanf("%d",&item);
        ptr->data = item;
        if(head==NULL){
            ptr->next=ptr;
            head=ptr;
        }
        else
         {
            temp = head;
            while(temp->next != head){
                temp= temp->next;
            }
            temp->next=ptr;
            ptr->next=head;
         }
    }
}

void randominsert(){
    int i, loc, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {  
        printf("\nOVERFLOW");
    }
    else
    {
        printf("\nEnter element value");
        scanf("%d", &item);
        ptr->data = item;
        printf("\nEnter the location after which you want to insert ");
        scanf("\n%d", &loc);
        temp = head;
    
        for (i = 0; i < loc; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\ncan't insert\n");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        // while(ptr->next!=head)
        // {
        //     ptr=ptr->next;
        // }
        // head = ptr;
        printf("\nNode inserted");
    }
}

void begin_delete(){
    struct node *ptr,*temp;
    if(head == NULL){
        printf("\nlist is empty.");
    }
    else{
        ptr = head;
        while(ptr->next != head){
            ptr = ptr->next;
        }
        temp = head;
        head = head->next;
        ptr->next = head;
        free(temp);
    }
}
void last_delete(){
    struct node *ptr,*temp;
    if(head == NULL){
        printf("\ncan't inserted.");
    }
    else{
        ptr=head;
        while(ptr->next != head){
            temp=ptr;
            ptr=ptr->next;
        }
        temp->next=head;
        free(ptr);
    }
}

void random_delete(){
    struct node *ptr,*ptr1;
    int i,loc;
    printf("Enter the location after location which want you delete: ");
    scanf("%d",&loc);
    ptr = head;
    for(i=0;i<loc;i++){
     ptr1 = ptr;
     ptr = ptr->next;
     if(ptr==NULL){
        printf("\n can't delete data");
     }
    }
    ptr1->next= ptr->next;
    free(ptr);
    printf("Random node deleted from location %d",1+loc);
}

void display()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\nprinting values . . . . .\n");
        do
        {
            printf("%d->", ptr->data); 
            ptr = ptr->next;
        }
        while (ptr!= head);

        printf("%d", ptr->data);
        
    }
}

void search(){
    struct node *ptr;
    int i=0,item,flag=0;
    ptr=head;
    if(ptr==NULL){
        printf("List is empty.");
    }
    else{
        printf("Enter the item which location you want to search: ");
        scanf("%d",&item);
        do{
            if(ptr->data==item){
                printf("item founded at location %d\n",i+1);
                flag=1;
                // break;
            }
            i++;
            ptr=ptr->next;
      }while(ptr!=head);
    if(flag==0){
        printf("item not found");
    }
     }
}
// void search()
// {
//     struct node *ptr;
//     int item, i = 0, flag;
//     ptr = head;
//     if (ptr == NULL)
//     {
//         printf("\nEmpty List\n");
//     }
//     else
//     {
//         printf("\nEnter the item which you want to search?\n");
//         scanf("%d", &item);
//         while (ptr != head)
//         {
//             if (ptr->data == item)
//             {
//                 printf("item found at location %d \n", i+1);
//                 flag=1;
             
//              }
//             i++;
//             ptr = ptr->next;
           
//         }
    
//          if (flag == 0)
//         {
//             printf("Item not found\n");
//         }
        
//     }
// }