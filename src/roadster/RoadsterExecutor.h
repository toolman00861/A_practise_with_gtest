//
// Created by Q on 2024/12/17.
//

#ifndef ROADSTEREXECUTOR_H
#define ROADSTEREXECUTOR_H
#include "../Executor.hpp"
#include "PoseHandler.h"

namespace roadster {
    class RoadsterExecutor : public adas::Executor {
        PoseHandler *poseHandler;
    public:
        RoadsterExecutor(const RoadsterExecutor &) = delete;
        RoadsterExecutor(const adas::Pose &pose = {0, 0, 'N'}) noexcept;
        ~RoadsterExecutor() override = default;
        static RoadsterExecutor *NewExecutor(const adas::Pose &pose = {0, 0, 'N'});

        void Execute(const std::string &command);
        adas::Pose Query();
    };
}

#endif //ROADSTEREXECUTOR_H
