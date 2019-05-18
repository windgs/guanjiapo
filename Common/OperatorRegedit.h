#ifndef _OPERATORREGEDIT_H
#define _OPERATORREGEDIT_H
#include <QString>
#include <Windows.h>
class COPeratorRegedit
{ 
public:
  static LONG RegOpenKeyExPrvg(HKEY hKey, 
    QString lpSubKey,
    DWORD ulOptions, 
    REGSAM samDesired, 
    PHKEY phkResult);
  //¶Á×¢²á±í¼üÖµ
  static HRESULT GetRegistryValue(HKEY hRootKey, 
    const QString contpszSubKeyName,
    const QString pszValueName, 
    DWORD* pdwType, 
    BYTE*  pszValue, 
    DWORD* puValueSize); 

  
};


#endif