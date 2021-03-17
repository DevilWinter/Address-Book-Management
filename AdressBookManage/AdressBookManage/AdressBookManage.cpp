#pragma once
#include <iostream>
#include <string>
#include <sstream>

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
        void operator = (Person p)
        {
            name = p.name;
            sex = p.sex;
            age = p.age;
            phone = p.phone;
            addr = p.addr;
        }
        void clearInfo()
        {
            name = "";
            sex = 0;
            age = 0;
            phone= "";
            std::string addr = "";
        }
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

// 检查当前用户名是否存在
int CheckReName(AddressBooks* abs, const std::string& name)
{
    for (int i = 0; i < abs->number; i++)
    {
        if (abs->personArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
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
    // 检查重复名称
    if (CheckReName(abs, tempName) != -1)
    {
        std::cout << "当前用户名已存在，请重新输入！" << std::endl;
        return;
    }
    abs->personArray[abs->number].name = tempName;
    std::getline(std::cin, tempName);

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
    std::string cinAge("");
    std::stringstream sstream;
    int tempAge = 0;
    while (true)
    {
        std::cin >> cinAge;
        sstream << cinAge;
        sstream >> tempAge;
        sstream.clear();
        sstream.str("");
        if (tempAge <= 0)
        {
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
    std::getline(std::cin, tempPhone);

    std::cout << "请输入住址：" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[abs->number].addr = tempAdress;
    std::getline(std::cin, tempAdress);

    std::cout << "添加\"" << abs->personArray[abs->number].name << "\"成功" << std::endl;
    abs->number++;
}



// 显示所有联系人
void ShowAllPerson(AddressBooks* abs)
{
    if (abs->number <= 0)
    {
        std::cout << "当前通讯录为空！" << std::endl;
        return;
    }
    for (int i = 0; i < abs->number; i++)
    {
        std::cout << "姓名：" << abs->personArray[i].name << "\t";
        std::cout << "性别：" << (abs->personArray[i].sex == 1 ? "男": "女") << "\t";
        std::cout << "年龄：" << abs->personArray[i].age << "\t";
        std::cout << "电话：" << abs->personArray[i].phone << "\t";
        std::cout << "住址：" << abs->personArray[i].addr << std::endl;
    }
}

// 删除联系人
void DeletePerson(AddressBooks* abs)
{
    std::string name = "";
    std::cout << "请输入您要删除的联系人姓名！" << std::endl;
    std::cin >> name;

    int rel = CheckReName(abs, name);
    if (rel != -1)
    {
        name = abs->personArray[rel].name;
        for (int i = rel; i < abs->number - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->personArray[abs->number - 1].clearInfo();
        abs->number--;
        std::cout << "删除\"" << name << "\"成功！" << std::endl;
    }
}

// 查找联系人
void FindPerson(AddressBooks* abs)
{
    std::cout << "请输入您要查找的名称：" << std::endl;
    std::string name;
    std::cin >> name;
    int rel = CheckReName(abs, name);
    if (rel == -1)
    {
        std::cout << "通讯录中无该联系人！" << std::endl;
        return;
    }
    std::cout << "姓名：" << abs->personArray[rel].name << "\t";
    std::cout << "性别：" << (abs->personArray[rel].sex == 1 ? "男" : "女") << "\t";
    std::cout << "年龄：" << abs->personArray[rel].age << "\t";
    std::cout << "电话：" << abs->personArray[rel].phone << "\t";
    std::cout << "住址：" << abs->personArray[rel].addr << std::endl;

}

// 修改联系人
void ChangePerson(AddressBooks* abs)
{
    std::string tempName{ "" };
    std::cout << "请输入要修改的联系人姓名： " << std::endl;
    std::cin >> tempName;
    // 检查重复名称
    int count = CheckReName(abs, tempName);
    if (count == -1)
    {
        std::cout << "当前用户名不存在，请重新输入！" << std::endl;
        return;
    }
    abs->personArray[count].name = tempName;
    std::getline(std::cin, tempName);

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
            abs->personArray[count].sex = tempSex;
            break;
        }
        else
        {
            std::cout << "性别输入错误，请重新输入!" << std::endl;
        }
    }

    std::cout << "请输入年龄：" << std::endl;
    std::string cinAge("");
    std::stringstream sstream;
    int tempAge = 0;
    while (true)
    {
        std::cin >> cinAge;
        sstream << cinAge;
        sstream >> tempAge;
        sstream.clear();
        sstream.str("");
        if (tempAge <= 0)
        {
            std::cout << "年龄输入错误，请重新输入!" << std::endl;
        }
        else
        {
            abs->personArray[count].age = tempAge;
            break;
        }
    }

    std::cout << "请输入电话：" << std::endl;
    std::string tempPhone{ "" };
    std::cin >> tempPhone;
    abs->personArray[count].phone = tempPhone;
    std::getline(std::cin, tempPhone);

    std::cout << "请输入住址：" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[count].addr = tempAdress;
    std::getline(std::cin, tempAdress);

    std::cout << "修改\"" << abs->personArray[count].name << "\"成功" << std::endl;
}

// 清空通讯录
void ClearAddressBooks(AddressBooks* abs)
{
    for (int i = 0; i < abs->number; i++)
    {
        abs->personArray[i].clearInfo();
    }
    abs->number = 0;
}


bool ExcuteCommand(const int& command, AddressBooks* abs)
{
    bool rel = true;
    do 
    {
        if (abs == nullptr)
        {
            rel = false;
        }
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
        case 2:             // 显示联系人
        {
            ShowAllPerson(abs);
            break;
        }
        case 3:             // 删除联系人
        {
            DeletePerson(abs);
            break;
        }
        case 4:             // 查找联系人
        {
            FindPerson(abs);
            break;
        }
        case 5:             // 修改联系人
        {
            ChangePerson(abs);
            break;
        }
        case 6:             // 清空联系人
        {
            ClearAddressBooks(abs);
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