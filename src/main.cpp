#include <QApplication>
#include <QWidget>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("sample-app");
    window.setFixedSize(800, 600);
    window.show();
    return app.exec();
}
