#include <iostream>
#include "ExecutorImpl.hpp"
// #include "gtest/gtest.h"

int main()
{
    std::cout << "Hello!" << std::endl;
    adas::ExecutorImpl *executor = adas::ExecutorImpl::NewExecutor();
    executor->Execute("FBMMMLLRRMM");
    std::cout << "Current pose: ";
    adas::Pose pose = executor->Query();
    std::cout << pose.x << " " << pose.y << " " << pose.heading << std::endl;
    return 0;
}

