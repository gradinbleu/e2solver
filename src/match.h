
#ifndef __MATCH_H__
#define __MATCH_H__

#include <board.h>
#include <e2.h>

// {{{ match_top()
int match_top(e2_t *e2, int x, int y)
{
   int id  = board_get(e2, x, y);
   int mid = -1;

	if(y-1>=0)
      mid = board_get(e2, x, y-1);

   if(mid==-1)
   {
      if(e2->tiles[id].top == 0)
         return 1;
      else
         return 0;
   }


   if(e2->tiles[id].top == 0)
      return 0;


   if(e2->tiles[id].top == e2->tiles[mid].bottom)
      return 1;
   else
      return 0;
} 
// }}}

// {{{ match_bottom()
int match_bottom(e2_t *e2, int x, int y)
{
   int id  = board_get(e2, x, y);
   int mid = -1;

	if(y+1<e2->side)
      mid = board_get(e2, x, y+1);


   if(mid==-1)
   {
      if(e2->tiles[id].bottom == 0)
         return 1;
      else
         return 0;
   }

   if(e2->tiles[id].bottom == 0)
      return 0;

   if(e2->tiles[id].bottom == e2->tiles[mid].top)
      return 1;
   else
      return 0;
} 
// }}}

// {{{ match_right()
int match_right(e2_t *e2, int x, int y)
{
   int id  = board_get(e2, x, y);
   int mid = -1;

	if(x+1<e2->side)
      mid = board_get(e2, x+1, y);


   if(mid==-1)
   {
      if(e2->tiles[id].right == 0)
         return 1;
      else
         return 0;
   }


   if(e2->tiles[id].right == 0)
      return 0;

   if(e2->tiles[id].right == e2->tiles[mid].left)
      return 1;
   else
      return 0;
} 
// }}}

// {{{ match_left()
int match_left(e2_t *e2, int x, int y)
{
   int id  = board_get(e2, x, y);
   int mid = -1;

	if(x-1>=0)
      mid = board_get(e2, x-1, y);


   if(mid==-1)
   {
      if(e2->tiles[id].left == 0)
         return 1;
      else
         return 0;
   }


   if(e2->tiles[id].left == 0)
      return 0;

   if(e2->tiles[id].left == e2->tiles[mid].right)
      return 1;
   else
      return 0;
} 
// }}}

// {{{ match_get_num_errors()
int match_get_num_errors(e2_t *e2, int x, int y)
{
   int count=0;

   if(!match_top(e2, x, y))
   {  
      //printf("top error\n");
      count ++;
   }

   if(!match_bottom(e2, x, y))
   {  
      //printf("bottom error\n");
      count ++;
   }

   if(!match_right(e2, x, y))
   {  
      //printf("right error\n");
      count ++;
   }

   if(!match_left(e2, x, y))
   {  
      //printf("left error\n");
      count ++;
   }

   return count;
}
// }}}

// {{{ match_get_num_total_errors() 
int match_get_num_total_errors(e2_t *e2)
{
   int count = 0;
   int x;
   int y;
   for(y=0; y<e2->side; y++)
      for(x=0; x<e2->side; x++)
         count += match_get_num_errors(e2, x, y);

   return count;
}
// }}}












#endif



