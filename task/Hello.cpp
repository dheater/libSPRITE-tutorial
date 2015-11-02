#include "task/Hello.hpp"
#include "base/XPRINTF.h"

namespace task {

    Hello::Hello(const char *const name)
        : SRTX::Task(name)
    {
    }

    bool Hello::init()
    {
        return true;
    }

    bool Hello::execute()
    {
        static unsigned int i = 0;
        IPRINTF("Hello World\n");
        return (++i < 5);
    }

    void Hello::terminate()
    {
    }

} // namespace
