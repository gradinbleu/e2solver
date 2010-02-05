
#ifndef __BOARD_H__
#define __BOARD_H__

// {{{ board_set_tiles(): initialize board
void board_set_tiles(e2_t *e2)
{
   int i;
   for(i=0; i<e2->ntiles; i++)
      e2->board[i]=i+1;
}
// }}}

// {{{ board_get/_set: board get/set methods
#define board_set(e2, x, y, value) (e2)->board[(e2)->side*(y) + x]=value
#define board_get(e2, x, y) (e2)->board[(e2)->side*(y) + x]
// }}}

// {{{ board_swap_tiles(): swap two tiles in board
void board_swap_tiles(e2_t *e2, int src_x, int src_y, int dst_x, int dst_y)
{
   int src_id = board_get(e2, src_x, src_y);
   int dst_id = board_get(e2, dst_x, dst_y);
   board_set(e2, src_x, src_y, dst_id);
   board_set(e2, dst_x, dst_y, src_id);
} 
// }}}






#endif

