#include "RecordLogItem.h"
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
#include <QTextStream>
#include <QDomNode>
#include <QDomText>
#include "SpecialFolderPath.h"
RecordLogItem::RecordLogItem(void)
{
  //LoadDisEnableLogItem();
}

RecordLogItem::~RecordLogItem(void)
{
	
}

RecordLogItem* RecordLogItem::Instance()
{
   static RecordLogItem app;
   return &app;
}

SafeRunInfo* RecordLogItem::GetDisEnableItem(const SafeRunInfo& info)
{
    int count =  GetCountDisEnableArray();
    for (int i = 0; i < count;++i)
    {
       SafeRunInfo* runinfo = GetDisEnableArray(i);
       if (runinfo->nType == info.nType && runinfo->strName == info.strName)
       {
         return runinfo;
       }
    }
    return NULL;
}

SafeRunInfo* RecordLogItem::GetEnableItem(const SafeRunInfo& info)
{
	int count =  GetCountEnableArray();
	for (int i = 0; i < count;++i)
	{
		SafeRunInfo* runinfo = GetEnableArray(i);
		if (runinfo->nType == info.nType && runinfo->strName == info.strName)
		{
			return runinfo;
		}
	}
	return NULL;
}

void RecordLogItem::ClearAll()
{ 
  int count = m_RunEnableArray.count();
  for (int i = 0;i < count; ++i)
  {
     delete m_RunEnableArray.at(i);
  }
  
  count = m_DisEnableArray.count();
  for (int i = 0;i < count; ++i)
  {
	  delete m_DisEnableArray.at(i);
  }
  
  count = m_ServiceRunArray.count();
  for (int i = 0;i < count; ++i)
  {
	  delete m_ServiceRunArray.at(i);
  }

  m_RunEnableArray.clear(); 
  m_DisEnableArray.clear(); 
  m_ServiceRunArray.clear();
}

bool RecordLogItem::RemoveEnableItem(const SafeRunInfo* info)
{
  int count =  GetCountDisEnableArray();
  for (int i = 0; i < count;++i)
  {
    SafeRunInfo* runinfo = GetDisEnableArray(i);
    if (runinfo->nType == info->nType && runinfo->strName == info->strName)
    {
      m_DisEnableArray.remove(i);
      break;
    }
  }
  return true;
}

bool RecordLogItem::SaveDisEnableLogItem()
{ 
  int count =  GetCountDisEnableArray();
  QDomDocument doc;
  QDomElement root = doc.createElement("xml"); //root节点
  for (int i = 0; i < count;++i)
  {
     SafeRunInfo* runinfo = GetDisEnableArray(i);
	 if (!runinfo)
	 {
		 continue;
	 }
	 QDomElement itemnode = doc.createElement("item");

     QDomElement namenode = doc.createElement("name");
	 QDomText TextNode = doc.createTextNode(runinfo->strName);
     namenode.appendChild(TextNode);
     itemnode.appendChild(namenode);
	 //
	 QString str;
	 QDomElement typenode = doc.createElement("type");
	 str.setNum(runinfo->nType);
	 TextNode = doc.createTextNode(str);
	 typenode.appendChild(TextNode);
	 itemnode.appendChild(typenode);
     //
	 QDomElement initstatenode = doc.createElement("initstate");
	 str.setNum(runinfo->nRegType);
	 TextNode = doc.createTextNode(str);
	 initstatenode.appendChild(TextNode);
	 itemnode.appendChild(initstatenode);
     //
	 QDomElement systemnode = doc.createElement("system");
	 str.setNum(runinfo->bSystem);
	 TextNode = doc.createTextNode(str);
	 systemnode.appendChild(TextNode);
	 itemnode.appendChild(systemnode);
     
	 //
     QDomElement descnode = doc.createElement("desc");
     TextNode = doc.createTextNode(runinfo->strDesc);
     descnode.appendChild(TextNode);
     itemnode.appendChild(descnode);
     
	 //
	 QDomElement pathcnode = doc.createElement("path");
	 TextNode = doc.createTextNode(runinfo->strPath);
	 pathcnode.appendChild(TextNode);
	 itemnode.appendChild(pathcnode);
     
	 //
	 QDomElement exepathcnode = doc.createElement("exepath");
	 TextNode = doc.createTextNode(runinfo->strExePath);
	 exepathcnode.appendChild(TextNode);
	 itemnode.appendChild(exepathcnode);
	 
	 //
	 QDomElement Valuecnode = doc.createElement("value");
	 TextNode = doc.createTextNode(runinfo->strValue);
	 Valuecnode.appendChild(TextNode);
	 itemnode.appendChild(Valuecnode);
     
	 //
	 QDomElement displaycnode = doc.createElement("display");
	 TextNode = doc.createTextNode(runinfo->strDisplay);
	 displaycnode.appendChild(TextNode);
	 itemnode.appendChild(displaycnode);
     
	 //
	 QDomElement warningnode = doc.createElement("warning");
	 TextNode = doc.createTextNode(runinfo->strWarning);
	 warningnode.appendChild(TextNode);
	 itemnode.appendChild(warningnode);
     
	 //
	 QDomElement dispathnode = doc.createElement("dispath");
	 TextNode = doc.createTextNode(runinfo->strDisPath);
	 dispathnode.appendChild(TextNode);
	 itemnode.appendChild(dispathnode);

	 root.appendChild(itemnode);

  }
  doc.appendChild(root);  
  QFile file("./dislog.xml");

  if (!file.open(QIODevice::WriteOnly))
	  return false;

  QString xml = doc.toString();		
  QTextStream out(&file);
  out.setCodec("UTF-8");
  out << xml;
  file.close();	
  return true;
}

void RecordLogItem::LoadDisEnableLogItem()
{
  QDomDocument doc;
  QFile file("./dislog.xml");
  if (!file.open(QIODevice::ReadOnly))
	  return;
  doc.setContent(&file);
  QDomElement root = doc.firstChildElement("xml");
  QDomNodeList nodelist	= root.childNodes ();
  int count = nodelist.count();
  for (int i = 0; i < count; ++i)
  {  
     SafeRunInfo* runinfo = new SafeRunInfo;
     QDomNode childnode = nodelist.at(i);
     QDomNode node = childnode.firstChildElement("name");
	 QDomText DomText = node.firstChild().toText();
     runinfo->strName = DomText.data();
     //
	 node = childnode.firstChildElement("type");
	 DomText = node.firstChild().toText(); 
	 runinfo->nType = DomText.data().toInt();

	 //
	 node = childnode.firstChildElement("initstate");
	 DomText = node.firstChild().toText(); 
	 runinfo->nRegType = DomText.data().toInt();
	 
	 //
	 node = childnode.firstChildElement("system");
	 DomText = node.firstChild().toText(); 
	 runinfo->bSystem = DomText.data().toInt();

	 //
	 node = childnode.firstChildElement("desc");
	 DomText = node.firstChild().toText(); 
	 runinfo->strDesc = DomText.data();
     
	 //
	 node = childnode.firstChildElement("path");
	 DomText = node.firstChild().toText(); 
	 runinfo->strPath = DomText.data();

	 //
	 node = childnode.firstChildElement("exepath");
	 DomText = node.firstChild().toText(); 
	 runinfo->strExePath = DomText.data();

     //
	 node = childnode.firstChildElement("value");
	 DomText = node.firstChild().toText(); 
	 runinfo->strValue = DomText.data();

	 //
	 node = childnode.firstChildElement("display");
	 DomText = node.firstChild().toText(); 
	 runinfo->strDisplay = DomText.data();

	 //
	 node = childnode.firstChildElement("warning");
	 DomText = node.firstChild().toText(); 
	 runinfo->strWarning = DomText.data();

     //
	 node = childnode.firstChildElement("dispath");
	 DomText = node.firstChild().toText(); 
	 runinfo->strDisPath = DomText.data();
     
	 //加载图标
	 
	 if (runinfo->nType == RUN_TYPE_STARTUP)
	 {      
         if (runinfo->nRegType == REG_RUN_TYPE_WINDOW_HKLM 
		  || runinfo->nRegType == REG_RUN_TYPE_WINDOW_HKCU)
         {
			 runinfo->hIcon = CSpecialFolderPath::GetExeIcon(runinfo->strName);
         }
		 else if (runinfo->nRegType == DIR_RUN_TYPE_WINDOW_COMM
			 || runinfo->nRegType == DIR_RUN_TYPE_WINDOW_USER)
		 {
             runinfo->hIcon = CSpecialFolderPath::GetExeIcon(runinfo->strPath);
		 }
		  
	 }
	 AddDisEnableArray(runinfo);
  }

}

bool RecordLogItem::LoadRunOpt(QString path)
{
  QDomDocument doc;
  QFile file(path);
  if (!file.open(QIODevice::ReadOnly))
    return false;
  if (!doc.setContent(&file)) 
  {
    file.close();
    return false;
  }

  QDomElement docElem = doc.documentElement();
  QDomNode n = docElem.firstChild();
  while(!n.isNull()) 
  {
    QDomElement e = n.toElement();
    if(!e.isNull()) 
    {
      QString tagname = e.tagName();
      RunOptItem* optitem = new RunOptItem;
      optitem->id = e.attribute("id").toInt();
      optitem->type = e.firstChildElement("type").text().toInt();
      optitem->name = e.firstChildElement("name").text();
      optitem->decs = e.firstChildElement("desc").text();
      optitem->dispayname = e.firstChildElement("display").text();
      optitem->appname = e.firstChildElement("appname").text();
      optitem->advice = e.firstChildElement("advice").text().toInt();
      m_runoptarray.append(optitem);
    }
    n = n.nextSibling();
  }

  file.close();
  
  return true;
}

ServiceConfig* RecordLogItem::GetServiceItembyName(QString ServiceName)
{
   int count = m_ServiceRunArray.count();
   for (int i = 0;i < count;++i)
   {
       ServiceConfig* Config = m_ServiceRunArray.at(i);
	   if (!Config)
	   {
		   continue;
	   }
	   if (Config->strName == ServiceName)
	   {
		   return Config;
	   }
   }
   return NULL;
}

void RecordLogItem::RemoveServiceItembyName(QString ServiceName)
{   
	int count = m_ServiceRunArray.count();
	for (int i = 0;i < count;++i)
	{
		ServiceConfig* Config = m_ServiceRunArray.at(i);
		if (!Config)
		{
			continue;
		}
		if (Config->strName == ServiceName)
		{
			m_ServiceRunArray.remove(i);
			break;
		}
	}
}

QString RecordLogItem::GetFileName(QString appname)
{
	int pos = appname.lastIndexOf('\\');
	if (-1 == pos)
	{
		return appname;
	}
	return appname.mid(pos + 1,appname.length() - pos);
}

RunOptItem* RecordLogItem::GetRunOptData(int type, QString appname)
{  
   int count = m_runoptarray.count();
   for (int i = 0;i < count;++i)
   {
      RunOptItem* optitem = m_runoptarray.at(i);
	
	  if (optitem->type == type)
	  {
		 QString filename = GetFileName(appname);
		 filename = filename.toLower();
		 QString appnamesLower = optitem->appname.toLower();
		 QString namelower = optitem->name.toLower();
		 /*if (i == 2610 || namelower == QString::fromStdWString(L"QQPCRTP"))
		 {
			 int a =0;
		 }*/
		 if (filename == appnamesLower ||namelower ==  filename)
		 {
			 return optitem;
		 }
        
	  }
   }
   return NULL;
}

QString RecordLogItem::GetAdviceStr(int nAdvice)
{
	QString	lpstr = tr("暂无建议");
	switch (nAdvice)
	{
	case 0:
		lpstr =tr("可以禁止");
		break;
	case 1:
		lpstr = tr("建议启动");
		break;
	case 2:
		lpstr = tr("必须启动");
		break;
	case 3:
		lpstr = tr("建议启动");
		break;
	case 4:
		lpstr = tr("维持现状");
		break;
	default:
		break;
	}
	
	return lpstr;
}