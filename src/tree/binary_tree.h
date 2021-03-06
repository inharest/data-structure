#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
  int data;
  struct TreeNode* lchild;
  struct TreeNode* rchild;
}TreeNode;

//stack

typedef TreeNode* ElemType;

typedef struct StackNode
{
  ElemType data;
  struct StackNode* next;
}StackNode;

void initStack(StackNode** snpp)
{
  *snpp = NULL;
  printf("stack: init\n");
}

void destroyStack(StackNode** snpp)
{
  while ((*snpp) != NULL) {
    StackNode* snp = (*snpp)->next;
    free(*snpp);
    *snpp = snp;
  }
  //printf("stack: destroy\n");
}

int isEmptyStack(StackNode* snp)
{
  return snp == NULL;
}

ElemType topStack(StackNode* snp)
{
  ElemType el = NULL;
  if(snp != NULL)
  {
    el = snp->data;
    //printf("stack: top: %d\n", el);
  }
  else
  {
    //printf("stack: top: empty\n");
  }
  return el;
}

int pushStack(StackNode** snpp,ElemType el) {
  StackNode* snp = malloc(sizeof(StackNode));
  snp->data = el;
  snp->next = *snpp;
  *snpp = snp;
  //printf("stack: push: %d\n", el);
  return 0;
}

ElemType popStack(StackNode** snpp)
{
  ElemType el = NULL;
  StackNode* snp = *snpp;
  if(snp != NULL)
  {
    el = snp->data;
    *snpp = snp->next;
    free(snp);
    snp = NULL;
    //printf("stack: pop: %d\n", el);
  }
  else
  {
    //printf("stack: pop: empty\n");
  }
  return el;
}

void traversalStack(StackNode* snp)
{
  printf("stack: traversal:\n");
  printf("  stack: ");
  while(snp != NULL)
  {
    printf("%d ", snp->data);
    snp = snp->next;
  }
  printf("\n");
}

#endif
