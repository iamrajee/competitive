/*
NAME - RAJENDRA SINGH
ROLL NO.- 111601017
PROGRAM: B-Tree(Insert and search)
DATE : 19 -03-18
*/

//----------------------------------------header-------------------------------------------------------//
#include<stdio.h>
#include<stdlib.h>///for malloc
#include<string.h>
#include <limits.h>//for INT_MAX


//----------------------------------------GLOBAL VARIABLE-------------------------------------------------------//
int ofset = 0;//for printing

//------------------------------------all structures and there creating function-------------------------//
typedef struct BTnode// a structure to represent a b-tnode
{
    int n;
    int t; //degree parameter
    int leaf;//laef = 1 if node is leaf, else 0.
    int *key; //ptr to headptr of key array in b-tree node
    struct BTnode **c; //ptr to headptr of child array of b-tree node
}BTnode;

BTnode* newBTnode(int t)
{
  BTnode *x = (BTnode *)malloc(sizeof(BTnode));
  x->t = t;
  x->n = 0;
  x->leaf = 0;


  x->key = (int *)malloc((2*t-1)*sizeof(int));

  for (int i = 0; i <(2*t-1); i++)
  {
    //*(x->key[i]) = (int *)malloc(sizeof(int));
    x->key[i] = -INT_MAX;
  }

  x->c = (struct BTnode **)malloc((2*t)*sizeof(struct BTnode *));
  for (int i = 0; i <(2*t); i++)
  {
    x->c[i] = NULL;
  }
  return(x);
}

typedef struct BT// a structure to represent a BT
{
  BTnode *root; //root
  int t;
  int height;
}BT;

BT* newBT(int t)
{
  BT *T = (BT *)malloc(sizeof(BT));
  T->root = NULL;
  T->t = t;
  T->height = 0;
  return(T);
}

typedef struct stack//structure of a stack
{
   int data;
   struct stack *next;
}stack;
stack *top=NULL;

void push(int data)//////////////////
{
   if(top==NULL)
  {
    top=(stack *) malloc(sizeof(stack));
    top->data = data;
    top->next = NULL;
   }
   else
   {
      stack  *temp=(stack *) malloc(sizeof(stack));
      temp->data = data;
      temp->next=top;
		  top=temp;
   }
   return;
 }

int  pop()////////////////////
{
  int y;
  struct stack* temp;
  if(top==NULL)
    return(-INT_MAX);
  else
  {
	   temp=(struct stack*) malloc(sizeof(struct stack));
	   temp=top;
	   top=top->next;
     y=temp->data;
     //printf("%d",y);
     free(temp);
  }
  return y;
}

//--------------------------------------------------------FUNCTION DECLARATION---------------------------------------//
BT *readInsertSearch();
void InsertKey(BT*, int);
BTnode* split(BT *, BTnode *, BTnode *, int);
BTnode* SearchKey(BT*, int);
void PrintTree(BTnode*, int);


//------------------------------------------------------------main function--------------------------------------------//
int main()
{
  int choice,key;
  BT *T = readInsertSearch();
}


//----------------------------------------------------readInsertSearch function--------------------------------------------//
BT* readInsertSearch()
{
    int n, key,i,t;

    // printf("Enter degree parameter of BT : ");
    // scanf("%d", &t);
    t = 3;

    BT *T= newBT(t);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &key);
        InsertKey(T, key);
        printf("PRINTING B-TREE :\nHeight = %d\n\n", T->height);
        PrintTree(T->root, 0);
    }
    while(key != -1)
    {
      scanf("%d", &key);
      if(key != -1)
      {
        BTnode *s = SearchKey(T, key);
      }
    }
    return(T);
}



//---------------------------------------------------------------INSERT FUNCTION------------------------------------------//
void InsertKey(BT *T, int key)
{
  printf("\n\n\n\n\ninsert of %d\n", key);
  int t = T->t;
  int i;
  BTnode *curr = T->root;
  BTnode *parent = NULL;
  if(curr == NULL)// if there no BTnode in T i.e BT is empty
  {
    curr = newBTnode(t);
    T->root = curr;
    curr->key[0] = key;
    //p->n = 1;
    curr->leaf = 1;
    T->height = 1;
  }
  else//i.e curr != NULL
  {

      while(curr->leaf != 1)//travel down to leaf node as new node is always added leaf node
      {
        if(curr->n == 2*t-1) //checking if node is full,split
        {
          curr = split(T, curr, parent,key);//split curr
        }

        for (i = 0; i < curr->n; i++)//checking through which children to travel down the tree
        {
          if(curr->key[i] > key)
          {
            break;
          }
        }
        parent = curr;
        curr = curr->c[i];
      }

      //now we had reach leaf node
      if(curr->n == 2*t-1)//checking if node is full,if then split
      {
        curr = split(T, curr, parent,key);//split curr
      }

      for (i = 0; i < curr->n; i++)//finding the index, where new key should go
      {
        if(curr->key[i] > key)
        {
          break;
        }
      }
      int index = i;
      for (i = curr->n-1; i > index-1; i--)//shifting all keys(index <----> n-1) after index(including) rightward
      {
          curr->key[i+1] = curr->key[i];
      }
      curr->key[index] = key;
  }
  curr->n++;
}




//----------------------------------------------------------------SPLIT FUNCTION------------------------------------------//
BTnode* split(BT *T, BTnode *curr, BTnode *parent, int key)
{
      int t = T->t;
      int i;
      if(parent == NULL)//this means curr is root(i.e we are spliting the root node, hence have to add a new node)
      {
        parent = newBTnode(t);//parent equal to new node
        T->root = parent;//updating root address
        T->height++;
      }

      int midkey = curr->key[t-1];
      for (i = 0; i < parent->n; i++)//finding index of parent where midkey should put
      {
        if(midkey < parent->key[i])
        {
          break;
        }
      }
      int index = i;
      for (i = parent->n-1; i >= index; i--)//shifting all keys(index <------> n-1) after index(including) rightward
      {
        parent->key[i+1] = parent->key[i];
      }
      for (i = parent->n; i > index; i--)//shifting all children(index+1 <----------> n) after index(excluding) rightward
      {
        parent->c[i+1] = parent->c[i];
      }
      parent->key[index] = midkey;
      parent->n++;

      //updating left(parent->c[index]) child of parent
      parent->c[index]  = curr;
      BTnode *l = parent->c[index]; //parent->c[index]; //left child //curr(= parent->c[index],was already unchanged)
      l->n = t-1;//no of keys reduce from 2t-1 to t-1

      //updating right(parent->c[index+1]) child of parent
      parent->c[index+1] =  newBTnode(t);//newly created node address
      BTnode *r = parent->c[index+1];
      r->n = t-1;
      r->leaf = curr->leaf;
      for (i = 0; i < t-1; i++)//updating first t-1 keys of 2nd child with last t-1 keys of curr
      {
        r->key[i] = curr->key[t+i];//t+i key
      }
      for (i = 0; i < t; i++)//updating first t children of 2nd child with last t children of curr
      {
        if(r->leaf == 0)
        {
          r->c[i] = curr->c[t+i];//t+i key
        }
      }
      if (key < midkey)
      {
        return(l);  //return l as curr node(since key will be left child)
      }
      else
        return(r);//return r as curr node(since key will be right child)
}





//---------------------------------------------------------------SEARCH FUNCTION------------------------------------------//
BTnode* SearchKey(BT *T, int key)
{
  printf("\n\n\nsearch of key = %d\n", key);
  int i;
  BTnode *curr = T->root;
  BTnode *parent = NULL;

  if(curr == NULL)// if there no BTnode in T i.e BT is empty
  {
    printf("\nBT is empty\n");
    return(curr);
  }
  else
  {
    while(curr != NULL)
    {

      for(i=0; i < curr->n; i++)
      {
        if(curr->key[i] ==  key)//key is Present at curr
        {
          push(i+1);
          int popchild = pop();
          printf("Key = %d is Present!!!\n\n", key);
          while(popchild != -INT_MAX)
          {
            printf("child %d <-", popchild);
            popchild = pop();
          }
          printf("<-root");
          return(curr);
          //since key is present, so printing path--------------------//
          // printf("Key = %d is Present!!!\n", key);
          // printf("Path = root");
          // curr = T->root;
          // int j;
          // while(curr != NULL)
          // {
          //   for(j=0; j < curr->n; j++)
          //   {
          //     if(curr->key[j] ==  key)//key is Present at curr
          //     {
          //       printf("->child %d!!! ", j+1);
          //       return(curr);
          //     }
          //     else if(curr->key[j] > key)//key might Present at curr->c[i]
          //     {
          //       //printf("->child %d", j);
          //       //curr = curr->c[j];
          //       break;
          //     }
          //   }
          //   printf("->child %d", j+1);
          //   if(curr != NULL)
          //     curr = curr->c[j];
          // }
          //---------------------------------------------------------------//
        }
        else if(curr->key[i] > key)//key might Present at curr->c[i]
        {
          //curr = curr->c[i];
          break;
        }
      }
      push(i+1);
       if(curr != NULL)
         curr = curr->c[i];
    }
    printf("Key = %d, is absent\n", key);
    top = NULL;
    return(curr);
  }
}




//----------------------------------------------------PRINT BT IN TREE FUNCTION------------------------------------------//
void PrintTree(BTnode *currentNode, int ofset)
{
  int i;

  if(currentNode == NULL)
  {
      printf("\nBT is empty\n");
      return;
  }
  else if(currentNode->leaf == 1)
  {
    for (i = currentNode->n-1; i > -1; i--)
    {
      for (int j = 0; j < ofset; j++)
      {
        printf("__");
      }
      printf("%d\n", currentNode->key[i]);
    }
    return;
  }
  else
  {
    //printf("flag,((%d))\n", currentNode->key);
    //printf("\nPRINTING BT : \n\n\n");
    PrintTree(currentNode->c[currentNode->n],ofset+2);
    for (i = currentNode->n-1; i >= 0; i--)
    {
      for (int j = 0; j < ofset; j++)
      {
        printf("__");
      }
      printf("%d\n", currentNode->key[i]);

      PrintTree(currentNode->c[i],ofset+2);
    }
    return;
  }
}
/*
SAMPLE INPUT :

27
25
50
75
10
15
35
40
45
55
65
85
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
40
55
83
43
-1

*/
