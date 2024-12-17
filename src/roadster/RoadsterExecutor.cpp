#include "RoadsterExecutor.h"
#include "Command.h"
#include <unordered_map>

namespace roadster {
    RoadsterExecutor *RoadsterExecutor::NewExecutor(const adas::Pose &pose) {
        return new RoadsterExecutor(pose);
    }

    RoadsterExecutor::RoadsterExecutor(const adas::Pose &pose) noexcept {
        poseHandler = new PoseHandler(pose);
    }

    void RoadsterExecutor::Execute(const std::string &command) {
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

    adas::Pose RoadsterExecutor::Query() {
        return poseHandler->Query();
    }
}
