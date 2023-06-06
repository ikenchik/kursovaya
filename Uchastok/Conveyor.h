#include <iostream>
#include "Container.h"  // класс контейнера
class Conveyor {
private:
    Container* inputContainer; // указатель на первый контейнер, откуда берем сырье
    Container* outputContainer;  // указатель на следующий контейнер, куда перегружаем сырье
public:
    Conveyor(Container* inC, Container* outC) {
        inputContainer = inC;
        outputContainer = outC;
    }

    void transferRawMaterial() {
        int a;
        std::cout << "Подтверждение: введите 1, если да., введите 0, если нет." << std::endl;
        std::cout << "==> ";
        std::cin >> a;
        if (a == 1) {
            float weight = inputContainer->getCurrentWeight();
            outputContainer->addRawMaterial(weight);
            inputContainer->removeRawMaterial();
            std::cout << "Сырье весом " << weight << " грамм успешно перегружено в следующий контейнер\n";
        }
        else if (a == 0) {
            std::cout << "Ожидание подтверждения перегрузки" << std::endl;
            return transferRawMaterial();
        }
        else {
            std::cout << "Ошибка, неверно введен идентификатор. Повторите попытку." << std::endl;
            return transferRawMaterial();
        }
    }
    
    void transferMixedMaterial() {
      int b;
      std::cout << "Подтверждение: введите 1, если да., введите 0, если нет." << std::endl;
      std::cout << "==> ";
      std::cin >> b;
      if (b == 1) {
          float weight = inputContainer->getCurrentWeight();
          outputContainer->addRawMaterial(weight);
          inputContainer->removeRawMaterial();
          std::cout << "Смесь весом " << weight << " грамм успешно перегружена в конечный контейнер\n";
      }
      else if (b == 0) {
          std::cout << "Ожидание подтверждения перегрузки" << std::endl;
          return transferMixedMaterial();
      }
      else {
          std::cout << "Ошибка, неверно введен идентификатор. Повторите попытку." << std::endl;
          return transferMixedMaterial();
      }
    }
};