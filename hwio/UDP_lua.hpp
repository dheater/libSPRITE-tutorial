#ifndef hwio_UDP_lua_hpp
#define hwio_UDP_lua_hpp

#include <SCALE/LuaWrapper.h>
#include "hwio/UDP.hpp"

namespace hwio {

    class UDP_lua {
      public:
        /**
         * The name regsitered with Lua to describe the class.
         */
        static const char class_name[];

        /**
         * The set of methods being exposed to Lua through the adapter
         * class.
         */
        static luaL_Reg methods[];

        /**
         * Because we are passing arguments to the constuctor, we cannot use the
         * default constructor method.
         * @param L Pointer to the Lua state.
         * @return A pointer to the Task.
         */
        static UDP *allocator(lua_State *L)
        {
            /* How many arguments were passed?
             */
            int nargs = lua_gettop(L);

            /* 2 arguments are passed for UDP clients, 3 for servers.
             */
            return new UDP(luaL_checkstring(L, 1), luaL_checknumber(L, 2),
                           (3 == nargs) ? luaL_checkstring(L, 3) : NULL);
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
            luaW_register<UDP>(L, "UDP", NULL, methods, allocator);
            luaW_extend<UDP, SRTX::Task>(L);
            return 0;
        }
    };

    const char UDP_lua::class_name[] = "UDP";

    luaL_Reg UDP_lua::methods[] = { { NULL, NULL } };

} // namespace

#endif // hwio_UDP_lua_hpp
