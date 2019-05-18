#include "PluginManager.h"

#include <QDir>
#include "..\Common\DefineInterface.h"
PluginManager::PluginManager(void)
{
}

PluginManager::~PluginManager(void)
{
	QMap<QString, QPluginLoader*>::iterator itbegin = m_PluginMap.begin();
	QMap<QString, QPluginLoader*>::iterator  itend = m_PluginMap.end();
	for (;itbegin != itend; ++itbegin)
	{
        itbegin.value()->unload();
	}
    m_PluginMap.clear();
}

PluginManager* PluginManager::Instance()
{
  static PluginManager PluginMgr;
  return &PluginMgr;
}

bool PluginManager::LoadPlugin(QString plugin_path)
{
  QDir pluginsDir(plugin_path);
  foreach (QString fileName, pluginsDir.entryList(QStringList("*.dll"),QDir::Files)) 
  {
    QPluginLoader* plugin_load = new  QPluginLoader(pluginsDir.absoluteFilePath(fileName));
    if (!plugin_load)
    {
		continue;
    }
	bool ret = plugin_load->load();
    if (ret)
    {
      QObject *plugin = plugin_load->instance();
	  ISafeCommon* Iplugin = qobject_cast<ISafeCommon*>(plugin);
      QString guid = Iplugin->GetGuid();
      m_PluginMap.insert(guid, plugin_load);
    }
    else
    {
      delete plugin_load;
    }
  }
  return true;
}

bool PluginManager::UnLoadPlugin(QString plugin_guid)
{
  QMap<QString, QPluginLoader*>::iterator iter = m_PluginMap.find(plugin_guid);
  if (iter == m_PluginMap.end())
  {
	  return false;
  }
  iter.value()->unload();
  m_PluginMap.erase(iter);
  return true;
}
