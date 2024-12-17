//
// Created by Q on 2024/12/17.
//

#ifndef BUSEXECUTOR_H
#define BUSEXECUTOR_H
#include "../Executor.hpp"
#include "PoseHandler.h"


namespace bus {
    class BusExecutor : public adas::Executor{
        PoseHandler *poseHandler;
    public:
        void Execute(const std::string &command) override ;
        adas::Pose Query() override ;
        static BusExecutor *NewExecutor(const adas::Pose &pose = {0, 0, 'N'}) noexcept;
        BusExecutor(const adas::Pose &pose) noexcept;
        ~BusExecutor() override = default;
        BusExecutor(const BusExecutor &) = delete;
    };
}

#endif //BUSEXECUTOR_H
