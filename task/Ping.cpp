#include "task/Ping.hpp"
#include <base/XPRINTF.h>

namespace task {

    Ping::Ping(const char *const name)
        : SRTX::Task(name), m_ping_publication(NULL), m_pong_subscription(NULL)
    {
    }

    bool Ping::init()
    {
        m_pong_subscription = new SRTX::Subscription<topic::Pong_msg_t>(
            topic::pong_topic, get_period());
        if((NULL == m_pong_subscription) ||
           (false == m_pong_subscription->is_valid())) {
            return false;
        }

        m_ping_publication = new SRTX::Publication<topic::Ping_msg_t>(
            topic::ping_topic, get_period());
        if((NULL == m_ping_publication) ||
           (false == m_ping_publication->is_valid())) {
            return false;
        }

        /* Set an initial value in the published content.
         */
        m_ping_publication->content.count = 0;
        m_ping_publication->put();

        return true;
    }

    bool Ping::execute()
    {
        /* Read the pong message and output the count.
         */
        if(false == m_pong_subscription->get()) {
            EPRINTF("Error retreiving pong data\n");
        }
        if(m_pong_subscription->was_updated()) {
            IPRINTF("Ping gets %u from pong\n",
                    m_pong_subscription->content.count);
        }

        /* Increment and publish the ping count.
         */
        ++m_ping_publication->content.count;
        IPRINTF("Ping puts %u\n", m_ping_publication->content.count);
        m_ping_publication->put();

        return true;
    }

    void Ping::terminate()
    {
        delete(m_pong_subscription);
        delete(m_ping_publication);
    }

} // namespace
