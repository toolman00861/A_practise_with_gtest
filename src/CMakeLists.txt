cmake_minimum_required(VERSION 3.28)
project(src)

set(EXECUTOR_SOURCE ExecutorImpl.cpp
        core/Pose.cpp
        core/Pose.h
        core/Command.cpp
        core/Command.h
        core/PoseHandler.cpp
        core/PoseHandler.h
        roadster/RoadsterExecutor.cpp
        roadster/RoadsterExecutor.h
        roadster/Command.h
        roadster/Command.cpp
        roadster/PoseHandler.cpp
        bus/BusExecutor.cpp
        bus/Command.cpp
        bus/PoseHandler.cpp
)

add_library(ExecutorLib SHARED ${EXECUTOR_SOURCE})

if (CMAKE_SYSTEM_NAME MATCHES "Windows")
    set(LIBRARY_OUTPUT_PATH ${BIN_ROOT})
endif ()



