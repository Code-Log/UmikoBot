#pragma once
#include <QtCore/QTimeZone>
#include "core/Module.h"

class TimezoneModule : public Module
{
public:
	TimezoneModule();

	void StatusCommand(QString& result, snowflake_t guild, snowflake_t user) override;

private:
	void OnSave(QJsonDocument& doc) const override;
	void OnLoad(const QJsonDocument& doc) override;

	bool TimeFromString(const QString& string, QDateTime* outTime) const;

	struct Setting
	{
		QDateTime time;
	};

	QMap<snowflake_t, Setting> m_settings;
};