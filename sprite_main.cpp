#include <SCALE/Scale_if.h>
#include <base/XPRINTF.h>

#include "hwio/UDP_lua.hpp"
#include "task/Echo_lua.hpp"
#include "task/Hello_lua.hpp"
#include "task/Ping_lua.hpp"
#include "task/Pong_lua.hpp"

int main(int argc, char* argv[])
{
    (void) argc; // Suppress unused variable warning.

    SCALE::Scale_if& scale = SCALE::Scale_if::get_instance();

    /* Register my tasks with with the Lua executive.
     */
    hwio::UDP_lua::register_class(scale.state());
    task::Echo_lua::register_class(scale.state());
    task::Hello_lua::register_class(scale.state());
    task::Ping_lua::register_class(scale.state());
    task::Pong_lua::register_class(scale.state());

    /* Execute the main script that drives the simulation.
     */
    if(false == scale.run_script(argv[1]))
    {
        EPRINTF("Failed executing script: %s\n", argv[1]);
        return -1;
    }

    return 0;
}
