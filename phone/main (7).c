#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char name[20];
    char family[20];
    char phone[20];
    char phone_type[20];
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current = NULL;

void add(char name[], char family[], char phone[], char phone_type[]){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    strcpy(new->name, name);
    strcpy(new->family, family);
    strcpy(new->phone, phone);
    strcpy(new->phone_type, phone_type);
    new->next = NULL;

    if(tail == NULL){
        head = tail = new;
    }else {
        new->prev = tail;
        tail->next = new;
    }
}

struct node* search(char name[]){
    current = head;
    while(current != NULL){
        if(strcmp(current->name, name)==0)
            return current;
        current = current->next;
    }
    current = NULL;
    return NULL;
}

void del(char name[]){
    search(name); // result in current
    if (current == NULL)
        return;
    if(current->prev != NULL && current->next != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }else if (current->prev != NULL){
        current->prev->next = current->next;
        tail = current->prev;
    }else if (current->next != NULL){
        head = current->next;
        current->next->prev = NULL;
    }else head = tail = NULL;
    free(current);
    current = NULL;
}

int main(){
    char ans = 'y';
    char name[20];
    char family[20];
    char phone[20];
    char phone_type[20];
    while(ans == 'y')
    {
        printf("What do you want to do:\n");
        printf("1. add\n2. remove\n3. search\n");
        char c[2];
        fflush(stdout);
        fgets(c, 2, stdin);
        fflush(stdin);
        switch (c[0]) {
            case '1':
                printf("Enter name:\n");
                fflush(stdout);
                fgets(name, 20, stdin);
                fflush(stdin);
                printf("Enter family:\n");
                fflush(stdout);
                fgets(family, 20, stdin);
                fflush(stdin);
                printf("Enter phone:\n");
                fflush(stdout);
                fgets(phone, 20, stdin);
                fflush(stdin);
                printf("Enter phone_type:\n");
                fflush(stdout);
                fgets(phone_type, 20, stdin);
                fflush(stdin);
                add(name, family, phone, phone_type);
                break;
            case '2':
                printf("Enter name:\n");
                fflush(stdout);
                fgets(name, 20, stdin);
                fflush(stdin);
                del(name);
                break;
            case '3':
                printf("Enter name:\n");
                fflush(stdout);
                fgets(name, 20, stdin);
                fflush(stdin);
                search(name);
                if(current == NULL){
                    printf("NOT EXISTS\n");
                    fflush(stdout);
                }else{
                    printf("Name: %s\nFamily: %s\nPhone: %s\nPhone Type: %s\n", current->name, current->family, current->phone, current->phone_type);
                    fflush(stdout);
                }

                break;
        }

        printf("Do you want to continue? (y/n)");
        fflush(stdout);
        ans = getc(stdin);
        fflush(stdin);

    }

    return 0;
}

