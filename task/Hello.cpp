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
        IPRINTF("Hello World\n");
        return true;
    }

    void Hello::terminate()
    {
    }

} // namespace
