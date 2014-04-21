#ifndef _STATION_MANAGER_H
#define _STATION_MANAGER_H

#include "Arduino.h"
#include "Station.h"

class StationManager{
public:
	StationManager(Station s[]);
	void blinkAllStations();
	void updateStation(int stationCode, int bikeCount);
private:
	Station _StationVector[];
	int _stationCount;
	int maxBikeCount();
};

StationManager::StationManager(Station s[]){
	this->_StationVector = s;
	this->_stationCount = sizeof(s) / sizeof(int);
};

void StationManager::maxBikeCount(){
	int maxBikeCount = 0;
	for(int i=0; i<this->_stationCount; i++){
		int bikeCount = this->_StationVector[i].getBikeCount();
		if(maxBikeCount < bikeCount){
			maxBikeCount = bikeCount;
		}
	}
	return maxBikeCount;
};
void StationManager::blinkAllStations(){
	for(int m=0; m < maxBikeCount(); m++){
		for(int i=0 ; i<this->_stationCount; i++){
			if(this->_StationVector[i].higher(m)){
				digitalWrite(this->_StationVector[i].getLedPin(), HIGH);
			};
		};
		delay(1000);
		for(int i=0 ; i<this->_stationCount; i++){
				digitalWrite(this->_StationVector[i].getLedPin(), LOW);
			};
		};
	};
};
void StationManager::updateStation(int stationCode, int bikeCount){
	for(int i=0; i<this->_stationCount; i++){
		if(this->_StationVector[i].is(stationCode){
			this->_StationVector[i].update(bikeCount);
		}
	}
};

#endif 