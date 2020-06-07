#include <iostream>
#include "UserStaticData.h"

const char* UserStaticData::houseclub = "House";
const char* UserStaticData::Popfolk = "Pop folk";
const char* UserStaticData::Rock = "Rock";
const char* UserStaticData::All = "All";
const char* UserStaticData::Housealt()
{
	return Popfolk;
}
const char* UserStaticData::Popfolkalt()
{
	return Rock;
}
const char* UserStaticData::Rockalt()
{
	return houseclub;
}
const char* UserStaticData::Allalt()
{
	return All;
}