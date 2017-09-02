#include "editortexto.h"
#include "ui_editortexto.h"

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
