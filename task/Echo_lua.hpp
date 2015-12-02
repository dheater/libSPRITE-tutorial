#ifndef __task_Echo_lua_hpp__
#define __task_Echo_lua_hpp__

#include <SCALE/LuaWrapper.h>
#include "task/Echo.hpp"

namespace task {

    class Echo_lua {
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
         * Allocate a new instance of the Echo task.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static Echo *allocator(lua_State *L)
        {
            return new Echo(luaL_checkstring(L, 1));
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
            luaW_register<Echo>(L, "Echo", NULL, methods, allocator);
            luaW_extend<Echo, SRTX::Task>(L);
            return 0;
        }
    };

    const char Echo_lua::class_name[] = "Echo";

    luaL_Reg Echo_lua::methods[] = { { NULL, NULL } };

} // namespace

#endif // __task_Echo_lua_hpp__
