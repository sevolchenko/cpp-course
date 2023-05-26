#pragma once
#include "QueenAnt.h"
#include "Storage.h"
#include "ConsumingEntity.h"
#include "Pest.h"
#include "Larva.h"
#include "WorkerAnt.h"
#include "PolicemanAnt.h"
#include "SoldierAnt.h"

#include <list>
#include <string.h>
#include <iostream>

using namespace std;

class Anthill
{

public:

	Anthill(int storage_max_size, int storage_curr_state,
		int queen_consumes, int queen_produces,
		int pests_consumes, int pests_spawns,
		int larvas_consumes,
		int workers_consumes, int workers_collects,
		int policemans_consumes, double policemans_increases,
		int soldiers_consumes, int soldiers_eliminates) {
		
		this->_storage = new Storage(storage_max_size, storage_curr_state);
		this->_queen = new QueenAnt(queen_consumes, queen_produces);

		this->_pests_consumes = pests_consumes;
		this->_pests_spawns = pests_spawns;
		this->_larvas_consumes = larvas_consumes;
		this->_workers_consumes = workers_consumes;
		this->_workers_collects = workers_collects;
		this->_policemans_consumes = policemans_consumes;
		this->_policemans_increases = policemans_increases;
		this->_soldiers_consumes = soldiers_consumes;
		this->_soldiers_eliminates = soldiers_eliminates;

	};

	~Anthill() {
		delete _queen;
		delete _storage;
	}

	void nextStep() {
		this->_performActions();
	}

	void printState() {
		if (_queen != nullptr) {
			cout << "Матка живая" << endl;
		}
		else {
			cout << "Матка умерла" << endl;
		}

		cout << "Состояние склада: " << _storage->getCurrState() << endl;
		
		cout << "Количество вредителей: " << _pests.size() << endl;
		cout << "Количество личинок: " << _larvas.size() << endl;
		cout << "Количество рабочих: " << _workers.size() << endl;
		cout << "Количество полицейских: " << _policemans.size() << endl;
		cout << "Количество солдатов: " << _soldiers.size() << endl;
	}

	// Процесс питания.
	// Возвращает true, если удалось покушать.
	bool consume(ConsumingEntity entity) {
		// Сколько пищи потребляет сущность
		int consumes = entity.getConsumes();
		// Если в хранилище не хватает пищи, чтобы сущность поела, то она умирает :(
		return _storage->get(consumes) >= consumes;
	}

private:
	Storage* _storage;

	QueenAnt* _queen;

	list<Pest> _pests;

	list<Larva> _larvas;
	list<WorkerAnt> _workers;
	list<PolicemanAnt> _policemans;
	list<SoldierAnt> _soldiers;

	int _pests_consumes;
	int _pests_spawns;
	int _larvas_consumes;
	int _workers_consumes;
	int _workers_collects;
	int _policemans_consumes;
	double _policemans_increases;
	int _soldiers_consumes;
	int _soldiers_eliminates;

	// Выполнение действия каждой сущностью из списков
	void _performActions() {

		// Если вредителю не удалось поесть, он умирает
		_pests.remove_if([this](Pest pest)
			{
				return !this->consume(pest);
			}
		);
		
		_larvas.remove_if([this](Larva larva)
			{
				return !this->consume(larva);
			}
		);

		_workers.remove_if([this](WorkerAnt worker)
			{
				return !this->consume(worker);
			}
		);

		for (WorkerAnt worker : _workers) {
			_storage->fill(worker.getCollects());
		}

		_policemans.remove_if([this](PolicemanAnt policeman)
			{
				return !this->consume(policeman);
			}
		);

		for (PolicemanAnt policeman : _policemans) {
			double increases = policeman.getIncreases();
			int to_fill = (1 + increases) * _storage->getCurrState();
			_storage->fill(to_fill);
		}

		_soldiers.remove_if([this](SoldierAnt soldier)
			{
				return !this->consume(soldier);
			}
		);

		for (SoldierAnt soldier : _soldiers) {
			_eliminate_pests(soldier.getElimitanes());
		}

		// Та же механика с "Умиранием" Матки
		if (_queen != nullptr) {
			if (!consume(*_queen)) {
				_queen = nullptr;
				return;
			}

			int produces = _queen->getProduces();

			// Каждый ход перерождается то количество личинок, которое рождает Матка
			for (int i = 0; !_larvas.empty() && i < produces; i++) {
				_reborn_one();
			}

			// Роды новых личинок
			for (int i = 0; i < produces; i++) {
				_larvas.push_back(_queen->produceOne(_larvas_consumes));
			}
		}

		// Появление новых вредителей
		for (int i = 0; i < _pests_spawns; i++) {
			_pests.push_back(Pest(_pests_consumes));
		}
		
	}

	void _eliminate_pests(int count) {
		for (int i = 0; i < !_pests.empty() && count; i++) {
			_pests.erase(_pests.begin());
		}
	}


	void _reborn_one()
	{
		AntRole desision = _queen->decide();
		switch (desision)
		{
			case AntRole::POLICEMAN:
			{
				PolicemanAnt policeman(_policemans_consumes, _policemans_increases);
				_policemans.push_back(policeman);
				break;
			}
			case AntRole::SOLDIER:
			{
				SoldierAnt soldier(_soldiers_consumes, _soldiers_eliminates);
				_soldiers.push_back(soldier);
				break;
			}
			case AntRole::WORKER:
			{
				WorkerAnt worker(_workers_consumes, _workers_collects);
				_workers.push_back(worker);
				break;
			}
			default:
				break;
		}
		_larvas.erase(_larvas.begin());
	}
};

