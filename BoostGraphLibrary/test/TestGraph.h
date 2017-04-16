#pragma once

#include <iostream>

#include "../inc/Graph.h"
#include "../inc/City.h"
#include "../inc/Road.h"

class Country;

class TestGraph
{
    const City Warszawa = City("Warszawa");
    const City Gdansk   = City("Gdansk");
    const City Poznan   = City("Poznan");

    const Road WarszawaGdansk = Road(100);
    const Road WarszawaWarszawa = Road(0);
    const Road WarszawaPoznan = Road(200);

    using GraphCityRoadDirectedListListList =
        Graph<City, Road, Country, boost::directedS, boost::listS, boost::listS, boost::listS>;
    using GraphCityRoadDirectedVecVecList =
        Graph<City, Road, Country, boost::directedS, boost::vecS, boost::vecS, boost::listS>;

    using IGraphCityRoad = IGraph<City, Road>;
    std::list<std::shared_ptr<IGraphCityRoad>> _graphs;
    void test(const std::string&, void(TestGraph::*)(std::shared_ptr<IGraphCityRoad>&));

public:

    TestGraph();
    void all()
    {
       test("Remove all vertices", &test_remove_all);
       test("Add vertex",          &test_add_vertex);
       test("Add vertex unique",   &test_add_vertex_unique);
       test("Remove vertex",       &test_remove_vertex);
       test("Find vertex",         &test_find_vertex);

       test("Add edge",            &test_add_edge);
       test("Add edge unique",     &test_add_edge_unique);
    }

    void test_add_edge(std::shared_ptr<IGraphCityRoad>&);
    void test_add_edge_unique(std::shared_ptr<IGraphCityRoad>&);

    void test_remove_all(std::shared_ptr<IGraphCityRoad>&);
    void test_add_vertex(std::shared_ptr<IGraphCityRoad>&);
    void test_add_vertex_unique(std::shared_ptr<IGraphCityRoad>&);
    void test_remove_vertex(std::shared_ptr<IGraphCityRoad>&);
    void test_find_vertex(std::shared_ptr<IGraphCityRoad>&);
};
