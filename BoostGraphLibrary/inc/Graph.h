#pragma once

#include <boost/graph/adjacency_list.hpp>
#include <iostream>

#include "IGraph.h"

template<class TPropertyVertex      = boost::no_property,
         class TPropertyEdge        = boost::no_property,
         class TPropertyGraph       = boost::no_property,
         class TGraphSelector       = boost::directedS,
         class TOutEdgeListSelector = boost::vecS,
         class TVertexListSelector  = boost::vecS,
         class TEdgeListSelector    = boost::listS>
class Graph : public IGraph<TPropertyVertex, TPropertyEdge>
{
private:
    using AdjacentListGraph =
        boost::adjacency_list<TOutEdgeListSelector, TVertexListSelector, TGraphSelector,
                              TPropertyVertex, TPropertyEdge, TPropertyGraph, TEdgeListSelector>;
    using VertexId = typename boost::graph_traits<AdjacentListGraph>::vertex_descriptor;

public:
    Graph() = default;

    void clear() override { std::cout << "Remove all vertices." << std::endl; graph.clear(); }

    void add_vertex(const TPropertyVertex&) override;
    bool add_vertex_unique(const TPropertyVertex&) override;
    bool remove_vertex(const TPropertyVertex&) override;
    bool find_vertex(const TPropertyVertex&) const override;
    unsigned num_of_vertices() const override { return num_vertices(graph); }

    bool add_edge(const TPropertyVertex&, const TPropertyVertex&, const TPropertyEdge&) override;
    bool add_edge_unique(const TPropertyVertex&, const TPropertyVertex&, const TPropertyEdge&) override;
    unsigned num_of_edges() const override { return num_edges(graph); }

private:
    AdjacentListGraph graph;

    bool add_edge(const TPropertyVertex&, const TPropertyVertex&, const TPropertyEdge&, bool);
    boost::optional<VertexId> searchVertex(const TPropertyVertex&) const;
};

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::find_vertex(const TPropertyVertex& vertex) const
{
    if(searchVertex(vertex))
    {
        return true;
    }
    return false;
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
            std::cout << "Found vertex: [" << vertex
                      << "] - descriptor(" << *_search_iter
                      << ")." << std::endl;
            return *_search_iter;
        }
    }
    std::cout << "Not found vertex: [" << vertex << "]." << std::endl;
    return boost::none;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::remove_vertex(const TPropertyVertex& vertex)
{
    auto search_result = searchVertex(vertex);
    if(not search_result) return false;

    clear_vertex(*search_result, graph);
    boost::remove_vertex(*search_result, graph);

    std::cout << "Removed vertex: [" << vertex
              << "] - descriptor(" << *search_result
              << "). Actual num of vertices : " << num_of_vertices()
              << "." << std::endl;

    return true;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
void Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::add_vertex(const TPropertyVertex& vertex)
{
    const auto _vertex_descriptor = boost::add_vertex(vertex, graph);
    std::cout << "Added vertex: [" << vertex
              << "] - descriptor(" << _vertex_descriptor
              << "). Actual num of vertices : " << num_of_vertices()
              << "." << std::endl;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::add_vertex_unique(const TPropertyVertex& vertex)
{
    if(find_vertex(vertex))
    {
        return false;
    }
    add_vertex(vertex);
    return true;
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::add_edge(const TPropertyVertex& source_vertex,
               const TPropertyVertex& target_vertex,
               const TPropertyEdge& edge)
{
    return Graph::add_edge(source_vertex, target_vertex, edge, false);
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::add_edge_unique(const TPropertyVertex& source_vertex,
                      const TPropertyVertex& target_vertex,
                      const TPropertyEdge& edge)
{
    return Graph::add_edge(source_vertex, target_vertex, edge, true);
}

template<class TPropertyVertex, class TPropertyEdge, class TPropertyGraph, class TGraphSelector,
        class TOutEdgeListSelector, class TVertexListSelector,class TEdgeListSelector>
bool Graph<TPropertyVertex, TPropertyEdge, TPropertyGraph, TGraphSelector,
           TOutEdgeListSelector, TVertexListSelector, TEdgeListSelector>
    ::add_edge(const TPropertyVertex& source_vertex,
               const TPropertyVertex& target_vertex,
               const TPropertyEdge& edge,
               bool  check_unique)
{
    std::cout << "Try add edge: [" << source_vertex
              << "] and [" <<  target_vertex
              << "]." << std::endl;
    auto source = searchVertex(source_vertex);
    auto target = source;
    if(source_vertex != target_vertex)
    {
        target = searchVertex(target_vertex);
    }

    if(source and target)
    {
        if(check_unique)
        {
            auto search_item = boost::edge(*source, *target, graph);
            if(search_item.second)
            {
                std::cout << "The edge is already in the graph "
                          << "- descriptor(" << search_item.first
                          << ")." << std::endl;
                return false;
            }
        }

        auto result = boost::add_edge(*source, *target, edge, graph);
        if(result.second)
        {
            std::cout << "Added edge: [" << source_vertex
                      << "] - descriptor(" << *source
                      << ") and [" << target_vertex
                      << "] - descriptor(" << *target
                      << ") - edge descriptor(" << result.first
                      << "). Actual num of edges : " << num_of_edges()
                      << "." << std::endl;
            return true;
        }
    }
    return false;
}
