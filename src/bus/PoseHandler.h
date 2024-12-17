//
// Created by Q on 2024/12/16.
//

#ifndef POSEHANDLER_H
#define POSEHANDLER_H
#include "../core/Pose.h"

namespace bus {
    class PoseHandler final{
    public:
        PoseHandler(const adas::Pose &pose) noexcept;
        PoseHandler(const PoseHandler &) = delete;
        PoseHandler &operator=(const PoseHandler &) = delete;


        void Move() noexcept;
        void Back() noexcept;
        void TurnLeft() noexcept;
        void TurnRight() noexcept;

        adas::Pose Query() noexcept;
        bool getBoost() const noexcept;
        void setBoost() noexcept;
        bool isBack() noexcept; // 获取是否倒车
        void setBack() noexcept; // 设置是否倒车 取反

    private:
        adas::Pose _pose;
        bool _is_boost{false};
        bool _is_back{false};
    };
}



#endif //POSEHANDLER_H
