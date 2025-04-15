#include <QApplication>
#include <QWidget>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QString>

int main(int argc, char** argv){
    QApplication app(argc, argv);

    QWidget * window = new QWidget;
    window->setWindowTitle("Volume");
    window->resize(300, 50);

    QSpinBox * spinBox = new QSpinBox;
    QSlider * slider = new QSlider(Qt::Horizontal);

    spinBox->setRange(0, 100);
    slider->setRange(0,100);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));
    QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));

    QObject::connect(slider, &QSlider::valueChanged, [=](int value){
        window->setWindowTitle(QString::number(value));
    });

    spinBox->setValue(15);

    QHBoxLayout * layout = new QHBoxLayout;
    layout -> addWidget(spinBox);
    layout -> addWidget(slider);
    window -> setLayout(layout);
    window -> setVisible(true);

    return app.exec();
}
