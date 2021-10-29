#include "mainwindow.h"

#include <QApplication>
#include <QStyleFactory>
#include <darktheme.h>
#include <fstream>
#include <QFileInfo>


int main(int argc, char *argv[])
{
    darktheme dt;
    QFileInfo fileListInfo("files.txt");
    
    QApplication app(argc, argv);
    MainWindow window;
    // Dark theme applying 
    app.setStyle(QStyleFactory::create("Fusion"));
    app.setPalette(dt.getDarkTheme());
    app.setStyleSheet(dt.QToolTipSheet);

    // Checking does files.txt exists then deleting it.
    if (fileListInfo.exists() && fileListInfo.isFile()) std::remove("files.tmp");
    window.show();
    return app.exec();
}
