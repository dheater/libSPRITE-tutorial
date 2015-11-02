#include <SCALE/Scale_if.h>
#include <base/XPRINTF.h>

#include "task/Hello_lua.hpp"

int main(int argc, char* argv[])
{
    argc; // Supress unused variable warning.

    SCALE::Scale_if& scale = SCALE::Scale_if::get_instance();

    /* Register my tasks with with the Lua executive.
     */
    task::Hello_lua::register_class(scale.state());

    /* Execute the main script that drives the simulation.
     */
    if(false == scale.run_script(argv[1]))
    {
        EPRINTF("Failed executing script: %s\n", argv[1]);
        return -1;
    }

    return 0;
}
