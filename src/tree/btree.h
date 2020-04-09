
#include "../common.h"
#include "../stack.h"


void c_btree_pre( c_node *node );


void c_btree_in( c_node *node );


void c_btree_post( c_node *node );


void c_btree_level( c_node *node );


int c_btree_depth( c_node *node );


c_node *c_btree_search( c_node *node, int key );


void c_btree_delete( c_node *pos );