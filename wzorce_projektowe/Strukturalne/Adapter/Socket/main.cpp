
#include "inc/Socket.h"
#include "inc/EuropeanSocketInterface.h"
#include "inc/USASocketInterface.h"
#include "inc/AdapterSocket.h"

#include <memory>

int main()
{
    std::shared_ptr<EuropeanSocketInterface> socket =
        std::make_shared<Socket>();

    std::shared_ptr<AdapterSocket> adapter =
        std::make_shared<AdapterSocket>();

    adapter->plug_in(socket);

    std::shared_ptr<USASocketInterface> usa_socket = adapter;

    return 0;
}
