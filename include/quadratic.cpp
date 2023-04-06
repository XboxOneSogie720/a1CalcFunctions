#include <cmath>
#include <ncurses.h>
using namespace std;

void printTitle(double a, double b, double c, int needsWhatNumber) {
    // Initialize color
    const int SELECTED_EQUATION_TERM = 1;
    init_pair(SELECTED_EQUATION_TERM, COLOR_RED, COLOR_BLACK);

    const int FULL_EQUATION = 2;
    init_pair(FULL_EQUATION, COLOR_GREEN, COLOR_BLACK);

    clear(); // Clear the screen

    if (needsWhatNumber == 1) {
        printw("Equation: f(x)=");
        attron(COLOR_PAIR(SELECTED_EQUATION_TERM));
        printw("%.0f", a);
        attroff(COLOR_PAIR(SELECTED_EQUATION_TERM));
        printw("x^2 + %.0fx + %.0f", b, c);
    } else if (needsWhatNumber == 2) {
        printw("Equation: f(x)=%.0fx^2 + ", a);
        attron(COLOR_PAIR(SELECTED_EQUATION_TERM));
        printw("%.0f", b);
        attroff(COLOR_PAIR(SELECTED_EQUATION_TERM));
        printw("x + %.0f", c);
    } else if (needsWhatNumber == 3) {
        printw("Equation: f(x)=%.0fx^2 + %.0fx + ", a, b);
        attron(COLOR_PAIR(SELECTED_EQUATION_TERM));
        printw("%.0f", c);
        attroff(COLOR_PAIR(SELECTED_EQUATION_TERM));
    } else {
        attron(COLOR_PAIR(FULL_EQUATION));
        printw("Equation: f(x)=%.0fx^2 + %.0fx + %.0f", a, b, c);
        attroff(COLOR_PAIR(FULL_EQUATION));
    }

    printw("\n\n");
    refresh();
}

double solveForY(double a, double b, double c, double x)
{
    // Solve for y
    double term1 = a * (pow(x, 2));
    double term2 = b * x;
    double term3 = c;
    // Return y, which is all terms added together
    return (term1 + term2 + term3);
}

int findYInQuadratic() {
    // Initialize ncurses
    start_color();

    // Define colors
    const int ERROR = 1;
    const int USER_OPTIONS = 2;
    const int RESULT = 3;

    // Initialize colors
    init_pair(ERROR, COLOR_RED, COLOR_BLACK);
    init_pair(RESULT, COLOR_GREEN, COLOR_BLACK);

    while (true) {
        // Variables
        double a;
        double b;
        double c;
        double x;

        while (true) {
            printTitle(0, 0, 0, 1);
            printw("What is the 'a' in your equation: ");
            if (scanw("%lf", &a) == 1) {
                break; // Input is valid, break out of the loop
            } else {
                clear();
                attron(COLOR_PAIR(ERROR));
                printw("Invalid input. Please try again. Press any key to contine.");
                attroff(COLOR_PAIR(ERROR));
                refresh();
                getch(); // Wait for user input
            }
        }

        while (true) {
            printTitle(a, 0, 0, 2);
            printw("What is the 'b' in your equation: ");
            if (scanw("%lf", &b) == 1) {
                break; // Input is valid, break out of the loop
            } else {
                clear();
                attron(COLOR_PAIR(ERROR));
                printw("Invalid input. Please try again. Press any key to contine.");
                attroff(COLOR_PAIR(ERROR));
                refresh();
                getch(); // Wait for user input
            }
        }

        while (true) {
            printTitle(a, b, 0, 3);
            printw("What is the 'c' in your equation: ");
            if (scanw("%lf", &c) == 1) {
                break; // Input is valid, break out of the loop
            } else {
                clear();
                attron(COLOR_PAIR(ERROR));
                printw("Invalid input. Please try again. Press any key to contine.");
                attroff(COLOR_PAIR(ERROR));
                refresh();
                getch(); // Wait for user input
            }
        }

        while (true) {
            while (true) {
                printTitle(a, b, c, 0);
                printw("What X value do you want to use to solve for Y: ");
                if (scanw("%lf", &x) == 1) {
                    break; // Input is valid, break out of the loop
                } else {
                    clear();
                    attron(COLOR_PAIR(ERROR));
                    printw("Invalid input. Please try again. Press any key to contine.");
                    attroff(COLOR_PAIR(ERROR));
                    refresh();
                }
            }

            attron(COLOR_PAIR(RESULT));
            printw("\nWhen x = %.0f, y = %.0f", x, solveForY(a, b, c, x));
            attroff(COLOR_PAIR(RESULT));

            printw("\n\nPress 'q' to solve a different type of algebra problem\nPress 'n' to use a different equation\nPress any other key to continue: ");

            int userInput = getch();

            if (userInput == 'q' || userInput == 'Q') {
                // Exit
                endwin();
                return 0;
            } else if (userInput == 'n' || userInput == 'N') {
                // Break out of this infinite loop
                break;
            } else {
                // Continue solving for this equation
                continue;
            }
        }
    }
}