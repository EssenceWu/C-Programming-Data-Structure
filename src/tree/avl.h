
#include "btree.h"

bool c_avl_insert( c_node **pos, int key, c_data data );


void c_avl_left_balance( c_node **pos );


void c_avl_right_balance( c_node **pos );


void c_avl_left_rotate( c_node **pos );


void c_avl_right_rotate( c_node **pos );