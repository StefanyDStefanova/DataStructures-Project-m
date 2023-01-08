#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "mapGraph.h"

template<class WeightType, class VertexType>
inline void Graph<WeightType, VertexType>::addVertex(const VertexType& v)
{
    //vertix.insert(v);
    vertix.emplace(v);
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::removeVertex(const VertexType& v)
{
    vertix.clear(v);
    vertix.erase(v);
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::addEdge(const VertexType& v1, const VertexType& v2, const WeightType& weight)
{
    vertix.insert(v1, std::make_pair(v2, weight));
    vertix.insert(v2, std::make_pair(v1, weight));
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::removeEdge(const VertexType& v1, const VertexType& v2,const int weight)
{
    vertix.erase(vertix.find(v1, std::make_pair(v2, weight)));
    vertix.erase(vertix.find(v2, std::make_pair(v1, weight)));
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::printOptimalPath(const vectorOfVisited& input)
{
    filter(input);

    for (auto tmp:input)
    {
        std::cout << tmp << " ";
    }
}




#endif // !_GRAPH_CPP

