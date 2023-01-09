#ifndef __MAP_GRAPH
#define __MAP_GRAPH

#include <iostream>
#include <map>
#include <utility>
#include <string>
#include <vector>


template <class WeightType = int, class VertexType = std::string>
class Graph
{
    using EdgeType = std::pair<VertexType, WeightType> ;

    //       key,        vector:   <place,min>   
    std::map<VertexType, std::vector<EdgeType>> vertix;

    using vectorOfVisited = std::vector<std::pair<std::vector<VertexType>, WeightType>>;

public:

    void addVertex(const VertexType& v);

    void addEdge(const VertexType& v1, const VertexType& v2, const WeightType& weight);

    //crawling
    void viewPlace(Graph places);

    std::vector<VertexType> findMaxOptimalPaths(vectorOfVisited& input, int maxMin);

    //filter "RailwayStation"
    std::vector<VertexType> filter(std::vector<VertexType>& input)
    {
        std::vector<VertexType> result;

        for(auto tmp:input)
        {
            if (tmp != "RailwayStation")
                result.push_back(tmp);
        }
        return result;
    }

    Graph<WeightType,VertexType> createMap(const std::string& fileName);

    void printOptimalPath(const std::vector<VertexType>& input);
};

#include "mapGraph.cpp"
#endif // !__MAP_GRAPH
