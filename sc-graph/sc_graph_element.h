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

/*! Calculates the \p vertex degree of the \p graph
 * \param graph sc-addr of the graph structure which contains the vertex
 * \param vertex sc-addr of the vertex the dergeee of which needs calculating
 * \param result pointer to int that will contain the degree
 * \return If degree was found, return SC_RESULT_OK; otherwise returns any error code
 */
sc_result sc_graph_vertex_degree(const sc_addr graph, const sc_addr vertex, int *result);

#endif // SC_GRAPH_FIND_CONN_COMP_H
