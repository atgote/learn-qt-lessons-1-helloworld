/** \file main.cpp
 * This is my first Qt project. The source is modified "Hello World"
 * from some lessons on youtube.
 *
 * Author: Andrei Tihonovschi
 * Date:   04.01.2017
 * */

#include <QApplication>
#include <QLabel>

/**
 * @brief DEFAULT_TEXT This is default greeting to be displayed in the main widget window.
 */
const char *DEFAULT_TEXT = "<span style=\"color: red\">Hello world!</span>";

/**
 * @brief The MyQApp class
 *
 * Extends QApplication with a custom constructor.
 */
class MyQApp:public QApplication
{
private:
    QLabel *lbl; //!< QLabel which will display the greetings text

public:
    MyQApp(int argc, char **argv): QApplication(argc, argv), lbl(NULL)
    {
        // if there are no command line parameters, use default greeting
        const char *txt = DEFAULT_TEXT;
        if(argc > 1) // or, if there are, use first CLI argument as greeting
            txt = argv[1];

        // create and show QLabel window
        lbl = new QLabel(txt);
        lbl->show();
    }

    ~MyQApp()
    {
        // delete QLabel, if it was created
        if(lbl)
            delete lbl;
    }
};

/**
 * @brief main application entry point
 * @param argc CLI arguments counter
 * @param argv CLI arguments
 * @return 0 if no error, other value if an error has occured
 */
int main(int argc, char **argv)
{
    MyQApp a(argc, argv);

    return a.exec();
}
