# ADS - Paskolos simuliacija (3 Užd. 8 Var.)

```
8. Banko skolų dengimas (ADT: eilė, prioritetinė eilė). Bankas išduoda klientui paskolą, pagal jos sumą ir paskolos laikotarpį sudaromas grąžinimo grafikas (paskolinta suma grąžinama lygiomis dalimis kas 30 dienų). Deja, ne visi klientai sugeba grąžinti paskolą laiku. Atėjus mokėjimo dienai klientas gali turėti tik tiek pinigų, kiek reikia einamajai įmokai pagal grafiką dengti, arba kažkiek daugiau pinigų (tokiu atveju jis dengia ir įsiskolinimus, jei tokių yra), arba kažkiek mažiau pinigų (tokiu atveju auga skolos). Palūkanos skaičiuojamos už visą tam momentui negrąžintą paskolos sumą. Už laiku negrąžintą paskolos dalį imami delspinigiai (delspinigiai neskaičiuojami nuo palūkanų ir delspinigių). Galimos 2 skolų dengimo strategijos: 1) dengiamos seniausios skolos, neatsižvelgiant į jų tipą; 2) dengiama pagal prioritetus: pagrindinė suma, palūkanos, delspinigiai. Įvertinti šių strategijų ekonominį poveikį klientui. Visi kiti rodikliai, nuo kurių priklauso procesas, įvedami kaip programos parametrai.
```

---

Sukurtas modulis simuliuoja du skolų padengimo variantus ir apskaičiuoja kokios buvo bendros išlaidos jas padengiant.

## Bendravimas ir Bendradarbiavimas

Prioritetinės eilės sprendimas buvo pasiskolintas ir pakeistas iš Jorio Uniko (joun2378). Buvo naudojama mano eilė, taip pat pakoreguota.

## Programos naudojimas

### Makefile

Makefile sukuria test.exe programos naudojimui. Reikalinga biblioteka (angl. package) `make`

```
$ make
```

### Go.cmd

Paleidžia programą (Windows aplinkoje)

```
$ ./Go.cmd
```

### Paleistis sukompiliavus

```
main.exe <failas> -rnd 67
```

Parametrai:

 - `<failas>` - skolų įrašo failas (`.cfg` plėtiniu)
 - `-rnd` - atsitiktinumo koeficientas
 - `-h` - pagalbos žinutei

### Įvestis

Įvestis gaunama iš pateikto `.cfg` failo

`.cfg` rašymo tvarka:

 - Skolos suma
 - Laikotarpis per kurį sumokėti sumą (mėnesiais)
 - Paskolos palūkanos
 - Delspinigio mėnesinės palūkanos
 - Sekanti skola iš kitos eilutės

`.cfg` pavyzdys:

```
10000 12 0.05 0.25
1200 2 0.08 0.25
20 1 0.30 0.40
```
