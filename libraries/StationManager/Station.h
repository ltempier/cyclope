#ifndef _STATION_H
#define _STATION_H

#include <Arduino.h>

class Station {
public:
	Station(int stationCode, int ledPin);
	Station(int stationCode, int ledPin, int bikeCount);
	void update(int bikeCount);
	void blink();
	bool higher(int bikeCount);
	bool is(int stationCode);

	int getLedPin();
	int getBikeCount();
private:
	int _stationCode;
	int _ledPin;
	int _bikeCount;
};

Station::Station(int stationCode, int ledPin){
	this->_stationCode = stationCode;
	this->_ledPin = ledPin;
	pinMode(ledPin, OUTPUT);
	this->_bikeCount = 0;
};
Station::Station(int stationCode, int ledPin,int bikeCount){
	this->_stationCode = stationCode;
	this->_ledPin = ledPin;
	pinMode(ledPin, OUTPUT);
	this->_bikeCount = bikeCount;
};

void Station::update(int bikeCount){
	this->_bikeCount = bikeCount;
}

void Station::blink(){
	for(int i=0; i<this->_bikeCount; i++){
		digitalWrite(this->ledPin, HIGH);
		delay(1000);
		digitalWrite(this->ledPin, LOW);
	}
}
bool Station::higher(int bikeCount){
	return this->_bikeCount>bikeCount;
}
bool Station::is(int stationCode){
	return this->_stationCode == stationCode;
}

int Station::getLedPin(){
	return this->_ledPin;
}
int Station::getBikeCount(){
	return this->_bikeCount;
}


#endif 