#ifndef SYSTEMOPTPLUGIN_GLOBAL_H
#define SYSTEMOPTPLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef SYSTEMOPTPLUGIN_LIB
# define SYSTEMOPTPLUGIN_EXPORT Q_DECL_EXPORT
#else
# define SYSTEMOPTPLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // SYSTEMOPTPLUGIN_GLOBAL_H
