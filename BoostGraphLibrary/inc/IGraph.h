#pragma once

template<class TPropertyVertex>
class IGraph
{
public:
    virtual ~IGraph() = default;

    virtual void clear() = 0;

    virtual void addVertex(const TPropertyVertex&) = 0;
    virtual bool removeVertex(const TPropertyVertex&) = 0;
    virtual bool findVertex(const TPropertyVertex&) const = 0;

    virtual unsigned numVertices() const = 0;
};
