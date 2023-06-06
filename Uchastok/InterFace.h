#include <iostream>

class InterFace {

private:
    
    Container outputContainer;
    Container inputContainer;
    Container inputContainer1;
    Container finalContainer;

    void DisplayMenu() {
        std::cout << "Меню:" << std::endl;
        std::cout << "1. Запустить программу" << std::endl;
        std::cout << "2. Выгрузить первый контейнер" << std::endl;
        std::cout << "3. Выгрузить второй контейнер" << std::endl;
        std::cout << "4. Перемешать сырье" << std::endl;
        std::cout << "5. Загрузить финальный контейнер" << std::endl;
        std::cout << "6. Выход" << std::endl;
    }

    int GetUserChoice() {
        int choice;
        std::cout << "Введите номер операции ==> ";
        std::cin >> choice;
        return choice;
    }

    void StartProgram() {
        std::cout << "Программа запущена." << std::endl;
        finalContainer.removeRawMaterial();
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
    }
    
    void cont1() {
        finalContainer.removeRawMaterial();
        Conveyor conveyor1(&inputContainer, &outputContainer);

        float grams;

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
    }
    
    void cont2() {
        Conveyor conveyor2(&inputContainer1, &outputContainer);

        float grams, gram;
        std::cout << "Сколько грамм фарша получил контейнер 1: ";
        std::cin >> grams;

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
    }
    
    void mixed() {
        outputContainer.mixMaterials();
    }

    void finalc() {
        Conveyor conveyor3(&outputContainer, &finalContainer);

        conveyor3.transferMixedMaterial();
        std::cout << "Выходной контейнер: " << outputContainer.getCurrentWeight() << "г" << std::endl;
        std::cout << "Конечный контейнер: " << finalContainer.getCurrentWeight() << "г" << std::endl;
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
                std::cout << "Выход из программы." << std::endl;
                return;
            default:
                std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
                break;
            }
        }
    }
};