#ifndef NEWPANEL_H
#define NEWPANEL_H

//(*Headers(NewPanel)
#include <wx/checkbox.h>
#include <wx/panel.h>
//*)

class NewPanel: public wxPanel
{
	public:

		NewPanel(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~NewPanel();

		//(*Declarations(NewPanel)
		wxCheckBox* CheckBox1;
		//*)

	protected:

		//(*Identifiers(NewPanel)
		static const long ID_CHECKBOX1;
		//*)

	private:

		//(*Handlers(NewPanel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
