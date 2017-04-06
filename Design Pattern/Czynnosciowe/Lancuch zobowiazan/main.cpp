
#include <memory>


#include "inc/InitMessageHandler.h"
#include "inc/SetupMessageHandler.h"
#include "inc/UnexpectedMessageHandler.h"

int main()
{
    Message init_msg { MessageId::id_init };
    Message config_msg { MessageId::id_config };
    Message setup_msg { MessageId::id_setup };

    std::shared_ptr<IMessageHandler> _handlerInit =
        std::make_shared<InitMessageHandler>();
    std::shared_ptr<IMessageHandler> _handlerSetup =
        std::make_shared<SetupMessageHandler>();
    std::shared_ptr<IMessageHandler> _handlerUnexpected =
        std::make_shared<UnexpectedMessageHandler>();

    _handlerInit->add_next(_handlerSetup);
    _handlerSetup->add_next(_handlerUnexpected);

    _handlerInit->handle(init_msg);
    _handlerInit->handle(config_msg);
    _handlerInit->handle(setup_msg);
    _handlerInit->handle(init_msg);

    return 0;
}

