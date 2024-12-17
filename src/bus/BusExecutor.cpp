//
// Created by Q on 2024/12/17.
//

#include "BusExecutor.h"
#include "PoseHandler.h"
#include <unordered_map>
#include "Command.h"

namespace bus {
    BusExecutor *BusExecutor::NewExecutor(const adas::Pose &pose) noexcept{
        return new BusExecutor(pose);
    }

    BusExecutor::BusExecutor(const adas::Pose &pose) noexcept {
        poseHandler = new PoseHandler(pose);
    }

    void BusExecutor::Execute(const std::string &command) {
        std::pmr::unordered_map<char, CommandInterface *> command_map;
        command_map['M'] = new MoveCommand();
        command_map['L'] = new TurnLeftCommand();
        command_map['R'] = new TurnRightCommand();
        command_map['F'] = new BoostCommand();
        command_map['B'] = new BackCommand();
        for (auto &c: command) {
            const auto it = command_map.find(c);
            if (it != command_map.end()) {
                command_map[c]->DoOperate(*poseHandler);
            }
        }
    }

    adas::Pose BusExecutor::Query() {
        return poseHandler->Query();
    }
}
