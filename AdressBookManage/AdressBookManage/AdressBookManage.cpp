#pragma once
#include <iostream>
#include <string>

namespace {
    const std::string helpInfo[10] = {
    "*******************************",
    "*****    1. 添加联系人    *****",
    "*****    2. 显示联系人    *****",
    "*****    3. 删除联系人    *****",
    "*****    4. 查找联系人    *****",
    "*****    5. 修改联系人    *****",
    "*****    6. 清空联系人    *****",
    "*****    7. 清除控制台    *****",
    "*****    0. 退出通讯录    *****",
    "*******************************"
    };
    bool checkClear = true;     // 检查是否执行清屏指令
    const int PERSON_SAVE_MAX = (1000); //通讯录存储最大个数
    struct Person
    {
        std::string name{ "" };     // 姓名
        int sex;                    // 性别
        int age;                    // 年龄
        std::string phone{ "" };    // 电话
        std::string addr{ "" };     // 住址
    };
    struct AddressBooks
    {
        Person personArray[PERSON_SAVE_MAX]; // 通讯录存储联系人数组
        int number{ 0 };                     // 通讯录中成员个数
    };
};

// 显示帮助菜单
void ShowHelpMenu()
{
    if (false == checkClear)
    {
        return;
    }
    checkClear = false;
    for (auto item : helpInfo)
    {
        std::cout << item << std::endl;
    }
}

// 校验输入是否合法
bool CheckCommand(const int& commond)
{
    if (commond >= 0 && commond <= 7)
    {
        return true;
    }
    std::cout << "请输入\"0-6\"的操作指令" << std::endl;
    return false;
}

// 添加联系人
void AddPerson(AddressBooks* abs)
{
    if (abs->number > PERSON_SAVE_MAX)
    {
        std::cout << "通讯录存储空间不足，请清理后再添加！" << std::endl;
        return;
    }
    std::string tempName{""};
    std::cout << "请输入姓名： " << std::endl;
    std::cin >> tempName;
    abs->personArray[abs->number].name = tempName;

    std::cout << "请输入性别：" << std::endl;
    std::cout << "1 --- 男" << std::endl;
    std::cout << "2 --- 女" << std::endl;
    int tempSex = 0;
    while (true)
    {
        std::cin >> tempSex;
        if (std::cin.fail())
        {
            char buffer;
            while ((buffer = getchar()) != '\n');
        }
        if (tempSex == 1 || tempSex == 2)
        {
            abs->personArray[abs->number].sex = tempSex;
            break;
        }
        else
        {
            std::cout << "性别输入错误，请重新输入!" << std::endl;
        }
    }

    std::cout << "请输入年龄：" << std::endl;
    int tempAge = 0;
    while (true)
    {
        std::cin >> tempAge;
        if (std::cin.fail())
        {
            char buff;
            while ((buff = getchar()) != '\n');
            std::cout << "年龄输入错误，请重新输入!" << std::endl;
        }
        else
        {
            abs->personArray[abs->number].age = tempAge;
            break;
        }
    }

    std::cout << "请输入电话：" << std::endl;
    std::string tempPhone{ "" };
    std::cin >> tempPhone;
    abs->personArray[abs->number].phone = tempPhone;

    std::cout << "请输入住址：" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[abs->number].addr = tempAdress;

    abs->number++;
    std::cout << "添加\"" << tempName << "\"成功" << std::endl;
}

bool ExcuteCommand(const int& command, AddressBooks* abs)
{
    bool rel = true;
    do 
    {
        switch (command)
        {
        case 0:             // 退出程序
        {
            rel = false;
            break;
        }
        case 1:             // 添加联系人
        {
            AddPerson(abs);
            break;
        }
        case 7:
        {
            system("cls");
            checkClear = true;
            break;
        }
        default:
            break;
        }
    } while (false);
    return rel;
}

int main()
{
    int excute = 10;    // 执行步骤
    int command = 0;    // 接收用户输入操作指令
    // 创建通讯录结构体变量
    AddressBooks addressAra;
    
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
            std::cout << "请输入您的操作指令：";
            std::cin >> command;
            if (std::cin.fail())
            {
                // 清空非法输入缓存
                char buffer;
                while ((buffer = getchar()) != '\n');
                std::cout << "非法指令！！！" << std::endl;
            }
            else
            {
                excute = CheckCommand(command) ? 30 : 20;
            }
            break;
        }
        case 30:
        {
            excute = ExcuteCommand(command, &addressAra) ? 10 : 999;
            break;
        }
        default:
        {
            excute = 999;
            break;
        }
        }
    
    } while (excute != 999);
    std::cout << "欢迎下次使用！" << std::endl;
    system("pause");
    return 0;
}