#ifndef task_Hello_hpp
#define task_Hello_hpp

#include "SRTX/Task.h"

namespace task {
    class Hello : public SRTX::Task {

      public:
        /**
         * Constructor.
         * @param name Task name.
         * @param ntimes Number of times to run before exiting the task.
         */
        Hello(const char *const name, unsigned int ntimes);

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

        /**
         * Set the number of times the program executes.
         * @param ntimes Number of times to execute.
         */
        void set_ntimes(unsigned int ntimes);

      private:
        /**
         * Number of times to run.
         */
        unsigned int m_ntimes;

        /**
         * Number of times we have run.
         */
        unsigned int m_count;
    };

} // namespace

#endif // task_Hello_hpp
