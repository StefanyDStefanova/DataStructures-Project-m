#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "mapGraph.h"

template<class WeightType, class VertexType>
inline void Graph<WeightType, VertexType>::addVertex(const VertexType& v)
{
    std::vector<EdgeType<VertexType,WeightType>> vectorOfEdge;
    vertix.emplace(v, vectorOfEdge);
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::addEdge(const VertexType& v1, const VertexType& v2, const WeightType& weight)
{
    if (vertix.find(v1))
    {
        addVertex(v1);
    }

    if (vertix.find(v2))
    {
        addVertex(v2);
    }

    vertix.find(v1).push_back(std::make_pair(v2, weight));
    vertix.find(v2).push_back(std::make_pair(v1, weight));
}

template<class WeightType, class VertexType>
Graph<WeightType, VertexType> Graph<WeightType, VertexType>::createMap(const std::string& fileName)
{
    std::ifstream in(fileName);
    if (!in)
    {
        std::cerr << "Error: Couldn't open " << fileName << " for reading.\n";
        return false;
    }

    int vertices, edgesand;
    in >> vertices >> edgesand;

    Graph<WeightType, VertexType> g;

    if (vertices <= 0 && edgesand <=vertex)
        return nullptr;

    std::string startV, endV;
    int weightE;
    for (int i = 0; i <= edgesand; i++)
    {
        if (in.good())
        {
            in >> startV >> endV >> weightE;
            g.addEdge(startV, endV, weightE);
        }
    }

    int minutes;
    in >> minutes;

    in.close();

    return g;

}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::printOptimalPath(const std::vector<VertexType>& input)
{
    filter(input);

    for (auto tmp:input)
    {
        std::cout << tmp << " ";
    }
}




#endif // !_GRAPH_CPP

