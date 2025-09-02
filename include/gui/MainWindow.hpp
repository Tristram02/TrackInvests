#pragma once
#include <QMainWindow>

namespace gui
{

class PortfolioView;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

};

} // namespace gui
