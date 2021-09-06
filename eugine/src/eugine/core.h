//
// Created by aiden on 8/2/21.
//

#ifndef EUGINE_CORE_H
#define EUGINE_CORE_H


#if defined(EG_PLATFORM_WINDOWS)

    #ifdef EG_BUILD_SHARED_LIB
        #define EG_API __declspec(dllexport)
    #else
        #define EG_API __declspec(dllimport)
    #endif
#elif defined(EG_PLATFORM_LINUX)
    #ifdef EG_BUILD_SHARED_LIB
        #define EG_API __attribute__((visibility("default")))
    #else
        #define EG_API
    #endif
#elif defined(EG_PLATFORM_DARWIN)
    //pray this works
    #ifdef EG_BUILD_SHARED_LIB
        #define EG_API __attribute__((visibility("default")))
    #endif
#endif

#include "log.h"

#ifdef EG_PLATFORM_WINDOWS
    #define EG_DEBUG_BREAK __debugbreak()
#else
    #include <signal.h>
    #define EG_DEBUG_BREAK raise(SIGTRAP)
#endif

#ifdef EG_ENABLE_ASSERTIONS
    #define EG_ASSERT(x, ...) { if(!(x)) { EG_ERROR("Assertion Failed: {0}", __VA_ARGS__); EG_DEBUG_BREAK; } }
    #define EG_CORE_ASSERT(x, ...) { if(!(x)) { EG_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); EG_DEBUG_BREAK; } }
#else
    #define EG_ASSERT(x, ...)
    #define EG_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define EG_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

#endif //EUGINE_CORE_H