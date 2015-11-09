#include "task/Hello.hpp"
#include "base/XPRINTF.h"

namespace task {

    Hello::Hello(const char *const name, unsigned int ntimes)
        : SRTX::Task(name)
        , m_ntimes(ntimes)
        , m_count(0)
    {
    }

    bool Hello::init()
    {
        m_count = 0;
        return true;
    }

    bool Hello::execute()
    {
        IPRINTF("Hello World\n");
        return (++m_count < m_ntimes);
    }

    void Hello::terminate()
    {
    }

    void Hello::set_ntimes(unsigned int ntimes)
    {
        m_count = 0;
        m_ntimes = ntimes;
    }

} // namespace
