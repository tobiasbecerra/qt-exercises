#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    QString imagePath = "screenshot.jpg";
    QPixmap pixmap(imagePath);

    if(pixmap.isNull()){
        qWarning("Failed to load image.");
        return -1;
    }

    QLabel *label = new QLabel;
    label->setPixmap(pixmap.scaled(
        QApplication::primaryScreen()->size(),
        Qt::KeepAspectRatio,
        Qt::SmoothTransformation

        ));
    label->setAlignment(Qt::AlignCenter);
    label->setWindowTitle("Image Viewer");

    label->showMaximized();

    QTimer::singleShot(3000, [&](){
        label->close();
        app.quit();
    });

        return app.exec();
}

