#ifndef WORDSMAP_H
#define WORDSMAP_H

#pragma once

#include <iostream> 
#include <string>
#include <map>

#include <QObject>
#include <QString>
#include <QFile>

using namespace std;

QT_BEGIN_NAMESPACE

class WordsMap:
	public QObject
{
	Q_OBJECT
	public:
		WordsMap();
		WordsMap(const WordsMap& src);

		Q_INVOKABLE QString values(QString sort_by);

		Q_INVOKABLE void save_into_file(QString path);

		Q_INVOKABLE void read_from_file(QString path);


	private:
		map<string, int> data;
		void insert(string word);
		function<bool(pair<string, int>, pair<string, int>)> getComparator(QString sort_by);
};

#endif // WORDSMAP_H