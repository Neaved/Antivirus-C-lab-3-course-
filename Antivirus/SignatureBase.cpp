#include "stdafx.h"
#include "SignatureBase.h"


SignatureBase::SignatureBase()
{
	Init();
}


SignatureBase::~SignatureBase()
{

}

void SignatureBase::Init()
{
	Signature signature1("12345_Virus", 5, "12345");
	Signature signature2("kg_Virus", 2, "kg");
	Signature signature3("Konstantin_Grinchik_Virus", 19, "Konstantin_Grinchik");

	//Signature signature2("kg_Virus", 2, "11");


	signList.push_back(signature1);
	signList.push_back(signature2);
	signList.push_back(signature3);
}



