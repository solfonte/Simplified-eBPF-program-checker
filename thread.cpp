#include "thread.h"
#include <iostream>
#include <utility>
#include <string>

void Thread::start() {
    this->thread = std::thread(&Thread::run, this);
}

void Thread::join() {
    this->thread.join();
}
