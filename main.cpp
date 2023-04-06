#include <iostream>
#include <ncurses.h>
#include "include/quadratic.h"
using namespace std;

void printOptions() {
    // Initialize color
    const int MAIN_TITLE = 0;
    const int OPTIONS = 1;
    init_pair(MAIN_TITLE, COLOR_WHITE, COLOR_BLACK);
    init_pair(OPTIONS, COLOR_GREEN, COLOR_BLACK);

    clear(); // Clear the screen
    refresh(); // Update

    attron(COLOR_PAIR(MAIN_TITLE));
    printw("Algebra 1 Calculation Functions - v1.0");
    attroff(COLOR_PAIR(MAIN_TITLE));

    attron(COLOR_PAIR(OPTIONS));
    printw("\n\n1. Find Y for any given X");
    printw("\n2. Exit");
    attroff(COLOR_PAIR(OPTIONS));
    
    printw("\n\nSelected Option: ");
}

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    start_color();

    // Ask the user what they want to do, do it, and repeat
    while (true) {
        // Track user input
        int optionSelected;
        // Make sure the user inputs a valid option
        while (true) {
            printOptions();
            if (scanw("%d", &optionSelected) == 1) {
                break; // Valid input, break
            } else {
                // Tell the user that numbers are only allowed
                clear();
                printw("Numbers Only! Press any key to retry:");
                getch();
                clear();
            }
        }

        // Depending on what the user chose, run that function
        switch (optionSelected) {
            case 1:
                // Run the quadratic function
                findYInQuadratic();
                break;
            case 2:
                // Cleanup and exit
                endwin();
                return 0;
        }
    }
}