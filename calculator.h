/* CS 224 -- Shawn Hillstrom -- Project 4 Header File
 * --------------------------------------------------
 * Contains all relevant objects and definitions for the project
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

#include "ui_mainwindow.h" // Created automatically from mainwindow.ui.

class Calculator: public QMainWindow, private Ui::MainWindow {
	Q_OBJECT

public:
	Calculator(); // Constructor

private slots:
	/* Function: numberKey
	 * -------------------
	 * Triggered when a number key is pressed.
	 */
	void numberKey();
	/* Function: actionKey
	 * -------------------
	 * Triggered when an action key is pressed.
	 */
	void actionKey();
	/* Function: clearLabel
	 * Clears the main calculator display.
	 */
	void clearLabel();

private:
	double result; // Stores calculated result.
	double previous; // Stores previous numerical value entered.
	QString action; // Stores action characters for computations.
	bool clr; // Determines whether or not the next key press should clear the label.
};

#endif
