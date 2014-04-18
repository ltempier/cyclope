#include "Arduino.h"
#include "VelibStation.h"

VelibStation::VelibStation(int stationPin[]){
    this->_delay = 100;
		this->_stationPin = stationPin;
		this->_stationBikeCount[] = stationPin;
    this->_stationLength = sizeof(stationPin) / sizeof(int);

    for(int i=0; i<this->_stationLength; i++){
      pinMode(this->_stationPin[i], OUTPUT);
      digitalWrite(this->_stationPin[i], LOW);
      this->_stationBikeCount[i] = 0;
    }
  }

void VelibStation::setBikeCount(int stationIndex, int bikeCount){
	if(this->_stationLength > stationIndex){
    this->_stationBikeCount[stationIndex] = bikeCount;
    for(int i=0 ; i<bikeCount ; i++){
      digitalWrite(this->_stationPin[stationIndex], HIGH);
      delay(this->_delay);
      digitalWrite(this->_stationPin[stationIndex], LOW);
    }
	}
}

void VelibStation::blinkAllStation(){
    for(int i=0; i<this->maxBike(), i++){
      for(int stationIndex=0; stationIndex<this->_stationLength; stationIndex++){
        if(this->_stationBikeCount[stationIndex] > i)
          digitalWrite(this->_stationPin[stationIndex], HIGH);
      }
    }
    delay(this->_delay);
    for(int stationIndex=0; stationIndex<this->_stationLength; stationIndex++){
      digitalWrite(this->_stationPin[stationIndex], LOW);
    }
  }
}

int VelibStation::maxBike(){
  int maxBike = 0;
    for(int i=0; i<this->_stationLength; i++){
      if(this->_stationBikeCount[i] > maxBike)
        maxBike = this->_stationBikeCount[i];
    }
    return maxBike;
}
