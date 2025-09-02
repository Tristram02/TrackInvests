#include "gui/MainWindow.hpp"

namespace gui
{

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow{parent}
{
    // portfolioView_ = new Po
    setWindowTitle("TrackInvests");
    resize(800, 600);
}

MainWindow::~MainWindow() {}

}// namespace gui