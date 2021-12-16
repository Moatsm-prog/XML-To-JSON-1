#include "../Headers/xml_editor.h"
#include "ui_xml_editor.h"
#include "QFileDialog"
#include "QMessageBox"
#include "../Headers/header.h"

XML_Editor::XML_Editor(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::XML_Editor)
{
    ui->setupUi(this);
    ui->output_textedit->setTabStopDistance(15);
}

XML_Editor::~XML_Editor()
{
    delete ui;
}

void XML_Editor::on_actionOpen_triggered()
{
    //QDir::homePath()
    QString file_name = QFileDialog::getOpenFileName(this, "open XML file", ".", tr("XML & JSON (*.xml *.dxml *.dson)"));
    QString ext = file_name.right(4);
    bool checkable = 1;
    qDebug() << "opening "<< ext << "file";
    ui->statusbar->showMessage("Valid XML");
    if(ext == "dxml" || ext ==  "dson"){
        actionButtons(0);
        if(ext == "dxml"){
            ui->Decomp_xml->setEnabled(true);
            ui->statusbar->showMessage("Compressed XML");
            checkable = 0;
        }
        else if(ext == "dson" && root){
            ui->Decomp_json->setEnabled(true);
            ui->statusbar->showMessage("Compressed JSON");
            checkable = 0;
        }
        else if(!root){
            ui->statusbar->showMessage("Compressed JSON (program can only decompress current session compressed files)");
        }
    }
    else{
        actionButtons(1);
    }
    input_string = open_file(file_name.toStdString());
    try {
        if(checkable) check();
        ui->input_textedit->setTextBackgroundColor(Qt::transparent);
    }  catch (XML_Exception* e) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::critical(this, "XML Invalid",
                              (e->msg + '\n' + "Do you want me to Autocorrect your file? ").c_str()
                              , QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes){
            string output = ident(correct_string(xml));
            ui->output_textedit->setText(QString::fromStdString(output));
            ui->input_textedit->setTextBackgroundColor(Qt::transparent);
            ui->statusbar->showMessage("Autocorrected XML (to complete open valid XML file)");
        }
        else{
            ui->input_textedit->setTextBackgroundColor(Qt::red);
            ui->statusbar->showMessage("Invalid XML");
        }
        actionButtons(0);
    }
    ui->input_textedit->setText(QString::fromStdString(input_string));
}

void XML_Editor::actionButtons(bool b){
    ui->format_button->setEnabled(b);
    ui->convert->setEnabled(b);
    ui->compress_xml->setEnabled(b);
    ui->comp_json->setEnabled(b);
    ui->Decomp_xml->setEnabled(0);
    ui->Decomp_json->setEnabled(0);
}

void XML_Editor::on_format_button_clicked()
{
    if(!INPUT_FILE.size()) XML_Editor::on_actionOpen_triggered();
    string formated_xml = ident(xml);
    ui->output_textedit->setText(QString::fromStdString(formated_xml));
    lastOp = XML;
}


void XML_Editor::on_convert_clicked()
{
    if(!INPUT_FILE.size()) XML_Editor::on_actionOpen_triggered();
    if(!root) root = xml_to_tree(xml);
    string json = tree_to_json(root, normal);
    ui->output_textedit->setText(QString::fromStdString(json));
    lastOp = JSON;
}


void XML_Editor::on_compress_xml_clicked()
{
    if(!INPUT_FILE.size()){
        XML_Editor::on_actionOpen_triggered();
        return;
    }
    string EnXml = encode(xml);
    QString fname = QFileDialog::getSaveFileName(this, "Save Compressed XML", ".", "Compressed XML files (*.dxml)" );
    saveAsFile((fname + ".dxml").toStdString(), EnXml);
}