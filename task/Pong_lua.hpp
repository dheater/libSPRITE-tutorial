#ifndef __task_Pong_lua_hpp__
#define __task_Pong_lua_hpp__

#include <SCALE/LuaWrapper.h>
#include "task/Pong.hpp"

namespace task {

    class Pong_lua {
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
         * Allocate a new instance of the Pong task.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static Pong *allocator(lua_State *L)
        {
            return new Pong(luaL_checkstring(L, 1));
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
            luaW_register<Pong>(L, "Pong", NULL, methods, allocator);
            luaW_extend<Pong, SRTX::Task>(L);
            return 0;
        }
    };

    const char Pong_lua::class_name[] = "Pong";

    luaL_Reg Pong_lua::methods[] = { { NULL, NULL } };

} // namespace

#endif // __task_Pong_lua_hpp__
