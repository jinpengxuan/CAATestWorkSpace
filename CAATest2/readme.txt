添加一个工具栏按钮，

CAA在这一块没有很好的做封装，所以代码看起来很多补丁。
首先是复制一个Addin module 写法完全是固定格式，只有红色部分可以更改。

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
工具栏存放位置 ，这里是工程制图的界面

void CAADrwAddin::CreateCommands()
{
/////////////////////////////////////////////////// 
new CAADrwHeader("window","HelloWindow", 
"CAAHelloWindow",(void *)NULL); 
//new CAADrwHeader(button name ，module name ，class name） 
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
————————————————————————————————
LINK_WITH = JS0GROUP CATApplicationFrame CATDraftingInterfaces
这3模块分别对应 BaseUnknown ApplicationFrame.XXX DraftingInterfaces.CATCommandHeader
————————————————————————————————
注意要用中文名在资源文件里面修改成“中文”形式
disco文件里面添加
CAAAddn CATIDRWFRAMEAddin libAddin
否则不显示工具条 lib+module名
sgcatlog的3个文件也是必须的 文件可以是空的，但是必须有,否者也是不出工具条
————————————————————————————————
一个空的commond是非常简单的 几乎可以什么都不写
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
————————————————————————————————
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
按钮复位，执行效果就是点击后按钮秒复位 其实就是闪一下
________________________________________________________________
LINK_WITH = JS0GROUP CATDialogEngine JS0FM 
这3个分别对应
BaseUnknown DialogEngine CATCommond
