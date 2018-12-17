/* CS 224 -- Shawn Hillstrom -- Project 4 Functionality
 * ----------------------------------------------------
 * Implements functionality for Project 4 calculator.
 */

#include <QtGui>

#include "calculator.h"

Calculator::Calculator() {
	
	setupUi(this); // Set up the interface we built.
	
	/* Initialization */
	clr = true;
	
	/* Connections */
	connect(clear, SIGNAL(clicked()), this, SLOT(clearLabel()));
	connect(button0, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button1, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button2, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button3, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button4, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button5, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button6, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button7, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button8, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(button9, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(neg, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(dec, SIGNAL(clicked()), this, SLOT(numberKey()));
	connect(div, SIGNAL(clicked()), this, SLOT(actionKey()));
	connect(mult, SIGNAL(clicked()), this, SLOT(actionKey()));
	connect(sub, SIGNAL(clicked()), this, SLOT(actionKey()));
	connect(add, SIGNAL(clicked()), this, SLOT(actionKey()));
	connect(eq, SIGNAL(clicked()), this, SLOT(actionKey()));
	
}

void Calculator::numberKey() {
	if (clr) {
		clearLabel();
		clr = false;
	}
	QPushButton * button = qobject_cast<QPushButton *>(sender());
	QString labelText = resultLabel->text();
	if (button->text() == "+/-") {
		if (!labelText.contains("-"))
			labelText.insert(0, '-');
		else
			labelText.remove(0, 1);
	} else if (button->text() == ".") {
		if (!labelText.contains("."))
			labelText.append(".");
	} else
		labelText.append(button->text());	
	resultLabel->setText(labelText);
}

void Calculator::actionKey() {
	QPushButton * button = qobject_cast<QPushButton *>(sender());
	QString labelText = resultLabel->text();
	if (action == "/")
		result = previous/labelText.toDouble();
	else if (action == "*")
		result = previous*labelText.toDouble();
	else if (action == "-")
		result = previous-labelText.toDouble();
	else if (action == "+")
		result = previous+labelText.toDouble();
	if (button->text() == "=") {
		resultLabel->setText(QString::number(result));
		previous = result;
		clr = true;
	} else {
		previous = labelText.toDouble();
		clearLabel();
	}
	action = button->text();
}

void Calculator::clearLabel() {
	resultLabel->setText("");
}

