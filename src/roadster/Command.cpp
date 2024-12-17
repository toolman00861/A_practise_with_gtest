//
// Created by Q on 2024/12/16.
//

#include "Command.h"

namespace roadster {
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
                poseHandler.Back();
            }
            poseHandler.Back();
            poseHandler.Back();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
                poseHandler.Move();
            }
            poseHandler.Move();
            poseHandler.Move();
        }
    }

    void TurnLeftCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.isBack()) {
            if (poseHandler.getBoost()) {
                poseHandler.Back();
            }
            poseHandler.TurnRight();
            poseHandler.Back();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
            }
            poseHandler.TurnLeft();
            poseHandler.Move();
        }
    }

    void TurnRightCommand::DoOperate(PoseHandler &poseHandler) const noexcept {
        if (poseHandler.isBack()) {
            if (poseHandler.getBoost()) {
                poseHandler.Back();
            }
            poseHandler.TurnLeft();
            poseHandler.Back();
        } else {
            if (poseHandler.getBoost()) {
                poseHandler.Move();
            }
            poseHandler.TurnRight();
            poseHandler.Move();
        }
    }
}
