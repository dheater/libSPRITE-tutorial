#ifndef task_Echo_hpp
#define task_Echo_hpp

#include <SRTX/Task.h>

namespace task {
    class Echo : public SRTX::Task {

      public:
        /**
         * Constructor.
         * @param name Task name.
         */
        Echo(const char *const name);

        /**
         * Initialization routine.
         * @return true on success or false on failure.
         */
        bool init();

        /**
         * This function gets executed each time this task is scheduled to run.
         * @return Return true to continue execution or false to terminate
         * the task.
         */
        bool execute();

        /**
         * Terminate routine.
         */
        void terminate();
    };

} // namespace

#endif // task_Echo_hpp
