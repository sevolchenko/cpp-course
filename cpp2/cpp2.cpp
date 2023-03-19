#include <iostream>

#include "Anthill.h"
#include "QueenAnt.h"
#include "Storage.h"
#include "ConsumingEntity.h"
#include "Larva.h"
#include "WorkerAnt.h"
#include "PolicemanAnt.h"
#include "SoldierAnt.h"

#include <list>
#include <string.h>

/*
* 
* 7. Муравейник. Типы объектов: матка, солдаты, полицейские, рабочие, личинки, вредители.
Каждый представиль является отдельным экземпляром класса.
Муравейник имеет склад пищи фиксированного размера.
Матка создает личинки, из личинок выводятся солдаты,
полицейские или рабочие муравьи и ест очень много,
солдаты уменьшают число вредителей и много едят,
полицейские помогают увеличить число добываемой пищи и едят меньше солдат,
рабочие добывают пищу и едят меньше полицейских, личинки только едят.
Матка имеет следующие параметры:
• кол-во потребляемой пищи;
• кол-во рождаемых личинок.
Солдаты имеют следующие параметры
• кол-во потребляемой пищи;
• кол-во уничтожаемых вредителей.
Полицейские имеются следующие параметры:
• кол-во потребляемой пищи;
• процент, на который увеличивается запас пищи.
Рабочие имеют следующие параметры:
• кол-во потребляемой пищи;
• кол-во добываемой пищи.
Личинки имеют только один параметр: кол-во потребляемой пищи.
Через некоторое время личинки должны разродится в новую форму.
При изменении формы личнки должны об этом сигнализировать матку, чтобы она определила тип, в который превратится личинка.
Показать работу муравейника для различных значений числа муравьев, вредителей, пищи.
* 
*/

int main()
{
    setlocale(LC_ALL, "Russian");

    // Параметры системы

    int storage_max_size = 500;
    int storage_curr_state = 300;

    int queen_consumes = 50;
    int queen_produces = 3;
    
    int pests_consumes = 2;
    int pests_spawns = 3;

    int larvas_consumes = 3;

    int workers_consumes = 5;
    int workers_collects = 10;

    int policemans_consumes = 7;
    double policemans_increases = 0.01;

    int soldiers_consumes = 8;
    int soldiers_eliminates = 2;

    Anthill anthill(
        storage_max_size, storage_curr_state,
        queen_consumes, queen_produces,
        pests_consumes, pests_spawns,
        larvas_consumes,
        workers_consumes, workers_collects,
        policemans_consumes, policemans_increases,
        soldiers_consumes, soldiers_eliminates
    );

    cout << "Для продолжения нажмите любую клавишу" << endl;
    cout << "Для выхода нажмите 'q'" << endl;

    int i = 0;
    while (true)
    {
        anthill.nextStep();

        cout << "--------------------------" << endl;
        cout << "Шаг " << ++i << endl;
        anthill.printState();
        cout << "--------------------------" << endl;
        cout << endl;

        if (getchar() == 'q')
        {
            break;
        }
    }
    
    return 0;
    
}