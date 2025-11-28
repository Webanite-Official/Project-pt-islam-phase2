#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();
	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_AND2] = "images\\Menu\\and.jpg";
	MenuItemImages[ITM_OR2] = "images\\Menu\\or.jpg";
	MenuItemImages[ITM_NOT] = "images\\Menu\\not.jpg";
	MenuItemImages[ITM_NAND] = "images\\Menu\\nand.jpg";
	MenuItemImages[ITM_NOR] = "images\\Menu\\nor.jpg";
	MenuItemImages[ITM_XOR] = "images\\Menu\\xor.jpg";
	MenuItemImages[ITM_XNOR] = "images\\Menu\\xnor.jpg";
	MenuItemImages[ITM_AND3] = "images\\Menu\\and3.jpg";
	MenuItemImages[ITM_NOR3] = "images\\Menu\\nor3.jpg";
	MenuItemImages[ITM_XOR3] = "images\\Menu\\xor3.jpg";
	MenuItemImages[ITM_BUFFER] = "images\\Menu\\buffer.jpg";
	MenuItemImages[ITM_SWITCH] = "images\\Menu\\switch.jpg";
	MenuItemImages[ITM_LED] = "images\\Menu\\led.jpg";
	MenuItemImages[ITM_CONNECTION] = "images\\Menu\\connection.jpg";
	MenuItemImages[ITM_SIM_MODE] = "images\\Menu\\simulation.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
	string SIMItemImages[ITM_SIM_CNT];
	SIMItemImages[ITM_SIM] = "images\\Menu\\play.jpg";
	SIMItemImages[ITM_TRUTH] = "images\\Menu\\truth_table.jpg";
	SIMItemImages[ITM_EDIT] = "images\\Menu\\edit.jpg";
	SIMItemImages[ITM_DELETE] = "images\\Menu\\delete.jpg";
	SIMItemImages[ITM_COPY] = "images\\Menu\\copy.jpg";
	SIMItemImages[ITM_CUT] = "images\\Menu\\cut.jpg";
	SIMItemImages[ITM_PASTE] = "images\\Menu\\paste.jpg";
	SIMItemImages[ITM_UNDO] = "images\\Menu\\undo.jpg";
	SIMItemImages[ITM_REDO] = "images\\Menu\\redo.jpg";
	SIMItemImages[ITM_PAUSE] = "images\\Menu\\pause.jpg";
	SIMItemImages[ITM_SAVE] = "images\\Menu\\save.jpg";
	SIMItemImages[ITM_LOAD] = "images\\Menu\\load.jpg";


	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(SIMItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);


}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\and (2).jpg";
	else
		GateImage = "Images\\Gates\\and.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNAND(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\nand (2).jpg";
	else
		GateImage = "Images\\Gates\\nand.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\or (2).jpg";
	else
		GateImage = "Images\\Gates\\or.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\nor (2).jpg";
	else
		GateImage = "Images\\Gates\\nor.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\nor3 (2).jpg";
	else
		GateImage = "Images\\Gates\\nor3.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawNOT(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\not (2).jpg";
	else
		GateImage = "Images\\Gates\\not.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\and3 (2).jpg";
	else
		GateImage = "Images\\Gates\\and3.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\xor (2).jpg";
	else
		GateImage = "Images\\Gates\\xor.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\xor3 (2).jpg";
	else
		GateImage = "Images\\Gates\\xor3.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawXNOR(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\xnor (2).jpg";
	else
		GateImage = "Images\\Gates\\xnor.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\buffer (2).jpg";
	else
		GateImage = "Images\\Gates\\buffer.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\led_on.jpg";
	else
		GateImage = "Images\\Gates\\led_off.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\switch_on.jpg";
	else
		GateImage = "Images\\Gates\\switch_off.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}



//TODO: Add similar functions to draw all components


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected, bool broken) const
{
	//TODO: Add code to draw connection
	double X1 = r_GfxInfo.x1, Y1 = r_GfxInfo.y1, X2 = r_GfxInfo.x2, Y2 = r_GfxInfo.y2;
	double midX = (X1 + X2) / 2;
	double midY = (Y1 + Y2) / 2;
	if (broken) 
	{
		pWind->SetPen(UI.SelectColor, 3);
		if (X1==X2) //vertical or horizontal line
		{
			pWind->DrawLine(X1, Y1, X2, midY);
			pWind->DrawLine(X2, midY + 10, X2, Y2);
			return;
		}
		else if (Y1==Y2) 
		{
			pWind->DrawLine(X1, Y1, midX, Y1);
			pWind->DrawLine(midX + 10, Y1, X2, Y2);
			return;
		}
		else if(Y2>Y1) {
			pWind->DrawLine(X1, Y1, midX, Y1);
			pWind->DrawLine(midX, Y1, midX, midY);
			pWind->DrawLine(midX, midY + 10, midX, Y2);
			pWind->DrawLine(midX, Y2, X2, Y2);
		}
		else {
			pWind->DrawLine(X1, Y1, midX, Y1);
			pWind->DrawLine(midX, Y1, midX, midY);
			pWind->DrawLine(midX, midY - 10, midX, Y2);
			pWind->DrawLine(midX, Y2, X2, Y2);
		}
		
	}
	else 
	{
		if (selected)
			pWind->SetPen(UI.ConnColor, 3); //for selected connection
		else
			pWind->SetPen(UI.SelectColor, 3);
		pWind->DrawLine(X1, Y1, midX, Y1);
		pWind->DrawLine(midX, Y1, midX, Y2);
		pWind->DrawLine(midX, Y2, X2, Y2);
	}
}


void Output::DrawString(int x, int y, const std::string& text) const
{
	if (pWind == nullptr) return;

	// Design area bounds
	const int top = UI.ToolBarHeight;
	const int bottom = UI.height - UI.StatusBarHeight;
	const int left = 0;
	const int right = UI.width;

	// Ensure a sensible font and pen so text is measurable and visible
	// (caller can still change font/pen before calling if desired)
	pWind->SetFont(20, PLAIN, BY_NAME, "Arial");
	pWind->SetPen(UI.DrawColor);

	// Measure text size
	int tw = 0, th = 0;
	pWind->GetStringSize(tw, th, text);

	// Fallback if GetStringSize returned zero (some backends behave poorly)
	if (tw == 0 || th == 0) {
		th = 20;
		tw = static_cast<int>(text.size()) * 8; // rough estimate
	}

	// If text cannot fit vertically in the design area, don't draw
	if (th > (bottom - top)) return;

	// Clamp y so the text stays inside the design area
	int sy = y;
	if (sy < top + 2) sy = top + 2;
	if (sy + th > bottom - 2) sy = bottom - th - 2;

	// Clamp x so the text stays inside horizontally
	int sx = x;
	if (sx < left + 2) sx = left + 2;
	if (sx + tw > right - 2) sx = right - tw - 2;

	pWind->DrawString(sx, sy, text);
}

Output::~Output()
{
	delete pWind;
}
