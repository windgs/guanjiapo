#include "OperatorRegedit.h"
#include "upreggradeprivilege.h"
#include <atlconv.h>
#include "..\include\atl\include\atlrx.h"

LONG COPeratorRegedit::RegOpenKeyExPrvg(HKEY hKey, 
                      QString lpSubKey,
                      DWORD ulOptions, 
                      REGSAM samDesired, 
                      PHKEY phkResult)
{
  LONG ret = 0;
  int i = 0;
  while(i < 2)
  {
    if (ERROR_SUCCESS == (ret=::RegOpenKeyExW(hKey, 
      lpSubKey.toStdWString().c_str(),
      ulOptions, 
      samDesired, 
      phkResult)))
    {
      break;
    }
    if ( i == 0 )
    {
      UpgradePrivilege(hKey, CW2T(lpSubKey.toStdWString().c_str()));
    }

    i++;
  }

  return ret;
}

HRESULT COPeratorRegedit::GetRegistryValue(HKEY hRootKey, 
                         const QString pszSubKeyName,
                         const QString pszValueName, 
                         DWORD* pdwType, 
                         BYTE* pszValue, 
                         DWORD* puValueSize)
{
  if (pszSubKeyName.isEmpty() || (NULL == puValueSize))
      return E_FAIL;

  HRESULT hr = S_OK;
  HKEY hSubKey = NULL;
  long lResult = ERROR_SUCCESS;

  lResult = RegOpenKeyExPrvg(hRootKey, pszSubKeyName, 0, KEY_READ, &hSubKey);
  if (ERROR_SUCCESS == lResult)
  {
    lResult = ::RegQueryValueEx(hSubKey, pszValueName.toStdWString().c_str(), 0, pdwType, pszValue, puValueSize);
    if (ERROR_SUCCESS != lResult)
    {
      hr = E_FAIL;
    }
  }

  if (hSubKey != NULL)
  {
    ::RegCloseKey(hSubKey);
    hSubKey = NULL;
  }

  return hr;
}