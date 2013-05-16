#ifndef __C_BASE_WIDGET_H__
#define __C_BASE_WIDGET_H__
#include "IHandleUIEvent.h"
#include "IUILoader.h"
#include "CDynObj.h"
#include "CMarcos.h"
class CGraphic;
class CBaseWidget:public IHandleUIEvent,public IUILoader,public CDynObj
{
public:
	DECLARE_DYNCREATE(CBaseWidget);
	CBaseWidget(void);
	virtual ~CBaseWidget(void);
	//////////////////////////////////////////////////////////////////////////
	//property
	static const std::string RECT;
	static const std::string TYPE;
	//////////////////////////////////////////////////////////////////////////
	//IHandleUIEvent
	virtual void handlePenDown(CWidgetEvent& event);
	virtual void handlePenUp(CWidgetEvent& event);
	virtual void handlePenClick(CWidgetEvent& event);
	virtual void handlePenMoveIn(CWidgetEvent& event);
	virtual void handlePenMove(CWidgetEvent& event);
	virtual void handlePenMoveOut(CWidgetEvent& event);
	///////////////////////////////////////////////////////////////////////////
	//IUILoader
	bool load(std::string& str);
	bool setPorperty(const std::string& key,const std::string& strvalue);
	/////////////////////////////////////////////////////////////////////////
	//draw function
	virtual void draw(CGraphic* pGraphic);
	//////////////////////////////////////////////////////////////////////////
	CCRect getChildRect(void);
	//////////////////////////////////////////////////////////////////////////
	COBRA_CREATE_PROPERTY(int,m_id,ID);//id
	COBRA_CREATE_PROPERTY(std::string,m_strType,Type);//type
	COBRA_CREATE_PROPERTY(CCRect,m_rect,Rect);//rect
	COBRA_CREATE_PROPERTY_BY_BOOL(m_bEnable,Enable);//bEnable
	COBRA_CREATE_PROPERTY_BY_BOOL(m_bVisible,Visble);//bVisble
	COBRA_CREATE_PROPERTY(char,m_zOrder,ZOrder);//ZOrder  [-255,255] the widget draw first if it's value is smaller than others'
	COBRA_CREATE_PROPERTY(ccColor4B,m_bkColor,BkColor);//background color
public:
	//bool operator<(const CBaseWidget& other) const;
};

#endif //__C_BASE_WIDGET_H__