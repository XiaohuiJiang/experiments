
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct double_link_t {
     void * pre;
     void * next;
     int    data;
};

struct double_link_t * head, * tail;
int g_id;

int delete_node (struct double_link_t * p) {
    struct double_link_t * o, * t;

    assert (head != NULL);
    assert (tail != NULL);
    assert (p != NULL);

    o = p -> pre;
    t = p -> next;

    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else if(p == head) {
        head = t;
        t -> pre = NULL;
    }else if(p == tail) {
        tail = o;
        o -> next = NULL;
    }else{
        o -> next = t;
        t -> pre  = o;
    }

    free(p);
    p = NULL;
    return 0;
}

/*    add new node after p  */
int add_node (struct double_link_t * p) {
    if(head != NULL){
        assert (p != NULL);
    }
    struct double_link_t * n = malloc(sizeof(struct double_link_t));
    if(n == NULL) {
        printf("there is no enought memory!\n");
        return -1;
    }
    n -> data = g_id++;
    if((head == NULL) || (tail == NULL)){ //0 node in list
        head = n;
        tail = n;
        n -> next = NULL;
        n -> pre  = NULL;
    } else if((tail == head) || (p ==tail)){ //only 1 node in list, or add after tail
        n -> pre = tail;
        n -> next = NULL;
        tail -> next = n;
        tail = n;
    } else{  //2 or more node in list, and p != tail
        n -> pre = p;
        n -> next = p -> next;
        p -> next = n;
        ((struct double_link_t*)(n->next)) ->pre = n;
    }
    return 0;
}

int print_double_list (){
    struct double_link_t * n = NULL;
    if(head == NULL){
        printf("double list is empty\n");
        return 0;
    }

    for(n = head; n != NULL; n = n->next){
        printf("%d ", n->data);
    }
    printf("\n");
    return 0;
}

int main(){

    for(int i = 0; i < 10; i++){
        if(add_node(head) != 0) {
            printf("add node %d failed\n", i);
            return -1;
        }
        print_double_list();
    }
    for(int i = 10; i < 20; i++){
        if(add_node(tail) != 0) {
            printf("add node %d failed\n", i);
            return -1;
        }
        print_double_list();
    }
    for(int i = 20; i < 30; i++){
        if(add_node(((struct double_link_t*)(head->next))->next) != 0) {
            printf("add node %d failed\n", i);
            return -1;
        }
        print_double_list();
    }

    delete_node(head);
    print_double_list();

    delete_node(head);
    print_double_list();

    delete_node(tail);
    print_double_list();

    delete_node(tail);
    print_double_list();

    for(int i = 0; i < 30; i++){
        delete_node(head->next);
        print_double_list();
    }
}

/*   output:
XIAOHUJI-M-L0GK:double_link xiaohuji$ ./a.out 
0 
0 1 
0 2 1 
0 3 2 1 
0 4 3 2 1 
0 5 4 3 2 1 
0 6 5 4 3 2 1 
0 7 6 5 4 3 2 1 
0 8 7 6 5 4 3 2 1 
0 9 8 7 6 5 4 3 2 1 
0 9 8 7 6 5 4 3 2 1 10 
0 9 8 7 6 5 4 3 2 1 10 11 
0 9 8 7 6 5 4 3 2 1 10 11 12 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 15 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 15 16 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 
0 9 8 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
0 9 8 29 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
9 8 29 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
8 29 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 19 
8 29 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 18 
8 29 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 28 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 27 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 26 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 25 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 24 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 23 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 22 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 21 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 20 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 7 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 6 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 5 4 3 2 1 10 11 12 13 14 15 16 17 
8 4 3 2 1 10 11 12 13 14 15 16 17 
8 3 2 1 10 11 12 13 14 15 16 17 
8 2 1 10 11 12 13 14 15 16 17 
8 1 10 11 12 13 14 15 16 17 
8 10 11 12 13 14 15 16 17 
8 11 12 13 14 15 16 17 
8 12 13 14 15 16 17 
8 13 14 15 16 17 
8 14 15 16 17 
8 15 16 17 
8 16 17 
8 17 
8 
Assertion failed: (p != NULL), function delete_node, file ./double_link.c, line 20.
Abort trap: 6
*/