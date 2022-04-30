#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct foodRecord
{
public:
	foodRecord(
	string inspectionID,
	string dbaName,
	string akaName,
	string License,
	string facilityType,
	string risk,
	string address,
	string city,
	string state,
	string zip,
	string inspectionDate,
	string inspectionType,
	string results,
	string violations, 
	string latitude,
	string longitude,
	string location
	)
	{
		InspecID = inspectionID;
		DbaName = dbaName;
		AkaName = akaName;
		LIcense = License;
		FacilityType = facilityType;
		Risk = risk;
		Address = address;
		City = city;
		State = state;
		Zip = zip;
		InspecDate = inspectionDate;
		InspecType = inspectionType;
		Results = results;
		Violations; violations;
		Latitude = latitude;
		Longitude = longitude;
		Location = location;

	}
	void display()
	{
		//how it would display the data that's getting collected from the csv.
		cout << "  Inspection ID: " << InspecID << endl;
		cout << "  Dba Name: " << DbaName << endl;
		cout << "  AKA Name: " << AkaName << endl;
		cout << "  License: " << LIcense << endl;
		cout << "  Facility Type: " << FacilityType << endl;
		cout << "  Risk: " << Risk << endl;
		cout << "  Address: " << Address << endl;
		cout << "  City: " << City << endl;
		cout << "  State: " << State << endl;
		cout << "  Zip: " << Zip << endl;
		cout << "  Inspection Date: " << InspecDate << endl;
		cout << "  Inspection Type: " << InspecType << endl;
		cout << "  Result: " << Results << endl;
		cout << "  Violation: " << Violations << endl;
		cout << "  Latitude: " << Latitude << endl;
		cout << "  Longitude: " << Longitude << endl;
		cout << "  Location: " << Location << endl;
		cout << endl;
	}
	string InspecID;
	string DbaName;
	string AkaName;
	string LIcense;
	string FacilityType;
	string Risk;
	string Address;
	string City;
	string State;
	string Zip;
	string InspecDate;
	string InspecType;
	string Results;
	string Violations;
	string Latitude;
	string Longitude;
	string Location;

};

void displayfoods(vector<foodRecord>& foods)
{
	for (auto food : foods)
	{
		food.display();
	}
}

int main()
{
	//how i input the file from my computer to make it collect the data from the csv.
	ifstream inputFile;
	inputFile.open("C:\\Users\\13129\\Desktop\\Food_Inspections.csv");
	string line = "";

	vector<foodRecord> foods;
	
	while (getline(inputFile, line))
	{
		string inspectionID;
		string dbaName;
		string akaName;
		string License;
		//int license;
		string facilityType;
		string risk;
		string address;
		string city;
		string state;
		string zip;
		string inspectionDate;
		string inspectionType;
		string results;
		string violations;
		//float latitude; 
		string latitude;
		//float longitude;
		string longitude;
		string location;

		//using for the float and int 
		//string tempString;

		stringstream inputString(line);

		getline(inputString, inspectionID, ',');
		getline(inputString, dbaName, ',');
		getline(inputString, akaName, ',');
		getline(inputString, License, ',');
		getline(inputString, facilityType, ',');
		getline(inputString, risk, ',');
		getline(inputString, address, ',');
		getline(inputString, city, ',');
		getline(inputString, state, ',');
		getline(inputString, zip, ',');
		getline(inputString, inspectionDate, ',');
		getline(inputString, inspectionType, ',');
		getline(inputString, results, ',');
		getline(inputString, violations, ',');
		getline(inputString, latitude, ',');
		getline(inputString, longitude, ',');
		getline(inputString, location, ',');
		
		foodRecord food(inspectionID, dbaName, akaName, License, facilityType, risk, 
			address, city, state, zip, inspectionDate, inspectionType, results,
			violations, latitude, longitude, location);
		foods.push_back(food);

		line = "";

	}


	displayfoods(foods);
}
