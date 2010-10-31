/* 
 * File:   main.cpp
 * Author: roysimkes
 *
 * Created on October 27, 2010, 11:26 PM
 */

#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

#include "Producer.h"
#include "App.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    App *application = new App();
    application->bootstrap()
        ->run();
    return 0;
}