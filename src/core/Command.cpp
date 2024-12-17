//
// Created by Q on 2024/12/16.
//

#include "Command.h"

namespace adas {
    void BoostCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        poseHandler.setBoost();
    }

    void BackCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        poseHandler.setBack();  // 设置是否后退
    }

    void MoveCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.isBack()) {
            if (poseHandler.getBoost()) {
                poseHandler.Back();
            }
            poseHandler.Back();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
            }
            poseHandler.Move();
        }
    }

    void TurnLeftCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.isBack()) {
            if (poseHandler.getBoost()) {
                poseHandler.Back();
            }
            poseHandler.TurnRight();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
        }
    }

    void TurnRightCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.isBack()) {
            if (poseHandler.getBoost()) {
                poseHandler.Back();
            }
            poseHandler.TurnLeft();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
        }
    }
}
