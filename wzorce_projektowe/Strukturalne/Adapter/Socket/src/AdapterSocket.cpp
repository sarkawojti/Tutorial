
#include "../inc/AdapterSocket.h"
#include "../inc/EuropeanSocketInterface.h"

void AdapterSocket::plug_in(const std::shared_ptr<EuropeanSocketInterface>& outlet)
{
    socket = outlet;
}

int AdapterSocket::voltage()
{
    return 110;
}

int AdapterSocket::live()
{
    return socket->live();
}

int AdapterSocket::neutral()
{
    return socket->neutral();
}
