
#include "inc/City.h"
#include "inc/Road.h"
#include "inc/Country.h"
#include "inc/Graph.h"

#include <cassert>


int main()
{
    using GraphCityRoadDirectedListListList =
        Graph<City, Road, Country, boost::directedS, boost::vecS, boost::listS, boost::listS>;
    using IGraphCityRoadDirectedListListList = IGraph<City>;

    const City Warszawa("Warszawa");
    const City Gdansk("Gdansk");
    const City Poznan("Poznan");
    const City Wroclaw("Wroclaw");
    const City Krakow("Krakow");
    const City Gniezno("Gniezno");

    std::shared_ptr<IGraphCityRoadDirectedListListList> graph =
        std::make_shared<GraphCityRoadDirectedListListList>();

    graph->clear();

    graph->addVertex(Warszawa);
    graph->addVertex(Gdansk);
    graph->addVertex(Poznan);
    graph->addVertex(Wroclaw);
    graph->addVertex(Krakow);
    graph->addVertex(Gniezno);

    assert(true == graph->findVertex(Gniezno));
    assert(true  == graph->removeVertex(Gniezno));
    assert(false == graph->removeVertex(Gniezno));
    assert(false == graph->findVertex(Gniezno));

    return 0;
}
