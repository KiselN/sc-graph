#ifndef SC_GRAPH_FIND_CONN_COMP_H
#define SC_GRAPH_FIND_CONN_COMP_H

#include "sc_graph_prerequest.h"

/* File contains functions to work with graph elements
 */
/*! Find connective components of the specified graph
 * \param graph sc-addr of graph structure to search connective components
 * \param sc_addr of a set of connective components; connective compoment is a set of vertices
 * \return if connective components were found, return SC_RESULT_OK; otherwise return any error code
 */
sc_result sc_graph_find_conn_comp(sc_addr graph, sc_addr *conn_comp_set);

#endif // SC_GRAPH_FIND_CONN_COMP_H
