#pragma once
#include <iostream>
#include <string>
#include <sstream>

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

// ��鵱ǰ�û����Ƿ����
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
    // ����ظ�����
    if (CheckReName(abs, tempName) != -1)
    {
        std::cout << "��ǰ�û����Ѵ��ڣ����������룡" << std::endl;
        return;
    }
    abs->personArray[abs->number].name = tempName;
    std::getline(std::cin, tempName);

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
    std::getline(std::cin, tempPhone);

    std::cout << "������סַ��" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[abs->number].addr = tempAdress;
    std::getline(std::cin, tempAdress);

    std::cout << "���\"" << abs->personArray[abs->number].name << "\"�ɹ�" << std::endl;
    abs->number++;
}



// ��ʾ������ϵ��
void ShowAllPerson(AddressBooks* abs)
{
    if (abs->number <= 0)
    {
        std::cout << "��ǰͨѶ¼Ϊ�գ�" << std::endl;
        return;
    }
    for (int i = 0; i < abs->number; i++)
    {
        std::cout << "������" << abs->personArray[i].name << "\t";
        std::cout << "�Ա�" << (abs->personArray[i].sex == 1 ? "��": "Ů") << "\t";
        std::cout << "���䣺" << abs->personArray[i].age << "\t";
        std::cout << "�绰��" << abs->personArray[i].phone << "\t";
        std::cout << "סַ��" << abs->personArray[i].addr << std::endl;
    }
}

// ɾ����ϵ��
void DeletePerson(AddressBooks* abs)
{
    std::string name = "";
    std::cout << "��������Ҫɾ������ϵ��������" << std::endl;
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
        std::cout << "ɾ��\"" << name << "\"�ɹ���" << std::endl;
    }
}

// ������ϵ��
void FindPerson(AddressBooks* abs)
{
    std::cout << "��������Ҫ���ҵ����ƣ�" << std::endl;
    std::string name;
    std::cin >> name;
    int rel = CheckReName(abs, name);
    if (rel == -1)
    {
        std::cout << "ͨѶ¼���޸���ϵ�ˣ�" << std::endl;
        return;
    }
    std::cout << "������" << abs->personArray[rel].name << "\t";
    std::cout << "�Ա�" << (abs->personArray[rel].sex == 1 ? "��" : "Ů") << "\t";
    std::cout << "���䣺" << abs->personArray[rel].age << "\t";
    std::cout << "�绰��" << abs->personArray[rel].phone << "\t";
    std::cout << "סַ��" << abs->personArray[rel].addr << std::endl;

}

// �޸���ϵ��
void ChangePerson(AddressBooks* abs)
{
    std::string tempName{ "" };
    std::cout << "������Ҫ�޸ĵ���ϵ�������� " << std::endl;
    std::cin >> tempName;
    // ����ظ�����
    int count = CheckReName(abs, tempName);
    if (count == -1)
    {
        std::cout << "��ǰ�û��������ڣ����������룡" << std::endl;
        return;
    }
    abs->personArray[count].name = tempName;
    std::getline(std::cin, tempName);

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
            abs->personArray[count].sex = tempSex;
            break;
        }
        else
        {
            std::cout << "�Ա������������������!" << std::endl;
        }
    }

    std::cout << "���������䣺" << std::endl;
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
            std::cout << "���������������������!" << std::endl;
        }
        else
        {
            abs->personArray[count].age = tempAge;
            break;
        }
    }

    std::cout << "������绰��" << std::endl;
    std::string tempPhone{ "" };
    std::cin >> tempPhone;
    abs->personArray[count].phone = tempPhone;
    std::getline(std::cin, tempPhone);

    std::cout << "������סַ��" << std::endl;
    std::string tempAdress{ "" };
    std::cin >> tempAdress;
    abs->personArray[count].addr = tempAdress;
    std::getline(std::cin, tempAdress);

    std::cout << "�޸�\"" << abs->personArray[count].name << "\"�ɹ�" << std::endl;
}

// ���ͨѶ¼
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
        case 2:             // ��ʾ��ϵ��
        {
            ShowAllPerson(abs);
            break;
        }
        case 3:             // ɾ����ϵ��
        {
            DeletePerson(abs);
            break;
        }
        case 4:             // ������ϵ��
        {
            FindPerson(abs);
            break;
        }
        case 5:             // �޸���ϵ��
        {
            ChangePerson(abs);
            break;
        }
        case 6:             // �����ϵ��
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