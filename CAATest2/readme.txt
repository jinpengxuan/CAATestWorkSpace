���һ����������ť��

CAA����һ��û�кܺõ�����װ�����Դ��뿴�����ܶಹ����
�����Ǹ���һ��Addin module д����ȫ�ǹ̶���ʽ��ֻ�к�ɫ���ֿ��Ը��ġ�

#ifndef CAADrwAddin_H 
#define CAADrwAddin_H 
#include "CATBaseUnknown.h" 

class CATCmdContainer; 
class CAADrwAddin : public CATBaseUnknown
{
CATDeclareClass;
public:
CAADrwAddin();
virtual ~CAADrwAddin();
void CreateCommands();
CATCmdContainer * CreateToolbars();
};
#endif

-------------------------------------------------------
#include "CAADrwAddin.h" 
#include "CATCommandHeader.h"
#include "CATCreateWorkshop.h"
#include "CATCmdContainer.h"
#include "CATCmdStarter.h"

MacDeclareHeader(CAADrwHeader);
CATImplementClass( CAADrwAddin,DataExtension,CATBaseUnknown,CAADrwAddn);
CAADrwAddin::CAADrwAddin():CATBaseUnknown(){}
CAADrwAddin::~CAADrwAddin(){}

#include "TIE_CATIDRWFRAMEAddin.h" 
TIE_CATIDRWFRAMEAddin(CAADrwAddin);
���������λ�� �������ǹ�����ͼ�Ľ���

void CAADrwAddin::CreateCommands()
{
/////////////////////////////////////////////////// 
new CAADrwHeader("window","HelloWindow", 
"CAAHelloWindow",(void *)NULL); 
//new CAADrwHeader(button name ��module name ��class name�� 
///////////////////////////////////////////////////// 
}
CATCmdContainer *CAADrwAddin::CreateToolbars()
{
NewAccess (CATCmdContainer, pCAADrwTlb, CAAUseCaseCommands );
/////////////////////////////////////////////////////////// 
NewAccess (CATCmdStarter, pDimDressupStr , DimDressupStr ); 
SetAccessCommand (pDimDressupStr, "HelloWindow" ); 
SetAccessChild (pCAADrwTlb, pDimDressupStr ); 
// SetAccessCommand (pDimDressupStr, "module name" ) 
//this var is same with CAADrwHeader 
///////////////////////////////////////////////////////// 
AddToolbarView (pCAADrwTlb , -1 , UnDock); 
return pCAADrwTlb;
}
����������������������������������������������������������������
LINK_WITH = JS0GROUP CATApplicationFrame CATDraftingInterfaces
��3ģ��ֱ��Ӧ BaseUnknown ApplicationFrame.XXX DraftingInterfaces.CATCommandHeader
����������������������������������������������������������������
ע��Ҫ������������Դ�ļ������޸ĳɡ����ġ���ʽ
disco�ļ��������
CAAAddn CATIDRWFRAMEAddin libAddin
������ʾ������ lib+module��
sgcatlog��3���ļ�Ҳ�Ǳ���� �ļ������ǿյģ����Ǳ�����,����Ҳ�ǲ���������
����������������������������������������������������������������
һ���յ�commond�Ƿǳ��򵥵� ��������ʲô����д
#ifndef CAAHelloWindow_H
#define CAAHelloWindow_H
#include "CATStateCommand.h"
class CAAHelloWindow: public CATStateCommand
{
public:
CAAHelloWindow ();
virtual ~CAAHelloWindow ();
void BuildGraph();
};
#endif
����������������������������������������������������������������
#include "CAAHelloWindow.h"
#include "CATCreateExternalObject.h" // Define the CATDeclareClass macro
#include "CATBaseUnknown.h"
CATCreateClass (CAAHelloWindow); 
CAAHelloWindow::CAAHelloWindow():
CATStateCommand(CATString("helloworld")){}
CAAHelloWindow::~CAAHelloWindow(){}
void CAAHelloWindow::BuildGraph()
{ 
RequestDelayedDestruction( ) ;
}
��ť��λ��ִ��Ч�����ǵ����ť�븴λ ��ʵ������һ��
________________________________________________________________
LINK_WITH = JS0GROUP CATDialogEngine JS0FM 
��3���ֱ��Ӧ
BaseUnknown DialogEngine CATCommond
