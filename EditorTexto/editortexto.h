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
    bool on_actionSalvar_Como_triggered();
    bool on_actionSalvar_triggered();

    void on_actionAbrir_triggered();

private:
    Ui::EditorTexto *ui;
    bool SalvarArquivo();
    bool Modificado();
    QString ArquivoAtual;
};

#endif // EDITORTEXTO_H
