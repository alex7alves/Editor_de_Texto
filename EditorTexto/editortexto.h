#ifndef EDITORTEXTO_H
#define EDITORTEXTO_H

#include <QMainWindow>

namespace Ui {
class EditorTexto;
}

class EditorTexto : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorTexto(QWidget *parent = 0);
    ~EditorTexto();

private slots:
    void on_actionSalvar_Como_triggered();
    void SalvarArquivo();
    QString ArquivoAtual;
private:
    Ui::EditorTexto *ui;
};

#endif // EDITORTEXTO_H
