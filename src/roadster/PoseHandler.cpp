//
// Created by Q on 2024/12/16.
//

#include "PoseHandler.h"
#include "../core/Pose.h"

namespace roadster {
    PoseHandler::PoseHandler(const adas::Pose &pose) noexcept {
        this->_pose = pose;
    }
    void PoseHandler::Back() noexcept {
        // 后退一格
        switch (_pose.heading) {
            case 'N':
                _pose.y -= 1;
            break;
            case 'E':
                _pose.x -= 1;
            break;
            case 'S':
                _pose.y += 1;
            break;
            case 'W':
                _pose.x += 1;
            break;
            default:
                break;
        }
    }
    void PoseHandler::Move() noexcept {
        // 移动一格
        switch (_pose.heading) {
            case 'N':
                _pose.y += 1;
            break;
            case 'E':
                _pose.x += 1;
            break;
            case 'S':
                _pose.y -= 1;
            break;
            case 'W':
                _pose.x -= 1;
            break;
            default:
                break;
        }
    }

    adas::Pose PoseHandler::Query() noexcept {
        return _pose;
    }
    void PoseHandler::TurnLeft() noexcept {
        switch (_pose.heading) {
            case 'N':
                _pose.heading = 'W';
            break;
            case 'E':
                _pose.heading = 'N';
            break;
            case 'S':
                _pose.heading = 'E';
            break;
            case 'W':
                _pose.heading = 'S';
            break;
            default:
                break;
        }
    }
    void PoseHandler::TurnRight() noexcept {
        switch (_pose.heading) {
            case 'N':
                _pose.heading = 'E';
            break;
            case 'E':
                _pose.heading = 'S';
            break;
            case 'S':
                _pose.heading = 'W';
            break;
            case 'W':
                _pose.heading = 'N';
            break;
            default:
                break;
        }
    }
    bool PoseHandler::getBoost() const noexcept {
        return _is_boost;
    }
    void PoseHandler::setBoost() noexcept {
        _is_boost = !_is_boost;
    }
    bool PoseHandler::isBack() noexcept {
        return _is_back;
    }
    void PoseHandler::setBack() noexcept {
        _is_back = !_is_back;
    }

}
