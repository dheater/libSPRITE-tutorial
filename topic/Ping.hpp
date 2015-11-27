#ifndef topic_Ping_hpp
#define topic_Ping_hpp

namespace topic {
    /**
     * This is the Ping message type.
     */
    typedef struct {
        unsigned int count;
    } Ping_msg_t;

    /**
     * This is the Ping message name.
     */
    const char ping_topic[] = "Ping";

} // namespace

#endif // topic_Ping_hpp
