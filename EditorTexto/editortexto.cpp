#include "editortexto.h"
#include "ui_editortexto.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QDebug>
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
    ArquivoAtual = NomeArquivo;
    if(NomeArquivo.isEmpty()){

        SalvarArquivo();
    }else {
         SalvarArquivo();
    }
}

void EditorTexto::SalvarArquivo()
{
    QFile file(ArquivoAtual);
    if(file.open(QFile::WriteOnly)) {
        //file.write(ui->plainTextEdit.toPlainText().toutf8());
        file.write(ui->textEdit->toPlainText().toUtf8());
    }else {
        QMessageBox::warning(this," EditorTexto ",tr("O arquivo não pode ser salvo %1.\nError: %2").arg(ArquivoAtual).arg(file.errorString()));
    }
}
