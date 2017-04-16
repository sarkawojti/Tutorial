#pragma once

template<class TPropertyVertex, class TPropertyEdge>
class IGraph
{
public:
    virtual ~IGraph() = default;

    virtual void clear() = 0;

    virtual void add_vertex(const TPropertyVertex&) = 0;
    virtual bool add_vertex_unique(const TPropertyVertex&) = 0;
    virtual bool remove_vertex(const TPropertyVertex&) = 0;
    virtual bool find_vertex(const TPropertyVertex&) const = 0;
    virtual unsigned num_of_vertices() const = 0;

    virtual bool add_edge(const TPropertyVertex&, const TPropertyVertex&, const TPropertyEdge&) = 0;
    virtual bool add_edge_unique(const TPropertyVertex&, const TPropertyVertex&, const TPropertyEdge&) = 0;
    virtual unsigned num_of_edges() const = 0;
};
