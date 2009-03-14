/*
 * =====================================================================================
 * 
 *       Filename:  MainWindow.h
 * 
 *    Description:  主窗口
 * 
 *        Version:  1.0
 *        Created:  2009年02月14日 07时49分10秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 * 
 *         Author:  lerosua (), lerosua@gmail.com
 *        Company:  Cyclone
 * 
 * =====================================================================================
 */

#ifndef  MAINWINDOW_FILE_HEADER_INC
#define  MAINWINDOW_FILE_HEADER_INC

#include <gtkmm.h>
#include <gtkmm/window.h>
#include <libglademm/xml.h>
#include <gtkmm/treeview.h>
#include <gtkmm/liststore.h>
#include "Board.h"
#define main_ui  "../data/gmchess.glade"
typedef Glib::RefPtr < Gnome::Glade::Xml > GlademmXML;

class Board;

class MainWindow:public Gtk::Window
{
	public:
		MainWindow();
		~MainWindow();
		/** 回到最初局面*/
		void on_start_move();
		/** 去到最后的局面*/
		void on_end_move();
		/** 执行下一步*/
		void on_next_move();
		/** 执行上一步*/
		void on_back_move();
		/** 开始对战*/
		void on_begin_game();
		/** 认输*/
		void on_lose_game();
		/** 求和*/
		void on_huo_game();
		/** 悔棋*/
		void on_undo_game();
		/** treeview 双击事件回调*/
		bool on_treeview_click(GdkEventButton* ev);
		/** 添加treview数据*/
		void add_step_line(int num,const Glib::ustring& f_line);
		void del_step_last_line();
	protected:
		void init_ui_manager();
		void on_menu_open_file();
		void on_menu_file_quit();
		void on_menu_view_preferences();
		void on_menu_war_to_ai();
		void on_menu_free_play();
		void on_menu_help_about();
		/** 初始化着法treeview */
		void init_move_treeview();
		/** 设置棋盘相关信息*/
		void set_information();
		/** 设置着法按钮可见性*/
		void set_move_button_property();
	public:
		class Columns:public Gtk::TreeModel::ColumnRecord
		{
			public:
				Columns()
				{
					add(step_num);
					add(step_line);
				}
				Gtk::TreeModelColumn <int> step_num;
				Gtk::TreeModelColumn <Glib::ustring> step_line;
		};
		Columns m_columns;
		Glib::RefPtr<Gtk::ListStore>	m_refTreeModel;
		
	private:
		Board*				board;
		GlademmXML			ui_xml;
		Glib::RefPtr<Gtk::UIManager>	ui_manager;
		Glib::RefPtr<Gtk::ActionGroup> 	action_group;
		Gtk::Widget*			menubar;
		Gtk::TreeView			m_treeview;
		/** treeview 里的按钮*/
		Gtk::Button*			btn_start;
		Gtk::Button*			btn_end ;
		Gtk::Button*			btn_prev;
		Gtk::Button*			btn_next;
		/** 对战按钮*/
		Gtk::Button*			btn_begin;
		Gtk::Button*			btn_lose;
		Gtk::Button*			btn_huo;
		Gtk::Button*			btn_undo;
};


#endif   /* ----- #ifndef MAINWINDOW_FILE_HEADER_INC  ----- */
