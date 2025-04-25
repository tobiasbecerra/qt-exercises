#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QRandomGenerator>
#include <QMessageBox>

class Formulario : public QWidget {
    Q_OBJECT

public:
    Formulario(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Formulario");

        QLabel *labelLegajo = new QLabel("Legajo:");
        QLabel *labelNombre = new QLabel("Nombre:");
        QLabel *labelApellido = new QLabel("Apellido:");
        QLabel *labelCaptcha = new QLabel("Captcha:");
        labelCaptchaValor = new QLabel(QString::number(generarCaptcha()));

        editLegajo = new QLineEdit;
        editNombre = new QLineEdit;
        editApellido = new QLineEdit;
        editCaptcha = new QLineEdit;

        QPushButton *botonAlta = new QPushButton("Alta");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelLegajo, 0, 0);
        layout->addWidget(editLegajo, 0, 1);
        layout->addWidget(labelNombre, 1, 0);
        layout->addWidget(editNombre, 1, 1);
        layout->addWidget(labelApellido, 2, 0);
        layout->addWidget(editApellido, 2, 1);
        layout->addWidget(labelCaptcha, 3, 0);
        layout->addWidget(labelCaptchaValor, 3, 1);
        layout->addWidget(editCaptcha, 4, 1);
        layout->addWidget(botonAlta, 5, 0, 1, 2);

        setLayout(layout);

        connect(botonAlta, &QPushButton::clicked, this, &Formulario::validarFormulario);
    }

private slots:
    void validarFormulario() {
        QString legajoStr = editLegajo->text();
        int legajo = legajoStr.toInt();
        QString nombre = editNombre->text();
        QString apellido = editApellido->text();
        QString captchaIngresado = editCaptcha->text();

        if (legajo < 1 || legajo > 10000) {
            QMessageBox::warning(this, "Error", "Legajo debe estar entre 1 y 10000");
            return;
        }

        if (nombre.isEmpty() || apellido.isEmpty()) {
            QMessageBox::warning(this, "Error", "Nombre y Apellido no pueden ser vacíos");
            return;
        }

        if (captchaIngresado != labelCaptchaValor->text()) {
            QMessageBox::warning(this, "Error", "Captcha incorrecto");
            editCaptcha->clear();
            return;
        }

        // Si todo es válido, cerrar la app
        qDebug() << "Formulario válido. Cerrando aplicación.";
        qApp->quit();
    }

private:
    QLineEdit *editLegajo, *editNombre, *editApellido, *editCaptcha;
    QLabel *labelCaptchaValor;

    int generarCaptcha() {
        return QRandomGenerator::global()->bounded(1000, 9999);
    }
};

class Login : public QWidget {
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        setWindowTitle("Login");

        QLabel *labelUsuario = new QLabel("Usuario:");
        QLabel *labelClave = new QLabel("Clave:");

        editUsuario = new QLineEdit;
        editClave = new QLineEdit;
        editClave->setEchoMode(QLineEdit::Password);

        QPushButton *botonLogin = new QPushButton("Ingresar");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelUsuario, 0, 0);
        layout->addWidget(editUsuario, 0, 1);
        layout->addWidget(labelClave, 1, 0);
        layout->addWidget(editClave, 1, 1);
        layout->addWidget(botonLogin, 2, 0, 1, 2);

        setLayout(layout);

        connect(botonLogin, &QPushButton::clicked, this, &Login::validarLogin);
        connect(editClave, &QLineEdit::returnPressed, this, &Login::validarLogin);
        connect(editUsuario, &QLineEdit::returnPressed, this, &Login::validarLogin);
    }

private slots:
    void validarLogin() {
        QString usuario = editUsuario->text();
        QString clave = editClave->text();

        if (usuario == "admin" && clave == "1111") {
            formulario = new Formulario;
            formulario->show();
            this->close();
        } else {
            editClave->clear();
        }
    }

private:
    QLineEdit *editUsuario, *editClave;
    Formulario *formulario;
};

#include "main.moc"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Login login;
    login.show();

    return app.exec();
}
