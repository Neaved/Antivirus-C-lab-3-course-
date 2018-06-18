#include "stdafx.h"
#include "Signature.h"


Signature::Signature(char* name, size_t signLength, char* signatureSequence)
{
	InitFields(name, signLength, signatureSequence);
}


Signature::Signature(const Signature &s)
{
	InitFields(s.signatureName, s.signature.seqLength, s.signature.sequence);
}

Signature::~Signature()
{
	delete signatureName;
	delete[] signature.sequence;
}

void Signature::InitFields(char* name, size_t signLength, char* signatureSequence)
{
	size_t nameLength = strlen(name) + 1;
	signatureName = new char[nameLength];
	strcpy_s(signatureName, nameLength, name);

	signature.seqLength = signLength;

	signature.sequence = new char[signLength + 1];
	strcpy_s(signature.sequence, signLength + 1, signatureSequence);
}

