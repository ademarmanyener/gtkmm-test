#include "MainHeader.hpp"

Gtk::Entry *g_entry1;
Gtk::Entry *g_entry2;
Gtk::Entry *g_entry3;
Gtk::Button *g_btn1;

void on_btn1_clicked(){
  std::cout << "btn1 clicked" << std::endl;
  return;
}

void MainWindow::getWidgets(){
  this->builder->get_widget("entry1", g_entry1);
  this->builder->get_widget("entry2", g_entry2);
  this->builder->get_widget("entry3", g_entry3);
  this->builder->get_widget("btn1", g_btn1);
  return;
}

void MainWindow::connectSignals(){
  g_btn1->signal_clicked().connect(sigc::ptr_fun(&on_btn1_clicked));
  return;
}

int main(int c, char *v[]){
  Gtk::Main kit(c, v);
  std::unique_ptr<MainWindow> mainwindow = std::make_unique<MainWindow>("ui/simple.glade", "window_main");
  mainwindow->showWindow();
  return 0;
}
