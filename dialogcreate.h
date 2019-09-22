#ifndef DIALOGCREATE_H
#define DIALOGCREATE_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui {
class Dialogcreate;
}

class Dialogcreate : public QWidget
{
    Q_OBJECT

public:
    explicit Dialogcreate(QWidget *parent = nullptr);
    ~Dialogcreate();

private:
    Ui::Dialogcreate *ui;
    void creer();

private slots:
    void quitcreate();
    void savecreate();
};

#endif // DIALOGCREATE_H
