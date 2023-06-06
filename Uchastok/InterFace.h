#include <iostream>

class InterFace {

private:
    
    Container outputContainer;
    Container inputContainer;
    Container inputContainer1;
    Container finalContainer;

    void DisplayMenu() {
        std::cout << "����:" << std::endl;
        std::cout << "1. ��������� ���������" << std::endl;
        std::cout << "2. ��������� ������ ���������" << std::endl;
        std::cout << "3. ��������� ������ ���������" << std::endl;
        std::cout << "4. ���������� �����" << std::endl;
        std::cout << "5. ��������� ��������� ���������" << std::endl;
        std::cout << "6. �����" << std::endl;
    }

    int GetUserChoice() {
        int choice;
        std::cout << "������� ����� �������� ==> ";
        std::cin >> choice;
        return choice;
    }

    void StartProgram() {
        std::cout << "��������� ��������." << std::endl;
        finalContainer.removeRawMaterial();
        Conveyor conveyor1(&inputContainer, &outputContainer);
        Conveyor conveyor2(&inputContainer1, &outputContainer);
        Conveyor conveyor3(&outputContainer, &finalContainer);

        float grams, gram;

        std::cout << "����� �����: ";
        std::cin >> grams;
        while (grams <= 0) {
            std::cout << "���������� ��������� ���������� �����: ��������� ����\n";
            std::cout << "����� �����: ";
            std::cin >> grams;
            if (grams > 0) {
                break;
            }
        }
        while (grams > 4999999) {
            std::cout << "���������� ��������� �������� �����: ��������� ����� ����������\n";
            std::cout << "����� �����: ";
            std::cin >> grams;
            if (grams < 499999) {
                break;
            }
        }
        inputContainer.addRawMaterial(grams);
        conveyor1.transferRawMaterial();
        std::cout << "������� ��������� 1: " << inputContainer.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;

        std::cout << "����� �����: ";
        std::cin >> gram;
        while (gram <= 0) {
            std::cout << "���������� ��������� ���������� �����: ��������� ����\n";
            std::cout << "����� �����: ";
            std::cin >> gram;
            if (gram > 0) {
                break;
            }
        }
        while (gram > (5000000 - grams)) {
            std::cout << "���������� ��������� ���������� �����: ������� ��������� ����� ����������\n";
            std::cout << "����� �����: ";
            std::cin >> gram;
            if (gram < (5000000 - grams)) {
                break;
            }
        }
        inputContainer1.addRawMaterial(gram);
        conveyor2.transferRawMaterial();
        std::cout << "������� ��������� 2: " << inputContainer1.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;

        outputContainer.mixMaterials();

        conveyor3.transferMixedMaterial();
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << finalContainer.getCurrentWeight() << "�" << std::endl;
    }
    
    void cont1() {
        finalContainer.removeRawMaterial();
        Conveyor conveyor1(&inputContainer, &outputContainer);

        float grams;

        std::cout << "����� �����: ";
        std::cin >> grams;
        while (grams <= 0) {
            std::cout << "���������� ��������� ���������� �����: ��������� ����\n";
            std::cout << "����� �����: ";
            std::cin >> grams;
            if (grams > 0) {
                break;
            }
        }
        while (grams > 4999999) {
            std::cout << "���������� ��������� �������� �����: ��������� ����� ����������\n";
            std::cout << "����� �����: ";
            std::cin >> grams;
            if (grams < 499999) {
                break;
            }
        }
        inputContainer.addRawMaterial(grams);
        conveyor1.transferRawMaterial();
        std::cout << "������� ��������� 1: " << inputContainer.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;
    }
    
    void cont2() {
        Conveyor conveyor2(&inputContainer1, &outputContainer);

        float grams, gram;
        std::cout << "������� ����� ����� ������� ��������� 1: ";
        std::cin >> grams;

        std::cout << "����� �����: ";
        std::cin >> gram;
        while (gram <= 0) {
            std::cout << "���������� ��������� ���������� �����: ��������� ����\n";
            std::cout << "����� �����: ";
            std::cin >> gram;
            if (gram > 0) {
                break;
            }
        }
        while (gram > (5000000 - grams)) {
            std::cout << "���������� ��������� ���������� �����: ������� ��������� ����� ����������\n";
            std::cout << "����� �����: ";
            std::cin >> gram;
            if (gram < (5000000 - grams)) {
                break;
            }
        }
        inputContainer1.addRawMaterial(gram);
        conveyor2.transferRawMaterial();
        std::cout << "������� ��������� 2: " << inputContainer1.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;
    }
    
    void mixed() {
        outputContainer.mixMaterials();
    }

    void finalc() {
        Conveyor conveyor3(&outputContainer, &finalContainer);

        conveyor3.transferMixedMaterial();
        std::cout << "�������� ���������: " << outputContainer.getCurrentWeight() << "�" << std::endl;
        std::cout << "�������� ���������: " << finalContainer.getCurrentWeight() << "�" << std::endl;
    }

public:
    void Run() {
        while (true) {
            DisplayMenu();
            int choice = GetUserChoice();

            switch (choice) {
            case 1:
                StartProgram();
                break;
            case 2:
                cont1();
                break;
            case 3:
                cont2();
                break;
            case 4:
                mixed();
                break;
            case 5:
                finalc();
                break;
            case 6:
                std::cout << "����� �� ���������." << std::endl;
                return;
            default:
                std::cout << "�������� �����. ���������� �����." << std::endl;
                break;
            }
        }
    }
};