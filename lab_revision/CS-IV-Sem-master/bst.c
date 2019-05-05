/*
NAME - RAJENDRA SINGH
ROLL NO.- 111601017
PROGRAM: A menu based program to implement a (unique key) binary search tree
*/

//----------------------------------------header-------------------------------------------------------//
#include<stdio.h>
#include<stdlib.h>///for malloc
#include<string.h>
#include <limits.h>//for INT_MAX


//------------------------------------all structures and there creating function-------------------------//
typedef struct bstnode// a structure to represent a bstnode
{
    int key;
    struct bstnode *lptr, *rptr, *pptr;
}bstnode;

bstnode* newbstnode(int key)
{
  bstnode *p;
  p = (bstnode *)malloc(sizeof(bstnode));
  p->key = key;
  p->lptr = NULL;
  p->rptr = NULL;
  p->pptr = NULL;
  return(p);
}



typedef struct BST// a structure to represent a BST
{
    int size;
    struct bstnode *root; //root
}BST;

BST* newBST()
{
  BST *T;
  T = (BST *)malloc(sizeof(BST));
  T->root = NULL;
  T->size = 0;
  return(T);
}


//--------------------------------------------------FUNCTION DECLARATION---------------------------------------//
void InsertKey(BST*, int);
bstnode* SearchKey(BST*, int);
bstnode* FindMinKey(bstnode*);
bstnode* FindMaxKey(bstnode*);
bstnode* DeleteKey(BST*, int);
void Deletenode(BST *, bstnode *);
void InOrderTravelsal(bstnode*);
void PostOrderTravelsal(bstnode*);
bstnode* FindInOrderPredecessorKey(BST*, int);
bstnode* FindInOrderPredecessorNode(BST*, bstnode* );
void PrintTree(bstnode*, int);


//---------------------------------------------------main function--------------------------------------------//
int main()
{
  int choice,key;
  BST *T= newBST();


  while(1)//MENU BASED CALL
  {
    printf("\n\n\nChoose from options below:\n");
    printf("[1]. Insert a key\n");
    printf("[2]. Search for a key\n");
    printf("[3]. find minimum a key\n");
    printf("[4]. delete a key\n");
    printf("[5]. InOrderTravelsal\n");
    printf("[6]. PostOrderTravelsal\n");
    printf("[7]. FindInOrderPredecessor\n");
    printf("[8]. PrintTree\n");
    printf("\nChoice :");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1: printf("\nEnter Key to Insert:");
              scanf("%d", &key);
              InsertKey(T, key);
              break;

      case 2: printf("\nEnter Key to search:");
              scanf("%d", &key);
              bstnode *searchednode = SearchKey(T, key);
              if(searchednode != NULL)
                printf("\n Searched Key Present!!\n");
              break;

      case 3: printf("\n");
              bstnode *minKeynode = FindMinKey(T->root);
              if(minKeynode != NULL)
                  printf("\n min Key is : %d\n", minKeynode->key);
              break;

      case 4: printf("\nEnter Key to Delete:");
              scanf("%d", &key);
              bstnode *deletednode = DeleteKey(T, key);
              if(deletednode != NULL)
              {
                printf("\n Deleted Key is : %d\n", deletednode->key);
              }
              break;

      case 5: InOrderTravelsal(T->root);
              break;

      case 6: PostOrderTravelsal(T->root);
              break;
      case 7: printf("Enter Key whose predecessor needed:");
              scanf("%d", &key);
              bstnode *pred = FindInOrderPredecessorKey(T, key);
              if(pred != NULL)
                printf("\n predecessor of %d in InOrder is : %d\n", key, pred->key);
              else
                printf("Hence predecessor!\n");
              break;

      case 8: printf("\nPRINTING BST : \n\n\n");
              PrintTree(T->root, 0);
              break;
      default: printf("Invalid choice! Please enter valid choice\n");
    }
  }
}

//-------------------------------------INSERT FUNCTION------------------------------------------//
void InsertKey(BST *T, int key)
{
  bstnode *p = newbstnode(key);
  // printf("flag1\n");

  bstnode *curr = T->root;
  int flag = 0;
  if(curr == NULL)// if there no bstnode in T i.e BST is empty
  {
    T->root = p;
    T->root->pptr = NULL;
    T->size++;
  }
  else
  {

    bstnode *parent = curr->pptr;
    while(curr != NULL)//travelling to exact location of key
    {
      if(curr->key < key)//travel in right sub tree of curr
      {
        parent = curr;
        curr = curr->rptr;
        flag = 0;
      }
      else if(curr->key > key)//travel in left sub tree of curr
      {
        parent = curr;
        curr = curr->lptr;
        flag = 1;
      }
      else//i.e when duplicate key present
      {
        printf("Entered a duplicate key!!!, Please enter a valid key!\n");
        return;
      }
    }


    // if(parent->key == key)//avoiding duplicate
    // {
    //   printf("Entered a duplicate key!!!, Please enter a valid key!\n");
    //   return;
    // }

    if(flag == 0 )//key is right child of parent
    {
      printf("Right child of parent %d\n", parent->key);
      parent->rptr = p;
      p->pptr = parent;
    }
    else//key is left child of parent
    {
      printf("Left child of parent %d\n", parent->key);
      parent->lptr = p;
      p->pptr = parent;
    }
    T->size++;
  }

}

//-------------------------------------SEARCH FUNCTION------------------------------------------//
bstnode* SearchKey(BST *T, int key)
{
  bstnode *curr = T->root;

  if(curr == NULL)// if there no bstnode in T i.e BST is empty
  {
    printf("\nBST is empty\n");
    return(curr);
  }
  else
  {
    while(curr != NULL)
    {
      if(curr->key ==  key)//key is Present at curr
      {
        //printf("\n Present!!!\n", );
        return(curr);
      }
      else if(curr->key < key)//travel in right sub tree of curr
      {
        curr = curr->rptr;
      }
      else//travel in left sub tree of curr
      {
        curr = curr->lptr;
      }
    }

    if(curr == NULL)//key is Absent and BST is not empty
    {
      printf("\n Key= %d, is Absent!!!! \n", key);
      return(curr);
    }
  }
}

//-------------------------------------FIND MIN KEY FUNCTION------------------------------------------//
bstnode* FindMinKey(bstnode *root)
{
  bstnode *curr = root;
  bstnode *parent = curr->pptr;
  if(curr == NULL)// if there no bstnode in T i.e BST is empty
  {
    printf("\nBST(of given root) is empty\n");
    return(curr);
  }
  else
  {
    while(curr != NULL)
    {
      parent = curr;
      curr = curr->lptr;
    }
    return(parent);
  }
}

bstnode* FindMaxKey(bstnode *root)
{
  bstnode *curr = root;
  bstnode *parent = curr->pptr;
  if(curr == NULL)// if there no bstnode in T i.e BST is empty
  {
    printf("\nBST(of given root) is empty\n");
    return(curr);
  }
  else
  {
    while(curr != NULL)
    {
      parent = curr;
      curr = curr->rptr;
    }
    return(parent);
  }
}

//-------------------------------------DELETE BY KEY FUNCTION------------------------------------------//
bstnode* DeleteKey(BST *T, int key)
{
  bstnode *curr = SearchKey(T, key);
  Deletenode(T,curr);
  return(curr);
}

//-------------------------------------DELETE BY NODE ADDRESS FUNCTION------------------------------------------//
void Deletenode(BST *T, bstnode *y)
{
  bstnode *curr = y;

  if(curr == NULL)// if there no bstnode in T i.e BST is empty
  {
    if(T->root == NULL)// if y is root node
      printf("BST is empty\n");
    else
      printf("\n No node at given node address(given node is not root)\n");
  }
  // else if(curr == T->root)// if y is root node
  // {
  //   T->root = NULL;
  // }
  else//curr is position of bstnode to delete
  {
      bstnode *parent = curr->pptr;
      if(curr->lptr == NULL && curr->rptr == NULL)//if curr have no child
      {
        if(parent == NULL)//curr is root node
        {
          T->root = NULL;
        }
        else//curr is not root node
        {
          if(parent->lptr = curr)//curr is parent's left child
          {
            parent->lptr = NULL;
          }
          else//curr is parent's right child
          {
            parent->rptr = NULL;
          }
        }
      }
      else if(curr->lptr != NULL && curr->rptr == NULL)//if curr have only left child
      {
        if(parent == NULL)//curr is root node
        {
          T->root = curr->lptr;
          curr->lptr->pptr = NULL;//since it will become root node so its parent = NULL
          //return(curr);
        }
        else//curr is not root node
        {
          if(parent->lptr == curr)//curr is parent's left child
          {
            parent->lptr = curr->lptr;
            curr->lptr->pptr = parent;
            //return(curr);
          }
          else//curr is parent's right child
          {
            parent->rptr = curr->lptr;
            curr->lptr->pptr = parent;
            //return(curr);
          }
        }
      }
      else if(curr->lptr == NULL && curr->rptr != NULL)//if curr have only right child
      {
        if(parent == NULL)//curr is root node
        {
          T->root = curr->rptr;
          curr->rptr->pptr = NULL;//since it will become root node so its parent = NULL
          //return(curr);
        }
        else//curr is not root node
        {
          if(parent->lptr == curr)//curr is parent's left child
          {
            parent->lptr = curr->rptr;
            curr->rptr->pptr = parent;
            //return(curr);
          }
          else//curr is parent's right child
          {
            parent->rptr = curr->rptr;
            curr->rptr->pptr = parent;
            //return(curr);
          }
        }
      }
      else//if curr have both child
      {
        // if(parent == NULL)//curr is root
        // {
        //   bstnode *pred = FindInOrderPredecessorNode(T, curr);
        //   if(pred != NULL)
        //   {
        //     Deletenode(T,pred);
        //     curr->key = pred->key;
        //     curr->pptr = NULL; //since curr is root
        //   }
        // }
        //{
          bstnode *pred = FindInOrderPredecessorNode(T, curr);
          if(pred != NULL)
          {
            Deletenode(T,pred);
            curr->key = pred->key;
          }
        //}
      }
      T->size--;
    }
  }


//-------------------------------------RECURSIVE  INORDER TRAVELSAL FUNCTION------------------------------------------//
void InOrderTravelsal(bstnode *r)
{
    if(r == NULL)
      return;
    InOrderTravelsal(r->lptr);
    printf("%d, ", r->key);
    InOrderTravelsal(r->rptr);
}


//-------------------------------------RECURSIVE  POSTORDER TRAVELSAL FUNCTION------------------------------------------//
void PostOrderTravelsal(bstnode *r)
{
  if(r == NULL)
    return;
  InOrderTravelsal(r->lptr);
  InOrderTravelsal(r->rptr);
  printf("%d, ", r->key);
}

//-------------------------------------FIND PREDECESSOR IN INORDER FUNCTION------------------------------------------//
bstnode* FindInOrderPredecessorKey(BST *T, int key)
{
  bstnode *x = SearchKey(T, key);
  bstnode *pred = FindInOrderPredecessorNode(T,x);
  return(pred);
}

bstnode* FindInOrderPredecessorNode(BST *T, bstnode* x)
{
  //bstnode *x = SearchKey(T, key);
  if(x == NULL)//return NULL if x is NULL
  {
    return(NULL);
  }
  else
  {
      if(x->lptr != NULL)
      {
        bstnode *max = FindMaxKey(x->lptr);//max element in left sub tree of given key
        return(max);
      }
      else
      {
        if(x == FindMinKey(T->root))//if x is minimum, then it have no predecessor
        {
            printf("Dont have predecessor, since given node is min!!\n");
            return(NULL);
        }

        bstnode * curr = x;
        bstnode *p = x->pptr;
        while (p != NULL && curr == p->lptr)//move up in rightward or until curr is leftchild of parent(p) && p is not root
        {
          curr = p;//updating curr
          p = p->pptr;//updating parent
        }
        return(p);
      }
    }
}

//-------------------------------------PRINT BST IN TREE FUNCTION------------------------------------------//
void PrintTree(bstnode *currentNode, int ofset)
{
  //printf("flag2\n");
if(currentNode == NULL)
  {
      printf("\nBST is empty\n");
      return;
  }
  else
  {
    //printf("flag,((%d))\n", currentNode->key);
    //printf("\nPRINTING BST : \n\n\n");
    if(currentNode->rptr != NULL)//checking if right child is there or not
    {
      PrintTree(currentNode->rptr,ofset+2);
    }


    for(int i=0; i < ofset; i++)
    {
      printf("  ");//ofset for non child node
    }
    printf("%d\n",currentNode->key);//non child node printed


    if(currentNode->lptr != NULL)//checking if left child is there or not
    {
        PrintTree(currentNode->lptr,ofset+2);
    }
  }
}
