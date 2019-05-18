#pragma once
#include <QMap>
//���������
#include <QPluginLoader>
class PluginManager
{
private:
  PluginManager(void);
  ~PluginManager(void);
public:
  static PluginManager* Instance();
  //���ز��
  bool LoadPlugin(QString plugin_path);
  //ж��ĳһ�����
  bool UnLoadPlugin(QString plugin_guid);
  //��ò���ӿ�
  template<class T>
  T* GetPlugin(QString plugin_guid)
  {
    QMap<QString, QPluginLoader*>::iterator iter = m_PluginMap.find(plugin_guid);
    if (iter == m_PluginMap.end())
    {
      return NULL;
    }
    return iter.value();
  }

  int count() {return m_PluginMap.count();}
  template<class T>
  T* GetPluginByindex(int index)
  {  
     QMap<QString, QPluginLoader*>::iterator iter = m_PluginMap.begin();
     for (int i = 0;i < index; ++i)
     {
       ++iter;
     }
     return iter.value();
  }
  template<class T>
  T* GetInterfaceByindex(int index)
  {
     QPluginLoader* Plugin = GetPluginByindex<QPluginLoader>(index);
     QObject *plugin = Plugin->instance();
     return qobject_cast<T*>(plugin);
  }

  template<class T>
  T* GetInterfaceByGuid(QString guid)
  {
    QMap<QString, QPluginLoader*>::iterator iter = m_PluginMap.find(guid);
    if (iter == m_PluginMap.end())
    {
      return NULL;
    }
    QPluginLoader* Plugin = iter.value();
    QObject *plugin = Plugin->instance();
    return qobject_cast<T*>(plugin);
  }
private:
  QMap<QString, QPluginLoader*> m_PluginMap;
};
