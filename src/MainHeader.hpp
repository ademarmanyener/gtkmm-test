#ifndef TEST_MAINHEADER_HPP
#define TEST_MAINHEADER_HPP

#include <iostream>
#include <boost/any.hpp>
#include <boost/variant.hpp>
#include <gtkmm.h>
#include <sqlite3.h>

void closeWindow(){
  Gtk::Main::quit();
  return;
}

class MainWindow {
  protected:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Window *g_window_main;
  public:
    void getWidgets();
    void connectSignals();
    MainWindow(std::string gladepath, std::string windowname){
      this->builder = Gtk::Builder::create_from_file(gladepath);
      this->builder->get_widget(windowname, this->g_window_main);
      this->g_window_main->signal_hide().connect(sigc::ptr_fun(&closeWindow));
      this->getWidgets();
      this->connectSignals();
    }	
    ~MainWindow(){
      std::cout << "closing bbe" << std::endl;
    }
    void showWindow(){
      this->g_window_main->show();
      Gtk::Main::run();
      return;
    }
};

#endif // TEST_MAINHEADER_HPP
