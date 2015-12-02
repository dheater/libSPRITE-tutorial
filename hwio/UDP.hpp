#ifndef hwio_UDP_hpp
#define hwio_UDP_hpp

#include <net/UDP_connection.h>
#include <SRTX/Task.h>

namespace hwio {
    /**
     * This class manages a UDP port.
     */
    class UDP : public SRTX::Task {
      public:
        /**
         * Constructor.
         * @param name Task name.
         * @param port Port number.
         * @param hostname Hostname (client-only)
         */
        UDP(const char *const name, unsigned int port,
            const char *const hostname = NULL);

        /**
         * UDP initialization routine.
         * @return true on success or false on failure.
         */
        bool init();

        /**
         * UDP terminate routine.
         */
        void terminate();

      private:
        /* Hide copy constructor and assignment operator.
         */
        UDP(const UDP&);
        UDP& operator=(const UDP&);

        /**
         * Read input from the UDP socket.
         * @param channel UDP channel to read from.
         * @param buffer Input data buffer.
         * @param nbytes Maximum number of bytes to read.
         * @return Number of bytes read, or -1 on failure.
         */
        static int read(unsigned int channel, void *buffer,
                        unsigned int nbytes);

        /**
         * Write output through the UDP socket.
         * @param channel UDP channel to write to.
         * @param buffer Output data buffer.
         * @param nbytes Number of bytes to write.
         * @return Number of bytes written, or -1 on failure.
         */
        static int write(unsigned int channel, const void *buffer,
                         unsigned int nbytes);

        /**
         * Define the number of ports that we can handle.
         */
        static const unsigned int NUM_UDP = 20;

        /**
         * Connection to the UDP socket.
         */
        static net::UDP_connection *m_conn[NUM_UDP];

        /**
         * Port number.
         */
        const unsigned int m_port;

        /**
         * Hostname
         */
        const char* const m_hostname;
    };

} // namespace

#endif // hwio_UDP_hpp
