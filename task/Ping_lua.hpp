#ifndef __task_Ping_lua_hpp__
#define __task_Ping_lua_hpp__

#include <SCALE/LuaWrapper.h>
#include "task/Ping.hpp"

namespace task {

    class Ping_lua {
      public:
        /**
         * The name registered with Lua to describe the class.
         */
        static const char class_name[];

        /**
         * The set of methods being exposed to Lua through the adapter
         * class.
         */
        static luaL_Reg methods[];

        /**
         * Allocate a new instance of the Ping task.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static Ping *allocator(lua_State *L)
        {
            return new Ping(luaL_checkstring(L, 1));
        }

        /**
         * Register the contents of this class as an adapter between Lua
         * and C++ representations of SRTX::Task.
         * @param L Pointer to the Lua state.
         * @return Number of elements being passed back through the Lua
         * stack.
         */
        static int register_class(lua_State *L)
        {
            luaW_register<Ping>(L, "Ping", NULL, methods, allocator);
            luaW_extend<Ping, SRTX::Task>(L);
            return 0;
        }
    };

    const char Ping_lua::class_name[] = "Ping";

    luaL_Reg Ping_lua::methods[] = { { NULL, NULL } };

} // namespace

#endif // __task_Ping_lua_hpp__
