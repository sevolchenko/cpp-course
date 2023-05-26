#include "WordsMap.h"
#include <QTextStream>

#include <iostream>
#include <vector>


WordsMap::WordsMap() {}

WordsMap::WordsMap(const WordsMap& src) {
	this->data = src.data;
}


QString WordsMap::values(QString sort_by) {

    // Declare vector of pairs
    vector<pair<string, int>> res;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : data) {
        res.push_back(it);
    }

    // Sort using comparator function
    sort(res.begin(), res.end(), getComparator(sort_by));

    string str;
    for (const auto& kv : res) {
        str += kv.first + " " + to_string(kv.second) + "\n";
    }

    return QString::fromStdString(str);
}

void WordsMap::save_into_file(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    file.write(values(QString::fromStdString("COUNT")).toUtf8());

    file.close();
}

void WordsMap::read_from_file(QString path) {
    QFile file(path);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString content = file.readAll();

    file.close();

    QStringList rows = content.split(' ');

    for (QString row : rows) {
        insert(row.toStdString());
    }

}

function<bool(pair<string, int>, pair<string, int>)> WordsMap::getComparator(QString sort_by) {

    QStringList sortVariants;
    sortVariants << "ALPHABET" << "COUNT";

    switch (sortVariants.indexOf(sort_by)) {
    case 0:
        return [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.first < b.first;
        };

    case 1:
        return [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second > b.second;
        };

    default:
        throw exception();
    }
}

void WordsMap::insert(string word) {

	if (data.count(word)) {
		data[word] += 1;
	}
	else {
		data[word] = 1;
	}

};