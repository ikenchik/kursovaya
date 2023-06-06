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
    
    std::cout << "Грамм фарша: ";
    std::cin >> grams;
    while (grams <= 0) {
        std::cout << "Невозможно выполнить перегрузку сырья: контейнер пуст\n";
        std::cout << "Грамм фарша: ";
        std::cin >> grams;
        if (grams > 0) {
            break;
        }
    }
    while (grams > 4999999) {
        std::cout << "Невозможно выполнить загрузку сырья: контейнер будет переполнен\n";
        std::cout << "Грамм фарша: ";
        std::cin >> grams;
        if (grams < 499999) {
            break;
        }
    }
    inputContainer.addRawMaterial(grams);
    conveyor1.transferRawMaterial();
    std::cout << "Входной контейнер 1: " << inputContainer.getCurrentWeight() << "г" << std::endl;
    std::cout << "Выходной контейнер: " << outputContainer.getCurrentWeight() << "г" << std::endl;

    std::cout << "Грамм хлеба: ";
    std::cin >> gram;
    while (gram <= 0) {
        std::cout << "Невозможно выполнить перегрузку сырья: контейнер пуст\n";
        std::cout << "Грамм хлеба: ";
        std::cin >> gram;
        if (gram > 0) {
            break;
        }
    }
    while (gram > (5000000 - grams)) {
        std::cout << "Невозможно выполнить перегрузку сырья: входной контейнер будет переполнен\n";
        std::cout << "Грамм хлеба: ";
        std::cin >> gram;
        if (gram < (5000000 - grams)) {
            break;
        }
    }
    inputContainer1.addRawMaterial(gram);
    conveyor2.transferRawMaterial();
    std::cout << "Входной контейнер 2: " << inputContainer1.getCurrentWeight() << "г" << std::endl;
    std::cout << "Выходной контейнер: " << outputContainer.getCurrentWeight() << "г" << std::endl;

    outputContainer.mixMaterials();

    conveyor3.transferMixedMaterial();
    std::cout << "Выходной контейнер: " << outputContainer.getCurrentWeight() << "г" << std::endl;
    std::cout << "Конечный контейнер: " << finalContainer.getCurrentWeight() << "г" << std::endl;

    return 0; 
}