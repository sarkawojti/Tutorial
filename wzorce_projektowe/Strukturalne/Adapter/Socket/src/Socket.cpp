
#include "../inc/Socket.h"

int Socket::voltage()
{
    return 230;
};

int Socket::live()
{
    return -1;
};
int Socket::neutral()
{
    return 0;
};
int Socket::earth()
{
    return 1;
};
