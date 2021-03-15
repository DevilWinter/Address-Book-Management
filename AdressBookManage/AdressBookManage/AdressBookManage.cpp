#pragma once
#include <iostream>
#include <string>

namespace {
    const std::string helpInfo[10] = {
    "*******************************",
    "*****    1. �����ϵ��    *****",
    "*****    2. ��ʾ��ϵ��    *****",
    "*****    3. ɾ����ϵ��    *****",
    "*****    4. ������ϵ��    *****",
    "*****    5. �޸���ϵ��    *****",
    "*****    6. �����ϵ��    *****",
    "*****    7. �������̨    *****",
    "*****    0. �˳�ͨѶ¼    *****",
    "*******************************"
    };
    bool checkClear = true;     // ����Ƿ�ִ������ָ��
    const int PERSON_SAVE_MAX = (1000); //ͨѶ¼�洢������
    struct Person
    {
        std::string name{ "" };     // ����
        int sex;                    // �Ա�
        int age;                    // ����
        std::string phone{ "" };    // �绰
        std::string addr{ "" };     // סַ
    };
    struct AddressBooks
    {
        Person personArray[PERSON_SAVE_MAX]; // ͨѶ¼�洢��ϵ������
        int number{ 0 };                     // ͨѶ¼�г�Ա����
    };
};

// ��ʾ�����˵�
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

// У�������Ƿ�Ϸ�
bool CheckCommand(const int& commond)
{
    if (commond >= 0 && commond <= 7)
    {
        return true;
    }
    std::cout << "������\"0-6\"�Ĳ���ָ��" << std::endl;
    return false;
}

// �����ϵ��
void AddPerson(AddressBooks* abs)
{
    if (abs->number > PERSON_SAVE_MAX)
    {
        std::cout << "ͨѶ¼�洢�ռ䲻�㣬�����������ӣ�" << std::endl;
        return;
    }
    std::string tempName{""};
    std::cout << "������������ " << std::endl;
    std::cin >> tempName;
    abs->personArray[abs->number].name = tempName;

    std::cout << "�������Ա�" << std::endl;
    std::cout << "1 --- ��" << std::endl;
    std::cout << "2 --- Ů" << std::endl;
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
            std::cout << "�Ա������������������!" << std::endl;
        }
    }

    std::cout << "���������䣺" << std::endl;
    int tempAge = 0;
    while (true)
    {
        std::cin >> tempAge;
        if (std::cin.fail())
        {
            char buff;
            while ((buff = getchar()) != '\n');
            std::cout << "���������������������!" << std::endl;
        }
        else
        {
            abs->personArray[abs->number].age = tempAge;
            break;
        }
    }

    std::cout << "������绰��" << std::endl;
    std::string tempPhone{ "" };
    std::cin >> tempPhone;
    abs->personArray[abs->number].phone = tempPhone;

    std::cout << "������סַ��" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[abs->number].addr = tempAdress;

    abs->number++;
    std::cout << "���\"" << tempName << "\"�ɹ�" << std::endl;
}

bool ExcuteCommand(const int& command, AddressBooks* abs)
{
    bool rel = true;
    do 
    {
        switch (command)
        {
        case 0:             // �˳�����
        {
            rel = false;
            break;
        }
        case 1:             // �����ϵ��
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
    int excute = 10;    // ִ�в���
    int command = 0;    // �����û��������ָ��
    // ����ͨѶ¼�ṹ�����
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
            std::cout << "���������Ĳ���ָ�";
            std::cin >> command;
            if (std::cin.fail())
            {
                // ��շǷ����뻺��
                char buffer;
                while ((buffer = getchar()) != '\n');
                std::cout << "�Ƿ�ָ�����" << std::endl;
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
    std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
    system("pause");
    return 0;
}