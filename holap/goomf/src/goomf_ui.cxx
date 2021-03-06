// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include <libintl.h>
#include "goomf_ui.h"

Rueda::Rueda(int x,int y, int w, int h, const char *label):Fl_Dial(x,y,w,h,label) {
  char tempfile[128];

sprintf(tempfile,"%s/knob.png",DATADIR);

img = Fl_Shared_Image::get((const char *)tempfile);

if (w != 50) 
   temp = img->copy(w*51,w);
   else temp= img;
}

Rueda::~Rueda() {
  img ->release();
delete temp;
}

void Rueda::draw() {
  int ox,oy,ww,hh;
int paso;
char buf[128];
float val;

ox = x();
oy = y();
ww = w();
hh = h();



  if (minimum() == maximum())
    val = 0.5;
  else {
    val = (value()-minimum())/(maximum()-minimum());
     
    if (val > 1.0) val = 1.0;
    else if (val < 0.0) val = 0.0;
  }


  paso = (int) (val * 47);


if (damage()&FL_DAMAGE_ALL)
{
draw_box(box(), ox, oy, ww, hh, color());
}


draw_box(box(), ox, oy, ww, hh, color());

temp->draw(ox,oy,ww,hh,paso*ww,0);

bzero(buf,sizeof(buf));

sprintf(buf,theformat,value());

draw_box(box(),ox,oy+ww,ww,hh-ww, color());

fl_font(FL_HELVETICA, 11);

fl_color(active_r() ? labelcolor() : fl_inactive(labelcolor()));

fl_draw(buf, ox, oy+ww,ww,hh-ww,FL_ALIGN_CLIP);
}

int Rueda::handle(int  event) {
  int i=0;

if (event == FL_PUSH && Fl::visible_focus()) {
    Fl::focus(this);
    draw();
} 



switch (event) 
	{
    	              		
    		 case FL_MOUSEWHEEL :
                      {
                      if (Fl::e_dy==0) return 0;
                      handle_push();
                      handle_drag(clamp(increment(value(),Fl::e_dy)));
                      handle_release();
                      return 1;	
                      }
         
                case FL_FOCUS :
                case FL_UNFOCUS :
                      if (Fl::visible_focus()) {
                      redraw();
                      return 1;
                      } else return 0;
        }


 i = Fl_Dial::handle(event);
 //redraw();
 
 
return i;
}

void goomf_ui::cb_ui_win_i(Fl_Double_Window*, void*) {
  Pexit=1;
}
void goomf_ui::cb_ui_win(Fl_Double_Window* o, void* v) {
  ((goomf_ui*)(o->user_data()))->cb_ui_win_i(o,v);
}

void goomf_ui::cb_New_i(Fl_Menu_*, void*) {
  ready = 6;
}
void goomf_ui::cb_New(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_New_i(o,v);
}

void goomf_ui::cb_Bank_i(Fl_Menu_*, void*) {
  BankWindow->show();
if(!made) ready = 5;
}
void goomf_ui::cb_Bank(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_Bank_i(o,v);
}

Fl_Menu_Item goomf_ui::menu_[] = {
 {gettext("&New"), 0x6e,  (Fl_Callback*)goomf_ui::cb_New, 0, 0, FL_NORMAL_LABEL, 0, 14, 7},
 {gettext("&Bank"), 0x62,  (Fl_Callback*)goomf_ui::cb_Bank, 0, 0, FL_NORMAL_LABEL, 0, 14, 7},
 {0,0,0,0,0,0,0,0,0}
};

void goomf_ui::cb_D_Vol_i(Rueda*, void*) {
  D_Vol_c=1;
}
void goomf_ui::cb_D_Vol(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_D_Vol_i(o,v);
}

void goomf_ui::cb_D_Tune_i(Rueda*, void*) {
  D_Tune_c=1;
}
void goomf_ui::cb_D_Tune(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_D_Tune_i(o,v);
}

void goomf_ui::cb_D_Portamento_i(Rueda*, void*) {
  D_Portamento_c=1;
}
void goomf_ui::cb_D_Portamento(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_D_Portamento_i(o,v);
}

void goomf_ui::cb_D_Wave_i(Rueda*, void*) {
  D_Wave_c[op]=1;
}
void goomf_ui::cb_D_Wave(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Wave_i(o,v);
}

void goomf_ui::cb_D_H_i(Rueda*, void*) {
  D_H_c[op]=1;
}
void goomf_ui::cb_D_H(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_H_i(o,v);
}

void goomf_ui::cb_D_HF_i(Rueda*, void*) {
  D_HF_c[op]=1;
}
void goomf_ui::cb_D_HF(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_HF_i(o,v);
}

void goomf_ui::cb_D_OVol_i(Rueda*, void*) {
  D_OVol_c[op]=1;
}
void goomf_ui::cb_D_OVol(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_OVol_i(o,v);
}

void goomf_ui::cb_D_pLFO_i(Rueda*, void*) {
  D_pLFO_c[op]=1;
}
void goomf_ui::cb_D_pLFO(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_pLFO_i(o,v);
}

void goomf_ui::cb_D_Attack_i(Rueda*, void*) {
  D_Attack_c[op]=1;
}
void goomf_ui::cb_D_Attack(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Attack_i(o,v);
}

void goomf_ui::cb_D_Decay_i(Rueda*, void*) {
  D_Decay_c[op]=1;
}
void goomf_ui::cb_D_Decay(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Decay_i(o,v);
}

void goomf_ui::cb_D_Sustain_i(Rueda*, void*) {
  D_Sustain_c[op]=1;
}
void goomf_ui::cb_D_Sustain(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Sustain_i(o,v);
}

void goomf_ui::cb_D_Release_i(Rueda*, void*) {
  D_Release_c[op]=1;
}
void goomf_ui::cb_D_Release(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Release_i(o,v);
}

void goomf_ui::cb_D_Algo_i(Rueda*, void*) {
  D_Algo_c=1;
}
void goomf_ui::cb_D_Algo(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Algo_i(o,v);
}

void goomf_ui::cb_OP1_i(Fl_Button* o, void*) {
  if ((int) o->value()==1)
{
op=0;
cop=1;
};
}
void goomf_ui::cb_OP1(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP1_i(o,v);
}

void goomf_ui::cb_OP2_i(Fl_Button* o, void*) {
  if ((int)o->value()==1)
{
op=1;
cop=1;
};
}
void goomf_ui::cb_OP2(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP2_i(o,v);
}

void goomf_ui::cb_OP3_i(Fl_Button* o, void*) {
  if ((int)o->value()==1)
{
op=2;
cop=1;
};
}
void goomf_ui::cb_OP3(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP3_i(o,v);
}

void goomf_ui::cb_OP4_i(Fl_Button* o, void*) {
  if ((int)o->value()==1)
{
op=3;
cop=1;
};
}
void goomf_ui::cb_OP4(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP4_i(o,v);
}

void goomf_ui::cb_OP5_i(Fl_Button* o, void*) {
  if ((int)o->value()==1)
{
op=4;
cop=1;
};
}
void goomf_ui::cb_OP5(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP5_i(o,v);
}

void goomf_ui::cb_OP6_i(Fl_Button* o, void*) {
  if ((int)o->value()==1)
{
op=5;
cop=1;
};
}
void goomf_ui::cb_OP6(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->parent()->user_data()))->cb_OP6_i(o,v);
}

void goomf_ui::cb_D_LFO_Frequency_i(Rueda*, void*) {
  D_LFO_Frequency_c=1;
}
void goomf_ui::cb_D_LFO_Frequency(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_LFO_Frequency_i(o,v);
}

void goomf_ui::cb_D_LFO_Volume_i(Rueda*, void*) {
  D_LFO_Volume_c=1;
}
void goomf_ui::cb_D_LFO_Volume(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_LFO_Volume_i(o,v);
}

void goomf_ui::cb_D_LFO_Delay_i(Rueda*, void*) {
  D_LFO_Delay_c=1;
}
void goomf_ui::cb_D_LFO_Delay(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_LFO_Delay_i(o,v);
}

void goomf_ui::cb_D_LFO_Wave_i(Rueda*, void*) {
  D_LFO_Wave_c=1;
}
void goomf_ui::cb_D_LFO_Wave(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_LFO_Wave_i(o,v);
}

void goomf_ui::cb_PresetSelect_i(Fl_Counter*, void*) {
  ready = 2;
}
void goomf_ui::cb_PresetSelect(Fl_Counter* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_PresetSelect_i(o,v);
}

void goomf_ui::cb_D_Ftype_i(Rueda*, void*) {
  D_Ftype_c=1;
}
void goomf_ui::cb_D_Ftype(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Ftype_i(o,v);
}

void goomf_ui::cb_D_Fgain_i(Rueda*, void*) {
  D_Fgain_c=1;
}
void goomf_ui::cb_D_Fgain(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Fgain_i(o,v);
}

void goomf_ui::cb_D_Fcutoff_i(Rueda*, void*) {
  D_Fcutoff_c=1;
}
void goomf_ui::cb_D_Fcutoff(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Fcutoff_i(o,v);
}

void goomf_ui::cb_D_Fq_i(Rueda*, void*) {
  D_Fq_c=1;
}
void goomf_ui::cb_D_Fq(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Fq_i(o,v);
}

void goomf_ui::cb_D_FLFO_i(Rueda*, void*) {
  D_FLFO_c=1;
}
void goomf_ui::cb_D_FLFO(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_FLFO_i(o,v);
}

void goomf_ui::cb_D_FADSR_i(Rueda*, void*) {
  D_FADSR_c=1;
}
void goomf_ui::cb_D_FADSR(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_FADSR_i(o,v);
}

void goomf_ui::cb_D_Fstages_i(Rueda*, void*) {
  D_Fstages_c=1;
}
void goomf_ui::cb_D_Fstages(Rueda* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Fstages_i(o,v);
}

void goomf_ui::cb_D_Fvelocity_i(Fl_Button*, void*) {
  D_Fvelocity_c = 1;
}
void goomf_ui::cb_D_Fvelocity(Fl_Button* o, void* v) {
  ((goomf_ui*)(o->parent()->parent()->user_data()))->cb_D_Fvelocity_i(o,v);
}

void goomf_ui::cb_BankWindow_i(Fl_Double_Window* o, void*) {
  o->hide();
}
void goomf_ui::cb_BankWindow(Fl_Double_Window* o, void* v) {
  ((goomf_ui*)(o->user_data()))->cb_BankWindow_i(o,v);
}

void goomf_ui::cb_NewB_i(Fl_Menu_*, void*) {
  ready=4;
}
void goomf_ui::cb_NewB(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_NewB_i(o,v);
}

void goomf_ui::cb_Load_Bank_i(Fl_Menu_*, void*) {
  char *filename;
filename=fl_file_chooser("Browse:","(*.goomf)",DATADIR,0);
if (filename==NULL) return;
filename=fl_filename_setext(filename,".goomf");
setBankFile->copy_label(filename);
strcpy(uBankFilename,filename);
ready=1;
}
void goomf_ui::cb_Load_Bank(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_Load_Bank_i(o,v);
}

void goomf_ui::cb_Save_Bank_i(Fl_Menu_*, void*) {
  char *filename;
filename=fl_file_chooser("Browse:","(*.goomf)","",0);
if (filename==NULL) return;
filename=fl_filename_setext(filename,".goomf");
setBankFile->copy_label(filename);
strcpy(uBankFilename,filename);
ready=3;
}
void goomf_ui::cb_Save_Bank(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_Save_Bank_i(o,v);
}

void goomf_ui::cb_salirB_i(Fl_Menu_*, void*) {
  BankWindow->do_callback();
}
void goomf_ui::cb_salirB(Fl_Menu_* o, void* v) {
  ((goomf_ui*)(o->parent()->user_data()))->cb_salirB_i(o,v);
}

Fl_Menu_Item goomf_ui::menu_MenuB[] = {
 {gettext("&File"), 0,  0, 0, 64, FL_NORMAL_LABEL, 0, 14, 7},
 {gettext("New"), 0,  (Fl_Callback*)goomf_ui::cb_NewB, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {gettext("Load Bank"), 0,  (Fl_Callback*)goomf_ui::cb_Load_Bank, 0, 0, FL_NORMAL_LABEL, 0, 14, 0},
 {gettext("Save Bank"), 0,  (Fl_Callback*)goomf_ui::cb_Save_Bank, 0, 128, FL_NORMAL_LABEL, 0, 14, 0},
 {gettext("Close"), 0,  (Fl_Callback*)goomf_ui::cb_salirB, 0, 0, FL_NORMAL_LABEL, 0, 14, 7},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* goomf_ui::ArchivoB = goomf_ui::menu_MenuB + 0;
Fl_Menu_Item* goomf_ui::NewB = goomf_ui::menu_MenuB + 1;
Fl_Menu_Item* goomf_ui::Load_Bank = goomf_ui::menu_MenuB + 2;
Fl_Menu_Item* goomf_ui::Save_Bank = goomf_ui::menu_MenuB + 3;
Fl_Menu_Item* goomf_ui::salirB = goomf_ui::menu_MenuB + 4;

goomf_ui::goomf_ui() {
  fl_open_display();
Fl::visual(FL_DOUBLE|FL_RGB);
fl_register_images();
make_window();
ui_win->xclass("goomf");
ready=1;
OP1->value(1);
ui_win->show();
void * v=MT;
Fl::add_timeout(1.0 * 0.04,tick,v);
}

Fl_Double_Window* goomf_ui::make_window() {
  { ui_win = new Fl_Double_Window(500, 580);
    ui_win->color((Fl_Color)137);
    ui_win->callback((Fl_Callback*)cb_ui_win, (void*)(this));
    { Fl_Menu_Bar* o = new Fl_Menu_Bar(0, 0, 500, 25);
      o->box(FL_BORDER_BOX);
      o->color((Fl_Color)138);
      o->selection_color((Fl_Color)4);
      o->labelsize(18);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      o->textsize(18);
      o->menu(menu_);
    } // Fl_Menu_Bar* o
    { d_osc_label = new Fl_Box(10, 510, 480, 20, gettext("OSC Dir"));
      d_osc_label->labelsize(11);
      d_osc_label->labelcolor((Fl_Color)3);
    } // Fl_Box* d_osc_label
    { setBankFile = new Fl_Box(10, 493, 480, 17, gettext("Default"));
      setBankFile->labelsize(11);
      setBankFile->labelcolor((Fl_Color)3);
    } // Fl_Box* setBankFile
    { Fl_Box* o = new Fl_Box(360, 558, 135, 17, gettext("<c>2009 by Josep Andreu"));
      o->labelsize(9);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(375, 531, 110, 29, gettext("GooMF"));
      o->labelfont(1);
      o->labelsize(21);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { MT = new Fl_Box(355, 129, 20, 16);
      MT->labelsize(11);
    } // Fl_Box* MT
    { Rueda* o = D_Vol = new Rueda(10, 70, 50, 60, gettext("Volume"));
      D_Vol->box(FL_FLAT_BOX);
      D_Vol->color((Fl_Color)137);
      D_Vol->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_Vol->labeltype(FL_NORMAL_LABEL);
      D_Vol->labelfont(0);
      D_Vol->labelsize(11);
      D_Vol->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Vol->step(0.01);
      D_Vol->value(1);
      D_Vol->callback((Fl_Callback*)cb_D_Vol);
      D_Vol->align(FL_ALIGN_TOP);
      D_Vol->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%1.2f");
    } // Rueda* D_Vol
    { Rueda* o = D_Tune = new Rueda(80, 70, 50, 60, gettext("Master Tune"));
      D_Tune->box(FL_FLAT_BOX);
      D_Tune->color((Fl_Color)137);
      D_Tune->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_Tune->labeltype(FL_NORMAL_LABEL);
      D_Tune->labelfont(0);
      D_Tune->labelsize(11);
      D_Tune->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Tune->minimum(-1);
      D_Tune->step(0.01);
      D_Tune->callback((Fl_Callback*)cb_D_Tune);
      D_Tune->align(FL_ALIGN_TOP);
      D_Tune->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%1.2f");
    } // Rueda* D_Tune
    { Rueda* o = D_Portamento = new Rueda(150, 70, 50, 60, gettext("Portamento"));
      D_Portamento->box(FL_FLAT_BOX);
      D_Portamento->color((Fl_Color)137);
      D_Portamento->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_Portamento->labeltype(FL_NORMAL_LABEL);
      D_Portamento->labelfont(0);
      D_Portamento->labelsize(11);
      D_Portamento->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Portamento->step(0.01);
      D_Portamento->callback((Fl_Callback*)cb_D_Portamento);
      D_Portamento->align(FL_ALIGN_TOP);
      D_Portamento->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%1.2f");
    } // Rueda* D_Portamento
    { Fl_Group* o = new Fl_Group(10, 285, 480, 210, gettext("Operator Parameters"));
      o->box(FL_BORDER_BOX);
      o->color((Fl_Color)138);
      o->labelfont(1);
      o->labelcolor((Fl_Color)5);
      { Rueda* o = D_Wave = new Rueda(30, 310, 50, 60, gettext("Wave"));
        D_Wave->box(FL_FLAT_BOX);
        D_Wave->color((Fl_Color)138);
        D_Wave->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Wave->labeltype(FL_NORMAL_LABEL);
        D_Wave->labelfont(0);
        D_Wave->labelsize(11);
        D_Wave->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Wave->minimum(1);
        D_Wave->maximum(9);
        D_Wave->step(1);
        D_Wave->value(1);
        D_Wave->callback((Fl_Callback*)cb_D_Wave);
        D_Wave->align(FL_ALIGN_TOP);
        D_Wave->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_Wave
      { Rueda* o = D_H = new Rueda(95, 310, 50, 60, gettext("Harmonic"));
        D_H->box(FL_FLAT_BOX);
        D_H->color((Fl_Color)138);
        D_H->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_H->labeltype(FL_NORMAL_LABEL);
        D_H->labelfont(0);
        D_H->labelsize(11);
        D_H->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_H->maximum(21);
        D_H->step(1);
        D_H->callback((Fl_Callback*)cb_D_H);
        D_H->align(FL_ALIGN_TOP);
        D_H->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%2.0f");
      } // Rueda* D_H
      { Rueda* o = D_HF = new Rueda(160, 310, 50, 60, gettext("H.Fine"));
        D_HF->box(FL_FLAT_BOX);
        D_HF->color((Fl_Color)138);
        D_HF->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_HF->labeltype(FL_NORMAL_LABEL);
        D_HF->labelfont(0);
        D_HF->labelsize(11);
        D_HF->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_HF->minimum(-0.02);
        D_HF->maximum(0.02);
        D_HF->step(0.0001);
        D_HF->callback((Fl_Callback*)cb_D_HF);
        D_HF->align(FL_ALIGN_TOP);
        D_HF->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.4f");
      } // Rueda* D_HF
      { Rueda* o = D_OVol = new Rueda(225, 310, 50, 60, gettext("Volume"));
        D_OVol->box(FL_FLAT_BOX);
        D_OVol->color((Fl_Color)138);
        D_OVol->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_OVol->labeltype(FL_NORMAL_LABEL);
        D_OVol->labelfont(0);
        D_OVol->labelsize(11);
        D_OVol->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_OVol->step(0.01);
        D_OVol->callback((Fl_Callback*)cb_D_OVol);
        D_OVol->align(FL_ALIGN_TOP);
        D_OVol->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_OVol
      { Rueda* o = D_pLFO = new Rueda(290, 310, 50, 60, gettext("pLFO"));
        D_pLFO->box(FL_FLAT_BOX);
        D_pLFO->color((Fl_Color)138);
        D_pLFO->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_pLFO->labeltype(FL_NORMAL_LABEL);
        D_pLFO->labelfont(0);
        D_pLFO->labelsize(11);
        D_pLFO->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_pLFO->step(0.01);
        D_pLFO->callback((Fl_Callback*)cb_D_pLFO);
        D_pLFO->align(FL_ALIGN_TOP);
        D_pLFO->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_pLFO
      { Rueda* o = D_Attack = new Rueda(30, 405, 50, 60, gettext("Attack"));
        D_Attack->box(FL_FLAT_BOX);
        D_Attack->color((Fl_Color)138);
        D_Attack->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Attack->labeltype(FL_NORMAL_LABEL);
        D_Attack->labelfont(0);
        D_Attack->labelsize(11);
        D_Attack->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Attack->minimum(0.01);
        D_Attack->maximum(4);
        D_Attack->step(0.01);
        D_Attack->value(0.01);
        D_Attack->callback((Fl_Callback*)cb_D_Attack);
        D_Attack->align(FL_ALIGN_TOP);
        D_Attack->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Attack
      { Rueda* o = D_Decay = new Rueda(95, 405, 50, 60, gettext("Decay"));
        D_Decay->box(FL_FLAT_BOX);
        D_Decay->color((Fl_Color)138);
        D_Decay->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Decay->labeltype(FL_NORMAL_LABEL);
        D_Decay->labelfont(0);
        D_Decay->labelsize(11);
        D_Decay->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Decay->minimum(0.01);
        D_Decay->maximum(4);
        D_Decay->step(0.01);
        D_Decay->value(0.01);
        D_Decay->callback((Fl_Callback*)cb_D_Decay);
        D_Decay->align(FL_ALIGN_TOP);
        D_Decay->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Decay
      { Rueda* o = D_Sustain = new Rueda(160, 405, 50, 60, gettext("Sustain"));
        D_Sustain->box(FL_FLAT_BOX);
        D_Sustain->color((Fl_Color)138);
        D_Sustain->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Sustain->labeltype(FL_NORMAL_LABEL);
        D_Sustain->labelfont(0);
        D_Sustain->labelsize(11);
        D_Sustain->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Sustain->step(0.01);
        D_Sustain->value(0.5);
        D_Sustain->callback((Fl_Callback*)cb_D_Sustain);
        D_Sustain->align(FL_ALIGN_TOP);
        D_Sustain->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Sustain
      { Rueda* o = D_Release = new Rueda(225, 405, 50, 60, gettext("Release"));
        D_Release->box(FL_FLAT_BOX);
        D_Release->color((Fl_Color)138);
        D_Release->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Release->labeltype(FL_NORMAL_LABEL);
        D_Release->labelfont(0);
        D_Release->labelsize(11);
        D_Release->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Release->minimum(0.01);
        D_Release->step(0.01);
        D_Release->value(0.01);
        D_Release->callback((Fl_Callback*)cb_D_Release);
        D_Release->align(FL_ALIGN_TOP);
        D_Release->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Release
      { Rueda* o = D_Algo = new Rueda(365, 405, 50, 60, gettext("Algorhytm"));
        D_Algo->box(FL_FLAT_BOX);
        D_Algo->color((Fl_Color)138);
        D_Algo->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Algo->labeltype(FL_NORMAL_LABEL);
        D_Algo->labelfont(0);
        D_Algo->labelsize(11);
        D_Algo->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Algo->minimum(1);
        D_Algo->maximum(2);
        D_Algo->step(1);
        D_Algo->value(1);
        D_Algo->callback((Fl_Callback*)cb_D_Algo);
        D_Algo->align(FL_ALIGN_TOP);
        D_Algo->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_Algo
      { Fl_Group* o = new Fl_Group(365, 315, 105, 65, gettext("Selector"));
        o->box(FL_BORDER_BOX);
        o->color((Fl_Color)138);
        o->labelfont(1);
        o->labelcolor((Fl_Color)5);
        { OP1 = new Fl_Button(375, 350, 25, 20, gettext("1"));
          OP1->type(102);
          OP1->box(FL_PLASTIC_UP_BOX);
          OP1->color((Fl_Color)48);
          OP1->selection_color((Fl_Color)3);
          OP1->callback((Fl_Callback*)cb_OP1);
          OP1->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP1
        { OP2 = new Fl_Button(375, 325, 25, 20, gettext("2"));
          OP2->type(102);
          OP2->box(FL_PLASTIC_UP_BOX);
          OP2->color((Fl_Color)48);
          OP2->selection_color((Fl_Color)3);
          OP2->callback((Fl_Callback*)cb_OP2);
          OP2->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP2
        { OP3 = new Fl_Button(405, 350, 25, 20, gettext("3"));
          OP3->type(102);
          OP3->box(FL_PLASTIC_UP_BOX);
          OP3->color((Fl_Color)48);
          OP3->selection_color((Fl_Color)3);
          OP3->callback((Fl_Callback*)cb_OP3);
          OP3->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP3
        { OP4 = new Fl_Button(405, 325, 25, 20, gettext("4"));
          OP4->type(102);
          OP4->box(FL_PLASTIC_UP_BOX);
          OP4->color((Fl_Color)48);
          OP4->selection_color((Fl_Color)3);
          OP4->callback((Fl_Callback*)cb_OP4);
          OP4->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP4
        { OP5 = new Fl_Button(435, 350, 25, 20, gettext("5"));
          OP5->type(102);
          OP5->box(FL_PLASTIC_UP_BOX);
          OP5->color((Fl_Color)48);
          OP5->selection_color((Fl_Color)3);
          OP5->callback((Fl_Callback*)cb_OP5);
          OP5->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP5
        { OP6 = new Fl_Button(435, 325, 25, 20, gettext("6"));
          OP6->type(102);
          OP6->box(FL_PLASTIC_UP_BOX);
          OP6->color((Fl_Color)48);
          OP6->selection_color((Fl_Color)3);
          OP6->callback((Fl_Callback*)cb_OP6);
          OP6->when(FL_WHEN_CHANGED);
        } // Fl_Button* OP6
        o->end();
      } // Fl_Group* o
      o->end();
    } // Fl_Group* o
    { LFO = new Fl_Group(225, 50, 265, 100, gettext("LFO"));
      LFO->box(FL_BORDER_BOX);
      LFO->color((Fl_Color)138);
      LFO->labelfont(1);
      LFO->labelcolor((Fl_Color)5);
      { Rueda* o = D_LFO_Frequency = new Rueda(305, 70, 50, 60, gettext("Frequency"));
        D_LFO_Frequency->box(FL_FLAT_BOX);
        D_LFO_Frequency->color((Fl_Color)138);
        D_LFO_Frequency->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_LFO_Frequency->labeltype(FL_NORMAL_LABEL);
        D_LFO_Frequency->labelfont(0);
        D_LFO_Frequency->labelsize(11);
        D_LFO_Frequency->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_LFO_Frequency->step(0.01);
        D_LFO_Frequency->callback((Fl_Callback*)cb_D_LFO_Frequency);
        D_LFO_Frequency->align(FL_ALIGN_TOP);
        D_LFO_Frequency->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_LFO_Frequency
      { Rueda* o = D_LFO_Volume = new Rueda(240, 70, 50, 60, gettext("Volume"));
        D_LFO_Volume->box(FL_FLAT_BOX);
        D_LFO_Volume->color((Fl_Color)138);
        D_LFO_Volume->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_LFO_Volume->labeltype(FL_NORMAL_LABEL);
        D_LFO_Volume->labelfont(0);
        D_LFO_Volume->labelsize(11);
        D_LFO_Volume->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_LFO_Volume->step(0.01);
        D_LFO_Volume->callback((Fl_Callback*)cb_D_LFO_Volume);
        D_LFO_Volume->align(FL_ALIGN_TOP);
        D_LFO_Volume->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_LFO_Volume
      { Rueda* o = D_LFO_Delay = new Rueda(365, 70, 50, 60, gettext("Delay"));
        D_LFO_Delay->box(FL_FLAT_BOX);
        D_LFO_Delay->color((Fl_Color)138);
        D_LFO_Delay->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_LFO_Delay->labeltype(FL_NORMAL_LABEL);
        D_LFO_Delay->labelfont(0);
        D_LFO_Delay->labelsize(11);
        D_LFO_Delay->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_LFO_Delay->step(0.01);
        D_LFO_Delay->callback((Fl_Callback*)cb_D_LFO_Delay);
        D_LFO_Delay->align(FL_ALIGN_TOP);
        D_LFO_Delay->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_LFO_Delay
      { Rueda* o = D_LFO_Wave = new Rueda(425, 70, 50, 60, gettext("Wave"));
        D_LFO_Wave->box(FL_FLAT_BOX);
        D_LFO_Wave->color((Fl_Color)138);
        D_LFO_Wave->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_LFO_Wave->labeltype(FL_NORMAL_LABEL);
        D_LFO_Wave->labelfont(0);
        D_LFO_Wave->labelsize(11);
        D_LFO_Wave->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_LFO_Wave->minimum(1);
        D_LFO_Wave->maximum(9);
        D_LFO_Wave->step(1);
        D_LFO_Wave->value(1);
        D_LFO_Wave->callback((Fl_Callback*)cb_D_LFO_Wave);
        D_LFO_Wave->align(FL_ALIGN_TOP);
        D_LFO_Wave->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_LFO_Wave
      LFO->end();
    } // Fl_Group* LFO
    { PresetSelect = new Fl_Counter(20, 550, 60, 25, gettext("Preset"));
      PresetSelect->type(1);
      PresetSelect->box(FL_BORDER_BOX);
      PresetSelect->selection_color((Fl_Color)FL_FOREGROUND_COLOR);
      PresetSelect->labelfont(1);
      PresetSelect->labelcolor((Fl_Color)5);
      PresetSelect->minimum(0);
      PresetSelect->maximum(40);
      PresetSelect->step(1);
      PresetSelect->textfont(1);
      PresetSelect->textcolor((Fl_Color)5);
      PresetSelect->callback((Fl_Callback*)cb_PresetSelect);
      PresetSelect->align(FL_ALIGN_TOP);
    } // Fl_Counter* PresetSelect
    { Pname = new Fl_Input(95, 535, 255, 40);
      Pname->box(FL_BORDER_BOX);
      Pname->color((Fl_Color)6);
      Pname->labelfont(1);
      Pname->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      Pname->textsize(22);
      Pname->textcolor((Fl_Color)5);
      Pname->when(FL_WHEN_CHANGED);
    } // Fl_Input* Pname
    { Fl_Group* o = new Fl_Group(10, 170, 480, 95, gettext("Filter"));
      o->box(FL_BORDER_BOX);
      o->color((Fl_Color)138);
      o->labelfont(1);
      o->labelcolor((Fl_Color)5);
      { Rueda* o = D_Ftype = new Rueda(20, 190, 50, 60, gettext("Type"));
        D_Ftype->box(FL_FLAT_BOX);
        D_Ftype->color((Fl_Color)138);
        D_Ftype->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Ftype->labeltype(FL_NORMAL_LABEL);
        D_Ftype->labelfont(0);
        D_Ftype->labelsize(11);
        D_Ftype->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Ftype->maximum(8);
        D_Ftype->step(1);
        D_Ftype->callback((Fl_Callback*)cb_D_Ftype);
        D_Ftype->align(FL_ALIGN_TOP);
        D_Ftype->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_Ftype
      { Rueda* o = D_Fgain = new Rueda(80, 190, 50, 60, gettext("Gain"));
        D_Fgain->box(FL_FLAT_BOX);
        D_Fgain->color((Fl_Color)138);
        D_Fgain->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Fgain->labeltype(FL_NORMAL_LABEL);
        D_Fgain->labelfont(0);
        D_Fgain->labelsize(11);
        D_Fgain->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Fgain->step(0.01);
        D_Fgain->value(0.5);
        D_Fgain->callback((Fl_Callback*)cb_D_Fgain);
        D_Fgain->align(FL_ALIGN_TOP);
        D_Fgain->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Fgain
      { Rueda* o = D_Fcutoff = new Rueda(140, 190, 50, 60, gettext("Cutoff"));
        D_Fcutoff->box(FL_FLAT_BOX);
        D_Fcutoff->color((Fl_Color)138);
        D_Fcutoff->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Fcutoff->labeltype(FL_NORMAL_LABEL);
        D_Fcutoff->labelfont(0);
        D_Fcutoff->labelsize(11);
        D_Fcutoff->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Fcutoff->minimum(21);
        D_Fcutoff->maximum(10020);
        D_Fcutoff->step(0.1);
        D_Fcutoff->value(5020.5);
        D_Fcutoff->callback((Fl_Callback*)cb_D_Fcutoff);
        D_Fcutoff->align(FL_ALIGN_TOP);
        D_Fcutoff->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%5.1f");
      } // Rueda* D_Fcutoff
      { Rueda* o = D_Fq = new Rueda(200, 190, 50, 60, gettext("Resonance"));
        D_Fq->box(FL_FLAT_BOX);
        D_Fq->color((Fl_Color)138);
        D_Fq->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Fq->labeltype(FL_NORMAL_LABEL);
        D_Fq->labelfont(0);
        D_Fq->labelsize(11);
        D_Fq->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Fq->minimum(-1);
        D_Fq->step(0.01);
        D_Fq->callback((Fl_Callback*)cb_D_Fq);
        D_Fq->align(FL_ALIGN_TOP);
        D_Fq->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_Fq
      { Rueda* o = D_FLFO = new Rueda(260, 190, 50, 60, gettext("LFO"));
        D_FLFO->box(FL_FLAT_BOX);
        D_FLFO->color((Fl_Color)138);
        D_FLFO->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_FLFO->labeltype(FL_NORMAL_LABEL);
        D_FLFO->labelfont(0);
        D_FLFO->labelsize(11);
        D_FLFO->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_FLFO->step(0.01);
        D_FLFO->callback((Fl_Callback*)cb_D_FLFO);
        D_FLFO->align(FL_ALIGN_TOP);
        D_FLFO->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.2f");
      } // Rueda* D_FLFO
      { Rueda* o = D_FADSR = new Rueda(320, 190, 50, 60, gettext("ADSR"));
        D_FADSR->box(FL_FLAT_BOX);
        D_FADSR->color((Fl_Color)138);
        D_FADSR->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_FADSR->labeltype(FL_NORMAL_LABEL);
        D_FADSR->labelfont(0);
        D_FADSR->labelsize(11);
        D_FADSR->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_FADSR->maximum(6);
        D_FADSR->step(1);
        D_FADSR->callback((Fl_Callback*)cb_D_FADSR);
        D_FADSR->align(FL_ALIGN_TOP);
        D_FADSR->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_FADSR
      { Rueda* o = D_Fstages = new Rueda(380, 190, 50, 60, gettext("Stages"));
        D_Fstages->box(FL_FLAT_BOX);
        D_Fstages->color((Fl_Color)138);
        D_Fstages->selection_color((Fl_Color)FL_INACTIVE_COLOR);
        D_Fstages->labeltype(FL_NORMAL_LABEL);
        D_Fstages->labelfont(0);
        D_Fstages->labelsize(11);
        D_Fstages->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        D_Fstages->minimum(1);
        D_Fstages->maximum(5);
        D_Fstages->step(1);
        D_Fstages->value(1);
        D_Fstages->callback((Fl_Callback*)cb_D_Fstages);
        D_Fstages->align(FL_ALIGN_TOP);
        D_Fstages->when(FL_WHEN_CHANGED);
        strcpy(o->theformat,"%1.0f");
      } // Rueda* D_Fstages
      { D_Fvelocity = new Fl_Button(435, 240, 50, 20, gettext("Velocity"));
        D_Fvelocity->type(1);
        D_Fvelocity->box(FL_PLASTIC_UP_BOX);
        D_Fvelocity->selection_color((Fl_Color)3);
        D_Fvelocity->labelsize(11);
        D_Fvelocity->callback((Fl_Callback*)cb_D_Fvelocity);
        D_Fvelocity->when(FL_WHEN_CHANGED);
      } // Fl_Button* D_Fvelocity
      { Flabel = new Fl_Box(435, 173, 50, 34);
        Flabel->labelsize(10);
        Flabel->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        Flabel->align(FL_ALIGN_WRAP|FL_ALIGN_INSIDE);
      } // Fl_Box* Flabel
      o->end();
    } // Fl_Group* o
    ui_win->end();
  } // Fl_Double_Window* ui_win
  { BankWindow = new Fl_Double_Window(800, 600, gettext("goomf - Bank"));
    BankWindow->color((Fl_Color)138);
    BankWindow->selection_color((Fl_Color)FL_BACKGROUND2_COLOR);
    BankWindow->callback((Fl_Callback*)cb_BankWindow, (void*)(this));
    { MenuB = new Fl_Menu_Bar(0, 0, 800, 20);
      MenuB->down_box(FL_DOWN_BOX);
      MenuB->color((Fl_Color)138);
      MenuB->selection_color((Fl_Color)FL_BACKGROUND2_COLOR);
      MenuB->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      MenuB->textcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      MenuB->menu(menu_MenuB);
    } // Fl_Menu_Bar* MenuB
    { ob = new Fl_Group(0, 20, 800, 580);
      ob->labelsize(18);
      ob->end();
    } // Fl_Group* ob
    BankWindow->size_range(640, 480, 3200, 2400);
    BankWindow->end();
    BankWindow->resizable(BankWindow);
  } // Fl_Double_Window* BankWindow
  return BankWindow;
}

void goomf_ui::tick(void* v) {
  Fl_Box *o = (Fl_Box*)v;
o->do_callback();
Fl::repeat_timeout(1.0 * 0.04,tick,v);
}
