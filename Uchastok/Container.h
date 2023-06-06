#include <iostream>
#include <Windows.h>
#pragma once

class Container {
private:
    float currentWeight;  // ������� ��� ����������, ������ ��������� ��� = 0
    float maxWeight;      // ������������ ��� ����������, ������ �� ��������� = 1000 �����
public:
    Container() {
        currentWeight = 0;
        maxWeight = 5000000;
    }

    void addRawMaterial(float grams) {
        if (currentWeight + grams > maxWeight) {
            std::cout << "������������ ����� � ���������� ��� ���������� �����\n";
        }
        else {
            currentWeight += grams;
        }
    }

    void mixMaterials() {
        std::cout << "����� �������������� � ����������\n";
        std::string a = "1..2..3..";
        int time = 1500;
        for (int i = 0; i < a.length(); i++) {
            Sleep(time);
            std::cout << a[i];
        }
        std::cout << std::endl << "������ ������.\n";
    }

    float getCurrentWeight() {
        return currentWeight;
    }

    float removeRawMaterial() {
        return currentWeight = 0;
    }
};