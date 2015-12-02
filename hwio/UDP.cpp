#include <net/UDP_client.h>
#include <net/UDP_server.h>

#include "hwio/UDP.hpp"
#include "service/UDP.hpp"

namespace hwio {
    net::UDP_connection *UDP::m_conn[UDP::NUM_UDP];

    UDP::UDP(const char *const name, unsigned int port,
             const char *const hostname)
        : SRTX::Task(name), m_port(port), m_hostname(hostname)
    {
        for(unsigned int i = 0; i < NUM_UDP; ++i) {
            m_conn[i] = NULL;
        }
    }

    bool UDP::init()
    {
        DPRINTF("channel = %d, hostname = %s, port = %d\n", 0, m_hostname,
                m_port);

        if(m_hostname) {
            DPRINTF("Create new UDP client\n");
            m_conn[0] = new net::UDP_client(m_hostname, m_port);
            if((NULL == m_conn[0]) || (false == m_conn[0]->is_valid())) {
                EPRINTF("Error creating UDP client\n");
                delete(m_conn[0]);
                m_conn[0] = NULL;
                return false;
            }
            /* When acting as a client, we have to send an initial message
             * before we receive messages.
             */
            char buffer[] = "Hi\n";
            m_conn[0]->write(buffer, sizeof(buffer));
        }
        else {
            DPRINTF("Create new UDP server\n");
            m_conn[0] = new net::UDP_server(m_port);
            if((NULL == m_conn[0]) || (false == m_conn[0]->is_valid())) {
                EPRINTF("Error creating UDP server\n");
                delete(m_conn[0]);
                m_conn[0] = NULL;
                return false;
            }
        }

        /* Set the function pointers for the UDP service.
         */
        service::UDP &udp = service::UDP::get_instance();
        udp.read = read;
        udp.write = write;

        /* We return false here because there is no need to schedule this task.
         * It's execute function does nothing.
         */
        return false;
    }

    void UDP::terminate()
    {
        if(m_conn[0] != NULL) {
            delete m_conn[0];
            m_conn[0] = NULL;
        }
    }

    int UDP::read(unsigned int channel, void *buffer, unsigned int nbytes)
    {
        if((NULL == m_conn[channel]) ||
           (false == m_conn[channel]->is_valid())) {
            return -1;
        }

        /* Read blocks program execution until data is received.
         * If the number of characters to be recieved is larger than
         * the number of chars available remaining data may be dropped.
         * res will be set to the actual number of characters
         * actually read
         */
        DPRINTF("Attempting to read channel %d\n", channel);
        int res = m_conn[channel]->read(buffer, nbytes);
        if(-1 == res) {
            PERROR("read");
            return res;
        }

        /* Set end of string, so we can print.
         */
        ((char *)buffer)[res] = '\0';
        DPRINTF("UDP read channel %d:%s:%d\n", channel, (char *)buffer, res);

        return res;
    }

    int UDP::write(unsigned int channel, const void *buffer,
                   unsigned int nbytes)
    {
        if((NULL == m_conn[channel]) ||
           (false == m_conn[channel]->is_valid())) {
            return -1;
        }

        return m_conn[channel]->write(const_cast<void *>(buffer), nbytes);
    }
}
