#include <stdio.h>

#include "parse.tab.h"
typedef struct node Node;

extern int yyparse();
extern void print_tree(Node *node);
extern void free_tree(Node *node);
extern Node* numList;
extern Node* opList;
extern Node* identList;

int main() {
    int parse_code;
    while (1) {
        free_tree(numList);  
        free_tree(opList);  
        free_tree(identList);  
        numList = NULL;
        identList = NULL;
        opList = NULL;

        printf("Enter input(Crtl-d to exit): ");
        parse_code = yyparse();
        if(feof(stdin)){
            break;
        }
        if (yyparse() == 0) {
            printf("numList: \t");
            print_tree(numList);  
            printf("opList: \t");
            print_tree(opList);  
            printf("identList: \t");
            print_tree(identList);  
        } else {
            printf("Syntax error\n");
        }
    }

    return 0;
}