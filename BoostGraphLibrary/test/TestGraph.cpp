#include "TestGraph.h"

#include "../inc/Road.h"
#include "../inc/Country.h"

#include <memory>
#include <cassert>

TestGraph::TestGraph()
{
    _graphs.push_back(std::make_shared<GraphCityRoadDirectedListListList>());
    _graphs.push_back(std::make_shared<GraphCityRoadDirectedVecVecList>());
}

void TestGraph::test(const std::string& name, void(TestGraph::* func)(std::shared_ptr<IGraphCityRoad>&))
{
    unsigned counter = 0;
    for(auto& graph : _graphs)
    {
        std::cout << std::endl << "===========================================================" << std::endl;
        std::cout << "Test(" << counter << "): " << name << std::endl << std::endl;

        graph->clear();
       (this->*func)(graph);

        counter++;
        std::cout << std::endl << "===========================================================" << std::endl;
    }
}

void TestGraph::test_remove_all(std::shared_ptr<IGraphCityRoad>& graph)
{
    graph->add_vertex(Warszawa);
    graph->add_vertex(Warszawa);
    graph->add_vertex(Warszawa);
    assert(3 == graph->num_of_vertices());
    graph->clear();
    assert(0 == graph->num_of_vertices());
}

void TestGraph::test_find_vertex(std::shared_ptr<IGraphCityRoad>& graph)
{
    assert(false == graph->find_vertex(Warszawa));
    graph->add_vertex(Warszawa);
    assert(true == graph->find_vertex(Warszawa));
    graph->remove_vertex(Warszawa);
    assert(false == graph->find_vertex(Warszawa));
}

void TestGraph::test_remove_vertex(std::shared_ptr<IGraphCityRoad>& graph)
{
    graph->add_vertex(Warszawa);
    graph->add_vertex(Poznan);
    graph->add_vertex(Gdansk);
    assert(3 == graph->num_of_vertices());

    graph->remove_vertex(Warszawa);
    assert(2 == graph->num_of_vertices());
    graph->add_vertex(Warszawa);

    graph->remove_vertex(Gdansk);
    graph->add_vertex(Gdansk);

    /**
        deskryptor wierzcholka grafu [wektor obiektem przechowujacym] = indeks wektora,
        gdy dokonujemy operacji usuwania wierzcholka wowczas przechowalnia ulega
        reorganizacji = przesuwane sa indeksy
    **/

    /**
        po usunieciu 'Warszawa' deskrytory kazdego miasta zmniejszyly sie o jeden
        Before remove: 'Poznan' descriptor = 1
        After remove:  'Poznan' descriptor = 0
    **/

    /**
        czemu nie uzyto tutaj adresow komorek pamieci tak jak w przechowalni = lista?

        przyczyna jest realokacja kontenera wektor przy dodawaniu nowego elementu,
        jesli mamy za male capacity (realokacja podwoja go) ktora nadaje komorka wektora
        nowe adresy - indeksy wektora sa w tym przypadku bardziej stabilniejsze niz
        adresy pamieci elementow wektora
    **/

    /** usuniecie wierzcholka reorganizuje rowniez przechowalnie krawedzi **/
}

void TestGraph::test_add_vertex(std::shared_ptr<IGraphCityRoad>& graph)
{
    assert(0 == graph->num_of_vertices());
    graph->add_vertex(Warszawa);
    graph->add_vertex(Poznan);
    graph->add_vertex(Gdansk);
    assert(3 == graph->num_of_vertices());
}

void TestGraph::test_add_edge_unique(std::shared_ptr<IGraphCityRoad>& graph)
{
    graph->add_vertex(Warszawa);
    assert(true == graph->add_edge_unique(Warszawa, Warszawa, WarszawaWarszawa));
    assert(1 == graph->num_of_edges());
    assert(false == graph->add_edge_unique(Warszawa, Warszawa, WarszawaWarszawa));
    assert(1 == graph->num_of_edges());
    std::cout << std::endl;
}

void TestGraph::test_add_edge(std::shared_ptr<IGraphCityRoad>& graph)
{
    /** sprawdzenie pustego grafu **/
    assert(0 == graph->num_of_edges());
    assert(false == graph->add_edge(Warszawa, Gdansk, WarszawaGdansk));
    assert(0 == graph->num_of_edges());
    std::cout << std::endl;

    /** sprawdzenie gdy tylko jeden z wierzcholkow istnieje **/
    graph->add_vertex(Warszawa);
    assert(false == graph->add_edge(Warszawa, Gdansk, WarszawaGdansk));
    assert(0 == graph->num_of_edges());
    std::cout << std::endl;

    /** sprawdzenie gdy oba wierzcholki istnieja **/
    graph->add_vertex(Gdansk);
    assert(true == graph->add_edge(Warszawa, Gdansk, WarszawaGdansk));
    assert(1 == graph->num_of_edges());
    std::cout << std::endl;

    /** sprawdzenie gdy wierzcholki sa takie same **/
    assert(true == graph->add_edge(Warszawa, Warszawa, WarszawaWarszawa));
    assert(2 == graph->num_of_edges());
    std::cout << std::endl;

    /** sprawdzenie ze implementacja dopuszcza dodanie kolejnej krawedzi **/
    assert(true == graph->add_edge(Warszawa, Warszawa, WarszawaWarszawa));
    assert(3 == graph->num_of_edges());
    std::cout << std::endl;
}

void TestGraph::test_add_vertex_unique(std::shared_ptr<IGraphCityRoad>& graph)
{
    assert(0 == graph->num_of_vertices());
    graph->add_vertex(Warszawa);
    graph->add_vertex(Warszawa);
    assert(2 == graph->num_of_vertices());
    assert(false == graph->add_vertex_unique(Warszawa));
    assert(2 == graph->num_of_vertices());
    assert(true == graph->add_vertex_unique(Poznan));
    assert(3 == graph->num_of_vertices());
    assert(false == graph->add_vertex_unique(Poznan));
    assert(3 == graph->num_of_vertices());
}
