#ifndef service_UDP_hpp
#define service_UDP_hpp

namespace service {

    class UDP {
      public:
        static UDP &get_instance()
        {
            static UDP instance;
            return instance;
        }

        typedef int (*read_t)(unsigned int channel, void *buffer,
                              unsigned int nbytes);

        typedef int (*write_t)(unsigned int channel, const void *buffer,
                               unsigned int nbytes);

        read_t read;
        write_t write;

      private:
        static int default_read(unsigned int channel, void *buffer,
                                unsigned int nbytes)
        {
            (void)channel; // Suppress unused variable warnings.
            (void)buffer;
            (void)nbytes;

            return -1;
        }

        static int default_write(unsigned int channel, const void *buffer,
                                 unsigned int nbytes)
        {
            (void)channel; // Suppress unused variable warnings.
            (void)buffer;
            (void)nbytes;

            return -1;
        }

        /**
         * Constructor.
         * The constructor is made private as part of the singleton
         * pattern.
         */
        UDP() : read(default_read), write(default_write)
        {
        }

        /**
         * Copy constructor.
         * The copy constructor is made private as part of the singleton
         * pattern.
         */
        UDP(const UDP &);

        /**
         * Assignment operator.
         * The assignment operator is made private as part of the singleton
         * pattern.
         */
        UDP &operator=(const UDP &);
    };

} // namespace

#endif // service_UDP_hpp
