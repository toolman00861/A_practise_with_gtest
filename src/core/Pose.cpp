//
// Created by Q on 2024/12/16.
//

#include "Pose.h"
namespace adas {
    bool Pose::operator==(const Pose &pose) const noexcept {
        return x == pose.x && y == pose.y && heading == pose.heading;
    }

}