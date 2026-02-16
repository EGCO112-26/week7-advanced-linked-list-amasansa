// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ll.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int idIn; // char entered by user
   char nameIn[30];
   char buffer[10];

   instructions(); // display the menu
   printf( "%s", "? " );
   // scanf( "%u", &choice );
   scanf("%s", buffer);    // รับค่าเป็น string (รับตัวอักษรได้ เวลาเป็น Invalid choice จะไม่เข้า infinite loop)
   choice = atoi(buffer);

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf( "%s", "Enter id and name: " );
            scanf( "%d %s", &idIn ,nameIn);
            insert( &startPtr, idIn , nameIn ); // insert item in list
            printList( startPtr );
            printListR( startPtr );
            break;
         case 2: // delete an element
            // if list is not empty
            if ( !isEmpty( startPtr ) ) { 
               printf( "%s", "Enter number to be deleted: " );
               scanf( "%d", &idIn );

               // if character is found, remove it
               if ( deletes( &startPtr, idIn ) ) { // remove item
                  printf( "%d deleted.\n", idIn );
                  printList( startPtr );
                  printListR( startPtr );
               } // end if
               else {
                  printf( "%d not found.\n\n", idIn );
               } // end else
            } // end if
            else {
               puts( "List is empty.\n" );
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      // scanf( "%u", &choice );
      scanf("%s", buffer);
      choice = atoi(buffer);
   } // end while
  /* Clear all nodes at the end of nodes*/
   puts( "clear all nodes" );
   while(startPtr!=NULL){
      int tempID = startPtr->id;
      deletes(&startPtr,tempID);
      printf("deleted %d\n",tempID);
   }

   puts("End of run.");
   return 0;
} // end main
