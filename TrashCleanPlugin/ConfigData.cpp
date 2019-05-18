#include "ConfigData.h"
#include "ConverPath.h"
ConfigData::ConfigData(void)
{

  FindDirInfo dirinfo;
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = false;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/sys.bmp";
  dirinfo.id = WIN_TEMP;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%windir%\\temp");
  dirinfo.strFriendName = tr("windows��ʱ�ļ�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/huishouzhan.bmp";
  dirinfo.id = WIN_HUISHOUZHAN;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("");
  dirinfo.strFriendName = tr("����վ");
  dirinfo.strExtArray << "*";
  //dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();

  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = false;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/suolvtu.bmp";
  dirinfo.id = WIN_SUOLIETU;
  dirinfo.parent = WIN_TRASH;
  dirinfo.strDirectory.append("%CSIDL_LOCAL_APPDATA%\\Microsoft\\Windows\\Explorer");
  dirinfo.strFriendName = tr("����ͼ����");
  dirinfo.strExtArray << "*.db";
  //dirinfo.strFilt << "%specfiles%";  
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/errrport.bmp";
  dirinfo.id = WIN_ERRPORT;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%archivefiles%");
  dirinfo.strFriendName = tr("windows���󱨸�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/person.bmp";
  dirinfo.id = WIN_USERTEMP;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%temp%");
  dirinfo.strFriendName = tr("windows�û���ʱ�ļ�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%" << "%driver%" << "%program%" << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = false;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/logfile.bmp";
  dirinfo.id = WIN_LOG;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%windir%");
  dirinfo.strDirectory.append("%windir%\\debug");
  dirinfo.strDirectory.append("%windir%\\system32\\wbem");
  dirinfo.strDirectory.append("%windir%\\security\\logs");
  dirinfo.strFriendName = tr("windowsϵͳ��־�ļ�");
  dirinfo.strExtArray << "*.log" << "lo_" << "log.txt" << "*.bak" << "*.old";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/download.bmp";
  dirinfo.id = WIN_DOWNLOAD;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%windir%\\Downloaded Program Files");

  dirinfo.strFriendName = tr("IE�����س����ļ�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%" << "%downloadlist%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/update.bmp";
  dirinfo.id = WIN_UPDATE;
  dirinfo.parent = 0;
  dirinfo.strDirectory.append("%windir%\\SoftwareDistribution\\Download");
  dirinfo.strFriendName = tr("windows���²���");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/dump.bmp";
  dirinfo.id = WIN_DUMP;
  dirinfo.parent = WIN_TRASH;
  dirinfo.strDirectory.append("%minidump%");
  dirinfo.strDirectory.append("%memdump%");
  dirinfo.strFriendName = tr("�ڴ�ת���ļ�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/wread.bmp";
  dirinfo.id = WIN_PREFETCH;
  dirinfo.parent = WIN_TRASH;
  dirinfo.strDirectory.append("%windir%\\Prefetch");
  dirinfo.strFriendName = tr("windowsԤ���ļ�");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/cache.bmp";
  dirinfo.id = WIN_OFFICE;
  dirinfo.parent = WIN_TRASH;
  dirinfo.strDirectory.append("%systemdrive%\\MSOCache");
  dirinfo.strFriendName = tr("Office��װ����Ŀ¼");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //

  /* dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Content.IE5");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Content.MSO");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Content.Outlook");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Content.Word");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\AntiPhishing");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Virtualized");
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%\\Low");*/
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/ie.bmp";
  dirinfo.id = BROWER_IE;
  dirinfo.parent = BROWER_TRASH;
  dirinfo.strDirectory.append("%CSIDL_INTERNET_CACHE%");
  dirinfo.strFriendName = tr("IE/QQ�����/360�����");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/Firefoxpassword.bmp";
  dirinfo.id = BROWER_FIREFOX;
  dirinfo.parent = BROWER_TRASH;
  dirinfo.strDirectory.append("%firefox%");
  dirinfo.strFriendName = tr("���(firefox)");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //dirinfo.bDefaultSelect = true;
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/sogo.bmp";
  dirinfo.id = BROWER_SOGO;
  dirinfo.parent = BROWER_TRASH;
  dirinfo.strDirectory.append("%CSIDL_APPDATA%\\SogouExplorer\\Webkit\\Cache");
  dirinfo.strFriendName = tr("�ѹ������(sogo)");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/googleChrome.bmp";
  dirinfo.id = BROWER_CHROME;
  dirinfo.parent = BROWER_TRASH;
  dirinfo.strDirectory.append("%CSIDL_LOCAL_APPDATA%\\Google\\Chrome\\User Data\\Default\\cache");
  dirinfo.strFriendName = tr("�ȸ�(Chrome)");
  dirinfo.strExtArray << "*.*";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/xunleikk.bmp";
  dirinfo.id = VIDEO_XUNLEI;
  dirinfo.parent = VIDEO_TRASH;
  dirinfo.strDirectory.append("%xunleikankan%");
  dirinfo.strFriendName = tr("Ѹ�׿���");
  dirinfo.strExtArray << "*.xv";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/iku.bmp";
  dirinfo.id = VIDEO_YOUKU;
  dirinfo.parent = VIDEO_TRASH;
  dirinfo.strDirectory.append("%youku%");
  dirinfo.strFriendName = tr("�ſ�");
  dirinfo.strExtArray << "cache_*.dat";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/qqlive.bmp";
  dirinfo.id = VIDEO_QQLIVE;
  dirinfo.parent = VIDEO_TRASH;
  dirinfo.strDirectory.append("%qqlive%");
  dirinfo.strFriendName = tr("QQLive�������");
  dirinfo.strExtArray << "*.tdl" << "*.tdi" << "*.tii" << "*.tpt";
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
  //
  dirinfo.bIsLeaf = true;
  dirinfo.bRecursive = true;
  dirinfo.bRSelect = true;
  dirinfo.iconName = "../SaftUI/Resources/button/TrashButton/PPTV.bmp";
  dirinfo.id = VIDEO_PPTV;
  dirinfo.parent = VIDEO_TRASH;
  dirinfo.strDirectory.append("%pptv%");
  dirinfo.strFriendName = tr("PPLive�������");
  dirinfo.strFilt << "%specfiles%";
  m_path_data.append(dirinfo);
  dirinfo.clear();
}

ConfigData::~ConfigData(void)
{
}

ConfigData* ConfigData::Instance()
{
   static ConfigData app;
   return &app;
}

void ConfigData::setNodeSelect(QString text, bool select)
{
    FindDirInfo* iteminfo = GetItemByName(text);
    if (!iteminfo)
    {
      return;
    }
    iteminfo->bselect = select;
}

FindDirInfo* ConfigData::GetItemByName(QString text)
{
  int count = m_path_data.count();
  for (int i = 0; i < count; ++i)
  {
    const FindDirInfo& info = GetData(i);
    if (info.strFriendName == text)
    {
      FindDirInfo* nodeinfo = const_cast<FindDirInfo*>(&info);
      return nodeinfo;
    }
  }
  return NULL;
}

FindDirInfo ConfigData::GetItem(QString FriendName)
{   
    int count = m_path_data.count();
    for (int i = 0; i < count; ++i)
    {
       const FindDirInfo& info = GetData(i);
       if (info.strFriendName == FriendName)
       {
           return info;
       }
    }
    return FindDirInfo();
}

void ConfigData::ConvertPath()
{
    if (m_path_data.isEmpty())
    {
      return;
    }
    
    int count = m_path_data.count();
    for (int i = 0; i < count;++i)
    {
       const  FindDirInfo& info = GetData(i);
       int dir_count = info.strDirectory.count();
       for (int c = 0; c < dir_count; ++c)
       {
        QString EvnPath = ConverPath::Instance()->ConverFindPath(info.strDirectory.at(c));
        if (!EvnPath.isEmpty())
        {
            m_path_data[i].strDirectory.replace(c,EvnPath);
        }
        
       }
    }

}

