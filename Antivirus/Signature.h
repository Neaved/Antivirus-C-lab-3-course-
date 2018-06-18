#pragma once
#include "stdafx.h"
#include "SequenceOfData.h"

using namespace std;

class Signature
{
public:
	Signature(char* name, size_t signLength, char* signatureSequence);
	Signature(const Signature &s);
	~Signature();

private:
	void InitFields(char* name, size_t signLength, char* signatureSequence);

public:
	char* signatureName;
	SequenceData signature;
};