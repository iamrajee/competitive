/*
Name - Rajendra Singh
Roll no. 111601017
Heapsort, buildheap,minHeapify,DeleteMin
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct treenode
{
  int val;
  struct treenode *left, *right;
} treenode;

int heap[1000000], heapSize,b[1000000];
void Init();
void buildHeap();
void Insert(int);
int DeleteMin();
int minHeapify(int);
void printTree(struct treenode* ,int );

struct treenode *node[1000000];
int main()
{
    printf("Enter the number of elements: ");

    scanf("%d", &heapSize);

    int i, element;

    //Init(); //Initialized

    printf("Enter the elements: ");

    for (i = 1; i <= heapSize; i++)
    {
        scanf("%d", &heap[i]);
    }

    buildHeap();
    printf("\nheap is : ");
    for (i = 1; i <= heapSize; i++)
    {
        printf("%d\t", heap[i]);
    }
    printf("\nEnter the element to Insert: ");
    scanf("%d", &element );
    Insert(element);
    printf("\nNew heap is : ");
    for (i = 1; i <= heapSize; i++)
    {
        printf("%d\t", heap[i]);
    }

    DeleteMin();//deleting the minimum element once
    printf("\nNew heap is after deleting minimum is: ");
    for (i = 1; i <= heapSize; i++)
    {
        printf("%d\t", heap[i]);
    }
    printf("\n");

    printf("\nheapSort:\n ");
    int fixsize = heapSize;         //sorting heap in increasing order and printing
    for (i = 1; i <= fixsize; i++)
    {
        b[i] = DeleteMin();
        printf("%d\t", b[i]);
    }
    printf("\nPrinting sorted heap in tree format:\n");

    for (i = 1; i <= fixsize; i++)//creating  the space for storing each element of heap
    {
        node[i] = (struct treenode*)malloc(sizeof(struct treenode));//tree node
    }
    for (i = 1; i <= fixsize; i++)//wrting the node value and left & right child address for node
    {
      if( (2*i) > fixsize)
      {
        node[i]->left  = NULL;
        node[i]->right = NULL;
        node[i]->val   = b[i];
      }
      else if( (2*i) == fixsize)
      {
        node[i]->left  = node[2*i];
        node[i]->right = NULL;
        node[i]->val   = b[i];
      }
      else
      {
        node[i]->left  = node[2*i];
        node[i]->right = node[(2*i)+1];
        node[i]->val   = b[i];
      }
    }
    printTree(node[1],0);
    return 0;

}
void printTree(struct treenode* currentNode,int ofset)
{
  if(currentNode->right != NULL)//checking if right child is there or not
  {
    printTree(currentNode->right,ofset+2);
  }
  for(int i=0; i < ofset; i++)
  {
    printf("__");//ofset for non child node
  }
  printf("%d\n",currentNode->val);//non child node printed
  if(currentNode->left != NULL)//checking if left child is there or not
  {
      printTree(currentNode->left,ofset+2);
  }
}

void Init()       //Initialize Heap
{
    heapSize = 0;
    heap[0] = -INT_MAX;
}

void Insert(int element)//for inserting element into heap
{

    heapSize++;

    heap[heapSize] = element;  //Insert in the last place


    int now = heapSize;      //now is the index where actually element should be

    while (heap[now / 2] > element)   //while the element is smaller than parent
    {
        heap[now] = heap[now / 2]; //send parent down
        now /= 2;//and current index goes up
    }

    heap[now] = element; //element is place at right place

}



int DeleteMin()
{
    int minElement, lastElement, child, now;

    minElement = heap[1]; //topmost element is the minimum
    if(heapSize >=3)
    {
        heap[1] = heap[heapSize--];//after copying reduced the heapSize
        for (now = 1; now * 2 <= heapSize; now = child)//will give the exact location of lastElement
        {
          child = minHeapify(now);
          if (child == INT_MAX)
          {
            break;
          }
        }
    }
    else if(heapSize == 2)
    {
      heap[1] = heap[heapSize--];
    }
    else if(heapSize == 1)
    {
      heapSize--;
    }
    else
    {
     printf("heap empty\n" );
    }
    return minElement;
}

void buildHeap() //buildHeap function for creating heap
{
  int now,i;
  int temp;
  for(now = heapSize/2; now >= 1; now--)  //strating from bottom parent with atleast one child
  {
    temp = minHeapify(now);//calling minHeapify
  }
}

int minHeapify(int now)
{
  int temp;
  int child = now * 2;
  if (child != heapSize && heap[child + 1] < heap[child]) //gives the minimum child of now
  {
    child++;
  }

  if (heap[now] > heap[child])//if heap[now] is greater(i.e unfit) than minimum child
  {
      temp = heap[now];
      heap[now] = heap[child];//if greater then send the child up
      heap[child] = temp;
      return(child);
  }
  return(INT_MAX);
}
