#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QKeyEvent>
#include <QDebug>

class Form : public QWidget{
    Q_OBJECT

public:
    Form(QWidget *parent = nullptr) : QWidget(parent){
        setWindowTitle("Form");

        QLabel *labelLegajo = new QLabel("ID:");
        QLabel *labelName = new QLabel("Name:");
        QLabel *labelLastname = new QLabel("Lastname:");

        QLineEdit *editLegajo = new QLineEdit;
        QLineEdit *editNombre = new QLineEdit;
        QLineEdit *editApellido = new QLineEdit;

        QPushButton *submitButton = new QPushButton("Submit");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelLegajo, 0, 0);
        layout->addWidget(editLegajo, 0, 1);
        layout->addWidget(labelName, 1, 0);
        layout->addWidget(editNombre, 1, 1);
        layout->addWidget(labelLastname, 2, 0);
        layout->addWidget(editApellido, 2, 1);
        layout->addWidget(submitButton, 3, 0, 1, 2);

        setLayout(layout);
    }
};

class Login : public QWidget{
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr) : QWidget(parent){
        setWindowTitle("Login");

        QLabel *labelUser = new QLabel("Username:");
        QLabel *labelPass = new QLabel("Password:");
        userEdit = new QLineEdit;
        passEdit = new QLineEdit;
        passEdit->setEchoMode(QLineEdit::Password);

        loginButton = new QPushButton("Login");

        QGridLayout *layout = new QGridLayout;
        layout->addWidget(labelUser, 0, 0);
        layout->addWidget(userEdit, 0, 1);
        layout->addWidget(labelPass, 1, 0);
        layout->addWidget(passEdit, 1, 1);
        layout->addWidget(loginButton, 2, 0, 1, 2);

        setLayout(layout);

        connect(loginButton, &QPushButton::clicked, this, &Login::attemptLogin);
        connect(passEdit, &QLineEdit::returnPressed, this, &Login::attemptLogin);
        connect(userEdit, &QLineEdit::returnPressed, this, &Login::attemptLogin);
    }

private:
    void attemptLogin(){
        QString user = userEdit->text();
        QString pass = passEdit->text();

        if(user == "admin" && pass == "1111"){
            form = new Form;
            form->show();
            this->close();
        }else{
            passEdit->clear();
        }
    }
private:
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QPushButton *loginButton;
    Form *form;

};



#include "main.moc"

int main(int argc, char *argv[]){
    QApplication app(argc, argv);

    Login login;
    login.show();

    return app.exec();
}
