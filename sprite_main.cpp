#include <SRTX/Scheduler.h>
#include <base/XPRINTF.h>
#include <signal.h>

#include "task/Hello.hpp"

static volatile bool done(false);

static void kill_me_now(int)
{
    done = true;
}

static units::Nanoseconds HZ_to_period(unsigned int hz)
{
    return units::Nanoseconds(1*units::SEC / hz);
}

int main(void)
{
    /* Set up the signal handler for control-C.
     */
    signal(SIGINT, kill_me_now);

    /* Declare the task properties.
     */
    SRTX::Task_properties tp;
    SRTX::priority_t priority = SRTX::MAX_PRIO;

    /* Create the scheduler
     */
    tp.prio = priority;
    tp.period = HZ_to_period(1);
    SRTX::Scheduler &s = SRTX::Scheduler::get_instance();
    s.set_properties(tp);

    /* Create the "Hello World!" task
     */
    --tp.prio;
    task::Hello hello("Hello");
    hello.set_properties(tp);

    s.start();
    hello.start();

    while(!done)
    {
        ;
    }

    hello.stop();
    s.stop();

    return 0;
}
