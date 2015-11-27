#include "task/Pong.hpp"
#include <base/XPRINTF.h>

namespace task {

    Pong::Pong(const char *const name)
        : SRTX::Task(name), m_pong_publication(NULL), m_ping_subscription(NULL)
    {
    }

    bool Pong::init()
    {
        m_ping_subscription = new SRTX::Subscription<topic::Ping_msg_t>(
            topic::ping_topic, get_period());
        if((NULL == m_ping_subscription) ||
           (false == m_ping_subscription->is_valid())) {
            return false;
        }

        m_pong_publication = new SRTX::Publication<topic::Pong_msg_t>(
            topic::pong_topic, get_period());
        if((NULL == m_pong_publication) ||
           (false == m_pong_publication->is_valid())) {
            return false;
        }

        /* Set an initial value in the published content.
         */
        m_pong_publication->content.count = 0;
        m_pong_publication->put();

        return true;
    }

    bool Pong::execute()
    {
        /* Read the pong message and output the count.
         */
        if(false == m_ping_subscription->get()) {
            EPRINTF("Error retreiving ping data\n");
        }
        if(m_ping_subscription->was_updated()) {
            IPRINTF("Pong gets %u from ping\n",
                    m_ping_subscription->content.count);
        }

        /* Increment and publish the pong count.
         */
        ++m_pong_publication->content.count;
        IPRINTF("Pong puts %u\n", m_pong_publication->content.count);
        m_pong_publication->put();

        return true;
    }

    void Pong::terminate()
    {
        delete(m_ping_subscription);
        delete(m_pong_publication);
    }

} // namespace
