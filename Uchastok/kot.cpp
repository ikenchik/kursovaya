#include "Container.h"
#include "Conveyor.h"
int main() {
    setlocale(LC_ALL, "rus");
    
    Container inputContainer;
    Container inputContainer1;
    Container outputContainer;
    Container finalContainer;
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

    return 0; 
}