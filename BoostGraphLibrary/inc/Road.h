#pragma once

class Road /** PropertyEdge **/
{
public:
    Road(unsigned _weight = 0): weight(_weight){}

    friend bool operator==(const Road& lRoad, const Road& rRoad)
    {
        return lRoad.weight == rRoad.weight;
    }
private:
    unsigned weight;
};
