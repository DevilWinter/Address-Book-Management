#pragma once
#include <iostream>
#include <string>

namespace {
    const std::string helpInfo[9] = {
    "*******************************",
    "*****    1. �����ϵ��    *****",
    "*****    2. ��ʾ��ϵ��    *****",
    "*****    3. ɾ����ϵ��    *****",
    "*****    4. ������ϵ��    *****",
    "*****    5. �޸���ϵ��    *****",
    "*****    6. �����ϵ��    *****",
    "*****    0. �˳�ͨѶ¼    *****",
    "*******************************"
    };
};

// ��ʾ�����˵�
void ShowHelpMenu()
{
    for (auto item : helpInfo)
    {
        std::cout << item << std::endl;
    }
}

// У�������Ƿ�Ϸ�
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
            int excutedNumber = 0; // �����û��������ָ��
            std::cout << "���������Ĳ���ָ�";
            std::cin >> excutedNumber;
            if (!std::cin.fail())
            {
                excutedNumber = CheckCommand(excutedNumber) ? 20 : 30;
            }
            // ��շǷ����뻺��
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
    //int excutedNumber = 0; // �����û��������ָ��
    //while (true)
    //{
    //    std::cout << "���������Ĳ���ָ�";
    //    std::cin >> excutedNumber;
    //    if (std::cin.fail())
    //    {
    //        std::cout << "����Ƿ������������룡" << std::endl;
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
    //        std::cout << "�޶�Ӧָ�����������!" << std::endl;
    //        continue;
    //    }

    //}
    return 0;
}