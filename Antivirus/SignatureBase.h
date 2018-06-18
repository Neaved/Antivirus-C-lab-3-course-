#pragma once
#include <vector>
#include "Signature.h"

class SignatureBase
{
public:
	SignatureBase();
	~SignatureBase();
	vector<Signature> signList;
	
	void Init();	
};