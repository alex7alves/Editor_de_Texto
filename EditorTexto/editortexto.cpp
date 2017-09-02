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

// metodo Salvar
void EditorTexto::SalvarArquivo()
{
    QFile file(ArquivoAtual);
    if(file.open(QFile::WriteOnly)) {
        file.write(ui->textEdit->toPlainText().toUtf8());
    }else {
        QMessageBox::warning(this," EditorTexto ",tr("O arquivo não pode ser salvo %1.\nError: %2").arg(ArquivoAtual).arg(file.errorString()));
    }
}

// metodo para verificar  se o documento foi modificado
bool EditorTexto::Modificado()
{
    if(ui->textEdit->document()->isModified()){
        QMessageBox::StandardButton ret =
                QMessageBox::warning(
                    this,
                    " Editortexto",
                    tr("O documento foi modificado, deseja salva-lo ?"),
                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
         if(ret == QMessageBox::Yes) {
             on_actionSalvar_Como_triggered();
         }else if(ret == QMessageBox::Cancel){
             return false;
         }else {
             return true;
         }
    }
}




// Evento do Salvar do menu
void EditorTexto::on_actionSalvar_triggered()
{
    if(ArquivoAtual.isEmpty()){
        on_actionSalvar_Como_triggered();
    }else {
        SalvarArquivo();
    }
}

void EditorTexto::on_actionAbrir_triggered()
{
    if(Modificado()){
        QString NomeArquivo = QFileDialog::getSaveFileName(this, "TextoEditor - Salvar ", "home/alex/Área de Trabalho/Pasta sem título/EditorTexto"," All Files (*.*);; Text Files (*.txt)");

        if(!(NomeArquivo.isEmpty())){
            QFile file(NomeArquivo);
            if(file.open(QFile::ReadOnly)) {
                 ui->textEdit->setPlainText(file.readAll());
             }else {
                 QMessageBox::warning(this," EditorTexto ",tr("O arquivo não pode ser salvo %1.\nError: %2").arg(ArquivoAtual).arg(file.errorString()));
            }
        }
     }

}
