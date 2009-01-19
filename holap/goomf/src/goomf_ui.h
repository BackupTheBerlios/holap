// generated by Fast Light User Interface Designer (fluid) version 1.0109

#ifndef goomf_ui_h
#define goomf_ui_h
#include <FL/Fl.H>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../config.h"
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_Valuator.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/x.H>

class Rueda : public Fl_Dial {
public:
  char theformat[32]; 
  Fl_Shared_Image *img; 
  Fl_Image *temp; 
  Rueda(int x,int y, int w, int h, const char *label=0);
  ~Rueda();
  void draw();
  int handle(int  event);
};
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Input.H>

class goomf_ui {
public:
  int Pexitprogram; 
  int ready; 
  int op; 
  int cop; 
  int D_Vol_c; 
  int D_Tune_c; 
  int D_Portamento_c; 
  int D_LFO_Volume_c; 
  int D_LFO_Frequency_c; 
  int D_LFO_Delay_c; 
  int D_LFO_Wave_c; 
  int D_Wave_c[6]; 
  int D_H_c[6]; 
  int D_HF_c[6]; 
  int D_OVol_c[6]; 
  int D_pLFO_c[6]; 
  int D_Attack_c[6]; 
  int D_Decay_c[6]; 
  int D_Sustain_c[6]; 
  int D_Release_c[6]; 
  int D_Ftype_c; 
  int D_Fgain_c; 
  int D_Fcutoff_c; 
  int D_Fq_c; 
  int D_FLFO_c; 
  int D_FADSR_c; 
  int D_Fstages_c; 
  int D_Fvelocity_c; 
  char uBankFilename[255]; 
  int made; 
  goomf_ui();
  Fl_Double_Window* make_window();
  Fl_Double_Window *ui_win;
private:
  void cb_ui_win_i(Fl_Double_Window*, void*);
  static void cb_ui_win(Fl_Double_Window*, void*);
  static Fl_Menu_Item menu_[];
  void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  void cb_Bank_i(Fl_Menu_*, void*);
  static void cb_Bank(Fl_Menu_*, void*);
public:
  Fl_Box *d_osc_label;
  Fl_Box *setBankFile;
  Fl_Box *MT;
  Rueda *D_Vol;
private:
  void cb_D_Vol_i(Rueda*, void*);
  static void cb_D_Vol(Rueda*, void*);
public:
  Rueda *D_Tune;
private:
  void cb_D_Tune_i(Rueda*, void*);
  static void cb_D_Tune(Rueda*, void*);
public:
  Rueda *D_Portamento;
private:
  void cb_D_Portamento_i(Rueda*, void*);
  static void cb_D_Portamento(Rueda*, void*);
public:
  Rueda *D_Wave;
private:
  void cb_D_Wave_i(Rueda*, void*);
  static void cb_D_Wave(Rueda*, void*);
public:
  Rueda *D_H;
private:
  void cb_D_H_i(Rueda*, void*);
  static void cb_D_H(Rueda*, void*);
public:
  Rueda *D_HF;
private:
  void cb_D_HF_i(Rueda*, void*);
  static void cb_D_HF(Rueda*, void*);
public:
  Rueda *D_OVol;
private:
  void cb_D_OVol_i(Rueda*, void*);
  static void cb_D_OVol(Rueda*, void*);
public:
  Rueda *D_pLFO;
private:
  void cb_D_pLFO_i(Rueda*, void*);
  static void cb_D_pLFO(Rueda*, void*);
public:
  Rueda *D_Attack;
private:
  void cb_D_Attack_i(Rueda*, void*);
  static void cb_D_Attack(Rueda*, void*);
public:
  Rueda *D_Decay;
private:
  void cb_D_Decay_i(Rueda*, void*);
  static void cb_D_Decay(Rueda*, void*);
public:
  Rueda *D_Sustain;
private:
  void cb_D_Sustain_i(Rueda*, void*);
  static void cb_D_Sustain(Rueda*, void*);
public:
  Rueda *D_Release;
private:
  void cb_D_Release_i(Rueda*, void*);
  static void cb_D_Release(Rueda*, void*);
public:
  Fl_Button *OP1;
private:
  void cb_OP1_i(Fl_Button*, void*);
  static void cb_OP1(Fl_Button*, void*);
public:
  Fl_Button *OP2;
private:
  void cb_OP2_i(Fl_Button*, void*);
  static void cb_OP2(Fl_Button*, void*);
public:
  Fl_Button *OP3;
private:
  void cb_OP3_i(Fl_Button*, void*);
  static void cb_OP3(Fl_Button*, void*);
public:
  Fl_Button *OP4;
private:
  void cb_OP4_i(Fl_Button*, void*);
  static void cb_OP4(Fl_Button*, void*);
public:
  Fl_Button *OP5;
private:
  void cb_OP5_i(Fl_Button*, void*);
  static void cb_OP5(Fl_Button*, void*);
public:
  Fl_Button *OP6;
private:
  void cb_OP6_i(Fl_Button*, void*);
  static void cb_OP6(Fl_Button*, void*);
public:
  Fl_Group *LFO;
  Rueda *D_LFO_Frequency;
private:
  void cb_D_LFO_Frequency_i(Rueda*, void*);
  static void cb_D_LFO_Frequency(Rueda*, void*);
public:
  Rueda *D_LFO_Volume;
private:
  void cb_D_LFO_Volume_i(Rueda*, void*);
  static void cb_D_LFO_Volume(Rueda*, void*);
public:
  Rueda *D_LFO_Delay;
private:
  void cb_D_LFO_Delay_i(Rueda*, void*);
  static void cb_D_LFO_Delay(Rueda*, void*);
public:
  Rueda *D_LFO_Wave;
private:
  void cb_D_LFO_Wave_i(Rueda*, void*);
  static void cb_D_LFO_Wave(Rueda*, void*);
public:
  Fl_Counter *PresetSelect;
private:
  void cb_PresetSelect_i(Fl_Counter*, void*);
  static void cb_PresetSelect(Fl_Counter*, void*);
public:
  Fl_Input *Pname;
  Rueda *D_Ftype;
private:
  void cb_D_Ftype_i(Rueda*, void*);
  static void cb_D_Ftype(Rueda*, void*);
public:
  Rueda *D_Fgain;
private:
  void cb_D_Fgain_i(Rueda*, void*);
  static void cb_D_Fgain(Rueda*, void*);
public:
  Rueda *D_Fcutoff;
private:
  void cb_D_Fcutoff_i(Rueda*, void*);
  static void cb_D_Fcutoff(Rueda*, void*);
public:
  Rueda *D_Fq;
private:
  void cb_D_Fq_i(Rueda*, void*);
  static void cb_D_Fq(Rueda*, void*);
public:
  Rueda *D_FLFO;
private:
  void cb_D_FLFO_i(Rueda*, void*);
  static void cb_D_FLFO(Rueda*, void*);
public:
  Rueda *D_FADSR;
private:
  void cb_D_FADSR_i(Rueda*, void*);
  static void cb_D_FADSR(Rueda*, void*);
public:
  Rueda *D_Fstages;
private:
  void cb_D_Fstages_i(Rueda*, void*);
  static void cb_D_Fstages(Rueda*, void*);
public:
  Fl_Button *D_Fvelocity;
private:
  void cb_D_Fvelocity_i(Fl_Button*, void*);
  static void cb_D_Fvelocity(Fl_Button*, void*);
public:
  Fl_Double_Window *BankWindow;
private:
  void cb_BankWindow_i(Fl_Double_Window*, void*);
  static void cb_BankWindow(Fl_Double_Window*, void*);
public:
  Fl_Menu_Bar *MenuB;
  static Fl_Menu_Item menu_MenuB[];
  static Fl_Menu_Item *ArchivoB;
  static Fl_Menu_Item *NewB;
private:
  void cb_NewB_i(Fl_Menu_*, void*);
  static void cb_NewB(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *Load_Bank;
private:
  void cb_Load_Bank_i(Fl_Menu_*, void*);
  static void cb_Load_Bank(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *Save_Bank;
private:
  void cb_Save_Bank_i(Fl_Menu_*, void*);
  static void cb_Save_Bank(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *salirB;
private:
  void cb_salirB_i(Fl_Menu_*, void*);
  static void cb_salirB(Fl_Menu_*, void*);
public:
  Fl_Group *ob;
  static void tick(void* v);
  void quit();
};
#endif
