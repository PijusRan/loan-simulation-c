/*
8. Banko skolų dengimas (ADT: eilė, prioritetinė eilė).
Bankas išduoda klientui paskolą, pagal jos sumą ir paskolos 
laikotarpį sudaromas grąžinimo grafikas (paskolinta suma grąžinama 
lygiomis dalimis kas 30 dienų). Deja, ne visi klientai sugeba 
grąžinti paskolą laiku. Atėjus mokėjimo dienai klientas gali turėti 
tik tiek pinigų, kiek reikia einamajai įmokai pagal grafiką dengti, 
arba kažkiek daugiau pinigų (tokiu atveju jis dengia ir įsiskolinimus, 
jei tokių yra), arba kažkiek mažiau pinigų (tokiu atveju auga skolos). 
Palūkanos skaičiuojamos už visą tam momentui negrąžintą paskolos sumą. 
Už laiku negrąžintą paskolos dalį imami delspinigiai (delspinigiai 
neskaičiuojami nuo palūkanų ir delspinigių). Galimos 2 skolų dengimo 
strategijos: 1) dengiamos seniausios skolos, neatsižvelgiant į jų tipą; 
2) dengiama pagal prioritetus: pagrindinė suma, palūkanos, delspinigiai. 
Įvertinti šių strategijų ekonominį poveikį klientui. Visi kiti rodikliai, 
nuo kurių priklauso procesas, įvedami kaip programos parametrai.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "config.h"
#include "loan.h"
#include "simulations.h"
#include "queue.h"
#include "priority_queue.h"

// Funkcijos prototipas
int main(int argc, char *argv[]) {

    // === PRADINIAI DUOMENYS ===
    // Skolos
    queue* loanQueue = CreateQueue(10);
    PQueue* loanPQueue = create_pq();
    readCFG(findCFG(argc, argv), loanQueue, loanPQueue);
    printf("%s\n", toStringQueue(loanQueue));

    // Random reikšmė
    unsigned int randomSeed = getRND(argc, argv);
    printf("Random Seed: %d\n\n", randomSeed);

    // === PRADINIŲ MOKĖJIMŲ SIMULIACIJA ===
    double queueSimulation = simulateQueue(loanQueue, randomSeed);
    printf("Simuliuojant eilę sumokėta: %lf\n\n", queueSimulation);

    double PqueueSimulation = simulatePQueue(loanPQueue, randomSeed);
    printf("Simuliuojant prioritetinę eilę sumokėta: %lf\n\n", PqueueSimulation);
    
    return 0;
}

