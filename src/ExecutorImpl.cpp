//
// Created by Q on 2024/12/14.

#include "ExecutorImpl.hpp"

#include <memory>
#include <unordered_map>

#include "core/Command.h"

namespace adas {

    ExecutorImpl* ExecutorImpl::NewExecutor(const Pose& pose, bool is_boost) {
        ExecutorImpl *executor = new ExecutorImpl(pose);
        return executor;
    }

    ExecutorImpl::ExecutorImpl(const Pose& pose) {
        poseHandler = new PoseHandler(pose);
    }

    void ExecutorImpl::Execute(const std::string& command) {
        std::pmr::unordered_map<char, CommandInterface*> command_map;
        command_map['M'] = new MoveCommand();
        command_map['L'] = new TurnLeftCommand();
        command_map['R'] = new TurnRightCommand();
        command_map['F'] = new BoostCommand();
        command_map['B'] = new BackCommand();
        for (auto& c : command) {
            const auto it = command_map.find(c);
            if (it != command_map.end()) {
                command_map[c]->DoOperate(*poseHandler);
            }
        }
    }

    Pose ExecutorImpl::Query() {
        return poseHandler->Query();
    }

    bool ExecutorImpl::getBoost() {
        return poseHandler->getBoost();
    }

}
