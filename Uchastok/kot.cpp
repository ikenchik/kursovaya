#include "Container.h"
#include "Conveyor.h"
#include "InterFace.h"

int main() {
    setlocale(LC_ALL, "rus");

    InterFace ui;
    ui.Run();

    return 0; 
}