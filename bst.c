#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
struct BSTNode *left;
struct BSTNode *right;
int value;
};
struct BSTNode* minimumOfRightSubTree(struct BSTNode* root);
struct BSTNode* deletion (struct BSTNode *root, int bstVal);
void printBST (struct BSTNode *root);
struct BSTNode* search (struct BSTNode *root, int bstVal);
struct BSTNode* insertion (struct BSTNode *root, int bstVal);
int main(int argc, char** argv) {
        struct BSTNode *root = NULL;
        struct BSTNode *currentNode = NULL;
        char operation;
        int bstVal;
        while (scanf("%c %d", &operation, &bstVal)!= EOF) {
if (operation == 's') {
                        currentNode = search(root,bstVal);
                        if (currentNode == NULL) {
                                printf("absent\n");
                        } else {
                                printf("present\n");
                        }
                }
                
 if (operation == 'p') {
                        printBST(root);
                        printf("\n");
                }
                if (operation == 'd') {
                        deletion(root, bstVal);
                    }
               
                if (operation == 'i') {
                        root = insertion(root, bstVal);
                }
                }
free(root);
        return 0;
}
struct BSTNode* search(struct BSTNode *root, int bstVal) {
        if (root == NULL) {
                return root;
        } else if (root-> value == bstVal) {
                return root;
        } else if (root->value > bstVal) {
                return  search(root->left, bstVal);
        } else if (root->value < bstVal) {
                return  search(root->right, bstVal);
        }
        return root;
}

void printBST(struct BSTNode *root) {
     if (root == NULL) {
         return;
     }
     printf("(");
     if (root -> left != NULL){
        printBST(root->left);
     }
     printf("%d", root->value);
     if (root->right != NULL){
       printBST(root->right);
     }
     printf(")");
}

struct BSTNode* insertion(struct BSTNode *root, int bstVal) {
if (root != NULL) {
if(root->value == bstVal) {
printf("duplicate\n");
}
if (root->value <  bstVal) {
root->right = insertion(root->right, bstVal);
}
if (root->value > bstVal) {
root->left = insertion(root->left, bstVal);                
} 
} else {
root = malloc(sizeof(struct BSTNode));
root->value = bstVal;
root->left = NULL;
root->right = NULL;
//free(root);
printf("inserted\n");
}
return root;}

struct BSTNode* deletion(struct BSTNode *root, int bstVal) {
if (root == NULL) {
printf("absent\n");
    return root;
} if(root -> value > bstVal) {
root -> left = deletion(root -> left, bstVal);
} else if (root -> value < bstVal) {
root -> right = deletion(root -> right, bstVal);
//} else if (root -> right == NULL && root -> left == NULL) {
//printf("deleted\n");
//free(root);        
//return root;
    } else{
//if (root ->left == NULL && root -> right == NULL) {
//root = NULL;
//free(root);
//printf("deleted");
//return root;

//} 
if  (root -> left == NULL) {
        struct BSTNode *garbage = root -> right;
        root = garbage;
//        free(root);
        printf("deleted\n");
return root;
    } else if (root -> right == NULL) {
        struct BSTNode *garbage = root -> left;
        
  //      free(root);
printf("deleted\n");
return garbage;
 } else {
   
        struct BSTNode* currentNode =  minimumOfRightSubTree(root -> right);
       // while (currentNode -> left != NULL) {
         //       currentNode = currentNode -> left;
       // }
       
        root -> value = currentNode-> value;
        root -> right = deletion(root -> right, currentNode -> value); 
}}/* else if (root -> value > bstVal) {
    root -> left = deletion(root -> left, bstVal);
} else if (root -> value < bstVal) {
    root -> right = deletion(root -> right, bstVal);
}*/
return root;
}      
struct BSTNode* minimumOfRightSubTree(struct BSTNode* root) {
struct BSTNode* currentNode = root;
while (currentNode -> left != NULL) {
currentNode = currentNode -> left;
}
return currentNode;
}

    

