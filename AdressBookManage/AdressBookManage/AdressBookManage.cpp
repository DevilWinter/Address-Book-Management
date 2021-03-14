#pragma once
#include <iostream>
#include <string>

namespace {
    const std::string helpInfo[9] = {
    "*******************************",
    "*****    1. 添加联系人    *****",
    "*****    2. 显示联系人    *****",
    "*****    3. 删除联系人    *****",
    "*****    4. 查找联系人    *****",
    "*****    5. 修改联系人    *****",
    "*****    6. 清空联系人    *****",
    "*****    0. 退出通讯录    *****",
    "*******************************"
    };
};

// 显示帮助菜单
void ShowHelpMenu()
{
    for (auto item : helpInfo)
    {
        std::cout << item << std::endl;
    }
}

// 校验输入是否合法
bool CheckCommand(const int& commond)
{
    if (commond >= 0 && commond < 7)
    {
        return true;
    }
    return false;
}

int main()
{
    int excute = 10;
    do {
        switch (excute)
        {
        case 10:
        {
            ShowHelpMenu();
            excute = 20;
            break;
        }
        case 20:
        {
            int excutedNumber = 0; // 接收用户输入操作指令
            std::cout << "请输入您的操作指令：";
            std::cin >> excutedNumber;
            if (!std::cin.fail())
            {
                excutedNumber = CheckCommand(excutedNumber) ? 20 : 30;
            }
            // 清空非法输入缓存
            char c;
            while ((c = getchar()) != '\n');
            break;
        }
        default:
        {
            excute = 999;
            break;
        }
        }
    
    } while (excute != 999);


    //ShowHelpMenu();
    //int excutedNumber = 0; // 接收用户输入操作指令
    //while (true)
    //{
    //    std::cout << "请输入您的操作指令：";
    //    std::cin >> excutedNumber;
    //    if (std::cin.fail())
    //    {
    //        std::cout << "输入非法，请重新输入！" << std::endl;
    //        std::cin.sync();
    //        std::cin.clear();
    //        std::cin.sync();
    //        std::cin.ignore();
    //        excutedNumber = 0;
    //        continue;
    //    }
    //    switch (excutedNumber)
    //    {
    //    case 0:
    //    {

    //        break;
    //    }
    //    default:
    //        std::cout << "无对应指令，请重新输入!" << std::endl;
    //        continue;
    //    }

    //}
    return 0;
}