// namespace adas
//
// Created by Q on 2024/12/17.
//

#include "gtest/gtest.h"
#include <memory>
#include "roadster/RoadsterExecutor.h"

namespace roadster {

    // 测试正常模式下前进2格
    TEST(ExecutorTestNormal, should_return_x_plus_2_given_command_is_M_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("M");
        const adas::Pose target({2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试正常模式下左转90度并前进1格
    TEST(ExecutorTestNormal, should_return_heading_W_and_x_minus_1_given_command_is_L_and_facing_is_N) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'N'}));
        executor->Execute("L");
        const adas::Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试正常模式下右转90度并前进1格
    TEST(ExecutorTestNormal, should_return_heading_S_and_y_minus_1_given_command_is_R_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("R");
        const adas::Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试后退模式下前进2格
    TEST(ExecutorTestBack, should_return_x_minus_2_given_command_is_BM_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("BM");
        const adas::Pose target({-2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试后退模式下左转90度并后退1格
    TEST(ExecutorTestBack, should_return_heading_S_and_y_plus_1_given_command_is_BR_and_facing_is_W) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'W'}));
        executor->Execute("BR");
        const adas::Pose target({0, 1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试加速模式下前进4格
    TEST(ExecutorTestFast, should_return_x_plus_4_given_command_is_FM_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FM");
        const adas::Pose target({4, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试加速模式下左转90度并前进1格
    TEST(ExecutorTestFast, should_return_heading_N_and_y_plus_1_given_command_is_FL_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FL");
        const adas::Pose target({1, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试加速模式下右转90度并前进1格
    TEST(ExecutorTestFast, should_return_heading_S_and_x_minus_1_given_command_is_FR_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("FR");
        const adas::Pose target({1, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试后退加速模式下后退4格
    TEST(ExecutorTestBackFast, should_return_x_minus_4_given_command_is_BFM_and_facing_is_E) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'E'}));
        executor->Execute("BFM");
        const adas::Pose target({-4, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试后退加速模式下左转90度并后退1格
    TEST(ExecutorTestBackFast, should_return_heading_W_and_x_plus_1_y_minus_1_given_command_is_FBL_and_facing_is_N) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'N'}));
        executor->Execute("FBL");
        const adas::Pose target({-1, -1, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试后退加速模式下右转90度并后退1格
    TEST(ExecutorTestBackFast, should_return_heading_S_and_x_plus_1_y_plus_1_given_command_is_FBR_and_facing_is_W) {
        std::unique_ptr<RoadsterExecutor> executor(RoadsterExecutor::NewExecutor({0, 0, 'W'}));
        executor->Execute("FBR");
        const adas::Pose target({1, 1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

}
