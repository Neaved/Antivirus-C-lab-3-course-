#pragma once
struct SequenceData
{
	SequenceData()
	{
		sequence = NULL;
		seqLength = 0;
	}

	SequenceData(size_t signLength, char* signatureSequence = NULL)
	{
		sequence = signatureSequence;
		seqLength = signLength;
	}

	void FreeMemory()
	{
		delete[] sequence;
	}

	char* sequence;
	LONG seqLength;
};