#include "task/Echo.hpp"
#include "service/UDP.hpp"
#include <base/XPRINTF.h>

namespace task {

    Echo::Echo(const char *const name) : SRTX::Task(name)
    {
    }

    bool Echo::init()
    {
        return true;
    }

    bool Echo::execute()
    {
        static service::UDP &udp = service::UDP::get_instance();
        const unsigned int NBYTES = 256;
        static char buffer[NBYTES];

        if(-1 == udp.read(0, buffer, NBYTES)) {
            EPRINTF("ERROR in UDP read\n");
        }
        else {
            IPRINTF("%s\n", buffer);
        }

        return true;
    }

    void Echo::terminate()
    {
    }

} // namespace
