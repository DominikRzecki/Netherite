//
// Created by dominik on 2/24/21.
//

#ifndef NETHERITE_THREAD_H
#define NETHERITE_THREAD_H

#include <thread>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <type_traits>

#include "../module/Module.h"

namespace Netherite {
    class Thread {
    public:
        Thread( const Thread& ) = delete;

        template<typename Callable, typename... Args>
        explicit Thread(Callable &&function, Args&& ...args)
                :_thread( &Thread::executor<Callable,  Args...>, this, function, args...)
        {
            _thread.detach();
        }

        ~Thread() {
            terminate();
        }

        void terminate() {
            disable();
            if ( _thread.joinable() ) {
                _thread.join();
            }
        }

        inline void disable() {
            if (_enabled) {
                toggle();
            }
        }

        inline void enable() {
            if (!_enabled) {
                toggle();
            }
        }

        void toggle() {
            {
                std::lock_guard<decltype(_mtx)> lock(_mtx);
                _enabled = !_enabled;
            }
            _cv.notify_one();
        }

        inline bool enabled() {
            return _enabled;
        }

        inline std::thread& std_thread() {
            return _thread;
        }

        inline const Module &get_owner() const {
            return _owner;
        }

        inline void set_owner(const Module &owner) {
            _owner = owner;
        }

    private:

        template<typename Callable, typename... Args>
        inline void executor(Callable &&callable, Args &&...args) {
            constexpr bool a = std::is_invocable<Callable, Args...>::value;
            static_assert( std::is_invocable<Callable, Args...>::value, "not invokable" );
            while ( _enabled ) {
                std::unique_lock<decltype(_mtx)> lock(_mtx);
                _cv.wait(lock, [&] { return this->enabled(); }); //return _enabled
                std::invoke(callable, args...);
            }
        }

    private:

        std::thread _thread;
        std::atomic<bool> _enabled {true};
        std::condition_variable _cv;
        std::mutex _mtx;
    };
}
    using NThread = Netherite::Thread/*<Callable, Args...>*/;

#endif //NETHERITE_THREAD_H