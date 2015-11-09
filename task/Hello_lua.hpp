#ifndef __task_Hello_lua_hpp__
#define __task_Hello_lua_hpp__

#include "SCALE/LuaWrapper.h"
#include "task/Hello.hpp"

namespace task {

    class Hello_lua {
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
         * Allocate a new instance of the Hello task.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static Hello *allocator(lua_State *L)
        {
            return new Hello(luaL_checkstring(L, 1), luaL_checknumber(L, 2));
        }

        /**
         * Set the number of times the task should run.
         * @param L Pointer to the Lua state.
         * @return Number of elements being passed back through the Lua stack.
         */
        static int set_ntimes(lua_State *L)
        {
            Hello *p = luaW_check<Hello>(L, 1);
            p->set_ntimes(luaL_checknumber(L, 2));
            return 0;
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
            luaW_register<Hello>(L, "Hello", NULL, methods, allocator);
            luaW_extend<Hello, SRTX::Task>(L);
            return 0;
        }
    };

    const char Hello_lua::class_name[] = "Hello";

    luaL_Reg Hello_lua::methods[] = { { "set_ntimes", Hello_lua::set_ntimes },
                                      { NULL, NULL } };

} // namespace

#endif // __task_Hello_lua_hpp__
