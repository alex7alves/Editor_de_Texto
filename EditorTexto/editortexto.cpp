#include "editortexto.h"
#include "ui_editortexto.h"
#include <QFileDialog>
EditorTexto::EditorTexto(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorTexto)
{
    ui->setupUi(this);
}

EditorTexto::~EditorTexto()
{
    delete ui;
}

// Evento do botão salvar como
void EditorTexto::on_actionSalvar_Como_triggered()
{
    // Caixa de dialogo
    QString NomeArquivo = QFileDialog::getSaveFileName(this, "TextoEditor - Salvar Como ", "home/alex/Área de Trabalho/Pasta sem título/EditorTexto"," All Files (*.*);; Text Files (*.txt)");
    if(NomeArquivo.isEmpty()){
        SalvarArquivo();
    }
}

void EditorTexto::SalvarArquivo()
{
    QFile file(ArquivoAtual);
}
