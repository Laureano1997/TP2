
#include "greenhouse_system.h"

int main()
{
    greenhouseSystemInit();
    while (true) {
        greenhouseSystemUpdate();
    }
}