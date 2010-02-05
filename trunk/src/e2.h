
#include<tile.h>

#ifndef _E2_H__
#define _E2_H__

static int debug = 0;

typedef struct
{
   int *board;
   tile_t *tiles;
   int ntiles;
   int side;
}
e2_t;



#endif

