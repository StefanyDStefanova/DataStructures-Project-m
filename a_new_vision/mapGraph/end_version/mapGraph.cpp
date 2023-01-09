#ifndef __GRAPH_CPP
#define __GRAPH_CPP

#include "mapGraph.h"
#include <iostream>
#include <fstream>

template<class WeightType, class VertexType>
inline void Graph<WeightType, VertexType>::addVertex(const VertexType& v)
{
    std::vector<EdgeType> vectorOfEdge;
    vertix.emplace(v, vectorOfEdge);
}

template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::addEdge(const VertexType& v1, const VertexType& v2, const WeightType& weight)
{
    if (vertix.find(v1)==vertix.end())
    {
        addVertex(v1);
    }

    if (vertix.find(v2)==vertix.end())
    {
        addVertex(v2);
    }

    vertix.find(v1)->second.push_back(std::make_pair(v2, weight));
    vertix.find(v2)->second.push_back(std::make_pair(v1, weight));
}

template<class WeightType, class VertexType>
std::vector<VertexType> Graph<WeightType, VertexType>::findMaxOptimalPaths(vectorOfVisited& input, int maxMin)
{
    std::vector<VertexType> result;

    WeightType maxLenOfPlace = 0, tmpLen;
    WeightType tmpMin= input.begin().second();
    
    std::vector<VertexType> tmp = input.begin().first();
    while (!tmp.empty())
    {
        filter(tmp);
        tmpLen = tmp.size();
    }
    return result;
}


template<class WeightType, class VertexType>
void Graph<WeightType, VertexType>::printOptimalPath(const std::vector<VertexType>& input)
{
    findMaxOptimalPaths(input);

    for (auto tmp:input)
    {
        std::cout << tmp << " ";
    }
}


template<class WeightType, class VertexType>
Graph<WeightType, VertexType> Graph<WeightType, VertexType>::createMap(const std::string& fileName)
{
    std::ifstream in("GraphCityMap.txt", std::ios::in);

    if (!in.is_open())
    {
        std::cout << "File cannot be opened!" << std::endl;
        return Graph();
    }

    int vertices, edgesand;
    in >> vertices >> edgesand;

    Graph<WeightType, VertexType> g;

    if (vertices <= 0 && edgesand <= vertices)
        throw std::runtime_error("Invalid values!");

    std::string startV, endV;
    int weightE;

    for (int i = 0; i <= edgesand; i++)
    {
        if (in.good())
        {
            in >> startV >> endV >> weightE;
            g.addEdge(startV, endV, weightE);
        }
        else if (in.eof())
        {
            std::cout << "End of file reached!" << std::endl;
        }
        else
        {
            // the state of the input stream is fail
            std::cout << "Last operation has failed!" << std::endl;

            // clears the state of the stream, 
            // the stream is back to good state, nothing more...
            in.clear();

            // we have to remove the erroneous data from the stream
            in.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
        }
    }

    int minutes;
    in >> minutes;

    in.close();


    return g;

}


#endif // !_GRAPH_CPP

