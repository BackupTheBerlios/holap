// generated by Fast Light User Interface Designer (fluid) version 1.0110

#include <libintl.h>
#include "holharm_ui.h"

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


// if (Fl::focus() == this) box(FL_THIN_UP_BOX); else box(FL_FLAT_BOX);


draw_box(box(), ox, oy, ww, hh, color());

temp->draw(ox,oy,ww,hh,paso*ww,0);


// format(buf);

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
    redraw();
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

return i;
}

void holharm_ui::cb_ui_win_i(Fl_Double_Window*, void*) {
  Pexitprogram=1;
}
void holharm_ui::cb_ui_win(Fl_Double_Window* o, void* v) {
  ((holharm_ui*)(o->user_data()))->cb_ui_win_i(o,v);
}

void holharm_ui::cb_D_Wet_i(Rueda*, void*) {
  D_Wet_c=1;
}
void holharm_ui::cb_D_Wet(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_Wet_i(o,v);
}

void holharm_ui::cb_D_Vol_i(Rueda*, void*) {
  D_Vol_c=1;
}
void holharm_ui::cb_D_Vol(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_Vol_i(o,v);
}

void holharm_ui::cb_D_Pan_i(Rueda*, void*) {
  D_Pan_c=1;
}
void holharm_ui::cb_D_Pan(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_Pan_i(o,v);
}

void holharm_ui::cb_D_IntR_i(Rueda*, void*) {
  D_IntR_c=1;
}
void holharm_ui::cb_D_IntR(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_IntR_i(o,v);
}

void holharm_ui::cb_D_IntL_i(Rueda*, void*) {
  D_IntL_c=1;
}
void holharm_ui::cb_D_IntL(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_IntL_i(o,v);
}

void holharm_ui::cb_D_IntRL_i(Rueda*, void*) {
  D_IntRL_c=1;
}
void holharm_ui::cb_D_IntRL(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_IntRL_i(o,v);
}

void holharm_ui::cb_q4_i(Fl_Check_Button*, void*) {
  SaveConfig(4);
fl_message("Restart the plugin to take effect this changes");
}
void holharm_ui::cb_q4(Fl_Check_Button* o, void* v) {
  ((holharm_ui*)(o->parent()->parent()->user_data()))->cb_q4_i(o,v);
}

void holharm_ui::cb_q8_i(Fl_Check_Button* o, void*) {
  int i;
i=fl_choice("You need a good CPU to operate with this changes, Continue?", "No","Yes",NULL);

if (i)
{
SaveConfig(8);
fl_message("Restart the plugin to take effect this changes");
}

else
{
o->value(0);
Qadjust(SQuality);
};
}
void holharm_ui::cb_q8(Fl_Check_Button* o, void* v) {
  ((holharm_ui*)(o->parent()->parent()->user_data()))->cb_q8_i(o,v);
}

void holharm_ui::cb_q16_i(Fl_Check_Button* o, void*) {
  int i;
i=fl_choice("You need a really good CPU to operate with this changes, Continue?", "No","Yes",NULL);

if (i)
{
SaveConfig(16);
fl_message("Restart the plugin to take effect this changes");
}
else
{
o->value(0);
Qadjust(SQuality);
};
}
void holharm_ui::cb_q16(Fl_Check_Button* o, void* v) {
  ((holharm_ui*)(o->parent()->parent()->user_data()))->cb_q16_i(o,v);
}

void holharm_ui::cb_D_Type_i(Fl_Choice*, void*) {
  D_Type_c=1;
}
void holharm_ui::cb_D_Type(Fl_Choice* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_Type_i(o,v);
}

void holharm_ui::cb_D_Note_i(Fl_Choice*, void*) {
  D_Note_c=1;
}
void holharm_ui::cb_D_Note(Fl_Choice* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_Note_i(o,v);
}

void holharm_ui::cb_D_ChType_i(Fl_Choice*, void*) {
  D_ChType_c=1;
}
void holharm_ui::cb_D_ChType(Fl_Choice* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_ChType_i(o,v);
}

void holharm_ui::cb_D_recocount_i(Rueda*, void*) {
  D_recocount_c=1;
}
void holharm_ui::cb_D_recocount(Rueda* o, void* v) {
  ((holharm_ui*)(o->parent()->user_data()))->cb_D_recocount_i(o,v);
}

holharm_ui::holharm_ui() {
  fl_open_display();
Fl::visual(FL_DOUBLE|FL_RGB);
fl_register_images();
make_window();
ui_win->xclass("holharm");
ui_win->show();
void * v=MT;
Fl::add_timeout(1.0 * 0.04,tick,v);
}

Fl_Double_Window* holharm_ui::make_window() {
  { ui_win = new Fl_Double_Window(390, 322, gettext("holharm"));
    ui_win->color((Fl_Color)147);
    ui_win->callback((Fl_Callback*)cb_ui_win, (void*)(this));
    { d_osc_label = new Fl_Box(0, -2, 390, 22);
      d_osc_label->labelsize(9);
      d_osc_label->labelcolor((Fl_Color)3);
    } // Fl_Box* d_osc_label
    { Fl_Box* o = new Fl_Box(220, 48, 165, 22, gettext("<c> 2008-2009 by Josep Andreu"));
      o->labelsize(9);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { Fl_Box* o = new Fl_Box(230, 22, 145, 28, gettext("Holharm"));
      o->labelfont(1);
      o->labelsize(21);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { MT = new Fl_Box(280, 354, 120, 16);
      MT->labelsize(11);
    } // Fl_Box* MT
    { Rueda* o = D_Wet = new Rueda(10, 44, 50, 60, gettext("Dry"));
      D_Wet->box(FL_FLAT_BOX);
      D_Wet->color((Fl_Color)147);
      D_Wet->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_Wet->labeltype(FL_NORMAL_LABEL);
      D_Wet->labelfont(0);
      D_Wet->labelsize(11);
      D_Wet->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Wet->step(0.01);
      D_Wet->callback((Fl_Callback*)cb_D_Wet);
      D_Wet->align(FL_ALIGN_TOP);
      D_Wet->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%1.2f");
    } // Rueda* D_Wet
    { Rueda* o = D_Vol = new Rueda(80, 44, 50, 60, gettext("Volume"));
      D_Vol->box(FL_FLAT_BOX);
      D_Vol->color((Fl_Color)147);
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
    { Rueda* o = D_Pan = new Rueda(150, 44, 50, 60, gettext("Pan"));
      D_Pan->box(FL_FLAT_BOX);
      D_Pan->color((Fl_Color)147);
      D_Pan->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_Pan->labeltype(FL_NORMAL_LABEL);
      D_Pan->labelfont(0);
      D_Pan->labelsize(11);
      D_Pan->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Pan->step(0.01);
      D_Pan->value(0.5);
      D_Pan->callback((Fl_Callback*)cb_D_Pan);
      D_Pan->align(FL_ALIGN_TOP);
      D_Pan->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%1.2f");
    } // Rueda* D_Pan
    { Rueda* o = D_IntR = new Rueda(80, 139, 50, 60, gettext("Interval R"));
      D_IntR->box(FL_FLAT_BOX);
      D_IntR->color((Fl_Color)147);
      D_IntR->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_IntR->labeltype(FL_NORMAL_LABEL);
      D_IntR->labelfont(0);
      D_IntR->labelsize(11);
      D_IntR->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_IntR->minimum(-12);
      D_IntR->maximum(12);
      D_IntR->step(1);
      D_IntR->callback((Fl_Callback*)cb_D_IntR);
      D_IntR->align(FL_ALIGN_TOP);
      D_IntR->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%2.0f");
    } // Rueda* D_IntR
    { Rueda* o = D_IntL = new Rueda(10, 139, 50, 60, gettext("Interval L"));
      D_IntL->box(FL_FLAT_BOX);
      D_IntL->color((Fl_Color)147);
      D_IntL->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_IntL->labeltype(FL_NORMAL_LABEL);
      D_IntL->labelfont(0);
      D_IntL->labelsize(11);
      D_IntL->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_IntL->minimum(-12);
      D_IntL->maximum(12);
      D_IntL->step(1);
      D_IntL->callback((Fl_Callback*)cb_D_IntL);
      D_IntL->align(FL_ALIGN_TOP);
      D_IntL->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%2.0f");
    } // Rueda* D_IntL
    { Rueda* o = D_IntRL = new Rueda(150, 139, 50, 60, gettext("Interval L+R"));
      D_IntRL->box(FL_FLAT_BOX);
      D_IntRL->color((Fl_Color)147);
      D_IntRL->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_IntRL->labeltype(FL_NORMAL_LABEL);
      D_IntRL->labelfont(0);
      D_IntRL->labelsize(11);
      D_IntRL->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_IntRL->minimum(-12);
      D_IntRL->maximum(12);
      D_IntRL->step(1);
      D_IntRL->callback((Fl_Callback*)cb_D_IntRL);
      D_IntRL->align(FL_ALIGN_TOP);
      D_IntRL->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%2.0f");
    } // Rueda* D_IntRL
    { Fl_Box* o = new Fl_Box(225, 124, 145, 21, gettext("Mode"));
      o->labelsize(11);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { ShowMode = new Fl_Box(235, 147, 145, 33, gettext("Normal"));
      ShowMode->box(FL_PLASTIC_THIN_DOWN_BOX);
      ShowMode->color((Fl_Color)147);
      ShowMode->labelcolor((Fl_Color)4);
    } // Fl_Box* ShowMode
    { Fl_Box* o = new Fl_Box(225, 188, 145, 21, gettext("Selected Chord"));
      o->labelsize(11);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { SelectedChord = new Fl_Box(235, 211, 145, 32);
      SelectedChord->box(FL_PLASTIC_THIN_DOWN_BOX);
      SelectedChord->color((Fl_Color)147);
      SelectedChord->labelcolor((Fl_Color)1);
    } // Fl_Box* SelectedChord
    { Fl_Box* o = new Fl_Box(225, 254, 145, 21, gettext("MIDI Chord"));
      o->labelsize(11);
      o->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
    } // Fl_Box* o
    { ShowChord = new Fl_Box(235, 277, 145, 31);
      ShowChord->box(FL_PLASTIC_THIN_DOWN_BOX);
      ShowChord->color((Fl_Color)147);
      ShowChord->labelcolor((Fl_Color)168);
    } // Fl_Box* ShowChord
    { Quality = new Fl_Group(225, 90, 155, 30, gettext("Quality"));
      Quality->box(FL_DOWN_BOX);
      Quality->color((Fl_Color)147);
      Quality->labelsize(10);
      Quality->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      { q4 = new Fl_Check_Button(230, 95, 40, 20, gettext("Poor"));
        q4->type(102);
        q4->down_box(FL_DOWN_BOX);
        q4->labelsize(10);
        q4->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        q4->callback((Fl_Callback*)cb_q4);
        q4->when(FL_WHEN_CHANGED);
      } // Fl_Check_Button* q4
      { q8 = new Fl_Check_Button(280, 95, 45, 20, gettext("Fine"));
        q8->type(102);
        q8->down_box(FL_DOWN_BOX);
        q8->labelsize(10);
        q8->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        q8->callback((Fl_Callback*)cb_q8);
        q8->when(FL_WHEN_CHANGED);
      } // Fl_Check_Button* q8
      { q16 = new Fl_Check_Button(330, 95, 40, 20, gettext("Good"));
        q16->type(102);
        q16->down_box(FL_DOWN_BOX);
        q16->labelsize(10);
        q16->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
        q16->callback((Fl_Callback*)cb_q16);
        q16->when(FL_WHEN_CHANGED);
      } // Fl_Check_Button* q16
      Quality->end();
    } // Fl_Group* Quality
    { D_Type = new Fl_Choice(130, 220, 90, 20, gettext("Mode"));
      D_Type->box(FL_PLASTIC_THIN_DOWN_BOX);
      D_Type->down_box(FL_UP_BOX);
      D_Type->color((Fl_Color)14);
      D_Type->selection_color((Fl_Color)147);
      D_Type->labelsize(11);
      D_Type->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Type->textsize(11);
      D_Type->callback((Fl_Callback*)cb_D_Type);
    } // Fl_Choice* D_Type
    { D_Note = new Fl_Choice(130, 255, 90, 20, gettext("Base"));
      D_Note->box(FL_PLASTIC_THIN_DOWN_BOX);
      D_Note->down_box(FL_UP_BOX);
      D_Note->color((Fl_Color)14);
      D_Note->selection_color((Fl_Color)147);
      D_Note->labelsize(11);
      D_Note->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_Note->textsize(11);
      D_Note->callback((Fl_Callback*)cb_D_Note);
    } // Fl_Choice* D_Note
    { D_ChType = new Fl_Choice(130, 285, 90, 20, gettext("Chord"));
      D_ChType->box(FL_PLASTIC_THIN_DOWN_BOX);
      D_ChType->down_box(FL_UP_BOX);
      D_ChType->color((Fl_Color)14);
      D_ChType->selection_color((Fl_Color)147);
      D_ChType->labelsize(11);
      D_ChType->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_ChType->textsize(11);
      D_ChType->callback((Fl_Callback*)cb_D_ChType);
    } // Fl_Choice* D_ChType
    { Rueda* o = D_recocount = new Rueda(10, 234, 50, 60, gettext("Rec. Times"));
      D_recocount->box(FL_FLAT_BOX);
      D_recocount->color((Fl_Color)147);
      D_recocount->selection_color((Fl_Color)FL_INACTIVE_COLOR);
      D_recocount->labeltype(FL_NORMAL_LABEL);
      D_recocount->labelfont(0);
      D_recocount->labelsize(11);
      D_recocount->labelcolor((Fl_Color)FL_BACKGROUND2_COLOR);
      D_recocount->minimum(1);
      D_recocount->maximum(48);
      D_recocount->step(1);
      D_recocount->value(24);
      D_recocount->callback((Fl_Callback*)cb_D_recocount);
      D_recocount->align(FL_ALIGN_TOP);
      D_recocount->when(FL_WHEN_CHANGED);
      strcpy(o->theformat,"%2.0f");
    } // Rueda* D_recocount
    ui_win->end();
  } // Fl_Double_Window* ui_win
  return ui_win;
}

void holharm_ui::tick(void* v) {
  Fl_Box *o = (Fl_Box*)v;
o->do_callback();
Fl::repeat_timeout(1.0 * 0.04,tick,v);
}

void holharm_ui::quit() {
  Pexitprogram=1;
exit(0);
}

void holharm_ui::Qadjust(int Quality) {
  switch(Quality)
{
   case 4:
      q4->value(1);
      SQuality=4;
      break;
   case 8:
      q8->value(1);
      SQuality=8;
      break;
   case 16:
      q16->value(1);
      SQuality=16;
      break;
}
}

void holharm_ui::SaveConfig(int Quality) {
  FILE *fs;
   char temp[32];
   char filename[128];
   sprintf (filename, "/home/%s/.holharm", getenv ("USER"));
   fs = fopen (filename, "w");
   bzero (temp, sizeof (temp));
   sprintf (temp, "%d", Quality);
   fputs (temp, fs);
   fclose (fs);
   SQuality=Quality;
}
