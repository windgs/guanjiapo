#ifndef SAFTUI_H
#define SAFTUI_H
//ui
#include <QtGui/QWidget>
#include "ui_saftui.h"
//qt
#include <QFrame>
#include <QVBoxLayout>
#include <QWidget>
#include <QMainWindow>
//qjp
#include "FetureListView.h"
#include "FetureListModel.h"
#include "ChangeSkinDlg.h"
#include <Windows.h>
class TitleBar;
class ToolBar;
class ContentWidget;
class StatuBar;

typedef struct _MY_TOKEN_MANDATORY_LABEL {
  SID_AND_ATTRIBUTES Label;
} MY_TOKEN_MANDATORY_LABEL, *PMY_TOKEN_MANDATORY_LABEL;

typedef struct _MY_TOKEN_LINKED_TOKEN {
  HANDLE LinkedToken;
} MY_TOKEN_LINKED_TOKEN, *PMY_TOKEN_LINKED_TOKEN;

typedef enum _MY_TOKEN_INFORMATION_CLASS {
  /*
  TokenUser = 1,
  TokenGroups,
  TokenPrivileges,
  TokenOwner,
  TokenPrimaryGroup,
  TokenDefaultDacl,
  TokenSource,
  TokenType,
  TokenImpersonationLevel,
  TokenStatistics,

  TokenRestrictedSids,
  TokenSessionId,
  TokenGroupsAndPrivileges,
  TokenSessionReference,
  TokenSandBoxInert,
  TokenAuditPolicy,
  TokenOrigin,*/
  MYTokenElevationType  = 18, // MaxTokenInfoClass
  MYTokenLinkedToken,
  MYTokenElevation,

  MYTokenHasRestrictions,
  MYTokenAccessInformation,
  MYTokenVirtualizationAllowed,
  MYTokenVirtualizationEnabled,
  MYTokenIntegrityLevel,
  MYTokenUIAccess,
  MYTokenMandatoryPolicy,
  MYTokenLogonSid,
  //MaxTokenInfoClass  // MaxTokenInfoClass should always be the last enum
} MY_TOKEN_INFORMATION_CLASS, *PMY_TOKEN_INFORMATION_CLASS;
class SaftUI : public QWidget
{
	Q_OBJECT

public:
  SaftUI(QWidget *parent = 0, Qt::WFlags flags = 0);
  ~SaftUI();
  virtual void paintEvent ( QPaintEvent * event );
  void SetPluginPath(QString plugin_path) { m_plugin_path = plugin_path;}
  void ReViewChangeBackSkin(QString pciture);
  void RestoreBackGropu();
  void ChangeBackSkin(QString pciture);
  void InitSkinList();
private:
  void InitLayout();
  void CreateFetureWidget();
  void LoadPlugin();
  bool AdjustPurview();
  BOOL IsNeedAdministratorCall();
public slots:
  void OnClickFetureListView(const QModelIndex & index);
  void OnOpenSkinDialog();
private:
  Ui::SaftUIClass ui;
  TitleBar* m_pTitleBar;
  ToolBar* m_pToolBar;
  ContentWidget* m_pContentWidget;
  StatuBar* m_pStatuBar;
  QVBoxLayout* m_pMainLayout;

  //CFetureListView*  m_feture_View; 
  CFetureListModel m_feture_Model;
	
  QString m_plugin_path;
  //changeskin
  QPixmap m_Back_Pixmap;
  QPixmap m_Review_Back_Pixmap;
  QString LastBackSkin;  //×îºóÆ¤·ô
  ChangeSkinDlg m_SkinDlg;
};

#endif // SAFTUI_H
