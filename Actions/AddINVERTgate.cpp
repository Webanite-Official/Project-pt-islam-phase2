#include "AddINVERTgate.h"
#include "..\ApplicationManager.h"

AddINVERTgate::AddINVERTgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddINVERTgate::~AddINVERTgate(void)
{
}

void AddINVERTgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("1-Input INVERT Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddINVERTgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the INVERT gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INVERT* pA = new INVERT(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddINVERTgate::Undo()
{
}

void AddINVERTgate::Redo()
{
}


