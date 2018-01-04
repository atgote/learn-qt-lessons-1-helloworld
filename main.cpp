/** \file main.cpp
 * This is my first Qt project. The source is slightly modified "Hello World"
 * from some lessons on youtube.
 *
 * Author: Andrei Tihonovschi
 * Date:   04.01.2017
 * */

#include <QApplication>
#include <QLabel>

/**
 * @brief DEFAULT_TEXT This is default text to be displayed in the main widget window.
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
    QLabel *lbl;

public:
    MyQApp(int argc, char **argv): QApplication(argc, argv), lbl(NULL)
    {
        const char *txt = DEFAULT_TEXT;
        if(argc > 1)
            txt = argv[1];

        lbl = new QLabel(txt);
        lbl->show();
    }

    ~MyQApp()
    {
        if(lbl)
            delete lbl;
    }
};

int main(int argc, char **argv)
{
    MyQApp a(argc, argv);

    return a.exec();
}
