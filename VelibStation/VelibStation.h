#ifndef VelibStation_h
#define VelibStation_h

class VelibStation{
public:
	VelibStation(int stationPin[]);
	void setBikeCount(int stationIndex, int bikeCount);
	void blinkAllStation();
private:
	int _stationPin[];
	int _stationBikeCount[];
	int _stationLength;
	int _delay;
	int maxBike();
};

#endif