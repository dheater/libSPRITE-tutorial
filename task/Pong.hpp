#ifndef task_Pong_hpp
#define task_Pong_hpp

#include <SRTX/Task.h>
#include <SRTX/Publication.h>
#include <SRTX/Subscription.h>
#include "topic/Ping.hpp"
#include "topic/Pong.hpp"

namespace task {
    class Pong : public SRTX::Task {
      public:
        /**
         * Constructor.
         * @param name Task name.
         */
        Pong(const char *const name);

        /**
         * Initialization routine.
         * @return true on success or false on failure.
         */
        bool init();

        /**
         * This the the function that gets executed on a periodic basis
         * each time this task is scheduler to run.
         * @return Return true to continue execution or false to terminate
         * the task.
         */
        bool execute();

        /**
         * Terminate routine.
         */
        void terminate();

      private:
        /* Hide copy constructor and assignment operator.
         */
        Pong(const Pong&);
        Pong& operator=(const Pong&);

        /**
         * Publication for pong data.
         */
        SRTX::Publication<topic::Pong_msg_t> *m_pong_publication;

        /**
         * Subscription to ping data.
         */
        SRTX::Subscription<topic::Ping_msg_t> *m_ping_subscription;
    };

} // namespace

#endif // task_Pong_hpp
