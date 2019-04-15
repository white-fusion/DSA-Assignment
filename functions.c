#include <stdio.h>
#include "functions.h"

int freehead=0;
int no_of_list=0;
int array[300];
int head[10];

void create_list()
{
 int m;
 no_of_list=no_of_list+1;
 printf("The sequence number of newly created list is:%d\n", no_of_list);
 printf("Enter key value to be inserted in the newly created list-%d: ",no_of_list );//here user inputs integer m
 scanf("%d", &m);
 if(no_of_list>9)
  {
    printf("FAILURE: MEMORY NOT AVAILABLE");
  }
 else
 {//memory is AVAILABLE
   int f=freehead;
   freehead=array[f+1];
   array[f]=m;
   array[f+1]=-1;
   array[f+2]=-1;
   head[no_of_list]=f;
   printf("SUCCESS\n");
 }
}

void insert()
{
 int n,m;
 printf("\nList you want to insert in:");// here user inputs list number n
 scanf("%d", &n);
 printf("\nEnter the key value: ");//here user inputs integer m
 scanf("%d", &m);
 int flag=0;
 int h=head[n];//to store value of head
 int pt_prev;
 if(m<array[h])
 {//given number is less than first element
   int temp=array[freehead+1];
   array[freehead]=m;
   array[freehead+1]=h;
   array[freehead+2]=-1;
   array[h+2]=freehead;
   head[n]=freehead;
   freehead=temp;
 }
 else
 {
   while(m>array[h])
   {
     pt_prev=h;
     if(array[h+1]!=-1)
     {//mid element
       h=array[h+1];
     }
     else
     {//end element
       flag=1;
       break;
     }
   }
   if(flag==0)
   {
     int temp=array[freehead+1];
     array[h+2]=freehead;
     array[pt_prev+1]=freehead;
     array[freehead]=m;
     array[freehead+1]=h;
     array[freehead+2]=pt_prev;
     freehead=temp;
   }
   else
   {
     int temp=array[freehead+1];
     array[freehead]=m;
     array[freehead+1]=-1;
     array[freehead+2]=h;
     array[h+1]=freehead;
     freehead=temp;
   }
 }
printf("SUCCESS\n");
}

void delete()
{
 int n,m,h,key,next,loc,flag=0;
 printf("\nList you want to delete from:"); //here user inputs list number n
 scanf("%d", &n);
 printf("Enter the key value:"); //here user inputs integer m
 scanf("%d", &m);
 h=head[n];
 if(h==-1)
 {//No list
   printf("FAILURE: ELEMENT NOT THERE / LIST EMPTY");
 }
 else
 {
   key=array[h];
   next=array[h+1];
   if(next==-1)
   {//for single element list
     if(key==m)
     {//if m is found
       array[h]=0;
       array[h+1]=freehead;
       array[h+2]=0;
       freehead=h;
       head[n]=-1;
       printf("SUCCESS");
     }
     else
     {//if m is not found
        printf("FAILURE: ELEMENT NOT THERE / LIST EMPTY");
     }
   }
   else
   {//for more than one element list
    if(key==m)//if m is found at first ELEMENT
     {
       array[h]=0;
       array[h+1]=freehead;
       array[h+2]=0;
       array[next+2]=-1;
       freehead=h;
       head[n]=array[next];
       printf("SUCCESS");
     }
    else
    {//if m is not found at first element
      while(next!=-1)
      {
       loc=next;
       key=array[next];
       next=array[next+1];
       if(key==m)
        {
          flag=1;
          break;
        }
      }
      if(flag=1)
      {//if element is found
        if(next==-1)
        {//element is found at the end of list
          int temp=array[loc+2];
          array[temp+1]=-1;
          array[loc]=0;
          array[loc+2]=0;
          array[loc+1]=freehead;
          freehead=loc;
          printf("SUCCESS");
        }
        else
        {//if element is found at the middle of the list
          int temp=array[loc+2];
          array[temp+1]=next;
          array[next+2]=temp;
          array[loc]=0;
          array[loc+2]=0;
          array[loc+1]=freehead;
          freehead=loc;
          printf("SUCCESS\n");
        }
      }
      else
      {//element is not found
        printf("FAILURE: ELEMENT NOT THERE / LIST EMPTY");
      }
    }
  }
 }
}

void tot_all_list()
{
  int n,h,count=0;
  for(n=0;n<10;n++)
  {
    h=head[n];
    if(h==-1)
    ;//do nothing
    else
    {
      count=count+1;
      while(array[h+1]!=-1)
      {
        count=count+1;
        h=array[h+1];
      }
    }
  }
  printf("\nTotal number of nodes in all lists are %d\n", count);
}

void tot_this_list()
{
  int n,h,count;
  printf("Enter the list number:  ");//here user inputs list number n
  scanf("%d\n", &n);
  h=head[n];
  if(h==-1)
  {
    count=0;
  }
  else
  {
    count=1;
    while(array[h+1]!=-1)
    {
     count=count+1;
     h=array[h+1];
    }
  }
  printf("Total number of nodes in list %d are %d", n, count);
}

void disp_all_list()
{
  int h,n,temp_key,temp_next,temp_prev;
  for(n=1;n<10;n++)
  {
    h=head[n];
    if(h==-1)
    ;//do nothing
    else
    {
      temp_key=array[h];
      temp_next=array[h+1];
      if(temp_next==-1)
      {//only one element
        printf("\nElements of list-%d are:\n", n);
        printf("key next prev\n");
        printf("%d NIL NIL\n", temp_key);
      }
      else
      {//many elements
        printf("\nElements of list-%d are:\n", n);
        printf("key next prev\n");
        printf("%d %d NIL\n", temp_key, temp_next );//firt element

        while(temp_next!=-1)
        {
          temp_key=array[temp_next];
          temp_prev=array[temp_next+2];
          temp_next=array[temp_next+1];
          if(temp_next!=-1)
           printf("%d %d %d\n", temp_key, temp_next, temp_prev);
          else
           printf("%d NIL %d\n", temp_key, temp_prev);
        }
      }

     }
   }
}

void disp_free_list()
{
  int temp=freehead;
  printf("\nElements are free list are:\n[%d,", temp );
  while(array[temp+1]!=-1)
  {
    temp=array[temp+1];
    if(temp!=-1)
    printf("%d,", temp);
  }
  printf("]\n");
}

void defrag()
{
  int defrag[300];
  int h;
  for(int x=0;x<300;x++)
  {
    defrag[x]=0;
  }
  int index=0;
  for(int n=0;n<10;n++)
  {
    h=head[n];
    if(h==-1)
    ;//do notjing
    else
    {//h points to head of the list n
      int key=array[h];
      int next=array[h+1];
      int prev=array[h+2];
      if(next=-1)
       {//single element list
         defrag[index]=key;
         defrag[index+1]=-1;
         defrag[index+2]=-1;
         head[n]=index;
         index=index+3;
       }
      else
      {//many element LIST
      while(next!=-1)
      {
        if(prev==-1)
        {//for the first element of list
          defrag[index]=key;
          defrag[index+1]=index+3;
          defrag[index+2]=-1;
          head[n]=index;
        }
        else
        {//for medieval elements of list
         defrag[index]=key;
         defrag[index+1]=index+3;
         defrag[index+2]=index-3;
        }
      key=array[next];
      next=array[next+1];
      prev=array[next+2];
      index=index+3;
    }
    //for last element of a list
    defrag[index]=key;
    defrag[index+1]=-1;
    defrag[index+2]=index-3;
         index=index+3;
  }
    }
  }
  freehead=index;
  int p=index/3;
  for(int z=p;z<(99-p);z++)
  {
    defrag[z*3]=0;
    defrag[z*3+1]=(z+1)*3;
    defrag[z*3+2]=0;
  }
  defrag[297]=0;
  defrag[298]=-1;
  defrag[299]=0;
  for(int l=0;l<300;l++)
  {
    array[l]=defrag[l];
  }
  printf("SUCCESS");
}
