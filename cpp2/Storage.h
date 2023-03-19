#pragma once
#include <algorithm>

class Storage
{
public:
	Storage(int max_capacity, int curr_state) {
		this->_max_capacity = max_capacity;
		this->_curr_state = curr_state;
	}

	// Запрос на получение заданного количества ресурсов.
	// Если ресурсов хватает, возвращает (и вычитает из остатка) count.
	// Если не хватает, то возвращает (и вычитает из остатка) оставшееся количество.
	int get(int count) {
		int to_get;
		if (_curr_state < count) {
			to_get = _curr_state;
			_curr_state = 0;
		}
		else {
			to_get = count;
			_curr_state -= count;
		}
		return to_get;
	}

	// Пополнение склада на заданное количество ресурсов.
	// Не допускает переполнения склада.
	// Возвращает количество ресурсов, на которое склад был пополнен.
	int fill(int count) {
		int to_fill;
		if (_curr_state + count > _max_capacity) {
			to_fill = _max_capacity - _curr_state;
			_curr_state = _max_capacity;
		}
		else {
			to_fill = count;
			_curr_state += count;
		}
		return to_fill;
	}

	int getMaxCapacity() {
		return _max_capacity;
	}
	void setMaxCapacity(int max_capacity) {
		_max_capacity = max_capacity;
	}

	int getCurrState() {
		return _curr_state;
	}
private:
	int _max_capacity;
	int _curr_state =0;
};

