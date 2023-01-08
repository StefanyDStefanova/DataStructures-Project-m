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
    using vectorOfVisited = std::vector<std::pair<std::vector, WeightType>>;
    using EdgeType = std::pair<VertexType, WeightType> ;

    //       key,        <place,min>   
    std::map<VertexType, EdgeType> vertix;

public:
    void addVertex(const VertexType& v);
    void deleteVertex(const VertexType& v);

    void addEdge(const VertexType& v1, const VertexType& v2, const WeightType& weight);
    void removeEdge(const VertexType& v1, const VertexType& v2);

    //crawling
    void viewPlace(Graph places);

    //filter "RailwayStation"
    vectorOfVisited filter(vectorOfVisited& input);

    void printOptimalPath(const vectorOfVisited& input, int maxMin);
};


#endif // !__MAP_GRAPH

