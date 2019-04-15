#include <stdio.h>
#include "functions.h"

int main()
{

 for(int i=0;i<99;i++)
 {
  array[i*3]=0;
  array[i*3+1]=(i+1)*3;
  array[i*3+2]=0;
 }
 array[297]=0;
 array[298]=-1;//Denote null with -1
 array[299]=0;//Put default value to 0

 for (int x=0;x<10;x++)
 {
   head[x]=-1;//-1 denotes no list
 }

 while(1)
 { int option;
   printf("Select an option:\n1. Create a new list\n2. Insert a new element in a given list in sorted order\n3. Delete an element from a given list\n4. Count total elements excluding free list\n5. Count total elements of a list\n6. Display all lists\n7. Display free list\n8. Perform defragmentation\n9. Press 0 to exit\n");
   scanf("%d", &option);
   if(option==0)
     break;
   else
   {
     switch(option)
     {
            case 1:create_list();
            break;
            case 2:insert();
            break;
            case 3:delete();
            break;
            case 4:tot_all_list();
            break;
            case 5:tot_this_list();
            break;
            case 6:disp_all_list();
            break;
            case 7:disp_free_list();
            break;
            case 8:defrag();
            break;
      }
     }
   }
}
