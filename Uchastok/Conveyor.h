#include <iostream>
#include "Container.h"  // ����� ����������
class Conveyor {
private:
    Container* inputContainer; // ��������� �� ������ ���������, ������ ����� �����
    Container* outputContainer;  // ��������� �� ��������� ���������, ���� ����������� �����
public:
    Conveyor(Container* inC, Container* outC) {
        inputContainer = inC;
        outputContainer = outC;
    }

    void transferRawMaterial() {
        int a;
        std::cout << "�������������: ������� 1, ���� ��., ������� 0, ���� ���." << std::endl;
        std::cout << "==> ";
        std::cin >> a;
        if (a == 1) {
            float weight = inputContainer->getCurrentWeight();
            outputContainer->addRawMaterial(weight);
            inputContainer->removeRawMaterial();
            std::cout << "����� ����� " << weight << " ����� ������� ����������� � ��������� ���������\n";
        }
        else if (a == 0) {
            std::cout << "�������� ������������� ����������" << std::endl;
            return transferRawMaterial();
        }
        else {
            std::cout << "������, ������� ������ �������������. ��������� �������." << std::endl;
            return transferRawMaterial();
        }
    }
    
    void transferMixedMaterial() {
      int b;
      std::cout << "�������������: ������� 1, ���� ��., ������� 0, ���� ���." << std::endl;
      std::cout << "==> ";
      std::cin >> b;
      if (b == 1) {
          float weight = inputContainer->getCurrentWeight();
          outputContainer->addRawMaterial(weight);
          inputContainer->removeRawMaterial();
          std::cout << "����� ����� " << weight << " ����� ������� ����������� � �������� ���������\n";
      }
      else if (b == 0) {
          std::cout << "�������� ������������� ����������" << std::endl;
          return transferMixedMaterial();
      }
      else {
          std::cout << "������, ������� ������ �������������. ��������� �������." << std::endl;
          return transferMixedMaterial();
      }
    }
};