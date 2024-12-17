//
// Created by Q on 2024/12/16.
//
//
// Created by Q on 2024/12/14.
//

#include "gtest/gtest.h"
#include <memory>
#include <tuple>
#include "ExecutorImpl.hpp"

namespace adas {
    // 用pose初始化
    TEST(ExecutorTest, should_return_init_pose_when_without_command) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // 不用pose初始化
    TEST(ExecutorTest, should_return_default_pose_when_without_init_and_command) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor());
        // when
        const Pose target({0, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向东前进
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向北前进
    TEST(ExecutorTest, should_return_y_plus_1_given_command_is_M_and_facing_is_N) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({0, 1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向西前进
    TEST(ExecutorTest, should_return_x_minus_1_given_command_is_M_and_facing_is_W) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'W'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({-1, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向南前进
    TEST(ExecutorTest, should_return_y_minus_1_given_command_is_M_and_facing_is_S) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'S'}));
        // when
        executor->Execute("M");
        // then
        const Pose target({0, -1, 'S'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向左转
    TEST(ExecutorTest, should_return_facing_is_W_given_command_is_L_and_facing_is_N) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        // when
        executor->Execute("L");
        // then
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试向右转
    TEST(ExecutorTest, should_return_facing_is_S_given_command_is_R_and_facing_is_E) {
        // given
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        // when
        executor->Execute("R");
        // then
        const Pose target({0, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
   }
    // 新测试集 测试是否可以转换加速状态，通过F判断：
    TEST(ExecutorTestBoost, should_return_boost_true_given_command_is_F) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor());
        executor->Execute("F");
        ASSERT_TRUE(executor->getBoost());
    }

    //  测试是否可以还原加速状态，通过当加速状态时再执行F判断：
    TEST(ExecutorTestBoost, should_return_boost_false_given_command_is_F) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor());
        executor->Execute("F");
        ASSERT_TRUE(executor->getBoost());
    }

    // 测试是否可以正确的根据加速状态来移动：
    TEST(ExecutorTestBoost, should_return_x_plus_2_given_command_is_FM_and_facing_is_E) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        executor->Execute("FM");
        const Pose target({2, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试是否可以根据加速状态左转
    TEST(ExecutorTestBoost, should_return_facing_is_N_and_x_plus_1_given_command_is_FL_and_facing_is_E) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        executor->Execute("FL");
        const Pose target({1, 0, 'N'});
        ASSERT_EQ(target, executor->Query());
    }
    // 测试是否可以根据加速状态右转
    TEST(ExecutorTestBoost, should_return_facing_is_S_and_x_minus_1_given_command_is_FR_and_facing_is_E) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        executor->Execute("FR");
        const Pose target({1, 0, 'S'});
        ASSERT_EQ(target, executor->Query());
    }

    // 测试Back 和 boost
    TEST(ExecutorTestBack, should_return_y_minus_1_given_command_is_BM) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BM");
        const Pose target({0, -1, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_y_minus_2_given_command_is_BFM) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BFM");
        const Pose target({0, -2, 'N'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_heading_E_given_command_is_BL) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BL");
        const Pose target({0, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_heading_W_given_command_is_BR) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BR");
        const Pose target({0, 0, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_heading_E_and_y_minus_1_given_command_is_BFL) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BFL");
        const Pose target({0, -1, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_heading_W_and_y_minus_1_given_command_is_BFR) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'N'}));
        executor->Execute("BFR");
        const Pose target({0, -1, 'W'});
        ASSERT_EQ(target, executor->Query());
    }

    TEST(ExecutorTestBack, should_return_x_plus_1_given_command_is_BBM) {
        std::unique_ptr<ExecutorImpl> executor(ExecutorImpl::NewExecutor({0, 0, 'E'}));
        executor->Execute("BBM");
        const Pose target({1, 0, 'E'});
        ASSERT_EQ(target, executor->Query());
    }

} // namespace adas
