#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX 26
typedef struct trie_node_s trie_node_t;
struct trie_node_s{
	int times;
	trie_node_t *child[MAX]; //指向各个子树的指针,下标0-25代表26字符, 所以不用存储节点字符值（储存在父节点） 
};

static trie_node_t *new_trie_node(void){
	int i;
	trie_node_t *tmp;
	tmp = (trie_node_t *)malloc(sizeof(trie_node_t));
	tmp->times=1;
	for(i=0;i<MAX;i++){
		tmp->child[i] = NULL;
	}
	return tmp;
} 

static int insert(trie_node_t *root, char* s){
	trie_node_t *node = root;
	while(*s != 0){
		if(NULL == node->child[*s-'a']){
			node->child[*s-'a'] = new_trie_node();
		}
		else{
			node->child[*s-'a']->times++;
		}
		node=node->child[*s-'a'];
		s++;
	}
	return 0;
}

static int search(trie_node_t *root, char* s){
	trie_node_t *node = root;
	while(*s !=0){
		
		if(NULL == node->child[*s-'a']) return 0;
		
		node=node->child[*s-'a'];
		s++;
		
	}
	return node->times;
}

int main(void ){
	int num;
	int i;
	int result;
	char str[10];
	trie_node_t *root = new_trie_node();
	root->times = 0;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%s",str);
		//printf("%s",str); 
		insert(root,str);
	}
	scanf("%d",&num);
	for(i=0;i<num;i++){
		scanf("%s",str);
		result = search(root,str);
		printf("%d\n",result);
	}
	return 0;
}
