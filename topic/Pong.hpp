#ifndef topic_Pong_hpp
#define topic_Pong_hpp

namespace topic {
    /**
     * This is the Pong message type.
     */
    typedef struct {
        unsigned int count;
    } Pong_msg_t;

    /**
     * This is the Pong message name.
     */
    const char pong_topic[] = "Pong";

} // namespace

#endif // topic_Pong_hpp
