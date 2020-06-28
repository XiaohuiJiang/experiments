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

typedef struct b_tree {
    list_node list;
    int value;
}btr;

typedef struct link {
    list_node list;
    int value;
} link;

btr* to_btr(list_node* l){
    return (btr *)((char*)l - (size_t)&(((btr*)0)->list));
}

void print_btr(btr * t) {
    list_node * left = t->list.left;
    list_node * right = t->list.right;
    printf("self=%p, left=%p, right =%p, value=%d\n", t, to_btr(left), to_btr(right), t->value);
    if(left)
        print_btr(to_btr(left));
    if(right)
        print_btr(to_btr(right));
}

/* try a different way to translate link and list_node*/
void print_link(link * l){
    link * p = NULL;
    list_node * next = l->list.next;
    list_node * prev = l->list.prev;
    printf("self=%p, next=%p, prev =%p, value=%d\n", l, next, prev, l->value);

    for(p = (link*)next; p != l; p = (link*)(p->list.next)){
	list_node * next = p->list.next;
	list_node * prev = p->list.prev;
	printf("self=%p, next=%p, prev =%p, value=%d\n", p, next, prev, p->value);
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

/*build parent as a link first*/
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

    btr left = {{NULL, NULL},1};
    btr right = {{NULL, NULL},2};
    btr root = {{&(left.list), &(right.list)},0};
    print_btr(&root);

    result = btr_to_link(&(root.list));

    print_link((link*)result);

    return 0;
}
