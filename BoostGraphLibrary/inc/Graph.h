#pragma once

#include <boost/graph/adjacency_list.hpp>

#include "IGraph.h"

template<class TPropertyVertex      = boost::no_property,
         class TPropertyEdge        = boost::no_property,
         class TPropertyGraph       = boost::no_property,
         class TGraphSelector       = boost::directedS,
         class TOutEdgeListSelector = boost::vecS,
         class TVertexListSelector  = boost::vecS,
         class TEdgeListSelector    = boost::listS>
class Graph : public IGraph<TPropertyVertex>
{
private:
    using AdjacentListGraph =
        boost::adjacency_list<TOutEdgeListSelector, TVertexListSelector, TGraphSelector,
                              TPropertyVertex, TPropertyEdge, TPropertyGraph, TEdgeListSelector>;
    using VertexId = typename boost::graph_traits<AdjacentListGraph>::vertex_descriptor;

public:
    Graph() = default;

    void clear() override { std::cout << "Remove all vertices." << std::endl; graph.clear(); }

    void addVertex(const TPropertyVertex&) override;
    bool removeVertex(const TPropertyVertex&) override;
    bool findVertex(const TPropertyVertex&) const override;

    unsigned numVertices() const override { return num_vertices(graph); }

private:
    AdjacentListGraph graph;

    boost::optional<VertexId> searchVertex(const TPropertyVertex&) const;
};

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::findVertex(const TPropertyVertex& vertex) const
{
    auto search_result = searchVertex(vertex);
    if(not search_result)
    {
        std::cout << "Not found vertex: [" << vertex << "]." << std::endl;
        return false;
    }

    std::cout << "Found vertex: [" << vertex << "] - descriptor("
              << *search_result << ")." << std::endl;

    return true;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
boost::optional<typename Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
               TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>::VertexId>
Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
      TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::searchVertex(const TPropertyVertex& vertex) const
{
    auto iterators = vertices(graph);
    for(auto _search_iter = iterators.first; _search_iter != iterators.second; ++_search_iter)
    {
        if(graph[*_search_iter] == vertex)
        {
            return *_search_iter;
        }
    }
    return boost::none;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::removeVertex(const TPropertyVertex& vertex)
{
    auto search_result = searchVertex(vertex);
    if(not search_result) return false;

    std::cout << "Removed vertex: [" << vertex << "] - descriptor(" << *search_result
              << "). Actual num of vertices - " << numVertices() - 1 << "." << std::endl;

    clear_vertex(*search_result, graph);
    remove_vertex(*search_result, graph);
    return true;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
void Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::addVertex(const TPropertyVertex& vertex)
{
    const auto _vertex_descriptor = add_vertex(vertex, graph);
    std::cout << "Added vertex: [" << vertex << "] - descriptor(" << _vertex_descriptor
              << "). Actual num of vertices - " << numVertices() << "." << std::endl;
}
