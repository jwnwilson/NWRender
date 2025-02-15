#pragma once
#include "ColourRGB.h"
#include "Scene.h"
#include "Vertex_R.h"
#include "Ray.h"
#include "Material.h"

struct LightParam{
	int lightIndex;
	float lightAttenuation;
};


class IlluminationModel
{
public:
	IlluminationModel(void);
	IlluminationModel(Scene* s){scenePtr=s;}
	~IlluminationModel(void);
	void setScene(Scene* s){scenePtr=s;}
	//void setMaterial(Material* m){matPtr=m;}
	virtual ColourRGB shade(const Ray*,const vector<LightParam>&, int &modelNo){return ColourRGB(0,0,0);}
	
protected:
	ColourRGB getTextureCol(const Vertex_R*, Material *);
	float getAttenuation(const Vertex_R*,LightParam lp);
	Vector3D getHalfVect(const Vector3D&,const Vector3D&);
	Vector3D getLightVect(const  Vertex_R*,int i);
	Vector3D getReflectVect(const  Vertex_R*,int i);
	Vector3D getVeiwVect(const  Vertex_R*,const Ray*);

	Scene* scenePtr;
	//Material *matPtr;
};
