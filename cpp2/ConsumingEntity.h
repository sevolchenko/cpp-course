#pragma once

class ConsumingEntity
{
public:
	int getConsumes() {
		return this->_consumes;
	}
	void setConsumes(int consumes) {
		this->_consumes = consumes;
	}
protected:
	int _consumes = 0;
	ConsumingEntity(int consumes) {
		this->_consumes = consumes;
	}
};

