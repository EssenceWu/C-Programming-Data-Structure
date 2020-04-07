
#include "btree.h"

bool c_rb_insert( c_node **root, c_node **pos, c_node *parent, int key, c_data data );


bool c_rb_delete( c_node **root, int key );


void c_rb_insert_fixup( c_node **root, c_node *pos, c_node *parent );


void c_rb_delete_fixup( c_node **root, c_node *pos, c_node *parent );


c_node *c_rb_left_minimum( c_node *pos );


c_node *c_rb_right_minimum( c_node *pos );


void c_rb_left_rotate( c_node **root, c_node *pos );


void c_rb_right_rotate( c_node **root, c_node *pos );


void c_rb_transplant( c_node **root, c_node *src, c_node *dst );