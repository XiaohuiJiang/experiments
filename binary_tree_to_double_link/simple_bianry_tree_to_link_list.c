#include <stdio.h>

typedef struct list_node{
    union {
        struct list_node * left;
        struct list_node * next;
    };
    union {
        struct list_node * right;
        struct list_node * prev;
    };
}list_node;

void print_btr(list_node * t) {
    list_node * left = t->left;
    list_node * right = t->right;
    printf("self=%p, left=%p, right =%p\n", t, left, right);
    if(left)
        print_btr(left);
    if(right)
        print_btr(right);
}

void print_link(list_node * l){
    list_node * p = NULL;
    list_node * next = l->next;
    list_node * prev = l->prev;
    printf("self=%p, next=%p, prev =%p\n", l, next, prev);

    for(p = next; p != l; p = p->next){
	printf("self=%p, next=%p, prev =%p\n", p, p->next, p->prev);
    }
}

/*a and b are head of double link list*/
list_node * list_merge(list_node * a, list_node * b){
/* find the tail node */
    list_node * last_a = a->prev;
    list_node * last_b = b->prev;

    last_a->next = b;
    b->prev = last_a;
    last_b->next = a;
    a->prev = last_b;

    return a;
}

/*change binary tree to a double link list*/
list_node * btr_to_link(list_node * t) {
    list_node * parent = t;
    list_node * left_child = NULL;
    list_node * right_child = NULL;

    if(parent == NULL)
	return parent;

    left_child = parent->left;
    right_child = parent->right;

/*build parent as a double link first*/
    parent->next = parent;
    parent->prev = parent;

   if(left_child != NULL) {
	left_child = btr_to_link(left_child);
	list_merge(parent, left_child);
    }
    if(right_child != NULL) {
        right_child = btr_to_link(right_child);
	list_merge(parent, right_child);
    }

    return parent;
}

int main(){
    list_node * result;

    list_node left = {NULL, NULL};
    list_node right = {NULL, NULL};
    list_node root = {&left, &right};
    print_btr(&root);

    result = btr_to_link(&root);

    print_link(result);

    return 0;
}
