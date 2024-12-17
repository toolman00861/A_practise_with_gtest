#pragma once	//防止头文件被多次包含，简化代码，避免重复定义和编译错误
#include <string>
#include "core/Pose.h"

namespace adas //  namespace：组织代码并防止命名冲突，使代码更易于管理和阅读
{
     class Executor //抽象类，提供接口定义，隐藏功能实现细节
     {
     public:
         // Caller should delete *executor when it is no longer needed.
         //静态成员函数，无需实例化即可调用，工厂方法模式
         static Executor *NewExecutor(const Pose &pose = {0, 0, 'N'}) noexcept;

         Executor() = default; //=default简化代码，明确表示使用编译器生成的默认实现
         virtual ~Executor() = default;

         Executor(const Executor &) = delete; //=delete防止对象的拷贝
         Executor &operator=(const Executor &) = delete;

         virtual void Execute(const std::string &command) = 0;
         virtual Pose Query() = 0;
     };
}
