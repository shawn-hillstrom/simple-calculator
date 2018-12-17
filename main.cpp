/* CS 224 -- Shawn Hillstrom -- Project 4 Main File
 * ------------------------------------------------
 * Contains main function and calls.
 */

#include <QApplication>

#include "calculator.h"

int main(int argc, char * argv[]) {
	QApplication app(argc, argv);
	Calculator calc;
	calc.show();
	return app.exec();
}

