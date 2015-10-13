#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int key_t;
typedef int data_t;
typedef enum color_t
{
        RED = 0,
        BLACK = 1
}color_t;

typedef struct rb_node_t
{
        /* data */
        struct rb_node_t *left, *right, *parent;
        key_t key;
        data_t data;
        color_t color;

}rb_node_t;

/*函数声明*/

rb_node_t *rb_insert(key_t key, data_t data, rb_node_t *root);
rb_node_t *rb_search(key_t key, rb_node_t *root);
rb_node_t *rb_erase(key_t key, rb_node_t *root);

int main (){

}

static rb_node_t *rb_new_node(key_t key, data_t data)
{
        rb_node_t *node = (rb_node_t*)malloc(sizeof(struct rb_node_t));

        if(!node){
                printf("rb_new_node malloc error\n");
                exit(-1);
        }
        node->key = key;
        node->data = data;
        return node;
}

/*-----------------------------------------------------------
| node             right
|  /\      ==>       /\
| a right         node y
|     /\           /\
|     b y         a b 
-----------------------------------------------------------*/
static rb_node_t *rb_rotate_left(rb_node_t *node, rb_node_t *root)
{
        rb_node_t *right = node->right;

        if((node->right = right->left))
        {
                right->left->parent = node;
        }
        right->left = node;

        if((right->parent = node->parent))
        {
                if(node == node->parent->right)
                {
                        node->parent->right = right;
                }
                else
                {
                        node->parent->left = right;
                }
        }
        else
        {
                root=right;
        }

        node->parent = right;
        return root;
}

/*-----------------------------------------------------------
|      node                       left
|       /\                         /\
|    left y         ==>           a node
|     /\                             /\
|     a b                           b y 
-----------------------------------------------------------*/

static rb_node_t * rb_rotate_right(rb_node_t *node, rb_node_t *root)
{
        rb_node_t *left = node->left;

        if((node->left = left->right))
        {
                left->right->parent = node;
        }

        left->right = node;

        if((left->parent = node->parent))
        {
                if(node == node->parent->right)
                {
                        node->parent->right = left;
                }
                else
                {
                        node->parent->left = left;
                }
        }
        else
        {
                root = left;
        }
        node->parent = left;
        return root;
}

static rb_node_t *rb_insert_rebalance(rb_node_t *node, rb_node_t *root)
{
        rb_node_t *parent, *gparent, *uncle, *tmp;

        while((parent = node->parent) && parent->color == RED)
        {
                gparent = parent->parent;

                if(parent == gparent->left)
                {
                        uncle = gparent->right;
                        if(uncle && uncle->color == RED)
                        {
                                uncle->color = BLACK;
                                parent->color = BLACK;
                                gparent->color = RED;
                                node = gparent;
                        }
                        else
                        {
                                if(parent->right == node)
                                {
                                        root = rb_rotate_left(parent,root);
                                        tmp = parent;
                                        parent = node;
                                        node = tmp;
                                }

                                parent->color = BLACK;
                                gparent->color = RED;
                                root = rb_rotate_right(gparent,root);
                        }
                }
                else
                {
                        uncle = gparent->left;
                        if(uncle && uncle->color ==RED)
                        {
                                uncle->color = BLACK;
                                parent->color = BLACK;
                                gparent->color = RED;
                                node = gparent;
                        }
                        else
                        {
                                if(parent->left == node)
                                {
                                        root = rb_rotate_right(parent,root);
                                        tmp = parent;
                                        parent = node;
                                        node = tmp;
                                }

                                parent->color = BLACK;
                                gparent->color = RED;
                                root = rb_rotate_left(gparent, root);
                        }
                }
        }

        root->color = BLACK;

        return root;
}

static rb_node_t *rb_erase_rebalance(rb_node_t *node, rb_node_t *parent, rb_node_t *root)
{
        rb_node_t *other, *left, *right;

        while((!node || node->color == BLACK) && node != root)
        {
                
        }
}


