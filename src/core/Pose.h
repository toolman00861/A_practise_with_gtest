//
// Created by Q on 2024/12/16.
//

#ifndef POSE_H
#define POSE_H
namespace adas {
    struct Pose {
        //在计算和计算机视觉领域，pose (或 spatial pose) 表示物体的位置和方向
        int x;
        int y;
        char heading;

        bool operator==(const Pose &pose) const noexcept;
    };
}
#endif //POSE_H
