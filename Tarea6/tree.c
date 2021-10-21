#include <stdio.h>
#include <stdlib.h>


typedef struct treenode {
    int value;
    struct treenode *left, *right;
} treenode;


treenode *crearnodo(char value){
    treenode* result = malloc(sizeof(treenode)); //“memory allocation” method in C is used to dynamically allocate a single large block of memory with the specified size. 
                                                 //It returns a pointer of type void which can be cast into a pointer of any form.
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}


void printtabs(int numtabs){
    for (int i=0; i<numtabs; i++){
        printf("\t");
    }
}


void printtree_rec(treenode *root, int level){
    if(root == NULL ){
        printtabs(level);
        printf("\n");
        return;
    }
    printtabs(level);
    printf("value = %c\n", root -> value);
    printtabs(level);
    printf("left\n");
    
    printtree_rec(root -> left, level+1);
    printtabs(level);
    printf("right\n");
    
    printtree_rec(root -> right, level+1);
    printtabs(level);
    printf("Done \n"); 
    
}

void printtree(treenode* root){
    printtree_rec(root, 0);
}

        
int main(){
   
   treenode *n1 = crearnodo('A');
   treenode *n2 = crearnodo('E');
   treenode *n3 = crearnodo('G'); 
   treenode *n4 = crearnodo('F');
   treenode *n5 = crearnodo('B');
   treenode *n6 = crearnodo('D');
   treenode *n7 = crearnodo('C');
   
   n1 -> right = n2;
   n1 -> left = n5;
   
   n2 -> right = n3;
   n2 -> left  = n4;
   
   n5 -> right = n6;
   n5 -> left = n7;

   
   printtree(n1);
   
   free(n1); // deallocate for previously malloc()
   free(n2);
   free(n3);
   free(n4);
   free(n5);
   free(n6);
   free(n7);

    return 0;
}
