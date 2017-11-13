#include "create.h"
#include  "command.h"
#include <qpixmap.h>

Create::Create(State *state, COMTYPE type, Ui::MainWindow *ui) : Command(state,type)
{
    this->ui = ui;
}

void Create::excute(){
    QPixmap cop(*this->ui->backup_image->pixmap());
    this->ui->original_image->setPixmap(cop);
}
