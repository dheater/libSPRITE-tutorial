#ifndef task_Ping_hpp
#define task_Ping_hpp

#include <SRTX/Task.h>
#include <SRTX/Publication.h>
#include <SRTX/Subscription.h>
#include "topic/Ping.hpp"
#include "topic/Pong.hpp"

namespace task {
    class Ping : public SRTX::Task {
      public:
        /**
         * Constructor.
         * @param name Task name.
         */
        Ping(const char *const name);

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
        Ping(const Ping&);
        Ping& operator=(const Ping&);

        /**
         * Publication for ping data.
         */
        SRTX::Publication<topic::Ping_msg_t> *m_ping_publication;

        /**
         * Subscription to pong data.
         */
        SRTX::Subscription<topic::Pong_msg_t> *m_pong_subscription;
    };

} // namespace

#endif // task_Ping_hpp
