#include "test_search_incident_vertexes.h"

TestSearchIncidentVertexes::TestSearchIncidentVertexes()
{

}

TestSearchIncidentVertexes::~TestSearchIncidentVertexes()
{

}

const String& TestSearchIncidentVertexes::name() const
{
    static String value = "Search incident vertex arc";
    return value;
}

bool TestSearchIncidentVertexes::prepare()
{
    return (sc_graph_generate_empty(&mOrGraphAddr) == SC_TRUE) &&
            (sc_graph_generate_empty(&mNotOrGraphAddr) == SC_TRUE);
}

bool TestSearchIncidentVertexes::run()
{
    PREPARE_SUBTESTS();
    RUN_SUBTEST(check_search_incident_edge_vertexes, "Search incident edge vertexes");
    RUN_SUBTEST(check_search_incident_arc_vertexes, "Search incident arc vertexes");

    return SUBTESTS_RESULT;
}

void TestSearchIncidentVertexes::done()
{

}


bool TestSearchIncidentVertexes::check_search_incident_edge_vertexes()
{
    assert(SC_ADDR_IS_NOT_EMPTY(mNotOrGraphAddr));

    sc_addr arc1, arc2, arc3, arc4, v1, v2, v3, v4;
    sc_memory_arc_new(sc_type_arc_pos_const_perm, sc_graph_keynode_not_oriented_graph, mNotOrGraphAddr);

    // create
    if (sc_graph_create_vertex(mNotOrGraphAddr, &v1) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mNotOrGraphAddr, &v2) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mNotOrGraphAddr, &v3) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mNotOrGraphAddr, &v4) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mNotOrGraphAddr, v1, v2, &arc1) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mNotOrGraphAddr, v1, v3, &arc2) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mNotOrGraphAddr, v2, v3, &arc3) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mNotOrGraphAddr, v3, v4, &arc4) != SC_RESULT_OK)
        return false;
    if(sc_graph_check_arc(mNotOrGraphAddr,arc1) != SC_RESULT_OK)
        return false;

    sc_addr_list *listVertexes = (sc_addr_list*)nullptr;
    if (search_incident_vertexes(mNotOrGraphAddr, arc1, &listVertexes) != SC_RESULT_OK)
            return false;

    if(!SC_ADDR_IS_EQUAL(listVertexes->value, v2))
        return false;

    listVertexes = sc_addr_list_next(listVertexes);

    if(!SC_ADDR_IS_EQUAL(listVertexes->value, v1))
        return false;

return true;
}

bool TestSearchIncidentVertexes::check_search_incident_arc_vertexes()
{
    assert(SC_ADDR_IS_NOT_EMPTY(mOrGraphAddr));

    sc_addr arc1, arc2, arc3,v1,v2, v3, v4;

    sc_memory_arc_new(sc_type_arc_pos_const_perm, sc_graph_keynode_oriented_graph, mOrGraphAddr);

    // create
    if (sc_graph_create_vertex(mOrGraphAddr, &v1) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mOrGraphAddr, &v2) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mOrGraphAddr, &v3) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_vertex(mOrGraphAddr, &v4) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mOrGraphAddr, v1, v2, &arc1) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mOrGraphAddr, v1, v3, &arc2) != SC_RESULT_OK)
        return false;
    if (sc_graph_create_arc(mOrGraphAddr, v1, v4, &arc3) != SC_RESULT_OK)
        return false;

    sc_addr_list *listVertexes = (sc_addr_list*)nullptr;
    if (search_incident_vertexes(mOrGraphAddr, arc2, &listVertexes) != SC_RESULT_OK)
            return false;

    if(!SC_ADDR_IS_EQUAL(listVertexes->value, v3))
        return false;

    listVertexes = sc_addr_list_next(listVertexes);

    if(!SC_ADDR_IS_EQUAL(listVertexes->value, v1))
        return false;

return true;
}
