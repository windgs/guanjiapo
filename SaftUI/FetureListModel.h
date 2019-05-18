#pragma once
#include <QAbstractListModel>
#include <QStandardItem>
#include <QList>
class CFetureListModel : public  QAbstractListModel
{
public:
	CFetureListModel(void);
	~CFetureListModel(void);
	//����row ��column�Ѷ�Ӧ�����ݷ�װ��QModelIndex
	virtual QModelIndex	index ( int row, int column = 0, const QModelIndex & parent = QModelIndex() ) const;
	//���ظ���index��Ӧ������
	QVariant data ( const QModelIndex & index, int role = Qt::DisplayRole ) const;
	virtual bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
	int rowCount ( const QModelIndex & parent = QModelIndex() ) const;
	int columnCount ( const QModelIndex & parent = QModelIndex() ) const;
	bool insertRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
	bool insertColumns ( int column, int count, const QModelIndex & parent = QModelIndex() );
	bool removeRows ( int row, int count, const QModelIndex & parent = QModelIndex() );
	bool removeColumns ( int column, int count, const QModelIndex & parent = QModelIndex() );
	//���ÿؼ�����
	QVariant headerData(int section,Qt::Orientation /* orientation */,int role) const;
	//�Զ���
	void Setitle(QStringList title) { m_title = title;}
  void SetGuid(QString guid) { m_guid_list.append(guid);}
  QString GetGuid(int index) { return m_guid_list.at(index);}
private:
	QList<QStandardItem*> m_data;
	QStringList  m_title;
  QStringList  m_guid_list;
};
