// Yogafinder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "houseCounter.h"
#include "aarudh.h"
#include "report.h";

int main()
{

    houseCounter objhc;
    aarudh objAarudh;
    basicR objrepo;

    objhc.assignPlanet();
    objAarudh.findArudha(lagna,"mars", "rahu");



    /*objrepo.d1report();
    objrepo.d9report();
    objhc.houseNumberD1(d1Lagna, d1venus);*/
}

