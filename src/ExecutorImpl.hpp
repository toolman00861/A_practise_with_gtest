//
// Created by Q on 2024/12/14.
//

#ifndef EXECUTORIMPL_H
#define EXECUTORIMPL_H
#include "Executor.hpp"
#include "core/Pose.h"
#include "core/PoseHandler.h"

namespace adas {
    class ExecutorImpl : public Executor{
    private:
        PoseHandler *poseHandler;
    public:
        static ExecutorImpl *NewExecutor(const Pose &pose = {0, 0, 'N'},bool is_boost = false);
        ExecutorImpl(const Pose& pose);
        ~ExecutorImpl() override = default;

        Pose Query() override;
        void Execute(const std::string &command) override;
        bool getBoost();
    };

}


#endif //EXECUTORIMPL_H
