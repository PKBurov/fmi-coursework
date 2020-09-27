#pragma once


enum class Objects {
	JSONArray = 0,
	JSONObject = 1
};

template<class T>
class envelop
{
protected:
	
	virtual Objects getType() const = 0;

public:



};

