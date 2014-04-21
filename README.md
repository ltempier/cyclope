Cyclope
==========

A lovely board that displays the availability of bicycles nearby.

JCDecaux API request type:
https://developer.jcdecaux.com/#/opendata/vls?page=dynamic

ApiKey: 833f7a45153*************************

Contract: Paris

	https://api.jcdecaux.com/vls/v1/stations?contract=paris&apiKey=833f7a45153*************************	
	
Gambetta station number_code: 	20024

	https://api.jcdecaux.com/vls/v1/stations/20024?contract=paris&apiKey=833f7a45153*************************
	
Return: 

	{
		"number":20024,
		"name":"20024 - GAMBETTA - PÃˆRE LACHAISE","address":"11 RUE MALTE BRUN - 75020 PARIS",
		"position":{
			"lat":48.864295696165875,
			"lng":2.398228667282044},
		"banking":true,
		"bonus":true,
		"status":"OPEN",
		"contract_name":"Paris",
		"bike_stands":29,
		"available_bike_stands":29,
		"available_bikes":0,
		"last_update":1397897376000
	}
	