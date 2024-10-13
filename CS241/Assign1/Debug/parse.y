%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
void yyerror(const char *s);

typedef enum type {
        NUM,
        OP,
        IDENT
}Type;
typedef struct node {
    Type type;
    union {
        int num;
        char op;
        char *ident;
    } value;
    struct node *next;
}Node;

Node* createNode(Type type, void* data){
    Node *node = (Node*)malloc(sizeof(Node));
    node->type = type;
    switch (type) {
        case NUM:
            node->value.num = *(int*)data;
            break;
        case OP:
            node->value.op = *(char*)data;
            break;
        case IDENT:
            node->value.ident = strdup((char*)data);
            break;
    }
    return node;
}

Node* appendNode(Node *list, Node *newNode) {
    if (list == NULL) {
        return newNode;
    }
    Node *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return list;
}

void free_tree(Node *node) {
    if (node == NULL) return;
    free_tree(node->next);
    if (node->type == IDENT) free(node->value.ident);
    free(node);
}

void print_tree(Node *node) {
    if (node == NULL) {
        printf("NULL\n");
        return;
    }
    switch (node->type) {
        case NUM:
            if (node->value.num < 0) {
                printf("(%d) -> ", node->value.num);
            } else {
                printf("%d -> ", node->value.num);
            }
            break;
        case OP:
            printf("%c -> ", node->value.op);
            break;
        case IDENT:
            printf("%s -> ", node->value.ident);
            break;
    }
    print_tree(node->next);
}

Node *numList = NULL;
Node *opList = NULL;
Node *identList = NULL;

%}

%union {
    int number;
    char op;
    char identifier[20];
}

%token <number> NUMBER
%token <identifier> IDENTIFIER
%token <op> OPERATOR
%token EOL

%type <number> STATEMENT EXP TERM

%left OPERATOR
%start STATEMENT

%%

STATEMENT: 
    EXP EOL {return 0;} 
    ;

EXP:
    | EXP OPERATOR TERM {
        char op = $2;
        opList = appendNode(opList, createNode(OP, &op));
    }
    | TERM 
    ;

TERM:
    NUMBER {
        int num = $1;
        numList = appendNode(numList, createNode(NUM, &num));
    }
    | IDENTIFIER {
        identList = appendNode(identList, createNode(IDENT, $1));
    }
    ;
%%

void yyerror(const char *s){}