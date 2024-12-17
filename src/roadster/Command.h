//
// Created by Q on 2024/12/16.
//

#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H
#include "PoseHandler.h"


namespace roadster {
    class CommandInterface {
    public:
        virtual ~CommandInterface() = default;
        virtual void DoOperate(PoseHandler &poseHandler)const noexcept = 0;
    };
    class MoveCommand final: public CommandInterface {
    public:
        void DoOperate(PoseHandler &poseHandler)const noexcept override;
    };
    class TurnLeftCommand final: public CommandInterface {
    public:
        void DoOperate(PoseHandler &poseHandler)const noexcept override;
    };
    class TurnRightCommand final: public CommandInterface {
    public:
        void DoOperate(PoseHandler &poseHandler)const noexcept override;
    };
    class BoostCommand final: public CommandInterface {
    public:
        void DoOperate(PoseHandler &poseHandler)const noexcept override;
    };
    class BackCommand final: public CommandInterface {
    public:
        void DoOperate(PoseHandler &poseHandler)const noexcept override;
    };
}


#endif //COMMANDINTERFACE_H
