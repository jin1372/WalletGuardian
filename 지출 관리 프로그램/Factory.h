#pragma once

class Factory
{
public:
	virtual ~Factory() {}
	virtual void Render() const = 0;
	virtual void Update( bool* isRun ) = 0;

};