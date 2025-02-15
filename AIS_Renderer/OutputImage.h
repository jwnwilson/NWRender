#pragma once
#include "Buffer.h"
#include "ColourRGB.h"
#include "Camera.h"

// Will output image as required according to it's derived children

class OutputImage
{
public:
	OutputImage(void);
	OutputImage(const Buffer<ColourRGB>*);
	~OutputImage(void);
	virtual void readBuff(const Buffer<ColourRGB>*);
	virtual void outputImage(const char*){;}
	virtual void setCamera(Camera *c){camera = c;}
	Camera* getCamera(){return camera;}

protected:
	static const Buffer<ColourRGB> *tempBuff;
	Camera *camera;
};
