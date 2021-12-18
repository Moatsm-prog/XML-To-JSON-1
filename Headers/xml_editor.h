#ifndef XML_EDITOR_H
#define XML_EDITOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class XML_Editor; }
QT_END_NAMESPACE

class XML_Editor : public QMainWindow
{
    Q_OBJECT

public:
    XML_Editor(QWidget *parent = nullptr);
    ~XML_Editor();

private slots:
    void on_actionOpen_triggered();

    void on_format_button_clicked();

    void on_convert_clicked();

    void on_compress_xml_clicked();

    void on_comp_json_clicked();

    void on_Decomp_xml_clicked();

    void on_Decomp_json_clicked();

    void on_actionSave_as_triggered();

    void on_actionGithub_triggered();

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::XML_Editor *ui;

    void actionButtons(bool b);
};
#endif // XML_EDITOR_H
