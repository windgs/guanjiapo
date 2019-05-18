#include "FindDirInfo.h"
#include <QtAlgorithms>
FindDirInfo::FindDirInfo(void)
{
  
  bDefaultSelect = false; //默认选项
  bRSelect = false;       //推荐选项
  bselect = true; 
}

FindDirInfo::~FindDirInfo(void)
{
}

void FindDirInfo::clear()
{
  strDirectory.clear(); //查找目录
  strFriendName = "";  //显示名称
  strExtArray.clear();  //需要查找的文件扩展名
  strFilt.clear();;  //要被过滤的文件夹
}

FindDirInfo::FindDirInfo(const FindDirInfo& cpy)
{
  //strDirectory = cpy.strDirectory; 
  for (int i = 0;i < cpy.strDirectory.count();++i)
  {
    strDirectory.append(cpy.strDirectory.value(i));
  }
  for (int i = 0;i < cpy.strExtArray.count();++i)
  {
    strExtArray.append(cpy.strExtArray.value(i));
  }
  for (int i = 0;i < cpy.strFilt.count();++i)
  {
    strFilt.append(cpy.strFilt.value(i));
  }
 
  strFriendName = cpy.strFriendName; 
  bRecursive = cpy.bRecursive;     
  bDefaultSelect = cpy.bDefaultSelect; 
  bRSelect = cpy.bRSelect;       
  iconName = cpy.iconName;      
  ulSize = cpy.ulSize;   
  id = cpy.id;             
  parent = cpy.parent;
  bIsLeaf = cpy.bIsLeaf;       
}

FindDirInfo& FindDirInfo::operator= (const FindDirInfo& cpy)
{
  for (int i = 0;i < cpy.strDirectory.count();++i)
  {
    strDirectory.append(cpy.strDirectory.value(i));
  }
  for (int i = 0;i < cpy.strExtArray.count();++i)
  {
    strExtArray.append(cpy.strExtArray.value(i));
  }
  for (int i = 0;i < cpy.strFilt.count();++i)
  {
    strFilt.append(cpy.strFilt.value(i));
  }

  strFriendName = cpy.strFriendName; 
  bRecursive = cpy.bRecursive;     
  bDefaultSelect = cpy.bDefaultSelect; 
  bRSelect = cpy.bRSelect;       
  iconName = cpy.iconName;      
  ulSize = cpy.ulSize;   
  id = cpy.id;             
  parent = cpy.parent;
  bIsLeaf = cpy.bIsLeaf; 
  return *this;
}