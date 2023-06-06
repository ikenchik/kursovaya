#include <iostream>
#include <Windows.h>
#pragma once

class Container {
private:
    float currentWeight;  // текущий вес контейнера, задаем начальный вес = 0
    float maxWeight;      // максимальный вес контейнера, задаем по умолчанию = 1000 грамм
public:
    Container() {
        currentWeight = 0;
        maxWeight = 5000000;
    }

    void addRawMaterial(float grams) {
        if (currentWeight + grams > maxWeight) {
            std::cout << "Недостаточно места в контейнере для добавления сырья\n";
        }
        else {
            currentWeight += grams;
        }
    }

    void mixMaterials() {
        std::cout << "Сырье перемешивается в контейнере\n";
        std::string a = "1..2..3..";
        int time = 1500;
        for (int i = 0; i < a.length(); i++) {
            Sleep(time);
            std::cout << a[i];
        }
        std::cout << std::endl << "Сместь готова.\n";
    }

    float getCurrentWeight() {
        return currentWeight;
    }

    float removeRawMaterial() {
        return currentWeight = 0;
    }
};