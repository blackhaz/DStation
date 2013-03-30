#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include "Magick++.h"

aboutDialog::aboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
}

aboutDialog::~aboutDialog()
{
    delete ui;
}

void aboutDialog::setApplicationLabel(const QString appString, const QString copyrightString)
{
    ui->label->setText(appString);
    ui->label_2->setText(copyrightString);
    ui->imLabel->setText(QString("Using ImageMagick libraries version ").append(QString(MagickLibVersionText)).append(QString(" Quantum Depth: ")).append(QString::number(MAGICKCORE_QUANTUM_DEPTH)).append(QString("-bit. ")));
    ui->imLabel_2->setText(QString(MagickCopyright));
}
